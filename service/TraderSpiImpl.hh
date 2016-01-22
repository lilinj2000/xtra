#ifndef XTRA_TRADER_SPI_IMPL_HH
#define XTRA_TRADER_SPI_IMPL_HH


#include "CXeleTraderApi.hpp"

namespace xtra
{

class TraderServiceImpl;

class TraderSpiImpl : public CXeleTraderSpi
{
 public:
		
  TraderSpiImpl(TraderServiceImpl* service);
		
  virtual ~TraderSpiImpl();

  // interface from CXeleTraderSpi

  virtual void OnFrontConnected();

  virtual void OnFrontDisconnected(int nReason);

  virtual void OnPackageStart(int nTopicID, int nSequenceNo);

  virtual void OnPackageEnd(int nTopicID, int nSequenceNo);

  virtual void OnRspError(CXeleFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
  
  virtual void OnRspUserLogin(CXeleFtdcRspUserLoginField *pRspUserLogin, CXeleFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);
  
  virtual void OnRspUserLogout(CXeleFtdcRspUserLogoutField *pRspUserLogout,
                               CXeleFtdcRspInfoField *pRspInfo,
                               int nRequestID,
                               bool bIsLast);

  virtual void OnRspOrderInsert(CXeleFtdcInputOrderField *pInputOrder, CXeleFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast);

  virtual void OnRspQryClientAccount(CXeleFtdcRspClientAccountField *pClientAccount,
                                     CXeleFtdcRspInfoField *pRspInfo,
                                     int nRequestID,
                                     bool bIsLast);
  
  virtual void OnRtnTrade(CXeleFtdcTradeField *pTrade);

  virtual void OnRtnOrder(CXeleFtdcOrderField *pOrder);

  virtual void OnErrRtnOrderInsert(CXeleFtdcInputOrderField *pInputOrder, CXeleFtdcRspInfoField *pRspInfo);

  virtual void OnRspQryOrder(CXeleFtdcOrderField* pOrderField, CXeleFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);

  virtual void OnRspQryTrade(CXeleFtdcTradeField* pTradeField, CXeleFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast);
  
  
 protected:
  
    void checkRspInfo(CXeleFtdcRspInfoField *pRspInfo);
  
 private:
  
  TraderServiceImpl* service_;
};

}; // namesapce xtra

#endif // XTRA_TRADER_SPI_IMPL_HH
