#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <fstream>
#include "boost/lexical_cast.hpp"

using namespace boost;

struct Journal {
  std::string title;
  std::vector<std::string> entries;

  Jorunal(const std::string& title) : title(title) {}

  void add_entry(const std::string& entry) {
    static int count = 1;
    entries.push_back(lexical_cast<std::string>(count++) + ": " + entry);
  }

  void save(const std::string& filename) {
    std::ofstream ofs(filename);
    for (auto& e : entries)
      ofs << e << endl;
  }
};

int main() {

  Journal jorunal{"Dear diary"};
  journal.add_entry("I ate a bug");
  journal.add_entry("I cried today");
  gecthar();
  return 0;
}
