#pragma once

#include <memory>
#include "hot_drink.hpp"

using namespace std;

// Abstract factory.
struct HotDrinkFactory {
  virtual unique_ptr<HotDrink> make() const = 0;
  virtual ~HotDrinkFactory() {};
};

// Family of factories for the family of products.

struct TeaFactory : HotDrinkFactory {
  unique_ptr<HotDrink> make() const override {
    return make_unique<Tea>();
  }
};

struct CoffeeFactory : HotDrinkFactory {
  unique_ptr<HotDrink> make() const override {
    return make_unique<Coffee>();
  }
};