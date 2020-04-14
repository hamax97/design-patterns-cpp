/*
 * Example of a web client server application.
 */

#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

struct HtmlElement {
  string name, text;
  vector<HtmlElement> elements;

  size_t indent_size = 2;

  HtmlElement() = default;
  HtmlElement(const string& name, const string& text) :
    name(name), text(text) {}

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
};

// The interesting question is: How to build HtmlElements ??.
// Allows the management of a the root html and the adding of children
// in a simple and fancy way ...
struct HtmlBuilder {
  HtmlElement root;

  HtmlBuilder(string root_name) {
    root.name = root_name;
  }

  void add_child(string child_name, string child_text) {
    HtmlElement e {child_name, child_text};
    root.elements.emplace_back(e);
  }

  string str() const { return root.str(); }
};
// ... something else to consider is having an interface of Builders
// and implement a different builder for different type of complicated objects.

int main() {
  auto text = "hello";
  string output;
  output += "<p>";
  output += text;
  output += "</p>";
  cout << output << endl;

  // This approach might be better than the used above.
  string words[] = {"hello", "world"};
  ostringstream oss;
  oss << "<ul>\n";
  for (auto w : words)
    oss << "  <li>" << w << "</li>\n";
  oss << "</ul>";
  cout << oss.str() << endl;

  // Here, instead of working directly with the HtmlElement, a dedicated
  // object is used, a builder.
  HtmlBuilder builder{"ul"};
  builder.add_child("li", "hello");
  builder.add_child("li", "world");
  cout << builder.str() << endl;

  // Note that we are adding two childs using the add_child consecutively.
  // There is a way of making it simpler and nicer for the user. For
  // example:
  // builder.add_child().add_child();
  // That is called a fluent interface, see 3_fluent_builder.cpp

  return 0;
}
