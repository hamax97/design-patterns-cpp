#include <iostream>
#include <cmath>

using namespace std;

enum class PointType {
  cartesian, polar
};

// The point can be a cartesian point or a polar point.
struct Point {

  // Constructor for cartesian coordinate.
  //Point(float x, float y) : x(x), y(y) {}

  // Constructor for polar coordinate.
  // PROBLEM: There cannot be two constructor with same signatures.
  // PROBLEM: The name of the constructor must match the name of the class,
  // but, what if we'd like to name the construction PolarPoint for example.
  // Point(float rho, float theta) {}

  // To solve that problem, one would normally create an enum and ...
  Point(float a, float b, PointType type = PointType::cartesian) {
    if (type == PointType::cartesian) {
      x = a;
      y = b;
    } else {
      x = a * cos(b);
      y = a * sin(b);
    }
  }
  // Note that in this approach a, b are used instead of x y, because we
  // don't know what type of point is. Also, in case of a polar point,
  // is a equal to rho or to theta ??.

  float x, y;
};

int main() {

}