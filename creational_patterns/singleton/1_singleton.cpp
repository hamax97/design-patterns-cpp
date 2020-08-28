#include <iostream>
#include <fstream>
#include <map>
#include <boost/lexical_cast.hpp>

using namespace std;
using namespace boost;

// The idea is to have a single object that manages the access to the database,
// database.txt.
class SingletonDatabase {
  SingletonDatabase() {
    cout << "Initializing database\n";

    ifstream ifs("database.txt", ios::in);

    string s, s2;
    while (getline(ifs, s)) {
      getline(ifs, s2);

      capitals[s] = lexical_cast<int>(s2);
    }
  }
  map<string, int> capitals;

public:
  // Make the API safe.
  SingletonDatabase(const SingletonDatabase &) = delete;
  void operator=(const SingletonDatabase &) = delete;

  // Expose the single instance.
  static SingletonDatabase &get() {
    static SingletonDatabase db;
    return db;
  }

  int getPopulation(string &city) {
    return capitals[city];
  }
};

int main() {
  auto &DB = SingletonDatabase::get();

  string city = "Tokyo";
  cout << city << " has population " << DB.getPopulation(city) << "\n";
  return 0;
}