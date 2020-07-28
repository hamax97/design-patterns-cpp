# Liskov Substitution Principle

* Objects in a program should be replaceable with instances of their subtypes without altering the correctness of the program.
* If you have a function that receives a base class, any *derived* class should be able to be substituted in the function without any problem.
    - The function `process` in the example shown has a behavior that won't work for the different `Rectangle`s. That is, it has a negative side effect when a `Square` is passed.
* The example compiles but the expected behavior is not ok, see the example.
* [Example](lsp.cpp).
