/*
* Student Name: Brittany Kyncl
* File Name: bkyncl_M8_DB_Exercise.cpp
* Date: 5.2.24
* Description: 
*   This program contains 2 errors for the purposes of debugging practice.
*   This program simulates a car garage by defining a class for cars and garages.
* Output:
*   - Car and garage information displayed
*/

#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

// Class for representing a Car
class Car {
// Member variables of the Car class
private:
    string m_make;
    string m_model;
    int m_year;
public:
    // Constructor for Car with parameter values using member initializer list
    Car(string mk, string md, int yr) 
        :  m_year(yr), m_model(md), m_make(mk) {}

    // Method to display car information
    void display() {
        cout << "Make: " << m_make << endl;
        cout << "Model: " << m_model << endl;
        cout << "Year: " << m_year << endl;
    }
};

// Class for representing a Garage
class Garage {
// Member variable of the Garage class
private:
    Car m_car1;
    Car m_car2;
public:
     // Constructor for garage with passed objects using member initializer list
    Garage(Car c1, Car c2) 
        : m_car1(c1), m_car2(c2) {}

    // Method to display garage contents
    void display() {
        cout << "Garage Contents:" << endl;
        cout << "Car 1:" << endl;
        garage.display();
        cout << "\nCar 2:" << endl;
        garage.display();
    }
};

int main() {
    // Creating objects of Car class
    Car car1("Toyota", "Camry", 2015);
    Car car2("Honda", "Civic", 2018);

    // Creating object of Garage class holding two car objects
    Garage garage(car1, car2);

    // Displaying garage contents
    garage.display();

    cout << "\nExiting program. Press any key to continue..." << endl;
    _getch(); // Halt execution until key entry

    return 0;
}