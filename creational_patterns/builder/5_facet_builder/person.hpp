#pragma once

#include <string>

class PersonBuilder;

// This person has two types of information which can be constructed
// separately.
class Person {

  // Address info.
  std::string street_address, post_code, city;

  // Employment info.
  std::string company_name, position;
  int annual_income {0};

public:
  // Builder initializer.
  static PersonBuilder create();

  friend class PersonBuilder;
  friend class PersonAddressBuilder;
  friend class PersonJobBuilder;
};