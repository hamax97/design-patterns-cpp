#include <iostream>

using namespace std;

// Imagine you need a structure to keep record of employess.
// Their addresses, names, .... You might do something like ...

struct Address {
  string street, city;
  int suite;

  Address(const string& street, const string& city, int suite) :
    street(street), city(city), suite(suite) {}
};

struct Contact {
  string name;
  Address address;

  Contact(const string& name, const Address& address) :
    name(name), address(address) {}
};

int main() {
  // Suppose you have two contacts in the same building.
  Contact john {"John Doe", Address {"123 East Dr", "London", 123}};
  Contact jane {"Jame Smith", Address {"123 East Dr", "London", 103}};

  // Suppose you many more contacts in the same building.
  // Is it really worth it replicating what is above, again and again ...
  // Contact jerardo {"Jerardo Perez", Address {"123 East Dr", "London", 103}};
  Contact jerardo = john;
  jerardo.name = "Jerardo Perez";
  jerardo.address.suite = 202;

  // Up to this point, everything works. But the problem is that normally one
  // would use a pointer to the Address in the Contact, because it's cheaper.
  // Now, doing the above (copying john wich is the prototype), and then
  // modifying jerardo's address would modify john also.
  return 0;
}