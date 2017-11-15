// Copyright (c) 2010
// All rights reserved.

#include "gtest/gtest.h"
#include "service/TraderServiceImpl.hh"

namespace xtra {

using soil::json::get_item_value;

class TraderServiceImplTest
    : public ::testing::Test,
      public TraderCallback {
 public:
  TraderServiceImplTest() {
    rapidjson::Document config;
    soil::json::load_from_file(&config, "xtra.json");
    soil::log::init(config);

    get_item_value(&instru, config, "/test/instru");
    get_item_value(&price, config, "/test/price");
    get_item_value(&volume, config, "/test/volume");

    cond.reset(soil::STimer::create());

    service.reset(
        TraderService::create(
            config,
            this));
  }

  void SetUp() {
  }

  void TearDown() {
  }

  void wait(int ms = 2000) {
    cond->wait(ms);
  }

  void notify(bool is_last) {
    if (is_last) {
      cond->notifyAll();
    }
  }

 protected:
  std::unique_ptr<TraderService> service;
  std::unique_ptr<soil::STimer> cond;

  std::string instru;
  double price;
  int volume;
};

TEST_F(TraderServiceImplTest, queryTest) {
  service->queryAccount();

  wait();

  SUCCEED();
}

TEST_F(TraderServiceImplTest, orderTest) {
  service->openBuyOrderFOK(instru, price, volume);

  wait();

  SUCCEED();
}

}  // namespace xtra
