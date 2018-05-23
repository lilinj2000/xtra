// Copyright 2017 The Xtra Authors.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//
// -----------------------------------------------------------------------------
// File: [file_name]
// -----------------------------------------------------------------------------
//
// [file_descrition]
//
// Example:
//
//   ... ...
//
//

#include "service/TraderServiceImpl.h"
#include "service/TraderOptions.h"
#include "service/TraderSpiImpl.h"
#include "service/CXeleFtdcUserApiStructPrint.h"
#include "soil/log.h"

namespace xtra {

TraderServiceImpl::TraderServiceImpl(const rapidjson::Document& doc,
  TraderServiceCallback* callback) :
    trader_api_(NULL),
    callback_(callback),
    request_id_(0),
    max_order_ref_(-1)
{
  SOIL_FUNC_TRACE;

  cond_.reset( soil::STimer::create() );

  options_.reset(new TraderOptions(doc));

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
  SOIL_FUNC_TRACE;
  
  trader_api_->RegisterSpi(NULL);
  
  trader_api_->Release();
  
  trader_api_ = NULL;
}


std::string TraderServiceImpl::tradingDay()
{
  SOIL_FUNC_TRACE;

  return trading_day_;
}

int TraderServiceImpl::orderOpenBuy(const std::string& instru,
                                    double price, int volume)
{
  SOIL_FUNC_TRACE;

  SOIL_DEBUG_PRINT(instru);
  SOIL_DEBUG_PRINT(price);
  SOIL_DEBUG_PRINT(volume);

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
  SOIL_FUNC_TRACE;

  SOIL_DEBUG_PRINT(instru);
  SOIL_DEBUG_PRINT(price);
  SOIL_DEBUG_PRINT(volume);

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
  SOIL_FUNC_TRACE;

  SOIL_DEBUG_PRINT(instru);
  SOIL_DEBUG_PRINT(price);
  SOIL_DEBUG_PRINT(volume);

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
  SOIL_FUNC_TRACE;

  SOIL_DEBUG_PRINT(instru);
  SOIL_DEBUG_PRINT(price);
  SOIL_DEBUG_PRINT(volume);

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
  SOIL_FUNC_TRACE;
  SOIL_DEBUG_PRINT(instru);
  SOIL_DEBUG_PRINT(price);
  SOIL_DEBUG_PRINT(volume);

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
  SOIL_FUNC_TRACE;

  SOIL_DEBUG_PRINT(instru);
  SOIL_DEBUG_PRINT(price);
  SOIL_DEBUG_PRINT(volume);

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
  SOIL_FUNC_TRACE;

  SOIL_DEBUG_PRINT(instru);
  SOIL_DEBUG_PRINT(price);
  SOIL_DEBUG_PRINT(volume);

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
  SOIL_FUNC_TRACE;

  SOIL_DEBUG_PRINT(instru);
  SOIL_DEBUG_PRINT(price);
  SOIL_DEBUG_PRINT(volume);

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
  SOIL_FUNC_TRACE;

  CXeleFtdcQryClientAccountField req;
  memset(&req, 0x0, sizeof(req));
  
  strncpy( req.ClientID, options_->client_id.data(), sizeof(req.ClientID) );

  SOIL_DEBUG_PRINT(req);
  
  int result = trader_api_->ReqQryClientAccount(&req, ++request_id_);

  if( result!=0 )
  {
    SOIL_ERROR("return code {}", result);
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
  SOIL_FUNC_TRACE;

  CXeleFtdcReqUserLoginField req;
  memset(&req, 0x0, sizeof(req));

  strncpy( req.UserID, options_->user_id.data(), sizeof(req.UserID) );
  strncpy( req.ParticipantID, options_->participant_id.data(), sizeof(req.ParticipantID) );
  strncpy( req.Password, options_->password.data(), sizeof(req.Password) );

  SOIL_DEBUG_PRINT(req);
  
  int result = trader_api_->ReqUserLogin(&req, ++request_id_);

  if( result!=0 )
  {
    SOIL_ERROR("return code {}", result);
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
  SOIL_FUNC_TRACE;
  
  SOIL_DEBUG_IF_PRINT(req);
  
  int result = trader_api_->ReqOrderInsert(req, ++request_id_);

  if( result!=0 )
  {
    SOIL_ERROR("return code {}", result);
    throw ;
  }
}

TraderService* TraderService::create(
  const rapidjson::Document& doc, 
  TraderServiceCallback* callback) {
  return new TraderServiceImpl(doc, callback);
}

} // namespace xtra
