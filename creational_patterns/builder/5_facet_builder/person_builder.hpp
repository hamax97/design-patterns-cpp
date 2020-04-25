#pragma once

#include "person.hpp"

// This class (PersonBuilder) is intended to be a base class for
// PersonAddressBuilder and PersonJobBuilder, but there is a problem:
// The builder has to have the Person p stored somewhere, this class
// is a nice place to store that as an attribute. But whenever one of
// its child classes (Address/Job) is instantiated a new person is created,
// and we need the same person for both childs.

// One approach is to have a Base class (PersonBuilderBase) with a reference
// to the object and a derived class with the actual object (PersonBuilder).
// Now the Address and Job builders can inherit from the
// Base class (or Facade class) which only has a reference.

// Nevertheless, see comment on person_address_builder.hpp.

class PersonAddressBuilder;
class PersonJobBuilder;

class PersonBuilderBase {
  protected:
    Person& person;

  public:
    explicit PersonBuilderBase(Person& p);

    // Builder facets.
    PersonAddressBuilder lives() const;
    PersonJobBuilder works() const;

    operator Person() const {
      return std::move(person); // Using move in return is bad practice.
      // Prevents return value optimization.
    }
};

class PersonBuilder : public PersonBuilderBase {
  private:
    Person person; // This lvalue reference is passed to the base class.
  public:
    PersonBuilder();
};