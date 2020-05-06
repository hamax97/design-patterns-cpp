#pragma once

#include <unordered_map>
#include "hot_drink.hpp"
#include "hot_drink_factory.hpp"

using namespace std;

class DrinkFactory {
  unordered_map<string, unique_ptr<HotDrinkFactory>> hotFactories;
public:
  DrinkFactory() {
    hotFactories["coffee"] = make_unique<CoffeeFactory>();
    hotFactories["tea"] = make_unique<TeaFactory>();
  }

  // This seems more organized and elegant. Now you don't have the if
  // statement. BUT this is NOT CACHE FRIENDLY. The instruction cache
  // does not know what function make() is, or better said, what object
  // it belongs to, therefore, incresing cache misses.
  unique_ptr<HotDrink> make_drink(const string& name) {
    auto drink = hotFactories[name]->make();
    drink->prepare(500);
    return drink;
  }
};