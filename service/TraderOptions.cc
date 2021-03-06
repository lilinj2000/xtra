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

#include "service/TraderOptions.h"

namespace xtra {

using soil::json::get_item_value;

TraderOptions::TraderOptions(const rapidjson::Document& doc) {
  
  get_item_value(&exchange_id,
                 doc,
                 "/xtra_trader/exchange_id");
  get_item_value(&participant_id,
                 doc,
                 "/xtra_trader/participant_id");
  get_item_value(&user_id,
                 doc,
                 "/xtra_trader/user_id");
  get_item_value(&password,
                 doc,
                 "/xtra_trader/password");
  get_item_value(&client_id,
                 doc,
                 "/xtra_trader/client_id");
  get_item_value(&front_address,
                 doc,
                 "/xtra_trader/front_address");

  return;
  
}

TraderOptions::~TraderOptions(){
}

};  
