/*
* Student Name: Brittany Kyncl
* File Name: bkyncl_M9_DB_Exercise.cpp
* Date: 5.8.24
* Description: 
*   This program contains 3 errors for the purposes of debugging practice.
*   This program implements a base class Shape and its derived classes Rectanble and Circle
*   It calculates and displays information about shapes, including their name, color, dimensions, area, and perimeter.
*/


#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

// Base class Shape
class Shape {
protected:
    string m_name; 
    string m_color; 
public:
    // Constructor to initialize the name and color of the shape
    Shape(string n, string c) : m_name(n), m_color(c) {}

    // Virtual function to display information about the shape
    void display() const{
        cout << m_color << " " << m_name << endl;
    }

    virtual double area() const = 0; // Pure virtual function to calcuate shape area
    virtual double perimeter() const = 0; // Pure virtual function to cacluate shape perimeter
};
// Child class Rectangle derived from Shape class
class Rectangle : public Shape {
private:
    double m_width;
    double m_height;
public:
    // Constructor to initialize the name, color, width, and height of the rectangle
    Rectangle(string n, string c, double w, double h) : m_name(n), m_color(c), m_width(w), m_height(h) {}

    // Override the display function to show the color, name, width, and height of the rectangle
    void display() const override  {
        Shape::display(); // Call the display() function of the base class
        cout << "Width: " << m_width << " Height: " << m_height << endl;
    }
    // Override the area function to calculate the area of the rectangle
    double area() const override {
        return m_width * m_height;
    }
    // Override the perimeter function to calculate the perimeter of the rectangle
    double perimeter() const override {
        return 2 * (m_width + m_height);
    }
};

// Child class Circle derived from Shape class
class Circle : public Shape {
private:
    double m_radius;
public:
    // Constructor to initialize the name, color, and radius of the circle
    Circle (string n, string c, double r) : Shape(n,c), m_radius(r) {}

    // Override display function to show color, name, and radius of the circle
    void display() const override {
        Shape::display(); // Call the display() function of the base class
        cout << "Radius: "<< m_radius << endl;
    }
    // Override the area function to calculate the area of the circle
    double area() const override {
        return 3.14 * m_radius * m_radius;
    }
    // Override the perimeter function to calculate the perimeter of the circle
    double getPerimeter() const  {
        return 2 * 3.14 * m_radius;
    }
};

int main() {
    // Creating objects of child classes
    Rectangle rect("Rectangle", "Blue",10, 5);
    Circle circle("Circle","Green",5);

    // Display information about the rectangle
    cout << "Shape #1: " << endl;
    rect.display(); // Output: This is Blue a Rectangle. 
                    //         Width: 10 Height: 5
    cout << "Area: " << rect.area() << endl;
    cout << "Perimeter: " << rect.perimeter() << endl;

    // Display information about the circle
    cout << "\nShape #2: " << endl;
    circle.display(); // Output: This is Green a Circle.
                      //          Radius: 5
    cout << "Area: " <<  circle.area() << endl;
    cout << "Perimeter: " << circle.perimeter() << endl;

    cout << "\nExiting program. Press any key to continue..." << endl;
    _getch(); // Halt execution until key entry

    return 0;
}