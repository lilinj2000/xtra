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

#ifndef SERVICE_TRADER_SERVICE_IMPL_H_
#define SERVICE_TRADER_SERVICE_IMPL_H_

#include <memory>
#include <atomic>

#include "xtra/TraderService.h"
#include "CXeleTraderApi.hpp"
#include "soil/s_timer.h"

namespace xtra
{

class TraderOptions;
class TraderSpiImpl;

class TraderServiceImpl : public TraderService
{
 public:
		
  TraderServiceImpl(
    const rapidjson::Document& doc, 
    TraderServiceCallback* callback);
		
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

  TraderServiceCallback* callback() { 
    return callback_;
  }
  
 protected:
  CXeleFtdcInputOrderField* orderField(int& order_ref);

  void orderGo(CXeleFtdcInputOrderField* req);
  
 private:
  std::unique_ptr<TraderOptions> options_;
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
