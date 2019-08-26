/*
 * Abstraction of a website that sells products classified by their
 * color and size.
*/

#include <iostream>
#include <vector>

using namespace std;

enum class Color { red, green, blue };
enum class Size { small, medium, large };

struct Product {
  string name;
  Color color;
  Size size;
};

struct ProductFilter {
  vector<Product*> by_color(vector<Product*> items, Color color) {
    vector<Product*> result;
    for (auto& i : items)
      if (i->color == color)
        result.push_back(i);
    return result;
  }

  // Now, if your boss asks you to filter by size. You copy and paste the
  // function above and change color by size.
  vector<Product*> by_size(vector<Product*> items, Size size) {
    vector<Product*> result;
    for (auto& i : items)
      if (i->size == size)
        result.push_back(i);
    return result;
  }

  // Now, your boss asks you to filter by size and color.
  vector<Product*> by_size_and_clor(vector<Product*> items,
                                    Size size, Color color) {
    vector<Product*> result;
    for (auto& i : items)
      if (i->size == size && i->color == color)
        result.push_back(i);
    return result;
  }
  // Creating all this functions is a bad idea. It DOES NOT SCALE, and you
  // would have as many functions as filtering criteria.
  // In this way, what you are doing is modifying your code, not extending it,
  // you are not inheriting.
  // Normally if your boss asks you to filter the products by color
  // you would do this.
  // ----------------------------------------------------------------------
  // A pattern called THE SPECIFICATION PATTERN can be used to overcome this
  // situation. This patter is related to working with data.
};

// The Specification interface.
template <typename T> struct Specification {
  // Checks wheter an item satisfies an specification.
  // Defined through inheritance.
  virtual bool is_satisfied(T *item) = 0;

  // Breaks the compilation due that the function does not exist.
  // AndSpecification<T> operator&&(Specification<T>&& other) {
  //   return AndSpecification<T>(this, other);
  // }
};

// This interface should be implemented by every type of filter.
template <typename T> struct Filter {
  virtual vector<T*> filter(vector<T *> items, Specification<T> &spec) = 0;
};

struct BetterFilter : Filter<Product> {
  vector<Product *> filter(vector<Product *> items,
                           Specification<Product> &spec) override {
    vector<Product *> result;
    for (auto& item : items)
      if (spec.is_satisfied(item))
        result.push_back(item);
    return result;
  }
};

struct ColorSpecification : Specification<Product> {
  Color color;

  explicit ColorSpecification(Color color) : color(color) {}

  bool is_satisfied(Product *item) override {
    return item->color == color;
  }
};

struct SizeSpecification : Specification<Product> {
  Size size;

  explicit SizeSpecification(Size size) : size(size) {}

  bool is_satisfied(Product *item) override {
    return item->size == size;
  }
};

// What about combined filters?.
// Well ...
template <typename T> struct AndSpecification : Specification<T> {
  Specification<T> &left;
  Specification<T> &right;

  AndSpecification(Specification<T> &left, Specification<T> &right) :
    left(left), right(right) {}

  bool is_satisfied(T *item) override {
    return left.is_satisfied(item) && right.is_satisfied(item);
  }
};

int main() {
  Product apple{ "Apple", Color::green, Size::small };
  Product tree{ "Tree", Color::green, Size::large };
  Product house{ "House", Color::blue, Size::large };

  vector<Product *> items { &apple, &tree, &house };

  // So instead of this ...
  // ProductFilter pf;
  // auto green_things = pf.by_color(items, Color::green);

  // for (auto& item : green_things)
  //   cout << item->name << " is green\n";

  // This ...
  BetterFilter bf;
  ColorSpecification green(Color::green);
  for (auto& item : bf.filter(items, green))
    cout << item->name << " is green\n";

  SizeSpecification large(Size::large);
  for (auto& item : bf.filter(items, large))
    cout << item->name << " is large\n";

  AndSpecification<Product> green_and_large(green, large);
  for (auto& item : bf.filter(items, green_and_large))
    cout << item->name << " is green and large\n";

  // This is now better, but we are creating too many variables:
  // green, large, green_and_large. To avoid this you can overload
  // the && operator in the Specification template ...
  // auto spec = ColorSpecification(Color::green)
  //   && SizeSpecification(Size::large);
  // for (auto& item : bf.filter(items, spec))
  //   cout << item->name << " is green and large\n";

  return 0;
}
