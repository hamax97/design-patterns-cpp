#include <iostream>
#define _USE_MATH_DEFINE
#include <cmath>

using namespace std;

enum class PointType {
  cartesian, polar
};

// The point can be a cartesian point or a polar point.
class Point {
private:

  float x, y;
  Point(float x, float y) : x(x), y(y) {}

public:
  friend ostream& operator<<(ostream& out, const Point& p) {
    out << p.x << " " << p.y;
    return out;
  }

private:
  // In case of wanting dedicated code for the factory.
  struct PointFactory {
    static Point NewCartesian(float x, float y) {
      return {x, y};
    }

    static Point NewPolar(float rho, float theta) {
      return {rho * cos(theta), rho * sin(theta)};
    }
  };

public:
  // Singleton.
  static PointFactory Factory;
};

int main() {
  // This is one way, by having the factory inside the main class.
  //auto p = Point::PointFactory::NewPolar(5, M_PI_4);
  //cout << p << endl;

  // Another way, if looking for something more encapsulated is
  // to have a singleton in the class.
  auto p2 = Point::Factory.NewPolar(5, M_PI_4);
  cout << p2 << endl;
}