#include "TraderServiceImpl.hh"

#include "XtraLog.hh"
#include "TraderOptions.hh"
#include "TraderSpiImpl.hh"

#include "CXeleFtdcUserApiStructPrint.hh"

namespace xtra
{

TraderServiceImpl::TraderServiceImpl(soil::Options* options, TraderServiceCallback* callback) :
    trader_api_(NULL),
    callback_(callback),
    request_id_(0),
    max_order_ref_(-1)
{
  XTRA_TRACE <<"TraderServiceImpl::TraderServiceImpl()" ;

  cond_.reset( soil::STimer::create() );

  options_ = dynamic_cast<TraderOptions*>(options);
  
  trader_api_ = CXeleTraderApi::CreateTraderApi(options_->exchange_id);

  trader_spi_.reset( new TraderSpiImpl(this) );
  
  trader_api_->RegisterSpi( trader_spi_.get() );

  trader_api_->SubscribePrivateTopic(XELE_TERT_QUICK);
  
  trader_api_->SubscribePublicTopic(XELE_TERT_QUICK);

  trader_api_->RegisterFront( const_cast<char*>(options_->front_address.data()) );

  trader_api_->Init();

  wait("login");
}

TraderServiceImpl::~TraderServiceImpl()
{
  XTRA_TRACE <<"TraderServiceImpl::~TraderServiceImpl()" ;
  
  trader_api_->RegisterSpi(NULL);
  
  trader_api_->Release();
  
  trader_api_ = NULL;
}


std::string TraderServiceImpl::tradingDay()
{
  XTRA_TRACE <<"TraderServiceImpl::tradingDate()" ;

  return trading_day_;
}

int TraderServiceImpl::orderOpenBuy(const std::string& instru,
                                    double price, int volume)
{
  XTRA_TRACE <<"TraderServiceImpl::orderOpenBuy()" ;

  XTRA_DEBUG <<"instru: " <<instru
            <<"\t price: " <<price
            <<"\t volume: " <<volume;

  int order_ref = -1;

  std::unique_ptr<CXeleFtdcInputOrderField> req( orderField(order_ref) );

  strncpy(req->InstrumentID, instru.data(), sizeof(req->InstrumentID));
  req->Direction = XELE_FTDC_D_Buy;
  req->LimitPrice = price;
  req->VolumeTotalOriginal = volume;

  try
  {
    orderGo( req.get() );
  }
  catch( ... )
  {
    throw std::runtime_error("order open buy failed.");
  }
  
  return order_ref;
}

int TraderServiceImpl::orderOpenBuyFAK(const std::string& instru,
                                       double price, int volume)
{
  XTRA_TRACE <<"TraderServiceImpl::orderOpenBuyFAK()" ;

  XTRA_DEBUG <<"instru: " <<instru
            <<"\t price: " <<price
            <<"\t volume: " <<volume;

  int order_ref = -1;

  std::unique_ptr<CXeleFtdcInputOrderField> req( orderField(order_ref) );

  strncpy(req->InstrumentID, instru.data(), sizeof(req->InstrumentID));
  req->Direction = XELE_FTDC_D_Buy;
  req->LimitPrice = price;
  req->VolumeTotalOriginal = volume;

  req->TimeCondition = XELE_FTDC_TC_IOC;
  

  try
  {
    orderGo( req.get() );
  }
  catch( ... )
  {
    throw std::runtime_error("order open buy FAK failed.");
  }
  
  return order_ref;

}

int TraderServiceImpl::orderOpenBuyFOK(const std::string& instru,
                                       double price, int volume)
{
  XTRA_TRACE <<"TraderServiceImpl::orderOpenBuyFOK()" ;

  XTRA_DEBUG <<"instru: " <<instru
            <<"\t price: " <<price
            <<"\t volume: " <<volume;

  int order_ref = -1;

  std::unique_ptr<CXeleFtdcInputOrderField> req( orderField(order_ref) );

  strncpy(req->InstrumentID, instru.data(), sizeof(req->InstrumentID));
  req->Direction = XELE_FTDC_D_Buy;
  req->LimitPrice = price;
  req->VolumeTotalOriginal = volume;

  req->TimeCondition = XELE_FTDC_TC_IOC;
  req->VolumeCondition = XELE_FTDC_VC_CV;

  try
  {
    orderGo( req.get() );
  }
  catch( ... )
  {
    throw std::runtime_error("order open buy FOK failed.");
  }
  
  return order_ref;

}


int TraderServiceImpl::orderOpenSell(const std::string& instru,
                                      double price, int volume)
{
  XTRA_TRACE <<"TraderServiceImpl::orderOpenSell()" ;

  XTRA_DEBUG <<"instru: " <<instru
            <<"\t price: " <<price
            <<"\t volume: " <<volume;

  int order_ref = -1;

  std::unique_ptr<CXeleFtdcInputOrderField> req( orderField(order_ref) );

  strncpy(req->InstrumentID, instru.data(), sizeof(req->InstrumentID));
  req->Direction = XELE_FTDC_D_Sell;
  req->LimitPrice = price;
  req->VolumeTotalOriginal = volume;

  try
  {
    orderGo( req.get() );
  }
  catch( ... )
  {
    throw std::runtime_error("order open sell failed.");
  }

  return order_ref;
}

int TraderServiceImpl::orderOpenSellFAK(const std::string& instru,
                                       double price, int volume)
{
  XTRA_TRACE <<"TraderServiceImpl::orderOpenSellFAK()" ;

  XTRA_DEBUG <<"instru: " <<instru
            <<"\t price: " <<price
            <<"\t volume: " <<volume;

  int order_ref = -1;

  std::unique_ptr<CXeleFtdcInputOrderField> req( orderField(order_ref) );

  strncpy(req->InstrumentID, instru.data(), sizeof(req->InstrumentID));
  req->Direction = XELE_FTDC_D_Sell;
  req->LimitPrice = price;
  req->VolumeTotalOriginal = volume;

  req->TimeCondition = XELE_FTDC_TC_IOC;
  
  try
  {
    orderGo( req.get() );
  }
  catch( ... )
  {
    throw std::runtime_error("order open sell FAK failed.");
  }
  
  return order_ref;

}

int TraderServiceImpl::orderOpenSellFOK(const std::string& instru,
                                       double price, int volume)
{
  XTRA_TRACE <<"TraderServiceImpl::orderOpenSellFOK()" ;

  XTRA_DEBUG <<"instru: " <<instru
            <<"\t price: " <<price
            <<"\t volume: " <<volume;

  int order_ref = -1;

  std::unique_ptr<CXeleFtdcInputOrderField> req( orderField(order_ref) );

  strncpy(req->InstrumentID, instru.data(), sizeof(req->InstrumentID));
  req->Direction = XELE_FTDC_D_Sell;
  req->LimitPrice = price;
  req->VolumeTotalOriginal = volume;

  req->TimeCondition = XELE_FTDC_TC_IOC;
  req->VolumeCondition = XELE_FTDC_VC_CV;

  try
  {
    orderGo( req.get() );
  }
  catch( ... )
  {
    throw std::runtime_error("order open sell FOK failed.");
  }
  
  return order_ref;

}


int TraderServiceImpl::orderCloseBuy(const std::string& instru,
                                     double price, int volume)
{
  XTRA_TRACE <<"TraderServiceImpl::orderCloseBuy()" ;

  XTRA_DEBUG <<"instru: " <<instru
            <<"\t price: " <<price
            <<"\t volume: " <<volume;

  int order_ref = -1;

  std::unique_ptr<CXeleFtdcInputOrderField> req( orderField(order_ref) );

  strncpy(req->InstrumentID, instru.data(), sizeof(req->InstrumentID));
  req->Direction = XELE_FTDC_D_Buy;
  req->LimitPrice = price;
  req->VolumeTotalOriginal = volume;
  req->CombOffsetFlag[0] = XELE_FTDC_OF_CloseToday;

  try
  {
    orderGo( req.get() );
  }
  catch( ... )
  {
    throw std::runtime_error("order close buy failed.");
  }

  return order_ref;

}

int TraderServiceImpl::orderCloseSell(const std::string& instru,
                                     double price, int volume)
{
  XTRA_TRACE <<"TraderServiceImpl::orderCloseSell()" ;

  XTRA_DEBUG <<"instru: " <<instru
            <<"\t price: " <<price
            <<"\t volume: " <<volume;

  int order_ref = -1;

  std::unique_ptr<CXeleFtdcInputOrderField> req( orderField(order_ref) );

  strncpy(req->InstrumentID, instru.data(), sizeof(req->InstrumentID));
  req->Direction = XELE_FTDC_D_Sell;
  req->LimitPrice = price;
  req->VolumeTotalOriginal = volume;
  req->CombOffsetFlag[0] = XELE_FTDC_OF_CloseToday;

  try
  {
    orderGo( req.get() );
  }
  catch( ... )
  {
    throw std::runtime_error("order close sell failed.");
  }

  return order_ref;

}

int TraderServiceImpl::queryAccount()
{
  XTRA_TRACE <<"TraderServiceImpl::queryAccount()" ;

  CXeleFtdcQryClientAccountField req;
  memset(&req, 0x0, sizeof(req));
  
  strncpy( req.ClientID, options_->client_id.data(), sizeof(req.ClientID) );

  XTRA_PDU <<req;
  
  int result = trader_api_->ReqQryClientAccount(&req, ++request_id_);

  if( result!=0 )
  {
    XTRA_ERROR <<"return code " <<result;
    throw std::runtime_error("query account failed.");
  }

}

void TraderServiceImpl::initSession(CXeleFtdcRspUserLoginField* pRspUserLogin)
{
  trading_day_ = pRspUserLogin->TradingDay;
  
  max_order_ref_ = atoi(pRspUserLogin->MaxOrderLocalID);;
}

void TraderServiceImpl::login()
{
  XTRA_TRACE <<"TraderServiceImpl::login()" ;

  CXeleFtdcReqUserLoginField req;
  memset(&req, 0x0, sizeof(req));

  strncpy( req.UserID, options_->user_id.data(), sizeof(req.UserID) );
  strncpy( req.ParticipantID, options_->participant_id.data(), sizeof(req.ParticipantID) );
  strncpy( req.Password, options_->password.data(), sizeof(req.Password) );

  XTRA_PDU <<req;
  
  int result = trader_api_->ReqUserLogin(&req, ++request_id_);

  if( result!=0 )
  {
    XTRA_ERROR <<"return code " <<result;
    throw std::runtime_error("login failed.");
  }

}

void TraderServiceImpl::wait(const std::string& hint)
{
  if( cond_->wait(2000) )
  {
    if( !hint.empty() )
      throw std::runtime_error(hint + " time out");
  }
}

void TraderServiceImpl::notify()
{
  cond_->notifyAll();
}

CXeleFtdcInputOrderField* TraderServiceImpl::orderField(int& order_ref)
{
  std::unique_ptr<CXeleFtdcInputOrderField> req( new CXeleFtdcInputOrderField() );

  order_ref = ++max_order_ref_;
  
  strncpy(req->ParticipantID, options_->participant_id.data(), sizeof(req->ParticipantID));
  strncpy(req->ClientID, options_->client_id.data(), sizeof(req->ClientID));
  strncpy(req->UserID, options_->user_id.data(), sizeof(req->UserID));

  
  req->OrderPriceType = XELE_FTDC_OPT_LimitPrice;

  // req->CombOffsetFlag[0] = XELE_FTDC_OF_Open;
  req->CombOffsetFlag[0] = XELE_FTDC_OF_Open;
  
  req->CombHedgeFlag[0] = XELE_FTDC_OPT_AnyPrice;
  req->TimeCondition = XELE_FTDC_TC_GFD;
  req->VolumeCondition = XELE_FTDC_VC_AV;
  req->MinVolume = 1;
  req->ContingentCondition = XELE_FTDC_CC_Immediately;
  req->ForceCloseReason = XELE_FTDC_FCC_NotForceClose;

  char OrderRef[13];
  snprintf(OrderRef, sizeof(OrderRef), "%d", order_ref);
  strncpy(req->OrderLocalID, OrderRef, sizeof(req->OrderLocalID));

  req->IsAutoSuspend = 0;

  return req.release();
}

void TraderServiceImpl::orderGo(CXeleFtdcInputOrderField* req)
{
  XTRA_TRACE <<"TraderServiceImpl::orderGo()";
  
  XTRA_PDU <<*req;
  
  int result = trader_api_->ReqOrderInsert(req, ++request_id_);

  if( result!=0 )
  {
    XTRA_ERROR <<"return code " <<result;
    throw ;
  }
}

soil::Options* TraderService::createOptions()
{
  return new TraderOptions();
}

TraderService* TraderService::createService(soil::Options* options, TraderServiceCallback* callback)
{
  return new TraderServiceImpl(options, callback);
}

} // namespace xtra
