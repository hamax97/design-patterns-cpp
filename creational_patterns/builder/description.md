# BUILDER
When piecewise object construction is complicated, provide an API for doing it succinctly.

* Creational pattern. Usually used to create an object that is made up from a bunch of other objects. Therefore, allowing a step-by-step creation.
* Some objects are simple and can be created in a single constructor call.
* Other objects require a lot to be created.
  - Having object with 10 constrcutor arguments in not productive.
  - Opt for piecewise construction.
* Builder provides and API for constructing an object step-by-step.

## Summary

* Only exists to create objects.
* There can be a static function in the object created that returns the builder or the builder can have a constructor to be called explicitly.
* To make the builder a fluent interface, return a reference to itself.
* Different facets of an object can be built with different buidlers working in tandem via a base class.
