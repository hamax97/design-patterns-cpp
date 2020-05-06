#include <iostream>
#include "hot_drink.hpp"
#include "hot_drink_factory.hpp"
#include "drink_factory.hpp"

using namespace std;

// This is one way of doing it if you don't have an abstract factory.
// Note the use of the if cases.
unique_ptr<HotDrink> make_drink(string type) {
  unique_ptr<HotDrink> drink;
  if (type == "coffee") {
    drink = make_unique<Coffee>();
    drink->prepare(200);
  } else {
    drink = make_unique<Tea>();
    drink->prepare(500);
  }

  return drink;
}

int main() {
  // Without the abstract factory.
  auto d = make_drink("coffee");

  // With the hash table in DrinkFactory and abstract factory.
  DrinkFactory df;
  auto c = df.make_drink("coffee");

  return 0;
}