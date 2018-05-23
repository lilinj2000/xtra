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

#ifndef SERVICE_TRADER_OPTIONS_H_
#define SERVICE_TRADER_OPTIONS_H_

#include <string>
#include "soil/json.h"

namespace xtra {

class TraderOptions {
 public:
  explicit TraderOptions(const rapidjson::Document& doc);
  
  virtual ~TraderOptions();

  int exchange_id;
  
  std::string participant_id;
  std::string user_id;
  std::string password;

  std::string client_id;
  
  std::string front_address;
};

}  


#endif 
