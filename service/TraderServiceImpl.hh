#ifndef XTRA_TRADER_SERVICE_IMPL_HH
#define XTRA_TRADER_SERVICE_IMPL_HH

#include <memory>
#include <atomic>

#include "xtra/TraderService.hh"
#include "CXeleTraderApi.hpp"

#include "soil/STimer.hh"

namespace xtra
{

class TraderOptions;
class TraderSpiImpl;

class TraderServiceImpl : public TraderService
{
 public:
		
  TraderServiceImpl(soil::Options* options, TraderServiceCallback* callback);
		
  virtual ~TraderServiceImpl();

  virtual std::string tradingDay() ;

  virtual int orderOpenBuy(const std::string& instru,
                           double price, int volume);

  virtual int orderOpenBuyFAK(const std::string& instru,
                              double price, int volume);

  virtual int orderOpenBuyFOK(const std::string& instru,
                              double price, int volume);

  virtual int orderOpenSell(const std::string& instru,
                            double price, int volume);

  virtual int orderOpenSellFAK(const std::string& instru,
                              double price, int volume);

  virtual int orderOpenSellFOK(const std::string& instru,
                              double price, int volume);

  virtual int orderCloseBuy(const std::string& instru,
                            double price, int volume);

  virtual int orderCloseSell(const std::string& instru,
                            double price, int volume);
  
  virtual int queryAccount();
  
  void login();

  void initSession(CXeleFtdcRspUserLoginField* pRspUserLogin);

  void wait(const std::string& hint="");
  
  void notify();

  TraderServiceCallback* callback() { return callback_; }

  TraderOptions* options() { return options_; }
  
 protected:

  CXeleFtdcInputOrderField* orderField(int& order_ref);

  void orderGo(CXeleFtdcInputOrderField* req);
  
 private:
  
  TraderOptions* options_;
    
  CXeleTraderApi* trader_api_;
  
  std::unique_ptr<TraderSpiImpl> trader_spi_;

  TraderServiceCallback* callback_;
  
  std::atomic_int request_id_;

  std::unique_ptr<soil::STimer> cond_;

  std::string trading_day_;
  
  std::atomic_int max_order_ref_;
};

}; // namesapce xtra

#endif // XTRA_TRADER_SERVICE_IMPL_HH
