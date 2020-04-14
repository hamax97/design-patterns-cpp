/*
 * Example of a web client server application.
 */

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <memory>

using namespace std;

class HtmlBuilder;

class HtmlElement {

  // The constructors are private to enforce the client of this class
  // to use the APIs provided:
  // build(), build2()
  // Or using directly the builder.
private:
  friend class HtmlBuilder;
  string name, text;
  vector<HtmlElement> elements;

  size_t indent_size = 2;

  HtmlElement() = default;
  HtmlElement(const string& name, const string& text) :
    name(name), text(text) {}

public:
  // Prints HtmlElement and its nested elements, not really important here.
  string str(int indent = 0) const {
    ostringstream oss;
    string i(indent_size * indent, ' ');
    oss << i << "<" << name << ">" << endl;
    if (text.size() > 0)
      oss << string(indent_size * (indent + 1), ' ') << text << endl;

    for (const auto& e: elements)
      oss << e.str(indent + 1);

    oss << i << "</" << name << ">" << endl;
    return oss.str();
  }

  static HtmlBuilder create(string root_name);

  static unique_ptr<HtmlBuilder> build2(string root_name);
};

// The interesting question is: How to build HtmlElements ??.
// Allows the management of a the root html and the adding of children
// in a simple and fancy way ...
class HtmlBuilder {
private:
  HtmlElement root;

public:
  HtmlBuilder(string root_name) {
    root.name = root_name;
  }

  HtmlBuilder& add_child(string child_name, string child_text) {
    HtmlElement e {child_name, child_text};
    root.elements.emplace_back(e);
    return *this;
  }

  // If you wnat to use '->' with pointers operator instead of '.' with
  // references ...
  HtmlBuilder* add_child_2(string child_name, string child_text) {
    HtmlElement e {child_name, child_text};
    root.elements.emplace_back(e);
    return this;
  }

  string str() const { return root.str(); }

  HtmlElement build() { return root; }

  // User defined conversion.
  // When this object (HtmlBuilder) is attempted to be converted to HtmlElement
  // come here, I know what to do.
  operator HtmlElement() const {
    // If you know that this is the last operation always, the root can be
    // moved:
    // return std::move(root);
    return root;
  }
};
// ... something else to consider is having an interface of Builders
// and implement a different builder for different type of complicated objects.

// These are defined here to avoid incomplete type error ...
// error: incomplete result type 'HtmlBuilder' in function definition
HtmlBuilder HtmlElement::create(string root_name) {
  return {root_name}; // Type is inferred from the return type.
}

unique_ptr<HtmlBuilder> HtmlElement::build2(string root_name) {
  return make_unique<HtmlBuilder>(root_name);
}

int main() {
  // Here, instead of working directly with the HtmlElement, a dedicated
  // object is used, a builder.
  // The builder has a fluent interface to add objects in an easier way.
  // ...
  HtmlBuilder builder{"ul"};
  builder.add_child("li", "fluent").add_child("li", "builder 1");
  cout << builder.str() << endl;

  // ... there is another approach, which might be more readable.
  // A builder is returned from the element that we want to construct ...
  auto builder2 =
    HtmlElement::create("ul").add_child("li", "fluent")
      .add_child("li", "builder 2");
  cout << builder2.str() << endl;

  // Also, you can add a user defined conversion operator to the builder
  // in order to return the HtmlElement it's building, hence, having an
  // HtmlElement at the end instead of the builder. like this:
  HtmlElement elem = HtmlElement::create("ul")
    .add_child("li", "fluent")
    .add_child("li", "builder 3");
  cout << elem.str() << endl;

  // Another slight change to the latter form, is to add a build() function
  // to the builder, that will be called at the end when the object is done.
  // This is better, it avoids the user defined conversion operator, and is
  // more readable.
  // You should tell the clients of this interface to use it like this.
  HtmlElement elem2 = HtmlElement::create("ul")
    .add_child("li", "fluent")
    .add_child("li", "builder 4").build();
  cout << elem2.str() << endl;

  return 0;
}
