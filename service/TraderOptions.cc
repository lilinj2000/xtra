#include "TraderOptions.hh"

#include <fstream>
#include <iostream>
#include <boost/program_options.hpp>

namespace xtra
{

TraderOptions::TraderOptions():
    options_("TraderOptions")
{
  namespace po = boost::program_options;

  options_.add_options()
      ("xtra_trader.exchange_id", po::value<int>(&exchange_id), 
       "exchange id")
      ("xtra_trader.participant_id", po::value<std::string>(&participant_id), 
       "participant id")
      ("xtra_trader.user_id", po::value<std::string>(&user_id), 
       "user id")
      ("xtra_trader.password", po::value<std::string>(&password), 
       "password")
      ("xtra_trader.client_id", po::value<std::string>(&client_id), 
       "client_id")
      ("xtra_trader.front_address", po::value<std::string>(&front_address), 
       "front address")
      ;

  return;
  
}

TraderOptions::~TraderOptions()
{
}

po::options_description* TraderOptions::configOptions()
{
  return &options_;
}

};  
