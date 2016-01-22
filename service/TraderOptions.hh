#ifndef XTRA_TRADER_OPTIONS_HH
#define XTRA_TRADER_OPTIONS_HH

#include "soil/Config.hh"

#include <string>

namespace xtra
{
namespace po = boost::program_options;

class TraderOptions : public soil::Options
{
 public:

  TraderOptions();
  
  virtual ~TraderOptions();

  virtual po::options_description* configOptions();

  int exchange_id;
  
  std::string participant_id;
  std::string user_id;
  std::string password;

  std::string client_id;
  
  std::string front_address;
  
 private:

  boost::program_options::options_description options_;
};

}  


#endif 
