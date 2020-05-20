#include <iostream>
#include <memory>

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

  Contact(const Contact& c) :
    name{c.name},
    address{ new Address { *c.address } }
  {}
};

// One could have a global object that serves as the main prototype
// and just copy from it.
// Contact prototype {"", new Address {"123 East Dr", "London", 0}};
// But this is still too permisive for the user.
// So you can have an employee factory that builds from an internal
// prototype ...
struct EmployeeFactory {
public:
  static unique_ptr<Contact>  createEmployee(const string& name, int suite) {
    // Note that the prototype is only visible within this function and is
    // static.
    static Contact prototype { "", new Address {"123 East Dr", "London", 0} };
    return newEmployee(name, suite, prototype);
  }

private:
  static unique_ptr<Contact> newEmployee(const string& name, int suite,
    Contact& prototype) {
    // Build new employee from prototype ...
    auto result = make_unique<Contact>(prototype);
    // Then customize the new employee ...
    result->name = name;
    result->address->suite = suite;
    return result;
  }
};

int main() {
  // See 1_motivation.cpp to understand what problem is being solved.

  // Creating john (the prototype) like this, might not be convenient.
  // You can have a nicer API for the user, something that returns to thi
  // the prototype ...
  //Contact john {"John Doe", new Address {"123 East Dr", "London", 123}};

  auto john = EmployeeFactory::createEmployee("John Doe", 123);
  Contact jane { *john };
  jane.name = "Jane Smith";
  jane.address->suite = 103;

  // If you want to restrict the Contact creation to the factory only,
  // privatize the Contact and Address constructors as well.

  return 0;
}