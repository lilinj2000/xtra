#ifndef XTRA_TRADER_SERVICE_HH
#define XTRA_TRADER_SERVICE_HH

#include <string>
#include "soil/json.h"
#include "soil/log.h"

namespace xtra {

class TraderCallback {
 public:
  virtual void onRspError(
      const std::string& theRspInfo,
      int nRequestID,
      bool bIsLast) {
    SOIL_FUNC_TRACE;

    SOIL_DEBUG_PRINT(theRspInfo);
    SOIL_DEBUG_PRINT(nRequestID);
    SOIL_DEBUG_PRINT(bIsLast);
  }

  virtual void onRspUserLogin(
      const std::string& theRspUserLogin,
      const std::string& theRspInfo,
      int nRequestID,
      bool bIsLast) {
    SOIL_FUNC_TRACE;

    SOIL_DEBUG_PRINT(theRspUserLogin);
    SOIL_DEBUG_PRINT(theRspInfo);
    SOIL_DEBUG_PRINT(nRequestID);
    SOIL_DEBUG_PRINT(bIsLast);
  }

  virtual void onRspUserLogout(
      const std::string& theRspUserLogout,
      const std::string& theRspInfo,
      int nRequestID,
      bool bIsLast) {
    SOIL_FUNC_TRACE;

    SOIL_DEBUG_PRINT(theRspUserLogout);
    SOIL_DEBUG_PRINT(theRspInfo);
    SOIL_DEBUG_PRINT(nRequestID);
    SOIL_DEBUG_PRINT(bIsLast);
  }

  virtual void onRspOrderInsert(
      const std::string& theInputOrder,
      const std::string& theRspInfo,
      int nRequestID,
      bool bIsLast) {
    SOIL_FUNC_TRACE;

    SOIL_DEBUG_PRINT(theInputOrder);
    SOIL_DEBUG_PRINT(theRspInfo);
    SOIL_DEBUG_PRINT(nRequestID);
    SOIL_DEBUG_PRINT(bIsLast);
  }

  virtual void onRspOrderAction(
      const std::string& theOrderAction,
      const std::string& theRspInfo,
      int nRequestID,
      bool bIsLast) {
    SOIL_FUNC_TRACE;

    SOIL_DEBUG_PRINT(theOrderAction);
    SOIL_DEBUG_PRINT(theRspInfo);
    SOIL_DEBUG_PRINT(nRequestID);
    SOIL_DEBUG_PRINT(bIsLast);
  }

  virtual void onRspQryClientPosition(
      const std::string& theRspClientPosition,
      const std::string& theRspInfo,
      int nRequestID,
      bool bIsLast) {
    SOIL_FUNC_TRACE;

    SOIL_DEBUG_PRINT(theRspClientPosition);
    SOIL_DEBUG_PRINT(theRspInfo);
    SOIL_DEBUG_PRINT(nRequestID);
    SOIL_DEBUG_PRINT(bIsLast);
  }

  virtual void onRspQryInstrument(
      const std::string& theRspInstrument,
      const std::string& theRspInfo,
      int nRequestID,
      bool bIsLast) {
    SOIL_FUNC_TRACE;

    SOIL_DEBUG_PRINT(theRspInstrument);
    SOIL_DEBUG_PRINT(theRspInfo);
    SOIL_DEBUG_PRINT(nRequestID);
    SOIL_DEBUG_PRINT(bIsLast);
  }

  virtual void onRspQryClientAccount(
      const std::string& theClientAccount,
      const std::string& theRspInfo,
      int nRequestID,
      bool bIsLast) {
    SOIL_FUNC_TRACE;

    SOIL_DEBUG_PRINT(theClientAccount);
    SOIL_DEBUG_PRINT(theRspInfo);
    SOIL_DEBUG_PRINT(nRequestID);
    SOIL_DEBUG_PRINT(bIsLast);
  }

  virtual void onRspQryInstrumentMarginRate(
      const std::string& theRspInstrumentMarginRate,
      const std::string& theRspInfo,
      int nRequestID,
      bool bIsLast) {
    SOIL_FUNC_TRACE;

    SOIL_DEBUG_PRINT(theRspInstrumentMarginRate);
    SOIL_DEBUG_PRINT(theRspInfo);
    SOIL_DEBUG_PRINT(nRequestID);
    SOIL_DEBUG_PRINT(bIsLast);
  }

