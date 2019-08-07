#include <iostream>
#include <string>
#include <tuple>
#include <vector>

using namespace std;

enum class Relationship {
                         parent,
                         child,
                         sibling
};

struct Person {
  string name;
};

struct RelationshipBrowser {
  virtual vector<Person> find_all_children_of(const string& name) = 0;
};

// Low-level module. It contains storage functionality.
// Also it has functions to populate that storage.
struct Relationships : RelationshipBrowser {

  vector<tuple<Person, Relationship, Person>> relations;

  void add_parent_and_child(const Person& parent, const Person& child) {
    relations.push_back({parent, Relationship::parent, child});
    relations.push_back({child, Relationship::child, parent});
  }

  vector<Person> find_all_children_of(const string& name) override {
    vector<Person> result;
    for (auto&& [first, rel, second] : relations) {
      if (first.name == name && rel == Relationship::parent)
        result.push_back(second);
    }
    return result;
  }
};

// High-level module.
// It uses relationships functionalities.
struct Research {

  // ERROR: Dependence on low-level module relationships.
  Research(Relationships& relationships) {
    // ERROR: Dependence on deatils.
    // What if 'Relationships' decides to make 'relations' private, or it
    // decides to change from 'vector' to another data structure.
    auto& relations = relationships.relations;
    for (auto&& [first, rel, second] : relations) {
      if (first.name == "John" && rel == Relationship::parent)
        cout << "John has a child called " << second.name << endl;
    }

    // Also you are using a functionality that shouldn't be used here ...
    // You are getting information about a relationship, and that is
    // 'Relationships's responsibility. (Single Responsibility Principle).
    // So:
    // 1. You can give this functionality to 'Relationships' or ...
    // 2. You can have an abstraction.
    //    -> RelationshipBrowser
    //    -> Make Relationships inherit from RelationshipBrowser
    //    -> New constructor that depends on 'RelationshipBrowser'
  }

  Research(RelationshipBrowser& browser) {
    for (auto& child : browser.find_all_children_of("John")) {
      cout << "John has a child called " << child.name << endl;
    }
  }
};

int main() {

  Person parent{"John"};
  Person child1{"Chris"}, child2{"Matt"};

  Relationships relationships;
  relationships.add_parent_and_child(parent, child1);
  relationships.add_parent_and_child(parent, child2);

  Research _(relationships);
  return 0;
}
