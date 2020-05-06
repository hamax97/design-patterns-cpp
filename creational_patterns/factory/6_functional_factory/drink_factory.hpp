#pragma once

#include <unordered_map>
#include <functional>
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

// The idea of the Functional Factory is to use lambas that represent
// the factory creation function instead of the factories themselves.
class FunctionalDrinkFactory {

  unordered_map<string, function<unique_ptr<HotDrink>()>> hotFactories;

public:
  FunctionalDrinkFactory() {
    hotFactories["coffee"] = [] {
      auto coffee = make_unique<Coffee>();
      coffee->prepare(500);
      return coffee;
    };

    hotFactories["tea"] = [] {
      auto tea = make_unique<Tea>();
      tea->prepare(200);
      return tea;
    };
  }

  unique_ptr<HotDrink> make_drink(const string& name) {
    return hotFactories[name]();
  }
};