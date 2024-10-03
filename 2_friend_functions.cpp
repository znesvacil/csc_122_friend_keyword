#include <iostream>

using namespace std;

class Rectangle
{
private:
    int width;
    int height;

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
        return this->width * this->height;
    }
    
    friend Rectangle scale(Rectangle, int);
    friend Rectangle swap(Rectangle);
};

Rectangle scale(Rectangle rectangle, int factor)
{
    int new_width = rectangle.width * factor;
    int new_height = rectangle.height * factor;
    return Rectangle(new_width, new_height);
}

Rectangle swap(Rectangle rectangle)
{
    int new_width = rectangle.height;
    int new_height = rectangle.width;
    return Rectangle(new_width, new_height);
}

int main()
{
    Rectangle r1(2, 3);
    cout << "Area of Rectangle 1: " << r1.area() << endl;

    Rectangle r2 = scale(r1, 2);
    cout << "Area of Rectangle 2: " << r2.area() << endl;
    cout << "Height of Rectangle 2: " << r2.get_height() << endl;
      
    Rectangle r3 = swap(r2);
    cout << "Height of Rectangle 3: " << r3.get_height() << endl;
    return 0;
}

