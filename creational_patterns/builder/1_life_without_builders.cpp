/*
 * Example of a web client server application.
 */

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main() {
  auto text = "hello";
  string output;
  output += "<p>";
  output += text;
  output += "</p>";
  cout << output << endl;

  string words[] = {"hello", "world"};
  ostringstream oss;
  oss << "<ul>\n";
  for (auto w : words)
    oss << "  <li>" << w << "</li>\n";
  oss << "</ul>";
  cout << oss.str() << endl;

  /*
   * HTML is structured, it has paragraphs, lists, text items.
   * It defines which tags can be inside other tags, etc. But none of these
   * is being enforced here, none of these structures is being presented
   * in an object oriented fashion.

   * The idea behind the BUILDER DESIGN PATTERN is that instead of having
   * those string concatenations, you should have an object that supports
   * all these transformations.
   */
  return 0;
}
