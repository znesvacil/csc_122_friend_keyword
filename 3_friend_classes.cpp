#include <iostream>

using namespace std;

class GeometricScaler;
class GeometricSwapper;

class Rectangle
{
private:
    
    int width, height;

public:
    Rectangle(int w, int h) : width(w), height(h) {}

    int get_width()
    {
        return this->width;
    }
    
    int get_height()
    {
        return this->height;
    }
    
    int area()
    {
        return (width * height);
    }
    void scale(GeometricScaler scalar);
    
    void swap(GeometricSwapper swapper);
        
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

class GeometricSwapper
{
private:
    friend class Rectangle;
    int factor;
    
public:
    GeometricSwapper(int factor)
    {
      this->factor = factor;
    }
};

void Rectangle::swap(GeometricSwapper swapper)
{
    int new_width;
    int new_height;
    
    for(int i = 0; i < swapper.factor; i++)
    {
        new_width = this->height;
        new_height = this->width;
        
        this->height = new_height;
        this->width = new_width;
    }
}

int main()
{
    Rectangle rectangle(1, 2);
    cout << "Area of the Rectangle: " << rectangle.area() << endl;

    GeometricScaler scaler(5);
    rectangle.scale(scaler);

    cout << "Area of the Rectangle: " << rectangle.area() << endl;
    cout << "Height of Rectangle: " << rectangle.get_height() << endl;
    
    GeometricSwapper swapper(5); //number of times it swaps. I did this to justify there being a class, since the function worked just fine without it
    rectangle.swap(swapper);
    
    cout << "Height of Rectangle after swap: " << rectangle.get_height() << endl;

    
    return 0;
}

