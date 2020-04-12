# BUILDER
When piecewise object construction is complicated, provide an API for doing it succinctly.

* Creational pattern. Usually used to create an object that is made up from a bunch of other objects.
* Some objects are simple and can be created in a single constructor call.
* Other objects require a lot to be created.
  - Having object with 10 constrcutor arguments in not productive.
  - Opt for piecewise construction.
* Builder provides and API for constructing an object step-by-step.
