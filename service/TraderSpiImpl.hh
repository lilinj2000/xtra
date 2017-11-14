#ifndef XTRA_TRADER_SPI_IMPL_HH
#define XTRA_TRADER_SPI_IMPL_HH

#include "CXeleTraderApi.hpp"
#include "TraderServiceImpl.hh"

namespace xtra {

class TraderSpiImpl
    : public CXeleTraderSpi {
 public:
  explicit TraderSpiImpl(
      TraderServiceImpl* service);
		
  virtual ~TraderSpiImpl();

  // interface from CXeleTraderSpi
  virtual void OnFrontConnected();

  virtual void OnFrontDisconnected(
      int nReason);

  virtual void OnPackageStart(
      int nTopicID,
      int nSequenceNo);

  virtual void OnPackageEnd(
      int nTopicID,
      int nSequenceNo);

  virtual void OnRspError(
      CXeleFtdcRspInfoField* pRspInfo,
      int nRequestID,
      bool bIsLast);

  virtual void OnRspUserLogin(
      CXeleFtdcRspUserLoginField* pRspUserLogin,
      CXeleFtdcRspInfoField* pRspInfo,
      int nRequestID,
      bool bIsLast);

  virtual void OnRspUserLogout(
      CXeleFtdcRspUserLogoutField* pRspUserLogout,
      CXeleFtdcRspInfoField* pRspInfo,
      int nRequestID,
      bool bIsLast);

  virtual void OnRspOrderInsert(
      CXeleFtdcInputOrderField* pInputOrder,
      CXeleFtdcRspInfoField* pRspInfo,
      int nRequestID,
      bool bIsLast);

  virtual void OnRspOrderAction(
      CXeleFtdcOrderActionField* pOrderAction,
      CXeleFtdcRspInfoField* pRspInfo,
      int nRequestID,
      bool bIsLast);

  virtual void OnRspQryClientPosition(
      CXeleFtdcRspClientPositionField* pRspClientPosition,
      CXeleFtdcRspInfoField* pRspInfo,
      int nRequestID,
      bool bIsLast);

  virtual void OnRspQryInstrument(
      CXeleFtdcRspInstrumentField* pRspInstrument,
      CXeleFtdcRspInfoField* pRspInfo,
      int nRequestID,
      bool bIsLast);

  virtual void OnRspQryClientAccount(
      CXeleFtdcRspClientAccountField* pClientAccount,
      CXeleFtdcRspInfoField* pRspInfo,
      int nRequestID,
      bool bIsLast);

  virtual void OnRspQryInstrumentMarginRate(
      CXeleFtdcRspInstrumentMarginRateField* pRspInstrumentMarginRate,
      CXeleFtdcRspInfoField* pRspInfo,
      int nRequestID,
      bool bIsLast);

  virtual void OnRspQryInstrumentCommissionRate(
      CXeleFtdcRspInstrumentCommissionRateField* pRspInstrumentCommissionRate,
      CXeleFtdcRspInfoField* pRspInfo,
      int nRequestID,
      bool bIsLast);

  virtual void OnRspUserPasswordUpdate(
      CXeleFtdcUserPasswordUpdateField* pUserPasswordUpdate,
      CXeleFtdcRspInfoField* pRspInfo,
      int nRequestID,
      bool bIsLast);

  virtual void OnRtnTrade(
      CXeleFtdcTradeField* pTrade);

  virtual void OnRtnOrder(
      CXeleFtdcOrderField* pOrder);

  virtual void OnRtnInstrumentStatus(
      CXeleFtdcInstrumentStatusField* pInstrumentStatus);

  virtual void OnRtnInsInstrument(
      CXeleFtdcInstrumentField* pInstrument);

  virtual void OnErrRtnOrderInsert(
      CXeleFtdcInputOrderField* pInputOrder,
      CXeleFtdcRspInfoField* pRspInfo);

  virtual void OnErrRtnOrderAction(
      CXeleFtdcOrderActionField* pOrderAction,
      CXeleFtdcRspInfoField* pRspInfo);

  virtual void OnRspQryOrder(
      CXeleFtdcOrderField* pOrderField,
      CXeleFtdcRspInfoField* pRspInfo,
      int nRequestID,
      bool bIsLast);

  virtual void OnRspQryTrade(
      CXeleFtdcTradeField* pTradeField,
      CXeleFtdcRspInfoField* pRspInfo,
      int nRequestID,
      bool bIsLast);

  virtual void OnRspInstrumentPrice(
      CXeleFtdcRspInstrumentPriceField* pTradeField,
      CXeleFtdcRspInfoField* pRspInfo,
      int nRequestID,
      bool bIsLast);

  virtual void OnRspQryExchangeFront(
      CXeleFtdcRspExchangeFrontField* pRspExchangeFront,
      CXeleFtdcRspInfoField* pRspInfo,
      int nRequestID,
      bool bIsLast);

  TraderCallback* callback() {
    return service_->callback();
  }
  
 private:
  TraderServiceImpl* service_;
};

}; // namesapce xtra

#endif // XTRA_TRADER_SPI_IMPL_HH
