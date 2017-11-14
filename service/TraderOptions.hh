#ifndef XTRA_TRADER_OPTIONS_HH
#define XTRA_TRADER_OPTIONS_HH

#include <string>
#include "soil/json.hh"

namespace xtra {

class TraderOptions {
 public:
  explicit TraderOptions(
      const rapidjson::Document& doc);

  int32_t exchange_id;
  
  std::string participant_id;
  std::string user_id;
  std::string password;

  std::string client_id;
  std::string account_id;
  
  std::string front_address;
};

}  


#endif 
