# Dependency Inversion Principle

It consists about two main arguments:
1. High-level modules shouldn't depend on low-level modules. Both should depend on abstractions.
   That is, insted of depending on a concrete type you want to be as general
   as possible. You want to use an interface that provides the necessary
   functionality but you don't want to depend on a concrete type, because you're
   then depending on implementation details.

2. Abstractions should not depend on details.
   Details should depend on abstractions.

* Best way of defining dependencies between objects.

[Example](dip.cpp).
