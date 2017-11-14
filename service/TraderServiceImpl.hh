#ifndef XTRA_TRADER_SERVICE_IMPL_HH
#define XTRA_TRADER_SERVICE_IMPL_HH

#include <atomic>

#include "xtra/TraderService.hh"
#include "CXeleTraderApi.hpp"
#include "soil/STimer.hh"
#include "soil/json.hh"

namespace xtra {

class TraderOptions;
class TraderSpiImpl;

class TraderServiceImpl
    : public TraderService {
 public:
  TraderServiceImpl(
      const rapidjson::Document& doc,
      TraderCallback* callback);

  virtual ~TraderServiceImpl();

  virtual std::string tradingDay() ;

  virtual int32_t openBuyOrder(
      const std::string& instru,
      double price,
      int volume);

  virtual int32_t openBuyOrderFAK(
      const std::string& instru,
      double price,
      int volume);

  virtual int32_t openBuyOrderFOK(
      const std::string& instru,
      double price,
      int volume);

  virtual void queryAccount();
  
  void login();

  void logout();

  void rspLogin(
      CXeleFtdcRspUserLoginField* pRspUserLogin);

  void notify();

  TraderCallback* callback() {
    return callback_;
  }

 protected:
  std::shared_ptr<CXeleFtdcInputOrderField>
  reqOrderMessage(
      const std::string& instru,
      double price,
      int volume,
      TXeleFtdcDirectionType direction = XELE_FTDC_D_Buy,
      TXeleFtdcOffsetFlagType offset_flag = XELE_FTDC_OF_Open,
      TXeleFtdcTimeConditionType time_condition = XELE_FTDC_TC_GFD,
      TXeleFtdcVolumeConditionType volume_condition = XELE_FTDC_VC_AV);

  int32_t orderGo(
      std::shared_ptr<CXeleFtdcInputOrderField> req);

  void wait(const std::string& hint = "");

  std::string orderLocalID(int32_t order_ref) {
    return fmt::format("{:0>12}", order_ref);
  }
  
 private:
  std::unique_ptr<TraderOptions> options_;
    
  CXeleTraderApi* trader_api_;
  
  std::unique_ptr<TraderSpiImpl> trader_spi_;
  TraderCallback* callback_;
  
  std::atomic_uint request_id_;
  std::unique_ptr<soil::STimer> cond_;
  std::string trading_day_;
  
  std::atomic_int max_order_ref_;
};

}; // namesapce xtra

#endif // XTRA_TRADER_SERVICE_IMPL_HH
