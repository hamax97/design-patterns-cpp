#include <iostream>

using namespace std;

// Imagine you need a structure to keep record of employess.
// Their addresses, names, .... You might do something like ...

struct Address {
  string street, city;
  int suite;

  Address(const string& street, const string& city, int suite) :
    street(street), city(city), suite(suite) {}

  Address(const Address& a) : street{a.street}, city{a.city}, suite{a.suite}
  {}
};

struct Contact {
  string name;
  Address* address;

  Contact(const string& name, Address* address) :
    name(name), address(address) {}

  // This is one approach of having a deep copy.
  // But there is a more robust approach, which is giving a copy
  // constructor to address as well.
  //Contact(const Contact& c) :
  //  name{c.name},
  //  address{ new Address{ c.address->street, c.address->city, c.address->suite} }
  //{}

  Contact(const Contact& c) :
    name{c.name},
    address{ new Address { *c.address } }
  {}
};

int main() {
  // See 1_motivation.cpp to understand what problem is being solved.

  // Suppose you have two contacts in the same building.
  // Here john is the prototype ...
  Contact john {"John Doe", new Address {"123 East Dr", "London", 123}};

  // jane uses the prototype and customizes it.
  // Having a shallow copy, and then changing the address, which is a pointer
  // would be a bug, because john points to the same address.
  // You need a deep copy, which can be achieved by a copy constructor.
  // See above ...
  Contact jane { john };
  jane.name = "Jane Smith";
  jane.address->suite = 103;

  // There are new all over the place. Obviously they need to be deleted.
  // Just for simplicity they aren't here.

  return 0;
}