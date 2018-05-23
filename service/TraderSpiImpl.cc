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

#include <sstream>

#include "service/TraderSpiImpl.h"
#include "service/TraderServiceImpl.h"
#include "service/TraderOptions.h"
#include "service/CXeleFtdcUserApiStructPrint.h"
#include "soil/log.h"

namespace xtra {

TraderSpiImpl::TraderSpiImpl(TraderServiceImpl* service) :
    service_(service) {
  SOIL_FUNC_TRACE;
}

TraderSpiImpl::~TraderSpiImpl() {
  SOIL_FUNC_TRACE;
}

/////////////////////////////////////////
// impl from CXeleTraderSpi
/////////////////////////////////////////
void TraderSpiImpl::OnFrontConnected() {
  SOIL_FUNC_TRACE;

  service_->login();
}

void TraderSpiImpl::OnFrontDisconnected(int nReason) {
  SOIL_FUNC_TRACE;
  SOIL_INFO("OnFrontDisconnected, the Reason is {:#x}", nReason);
}

void TraderSpiImpl::OnPackageStart(int nTopicID, int nSequenceNo) {
  SOIL_FUNC_TRACE;

  SOIL_INFO("nTopicID: {}, nSequenceNo: {}", nTopicID, nSequenceNo);
}

void TraderSpiImpl::OnPackageEnd(int nTopicID, int nSequenceNo) {
  SOIL_FUNC_TRACE;

  SOIL_INFO("nTopicID: {}, nSequenceNo: {}", nTopicID, nSequenceNo);
}

void TraderSpiImpl::OnRspError(
  CXeleFtdcRspInfoField *pRspInfo, 
  int nRequestID, 
  bool bIsLast) {
  SOIL_FUNC_TRACE;
  
  SOIL_DEBUG_IF_PRINT(pRspInfo);
}

void TraderSpiImpl::OnRspUserLogin(CXeleFtdcRspUserLoginField *pRspUserLogin,
                           CXeleFtdcRspInfoField *pRspInfo, int nRequestID, bool bIsLast) {
  SOIL_FUNC_TRACE;

  try  {
    checkRspInfo(pRspInfo);
    
    SOIL_DEBUG_IF_PRINT(pRspUserLogin);

    service_->initSession( pRspUserLogin );
                          
    if( bIsLast )
      service_->notify();
  }  catch (...)  {
  }
  
}

void TraderSpiImpl::OnRspUserLogout(CXeleFtdcRspUserLogoutField *pRspUserLogout,
                                    CXeleFtdcRspInfoField *pRspInfo,
                                    int nRequestID,
                                    bool bIsLast) {
  SOIL_FUNC_TRACE;

  try {
    checkRspInfo(pRspInfo);
    
    SOIL_DEBUG_IF_PRINT(pRspUserLogout);

    if( bIsLast )
      service_->notify();

  } catch (...) {
  }

}

void TraderSpiImpl::OnRspOrderInsert(
  CXeleFtdcInputOrderField *pInputOrder, 
  CXeleFtdcRspInfoField *pRspInfo,
  int nRequestID, 
  bool bIsLast) {
  SOIL_FUNC_TRACE;

  bool is_success = false;
  try
  {
    checkRspInfo(pRspInfo);

    is_success = true;
  }
  catch( ... )
  {
  }

  SOIL_DEBUG_IF_PRINT(pInputOrder);

  if (service_->callback() )
  {
    int order_ref = atoi(pInputOrder->OrderLocalID);
      
    service_->callback()->onRspOrderInsert( order_ref, is_success );
  }


}

void TraderSpiImpl::OnRspQryClientAccount(
  CXeleFtdcRspClientAccountField *pClientAccount, 
  CXeleFtdcRspInfoField *pRspInfo, 
  int nRequestID, 
  bool bIsLast) {
  SOIL_FUNC_TRACE;

  try {
    checkRspInfo(pRspInfo);
    SOIL_DEBUG_IF_PRINT(pClientAccount);
  } catch (...) {
  }

}

void TraderSpiImpl::OnRtnTrade(CXeleFtdcTradeField *pTrade) {
  SOIL_FUNC_TRACE;

  SOIL_DEBUG_IF_PRINT(pTrade);

  if( service_->callback() )
  {
    int order_ref = atoi(pTrade->OrderLocalID);

    double price = pTrade->Price;
    double volume = pTrade->Volume;
    
    service_->callback()->onRtnTrade( order_ref, price, volume );
  }

}

void TraderSpiImpl::OnRtnOrder(CXeleFtdcOrderField *pOrder) {
  SOIL_FUNC_TRACE;

  SOIL_DEBUG_IF_PRINT(pOrder);

  if( service_->callback() )
  {
    int order_ref = atoi(pOrder->OrderLocalID);

    std::string order_status;
    order_status.push_back(pOrder->OrderStatus);
    std::string status_msg;
    
    service_->callback()->onRtnOrder( order_ref, order_status, status_msg );
  }
  
}


void TraderSpiImpl::OnErrRtnOrderInsert(
  CXeleFtdcInputOrderField *pInputOrder, 
  CXeleFtdcRspInfoField *pRspInfo) {
  SOIL_FUNC_TRACE;

  try
  {
    checkRspInfo(pRspInfo); 
  }
  catch( ... )
  {
  }

  SOIL_DEBUG_IF_PRINT(pInputOrder);

  if (service_->callback()) {
    int order_ref = atoi(pInputOrder->OrderLocalID);
      
    service_->callback()->onErrRtnOrderInsert( order_ref );
  }
}

void TraderSpiImpl::OnRspQryOrder(
  CXeleFtdcOrderField* pOrderField, 
  CXeleFtdcRspInfoField* pRspInfo, 
  int nRequestID, 
  bool bIsLast) {
  SOIL_FUNC_TRACE;
  
  try
  {
    checkRspInfo(pRspInfo);
    
    SOIL_DEBUG_IF_PRINT(pOrderField);
  }
  catch( ... )
  {
  }

  
}

void TraderSpiImpl::OnRspQryTrade(
  CXeleFtdcTradeField* pTradeField, 
  CXeleFtdcRspInfoField* pRspInfo, 
  int nRequestID, 
  bool bIsLast) {
  SOIL_FUNC_TRACE;
  
  try
  {
    checkRspInfo(pRspInfo);
    SOIL_DEBUG_IF_PRINT(pTradeField);
  }
  catch( ... )
  {
  }

}

void TraderSpiImpl::checkRspInfo(CXeleFtdcRspInfoField *pRspInfo) {
  SOIL_FUNC_TRACE;
  
  SOIL_DEBUG_IF_PRINT(pRspInfo);
  
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
