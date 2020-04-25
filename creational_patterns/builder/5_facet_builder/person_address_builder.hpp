#pragma once

#include <string>
#include "person.hpp"
#include "person_builder.hpp"

class PersonAddressBuilder : public PersonBuilderBase {
private:
  using Self = PersonAddressBuilder;
public:
  // April 25 2020, this looks ugly to me. This class is created from the
  // PersonBuilderBase which has the reference to p. But then when this is
  // created, it creates another PersonBuilderBase, but with the same reference
  // It's kind of a loop creation, seems ugly to me.
  explicit PersonAddressBuilder(Person& p) : PersonBuilderBase(p) {}

  Self& at(std::string street_address) {
    person.street_address = street_address;
    return *this;
  }

  Self& with_postcode(std::string post_code) {
    person.post_code = post_code;
    return *this;
  }

  Self& in(std::string city) {
    person.city = city;
    return *this;
  }
};