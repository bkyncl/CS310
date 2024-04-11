// Discussionboardweek5.cpp : This file contains the 'main' function. Program execution begins and ends there.
// NOTE: Bugs fixed by Brittany Kyncl 4.10.24

#include <iostream>
using namespace std;

// Function to calculate square of a number
int square(int n) {
    return n * n; // FIX: Added function definition to correctly define instructions to return square of n
}

int main() {
    int number, result;

    cout << "Enter a number: ";
    cin >> number;

    result = square(number); // FIX: Changed to correclty call user defined square() instead of unkown sqr() function

    cout << "The square of " << number << " is " << result << endl;

    return 0;
}