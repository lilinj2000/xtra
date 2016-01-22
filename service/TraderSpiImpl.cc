#include "TraderSpiImpl.hh"
#include "TraderServiceImpl.hh"
#include "TraderOptions.hh"
#include "XtraLog.hh"

#include "CXeleFtdcUserApiStructPrint.hh"

namespace xtra
{

TraderSpiImpl::TraderSpiImpl(TraderServiceImpl* service) :
    service_(service)
{
  XTRA_TRACE <<"TraderSpiImpl::TraderSpiImpl()" ;
}

TraderSpiImpl::~TraderSpiImpl()
{
  XTRA_TRACE <<"TraderSpiImpl::~TraderSpiImpl()" ;
}

/////////////////////////////////////////
// impl from CXeleTraderSpi
/////////////////////////////////////////
void TraderSpiImpl::OnFrontConnected()
{
  XTRA_TRACE <<"TraderSpiImpl::OnFrontConnected()" ;

  service_->login();
}

void TraderSpiImpl::OnFrontDisconnected(int nReason)
{
  XTRA_TRACE <<"TraderSpiImpl::OnFrontDisconnected()" ;

  XTRA_INFO <<"OnFrontDisconnected, the Reason is " <<std::hex <<nReason ;
}

void TraderSpiImpl::OnPackageStart(int nTopicID, int nSequenceNo)
{
  XTRA_TRACE <<"TraderSpiImpl::OnPackageStart()" ;

  XTRA_INFO <<"nTopicID: " <<nTopicID
            <<" nSequenceNo:" <<nSequenceNo;
}

void TraderSpiImpl::OnPackageEnd(int nTopicID, int nSequenceNo)
{
  XTRA_TRACE <<"TraderSpiImpl::OnPackageEnd()" ;

  XTRA_INFO <<"nTopicID: " <<nTopicID
            <<" nSequenceNo:" <<nSequenceNo;
}

void TraderSpiImpl::OnRspError(CXeleFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  XTRA_TRACE <<"TraderSpiImpl::OnRspError()" ;

  if( pRspInfo )
    XTRA_PDU <<*pRspInfo;
  
}

void TraderSpiImpl::OnRspUserLogin(CXeleFtdcRspUserLoginField *pRspUserLogin,
                           CXeleFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  XTRA_TRACE <<"TraderSpiImpl::OnRspUserLogin()" ;

  try
  {
    checkRspInfo(pRspInfo);
    
    XTRA_PDU <<*pRspUserLogin;

    service_->initSession( pRspUserLogin );
                          
    if( bIsLast )
      service_->notify();

  }
  catch( ... )
  {
  }
  
}

void TraderSpiImpl::OnRspUserLogout(CXeleFtdcRspUserLogoutField *pRspUserLogout,
                                    CXeleFtdcRspInfoField *pRspInfo,
                                    int nRequestID,
                                    bool bIsLast)
{
  XTRA_TRACE <<"TraderSpiImpl::OnRspUserLogout()" ;

  try
  {
    checkRspInfo(pRspInfo);
    
    XTRA_PDU <<*pRspUserLogout;

    if( bIsLast )
      service_->notify();

  }
  catch( ... )
  {
  }

}

void TraderSpiImpl::OnRspOrderInsert(CXeleFtdcInputOrderField *pInputOrder, CXeleFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  XTRA_TRACE <<"TraderSpiImpl::OnRspOrderInsert()" ;

  try
  {
    checkRspInfo(pRspInfo);
    
    XTRA_PDU <<*pInputOrder;

    if( service_->callback() )
    {
      int order_ref = atoi(pInputOrder->OrderLocalID);
      
      service_->callback()->onRspOrderInsert( order_ref );
    }

  }
  catch( ... )
  {
  }

}

void TraderSpiImpl::OnRspQryClientAccount(CXeleFtdcRspClientAccountField *pClientAccount, CXeleFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast)
{
  XTRA_TRACE <<"TraderSpiImpl::OnRspQryClientAccount()" ;

  try
  {
    checkRspInfo(pRspInfo);
    
    XTRA_PDU <<*pClientAccount;
  }
  catch( ... )
  {
  }

}

void TraderSpiImpl::OnRtnTrade(CXeleFtdcTradeField *pTrade)
{
  XTRA_TRACE <<"TraderSpiImpl::OnRtnTrade()" ;

  if( pTrade )
    XTRA_PDU <<*pTrade;

  if( service_->callback() )
  {
    int order_ref = atoi(pTrade->OrderLocalID);

    double price = pTrade->Price;
    double volume = pTrade->Volume;
    
    service_->callback()->onRtnTrade( order_ref, price, volume );
  }

}

void TraderSpiImpl::OnRtnOrder(CXeleFtdcOrderField *pOrder)
{
  XTRA_TRACE <<"TraderSpiImpl::OnRtnOrder()" ;

  if( pOrder )
    XTRA_PDU <<*pOrder;

  if( service_->callback() )
  {
    int order_ref = atoi(pOrder->OrderLocalID);

    std::string order_status;
    order_status.push_back(pOrder->OrderStatus);
    std::string status_msg;
    
    service_->callback()->onRtnOrder( order_ref, order_status, status_msg );
  }
  
}


void TraderSpiImpl::OnErrRtnOrderInsert(CXeleFtdcInputOrderField *pInputOrder, CXeleFtdcRspInfoField *pRspInfo)
{
  XTRA_TRACE <<"TraderSpiImpl::OneErrRtnOrderInsert()" ;

  try
  {
    checkRspInfo(pRspInfo);
    
    XTRA_PDU <<*pInputOrder;

  }
  catch( ... )
  {
  }
}

void TraderSpiImpl::OnRspQryOrder(CXeleFtdcOrderField* pOrderField, CXeleFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
  XTRA_TRACE <<"TraderSpiImpl::OnRspQryOrder()";
  
  try
  {
    checkRspInfo(pRspInfo);
    
    XTRA_PDU <<*pOrderField;
  }
  catch( ... )
  {
  }

  
}

void TraderSpiImpl::OnRspQryTrade(CXeleFtdcTradeField* pTradeField, CXeleFtdcRspInfoField* pRspInfo, int nRequestID, bool bIsLast)
{
  XTRA_TRACE <<"TraderSpiImpl::OnRspQryTrade()";
  
  try
  {
    checkRspInfo(pRspInfo);
    
    XTRA_PDU <<*pTradeField;
  }
  catch( ... )
  {
  }

}

void TraderSpiImpl::checkRspInfo(CXeleFtdcRspInfoField *pRspInfo)
{
  XTRA_TRACE <<"TraderSpiImpl::checkRspInfo()" ;

  if( pRspInfo )
    XTRA_PDU <<*pRspInfo ;
  
  bool result = ((pRspInfo) && (pRspInfo->ErrorID != 0));
  
  if (result)
  {
    std::stringstream err_stream;
    err_stream <<"ErrorID=" <<pRspInfo->ErrorID <<","
               <<"ErrorMsg=" <<pRspInfo->ErrorMsg;

    throw std::runtime_error(err_stream.str());
  }
  
}


} // namespace xtra
