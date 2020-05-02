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

  // PROBLEM: If you coded Point without this factory, then you have to add
  // this friend class, violating Open Closed Principle, you modified an
  // already created object.
  // Another option is to have from principle the constructor public, but now
  // the user has two ways of creating a Point.
  friend class PointFactory;

  // PROBLEM: If a user comes and see this class with private constructor, and
  // there is no other hint of how to construct the object, it will be anoying
  // and confusing.
  // See 4_inner_factory.cpp ...

  Point(float x, float y) : x(x), y(y) {}
public:
  float x, y;

  friend ostream& operator<<(ostream& out, const Point& p) {
    out << p.x << " " << p.y;
    return out;
  }
};

// In case of wanting dedicated code for the factory.
struct PointFactory {
  // Factory method.
  static Point NewCartesian(float x, float y) {
    return {x, y};
  }

  // Factory method.
  static Point NewPolar(float rho, float theta) {
    return {rho * cos(theta), rho * sin(theta)};
  }
};

int main() {

  auto p = PointFactory::NewPolar(5, M_PI_4);

  cout << p << endl;
}