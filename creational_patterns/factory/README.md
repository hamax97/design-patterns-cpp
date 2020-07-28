# Factory and Abstract Factory

* Used when the object construction is becoming complicated.
* Used when cannot overload function with same set of arguments with different names.
* Used to avoid super big constructors with default arguments.
* The object creation is non-piece wise, unlike builder.
  - Here the process of construction can be very variable.
  - The creation can be outsourced to:
    + Factory method.
    + Factory class.
    + Hierarchy of Factories with Abstract Factory.
  - The object creation is reduced mostly to a single call, unlike builder.

## Summary

* A FACTORY METHODS is a static method that creates objects.
* A FACTORY can be external or reside inside the object as an inner class (which allow access to private members, so avoiding friend classes).
* Hierarchies of factories can be used to create related objects (not very common today).

## Examples

1. [Motivation](1_motivation.cpp).
2. [Factory method](2_factory_method.cpp).
3. [Factory](3_factory.cpp).
4. [Inner factory](4_inner_factory.cpp).
5. [Abstract factory](5_abstract_factory).
6. [Functional factory](6_functional_factory).