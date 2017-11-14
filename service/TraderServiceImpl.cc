// Copyright (c) 2010
// All rights reserved.

#include <cassert>

#include "TraderServiceImpl.hh"
#include "TraderOptions.hh"
#include "TraderSpiImpl.hh"
#include "soil/Macro.hh"
#include "soil/Log.hh"

#include "CXeleFtdcUserApiStructPrint.hh"

namespace xtra {

TraderServiceImpl::TraderServiceImpl(
    const rapidjson::Document& doc,
    TraderCallback* callback) :
    trader_api_(nullptr),
    callback_(callback),
    request_id_(0),
    max_order_ref_(-1) {
  SOIL_FUNC_TRACE;

  cond_.reset(soil::STimer::create());
  options_.reset(new TraderOptions(doc));;

  trader_api_ = CXeleTraderApi::CreateTraderApi(
      options_->exchange_id);
  assert(trader_api_ != nullptr);

  SOIL_INFO("the api version: {}", trader_api_->GetVersion());

  trader_spi_.reset(new TraderSpiImpl(this));
  trader_api_->RegisterSpi(trader_spi_.get());

  trader_api_->SubscribePrivateTopic(XELE_TERT_QUICK);
  trader_api_->SubscribePublicTopic(XELE_TERT_QUICK);

  trader_api_->RegisterFront(
      const_cast<char*>(
          options_->front_address.data()));

  trader_api_->Init();
  wait("login");

  SOIL_INFO("trading day: {}", tradingDay());
}

TraderServiceImpl::~TraderServiceImpl() {
  SOIL_FUNC_TRACE;

  logout();
  wait();

  trader_api_->RegisterSpi(nullptr);
  trader_api_->Release();
  trader_api_ = nullptr;
}

std::string TraderServiceImpl::tradingDay() {
  SOIL_FUNC_TRACE;

  return trading_day_;
}

int32_t TraderServiceImpl::openBuyOrder(
    const std::string& instru,
    double price,
    int volume) {
  SOIL_FUNC_TRACE;

  std::shared_ptr<CXeleFtdcInputOrderField>
      req = reqOrderMessage(instru, price, volume);

  return orderGo(req);
}

int32_t TraderServiceImpl::openBuyOrderFAK(
    const std::string& instru,
    double price,
    int volume) {
  SOIL_FUNC_TRACE;

  std::shared_ptr<CXeleFtdcInputOrderField>
      req = reqOrderMessage(
          instru,
          price,
          volume,
          XELE_FTDC_D_Buy,
          XELE_FTDC_OF_Open,
          XELE_FTDC_TC_IOC);

  return orderGo(req);
}

int32_t TraderServiceImpl::openBuyOrderFOK(
    const std::string& instru,
    double price,
    int volume) {
  SOIL_FUNC_TRACE;

  std::shared_ptr<CXeleFtdcInputOrderField>
      req = reqOrderMessage(
          instru,
          price,
          volume,
          XELE_FTDC_D_Buy,
          XELE_FTDC_OF_Open,
          XELE_FTDC_TC_IOC,
          XELE_FTDC_VC_CV);

  return orderGo(req);
}

void TraderServiceImpl::queryAccount() {
  SOIL_FUNC_TRACE;

  CXeleFtdcQryClientAccountField req;
  memset(&req, 0x0, sizeof(req));

  S_INPUT(&req,
          CXeleFtdcQryClientAccountField,
          ClientID,
          options_->client_id.data());
  S_INPUT(&req,
          CXeleFtdcQryClientAccountField,
          AccountID,
          options_->account_id.data());

  SOIL_DEBUG_PRINT(req);

  int result = trader_api_->ReqQryClientAccount(
      &req,
      ++request_id_);

  if (result != 0) {
    throw std::runtime_error(
        fmt::format("query account failed.\n"
                    "return code is {}", result));
  }
}

void TraderServiceImpl::rspLogin(
    CXeleFtdcRspUserLoginField* pRspUserLogin) {
  SOIL_FUNC_TRACE;

  trading_day_ = pRspUserLogin->TradingDay;
  max_order_ref_ = atoi(pRspUserLogin->MaxOrderLocalID);
}

void TraderServiceImpl::login() {
  SOIL_FUNC_TRACE;

  CXeleFtdcReqUserLoginField req;
  memset(&req, 0x0, sizeof(req));

  S_INPUT(&req,
          CXeleFtdcReqUserLoginField,
          UserID,
          options_->user_id.data());
  S_INPUT(&req,
          CXeleFtdcReqUserLoginField,
          Password,
          options_->password.data());
  S_INPUT(&req,
          CXeleFtdcReqUserLoginField,
          ParticipantID,
          options_->participant_id.data());
  req.DataCenterID = 25;

  SOIL_DEBUG_PRINT(req);

  int result = trader_api_->ReqUserLogin(&req, 0);
  if (result != 0) {
    throw std::runtime_error(
        fmt::format("login failed.\n"
                    "return code is {}",
                    result));
  }
}

void TraderServiceImpl::logout() {
  SOIL_FUNC_TRACE;

  CXeleFtdcReqUserLogoutField req;
  memset(&req, 0x0, sizeof(req));

  S_INPUT(&req,
          CXeleFtdcReqUserLogoutField,
          UserID,
          options_->user_id.data());
  S_INPUT(&req,
          CXeleFtdcReqUserLogoutField,
          ParticipantID,
          options_->participant_id.data());
  SOIL_DEBUG_PRINT(req);

  int result = trader_api_->ReqUserLogout(
      &req,
      ++request_id_);
  if (result != 0) {
    throw std::runtime_error(
        fmt::format("logout failed.\n"
                    "return code is {}",
                    result));
  }
}

void TraderServiceImpl::wait(
    const std::string& hint) {
  if (cond_->wait(2000)) {
    if (!hint.empty()) {
      throw std::runtime_error(hint + " time out");
    }
  }
}

void TraderServiceImpl::notify() {
  cond_->notifyAll();
}

std::shared_ptr<CXeleFtdcInputOrderField>
TraderServiceImpl::reqOrderMessage(
      const std::string& instru,
      double price,
      int volume,
      TXeleFtdcDirectionType direction,
      TXeleFtdcOffsetFlagType offset_flag,
      TXeleFtdcTimeConditionType time_condition,
      TXeleFtdcVolumeConditionType volume_condition) {
  SOIL_FUNC_TRACE;

  std::shared_ptr<CXeleFtdcInputOrderField> req(
      new CXeleFtdcInputOrderField());

  S_INPUT(req.get(),
          CXeleFtdcInputOrderField,
          ParticipantID,
          options_->participant_id.data());
  S_INPUT(req.get(),
          CXeleFtdcInputOrderField,
          ClientID,
          options_->client_id.data());
  S_INPUT(req.get(),
          CXeleFtdcInputOrderField,
          UserID,
          options_->user_id.data());
  S_INPUT(req.get(),
          CXeleFtdcInputOrderField,
          InstrumentID,
          instru.data());
  req->OrderPriceType = XELE_FTDC_OPT_LimitPrice;
  req->Direction = direction;
  req->CombOffsetFlag[0] = offset_flag;
  req->CombHedgeFlag[0] = XELE_FTDC_HF_Speculation;
  req->LimitPrice = price;
  req->VolumeTotalOriginal = volume;
  req->TimeCondition = time_condition;
  req->VolumeCondition = volume_condition;
  req->MinVolume = 1;
  req->ContingentCondition = XELE_FTDC_CC_Immediately;
  req->ForceCloseReason = XELE_FTDC_FCC_NotForceClose;
  req->IsAutoSuspend = 0;

  return req;
}

int32_t TraderServiceImpl::orderGo(
    std::shared_ptr<CXeleFtdcInputOrderField> req) {
  SOIL_FUNC_TRACE;

  int32_t order_ref = ++max_order_ref_;
  S_INPUT(req.get(),
          CXeleFtdcInputOrderField,
          OrderLocalID,
          orderLocalID(order_ref).data());
  SOIL_DEBUG_PRINT(*req);

  int result = trader_api_->ReqOrderInsert(
      req.get(),
      ++request_id_);
  if (result != 0) {
    throw std::runtime_error(
        fmt::format("req order insert failed.\n"
                    "return code is {}", result));
  }

  return order_ref;
}

TraderService* TraderService::create(
    const rapidjson::Document& doc,
    TraderCallback* callback) {
  return new TraderServiceImpl(doc, callback);
}

}  // namespace xtra
