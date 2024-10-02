#include <iostream>

using namespace std;

class GeometricScaler;

class Rectangle
{
  int width, height;

public:
  Rectangle(int w, int h) : width(w), height(h) {}

  int area()
  {
    return (width * height);
  }
  void scale(GeometricScaler scalar);
};

class GeometricScaler
{
private:
  friend class Rectangle;
  int factor;

public:
  GeometricScaler(int factor)
  {
    this->factor = factor;
  }
};

void Rectangle::scale(GeometricScaler scalar)
{
  this->width = this->width * scalar.factor;
  this->height = this->height * scalar.factor;
}

int main()
{
  Rectangle rectangle(1, 2);
  cout << "Area of the Rectangle: " << rectangle.area() << endl;

  GeometricScaler scaler(5);
  rectangle.scale(scaler);

  cout << "Area of the Rectangle: " << rectangle.area() << endl;

  return 0;
}
