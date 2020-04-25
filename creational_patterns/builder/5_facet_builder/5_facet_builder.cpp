#include <iostream>
#include "person.hpp"
#include "person_builder.hpp"
#include "person_job_builder.hpp"
#include "person_address_builder.hpp"

using namespace std;

// Pattern for building very complex objects. Objects that might require
// more than one builder.

int main() {

  Person p = Person::create()
    .lives().at("El Salvador").with_postcode("050016").in("Medellin")
    .works().at("Google").as_a("Software Engineer").earning(96e3);
  return 0;
}