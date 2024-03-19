/*
* Student Name: Brittany Kyncl
* File Name: bkyncl_buggyProgram2.cpp
* Date: 3.18.24
* Description: 
*   This is a simple program with intentional common errors.
*   The purpose of this program is to demonstrate common errors
*   that can prevent a program from executing successfully and
*   to provide practice with analyzing code, identifying and debugging errors.
*   (Hint: there are 5 bugs in total to find)
* Input:
*   - 3 double numbers for caclucations
* Output:
*   - the sum of the 3 numbers
*   - The average of the 3 numbers
*   - The maximum of the 3 numbers
*/

#include <iostream>
#include <conio.h>
#include <iomanip>
#include <limits>
#include <algorithm>
using namespace std;

int main() {

    // Declare choice variable for do while loop
    int choice;

    // Program welcome message
    cout << "\n\n  Welcome to the buggy program!" << endl;

    // Do while loop to re-start based on user input choice
    do {
        // Declare variables for user input
        double x, y, z;
        // Declare variable for output
        double sum, average, max;

        // Prompt for user input of 3 double numbers
        cout << "\n  Please enter three numbers for calculation: ";
        // Input validation loop to handle non-numerical input and prompt for re-entry
        while (!(cin >> x, y, z) || cin.peek() != '\n') {
            cout << "\n  Invalid input. Please enter three numbers separated by spaces: ";
            cin.clear(); // Clear error flag
        }

        // Calculate sum of all user input
        sum = x + y + z;
        // Calculate average of all user input
        average = sum / 3;
        // Calculate max of all user input
        max = max({x,y,z});
    
        // Output the result of sum, average, and max of user input
        cout << fixed << setprecision(2); // Set decimal precision to 2 places for output
        cout << "\n  You entered: " << x << ", " << y << ", " << z << endl;
        cout << "\n  The resulting sum is: " << sum << "!" << endl;
        cout << "\n  The resulting average is: " << average << "!" << endl;
        cout << "\n  The resulting max is: " << max << "!" << endl;

        // Prompt user for program continue input choice
        cout << "\n  Do you want to continue? (Y/N): ";
        cin >> choice;

    } while (choice = 'Y' || choice = 'y'); // Continue loop if case insensitive y else exit

    // Prompt user to press any key to continue program exit
    cout << "\n\n  Exiting program. Press any key to continue..." << endl;
    _getch(); // Halt execution until key entry

    return 0;

}