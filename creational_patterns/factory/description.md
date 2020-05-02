# FACTORY AND ABSTRACT FACTORY

* Creational pattern.
* Used when the object construction is becoming complicated.
* Used when cannot overload function with same set of arguments with different names.
* Used to avoid super big constructors with default arguments.
* The object creation is non-piece wise, unlike builder.
  - Here the process of construction can be very variable.
  - The creation can be outsourced to:
    + Factory method.
    + Factory class.
    + Hierarchy of Factories with Abstract Factory.
  - The object creation is reduced mostly to a single call, unlinke builder.