  virtual void onRspQryInstrumentCommissionRate(
      const std::string& theRspInstrumentCommissionRate,
      const std::string& theRspInfo,
      int nRequestID,
      bool bIsLast) {
    SOIL_FUNC_TRACE;

    SOIL_DEBUG_PRINT(theRspInstrumentCommissionRate);
    SOIL_DEBUG_PRINT(theRspInfo);
    SOIL_DEBUG_PRINT(nRequestID);
    SOIL_DEBUG_PRINT(bIsLast);
  }

  virtual void onRspUserPasswordUpdate(
      const std::string& theUserPasswordUpdate,
      const std::string& theRspInfo,
      int nRequestID,
      bool bIsLast) {
    SOIL_FUNC_TRACE;

    SOIL_DEBUG_PRINT(theUserPasswordUpdate);
    SOIL_DEBUG_PRINT(theRspInfo);
    SOIL_DEBUG_PRINT(nRequestID);
    SOIL_DEBUG_PRINT(bIsLast);
  }

  virtual void onRtnTrade(
      const std::string& theTrade) {
    SOIL_FUNC_TRACE;

    SOIL_DEBUG_PRINT(theTrade);
  }

  virtual void onRtnOrder(
      const std::string& theOrder) {
    SOIL_FUNC_TRACE;

    SOIL_DEBUG_PRINT(theOrder);
  }

  virtual void onRtnInstrumentStatus(
      const std::string& theInstrumentStatus) {
    SOIL_FUNC_TRACE;

    SOIL_DEBUG_PRINT(theInstrumentStatus);
  }

  virtual void onRtnInsInstrument(
      const std::string& theInstrument) {
    SOIL_FUNC_TRACE;

    SOIL_DEBUG_PRINT(theInstrument);
  }

  virtual void onErrRtnOrderInsert(
      const std::string& theInputOrder,
      const std::string& theRspInfo) {
    SOIL_FUNC_TRACE;

    SOIL_DEBUG_PRINT(theInputOrder);
    SOIL_DEBUG_PRINT(theRspInfo);
  }

  virtual void onErrRtnOrderAction(
      const std::string& theOrderAction,
      const std::string& theRspInfo) {
    SOIL_FUNC_TRACE;

    SOIL_DEBUG_PRINT(theOrderAction);
    SOIL_DEBUG_PRINT(theRspInfo);
  }

  virtual void onRspQryOrder(
      const std::string& theOrderField,
      const std::string& theRspInfo,
      int nRequestID,
      bool bIsLast) {
    SOIL_FUNC_TRACE;

    SOIL_DEBUG_PRINT(theOrderField);
    SOIL_DEBUG_PRINT(theRspInfo);
    SOIL_DEBUG_PRINT(nRequestID);
    SOIL_DEBUG_PRINT(bIsLast);
  }

  virtual void onRspQryTrade(
      const std::string& theTradeField,
      const std::string& theRspInfo,
      int nRequestID,
      bool bIsLast) {
    SOIL_FUNC_TRACE;

    SOIL_DEBUG_PRINT(theTradeField);
    SOIL_DEBUG_PRINT(theRspInfo);
    SOIL_DEBUG_PRINT(nRequestID);
    SOIL_DEBUG_PRINT(bIsLast);
  }

  virtual void onRspInstrumentPrice(
      const std::string& theTradeField,
      const std::string& theRspInfo,
      int nRequestID,
      bool bIsLast) {
    SOIL_FUNC_TRACE;

    SOIL_DEBUG_PRINT(theTradeField);
    SOIL_DEBUG_PRINT(theRspInfo);
    SOIL_DEBUG_PRINT(nRequestID);
    SOIL_DEBUG_PRINT(bIsLast);
  }

  virtual void onRspQryExchangeFront(
      const std::string& theRspExchangeFront,
      const std::string& theRspInfo,
      int nRequestID,
      bool bIsLast) {
    SOIL_FUNC_TRACE;

    SOIL_DEBUG_PRINT(theRspExchangeFront);
    SOIL_DEBUG_PRINT(theRspInfo);
    SOIL_DEBUG_PRINT(nRequestID);
    SOIL_DEBUG_PRINT(bIsLast);
  }

  virtual ~TraderCallback() {
  }
};


class TraderService {
 public:
  virtual std::string tradingDay() = 0;

  virtual int32_t openBuyOrder(
      const std::string& instru,
      double price,
      int volume) = 0;

  virtual int32_t openBuyOrderFAK(
      const std::string& instru,
      double price,
      int volume) = 0;

  virtual int32_t openBuyOrderFOK(
      const std::string& instru,
      double price,
      int volume) = 0;

  virtual void queryAccount() = 0;

  static TraderService* create(
      const rapidjson::Document& doc,
      TraderCallback* callback);
};

}; // namesapce xtra

#endif // XTRA_TRADER_SERVICE_HH
