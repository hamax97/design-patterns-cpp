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
  Point(float x, float y) : x(x), y(y) {}
public:
  float x, y;

  // Factory method.
  static Point NewCartesian(float x, float y) {
    return {x, y};
  }

  // Factory method.
  static Point NewPolar(float rho, float theta) {
    return {rho * cos(theta), rho * sin(theta)};
  }

  friend ostream& operator<<(ostream& out, const Point& p) {
    out << p.x << " " << p.y;
    return out;
  }
};

int main() {
  // IMPOSIBLE.
  // Point p {1, 2};

  auto p = Point::NewPolar(5, M_PI_4);

  cout << p << endl;
}