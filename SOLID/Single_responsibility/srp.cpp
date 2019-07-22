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

  explicit Journal(const std::string& title) : title(title) {}

  void add_entry(const std::string& entry) {
    static int count = 1;
    entries.push_back(lexical_cast<std::string>(count++) + ": " + entry);
  }

  // Using this function of saving an entry to a file (persistence) is a bad
  // practice. If you use this functionality of PERSISTENCE in more classes,
  // and you change the way of how your persistence works, you will have to
  // change this function 'save' here and in every single class you are
  // using persistence.
  // The solution to this is to create another class that handles all your
  // persistence stuff.
  void save(const std::string& filename) {
    std::ofstream ofs(filename);
    for (auto& e : entries)
      ofs << e << std::endl;
  }
};

struct PersistenceManager {
  // Only here you can change your persistence function.
  static void save(const Journal& j, const std::string& filename) {
    std::ofstream ofs(filename);
    for (auto& e : j.entries)
      ofs << e << std::endl;
  }
};

int main() {

  Journal journal{"Dear diary"};
  journal.add_entry("I ate a bug");
  journal.add_entry("I cried today");

  // Bad practice
  // journal.save("diary.txt");

  // Good practice
  PersistenceManager pm;
  pm.save(journal, "diary.txt");

  return 0;
}
