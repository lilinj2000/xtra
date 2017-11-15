// Copyright (c) 2010
// All rights reserved.

#include "TraderOptions.hh"

namespace xtra {

using soil::json::get_item_value;

TraderOptions::TraderOptions(
    const rapidjson::Document& doc) {
  get_item_value(&exchange_id,
                 doc,
                 "/xtra/exchange_id");
  get_item_value(&participant_id,
                 doc,
                 "/xtra/participant_id");
  get_item_value(&user_id,
                 doc,
                 "/xtra/user_id");
  get_item_value(&password,
                 doc,
                 "/xtra/password");
  get_item_value(&client_id,
                 doc,
                 "/xtra/client_id");
  get_item_value(&account_id,
                 doc,
                 "/xtra/account_id");
  get_item_value(&front_address,
                 doc,
                 "/xtra/front_address");
  return;
}

}  // namespace xtra
