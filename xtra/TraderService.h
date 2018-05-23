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

#ifndef XTRA_TRADER_SERVICE_H_
#define XTRA_TRADER_SERVICE_H_

#include <string>

#include "soil/json.h"

namespace xtra
{

class TraderServiceCallback
{
 public:
  virtual void onRspError(int errord_id, const std::string& error_msg)= 0;
  
  virtual void onRspOrderInsert(int order_ref, bool is_success)= 0;

  virtual void onErrRtnOrderInsert(int order_ref) = 0;

  virtual void onRtnOrder(int order_ref, const std::string& order_status, const std::string& status_msg) = 0;

  virtual void onRtnTrade(int order_ref,
                          double price, int volume)= 0;
  
  virtual ~TraderServiceCallback() {}
};


class TraderService
{
 public:

  virtual std::string tradingDay() = 0;

  virtual int orderOpenBuy(const std::string& instru,
                           double price, int volume) = 0;

  virtual int orderOpenBuyFAK(const std::string& instru,
                              double price, int volume) = 0;

  virtual int orderOpenBuyFOK(const std::string& instru,
                              double price, int volume) = 0;

  virtual int orderOpenSell(const std::string& instru,
                            double price, int volume) = 0;

  virtual int orderOpenSellFAK(const std::string& instru,
                              double price, int volume) = 0;

  virtual int orderOpenSellFOK(const std::string& instru,
                              double price, int volume) = 0;

  virtual int orderCloseBuy(const std::string& instru,
                            double price, int volume) = 0;

  virtual int orderCloseSell(const std::string& instru,
                            double price, int volume) = 0;

  virtual int queryAccount() = 0;
  
  virtual ~TraderService() {}
  
  static TraderService* createService(
    const rapidjson::Document& doc, 
    TraderServiceCallback* callback);

};


}; // namesapce xtra

#endif // XTRA_TRADER_SERVICE_HH
