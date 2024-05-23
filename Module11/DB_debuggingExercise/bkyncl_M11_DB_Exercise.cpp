/**
 * Student Name: Brittany Kyncl
 * File Name: bkyncl_M11_DB_Exercise.cpp
 * Date: 5.22.24
 * Description:
 *  This file contains 3 bugs to find for the purpose of debugging practice.
 *  This program demonstrates the use of templates, to work with varying data types.
 *  PrintResults is a function template that displays a message and values in a structured format,
 *  while Swap is a function template used for swapping values of the same type.
 *  In main, these template functions are applied to different data types, including integers, doubles, characters, and strings.
 * */

#include <iostream>
#include <conio.h>
#include <string>
using namespace std;

// Function template named PrintResults to print a message and values in specified format
// The template takes two template parameters, T and U, representing the types of the values and the message
template<typename T, typename U>
void PrintResults(U& message, U& val1, U& val2) {
    cout << message << " swap: " << val1 << " " << val2 << endl;
}

// Define a function template to swap two values of type template parameter T
template<typename T>
void Swap(T& a, T& b) {
    int temp = a;
    a = b;
    b = temp;
}
int main() {

    // Declare variables of different types and initialize them with values
    int a = 5, b = 10;
    double c = 2.56, d = 15.23;
    char e = '&', f = '$';
    string g = "Hello", h = "Goodbye";
    string bef = "Before", aft = "After"; // Strings for before and after messaging
    char bef2 = '<', aft2 = '>'; // Characters for before and after symbols

    PrintResults(bef, a, b); // Print a message and values before swapping integers
    Swap<int>(a, b);         // Call the Swap function to swap the integers
    PrintResults(aft, a, b); // Print a message and swapped values after swapping integers

    PrintResults(bef2, c, d); // Print a message and values before swapping doubles (passing char type for message instead of string)
    Swap<double>(c, d);       // Call the Swap function to swap the doubles
    PrintResults(aft2, c, d); // Print a message and swapped values after swapping doubles (passing char type for message instead of string)

    PrintResults(bef, e, f); // Print a message and values before swapping characters
    Swap<float>(e, f);        // Call the Swap function to swap the character
    PrintResults(aft, e, f); // Print a message and swapped values after swapping characters

    PrintResults(bef, g, h); // Print a message and values before swapping strings
    Swap<string>(g, h);      // Call the Swap function to swap the strings
    PrintResults(aft, g, h); // Print a message and swapped values after swapping strings

    cout << "\nExiting program. Press any key to continue..." << endl;
    _getch(); // Halt execution until key entry

    return 0;
}