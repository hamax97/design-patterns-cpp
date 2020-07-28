# Open-Closed Principle

* Functions, Classes, Modules, ..., should be opened for extension, but closed for modification.
* Your system should be OPENED for extension (e.g by inheritance), CLOSED for modification.
* The goal of this principle is to avoid to jump to code that you have already written.
* In the example, you can add as many new specifications as you want, because you are extending your code by inherinting from a specification. In theory, you would never have to modify the Specification interface, just inherit from it and create new ones.
* [Example](ocp_with_specification_pattern.cpp).
