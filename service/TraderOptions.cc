// Copyright (c) 2010
// All rights reserved.

#include "TraderOptions.hh"

namespace xtra {

using soil::json::get_item_value;

TraderOptions::TraderOptions(
    const rapidjson::Document& doc) {
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
  get_item_value(&account_id,
                 doc,
                 "/xtra_trader/account_id");
  get_item_value(&front_address,
                 doc,
                 "/xtra_trader/front_address");
  return;
}

}  // namespace xtra
