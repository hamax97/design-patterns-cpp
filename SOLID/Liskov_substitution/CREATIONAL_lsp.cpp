#include <iostream>

using namespace std;

class Rectangle {
protected:
  int width, height;

public:
  Rectangle(int width, int height) :
    width(width),
    height(height)
  {}

  virtual void setWitdh(int width) { this->width = width; }
  virtual void setHeight(int height) { this->height = height; }

  int getWidth() const { return this->width; }
  int getHeight() const { return this->height; }

  int area() const { return width * height; }
};

class Square : public Rectangle {
public:
  Square(int size) :
    Rectangle(size, size)
  {}

  void setWitdh(int width) override {
    this->width = this->height = width;
  }
  void setHeight(int height) override {
    this->height = this->width = height;
  }
};

void process(Rectangle& r) {
  // NOTE: When you use the Square class here, there is a problem.
  // You get the square width (which is the same as the height), let's
  // say 'w' is now equals to 5.
  // Then you set the heigth (which is the same as the width) to 10.
  // Then you multiply your supposed width (that is, 5) with the new height.
  // The expected value is 100, but what the program says is
  // that it should be 50, which is wrong. You are multiplying the old value
  // of the width with the new value of the height, and they are supposed to
  // be the same.
  int w = r.getWidth();
  r.setHeight(10);

  cout << "expected area = " << (w * 10)
       << ", got " << r.area() << endl;

  // So, what to do?.
  // It is not a good idea for Square to inherit from Rectangle, even though
  // a Square is a rectangle strictly speaking.
  // ** One idea, is to have a boolean flag that says if the Rectangle is a
  // Square or not, so the behaviour of the setters change.
  // ** Another idea, is to have a RectangleFactory that creates rectangles
  // and squares.
  // Also, one of the main problems is that the 'process' function is designed
  // so that when another kind of Rectangle is passed, it might break the
  // program expected behavior.
}

int main() {
  Rectangle r{3, 4};
  process(r);

  Square sq{5};
  process(sq);

  return 0;
}
