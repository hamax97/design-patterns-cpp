# Singleton
Component that instantiated only once.

For some components it only makes sense to have one in the system:
* Database repository.
* Object factory.

The constructor call might be expensive, so you only want the object
to be constructed once.
* Every consumer has the same instance.
* You want your clients to create any aditional copies.

Also, you might want to take care of lazy instantiation and thead safety.

## Examples

1. [Singleton](1_singleton.cpp).