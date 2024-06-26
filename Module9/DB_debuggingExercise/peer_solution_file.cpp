//Cristian Taylor
//5/10/2024
//Shapes Parent class + two subclasses

// Bugs fixed 5.10.24 by brittany kyncl

#include <iostream>

using namespace std; // FIX: Added missing namespace std for cout and endl

// Base class
class Shape {
protected:
    double width;
    double height;

public:
    Shape(double w, double h) : width(w), height(h) {}

    virtual double area() = 0; // Pure virtual function
};

// Derived class 1
class Rectangle : public Shape {
public:
    Rectangle(double w, double h) : Shape(w, h) {}

    double area() {
        return width * height;
    }
};

// Derived class 2
class Triangle : public Shape {
public:
    Triangle(double w, double h) : Shape(w, h) {}

    double area() {
        return 0.5 * width * height; // FIX: Added missing semicolon after return statement
    }
};

int main() {
    Rectangle rect(5, 4);
    Triangle tri(5, 4);

    cout << "Area of Rectangle: " << rect.area() << endl;
    cout << "Area of Triangle: " << tri.area() << endl;

    return 0;
}