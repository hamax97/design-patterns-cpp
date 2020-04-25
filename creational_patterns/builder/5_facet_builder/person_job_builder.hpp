#pragma once

#include "person.hpp"
#include "person_builder.hpp"

class PersonJobBuilder : public PersonBuilderBase {
private:
  using Self = PersonJobBuilder;

public:
  explicit PersonJobBuilder(Person& p) : PersonBuilderBase{p} {}

  Self& at(std::string company_name) {
    person.company_name = company_name;
    return *this;
  }

  Self& as_a(std::string position) {
    person.position = position;
    return *this;
  }

  Self& earning(int annual_income) {
    person.annual_income = annual_income;
    return *this;
  }
};