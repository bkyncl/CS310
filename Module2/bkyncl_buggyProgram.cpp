/*
* Student Name: Brittany Kyncl
* File Name: bkyncl_buggyProgram.cpp
* Date: 3.19.24
* Description: 
*   This is a simple program with intentional common errors.
*   The purpose of this program is to demonstrate common errors
*   that can prevent a program from executing successfully and
*   to provide practice with analyzing code, identifying and debugging errors.
*   (Hint: there are 3 bugs in total to find)
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
using namespace std;

int main() {

    // Program welcome message
    cout << "\n\n  Welcome to the buggy program!" << endl;

    // Declare variables for user input
    double x, y, z;
    // Declare variable for output
    double sum, average, maximum;

    // Prompt for user input of 3 double numbers
    cout << "\n  Please enter three numbers for calculation: ";
    // Read user input for three numbers
    cin << x << y << z;
    
    // Calculate sum of all user input
    sum = x + y + z;
    // Calculate average of all user input
    average = sum / 3;
    // Calculate max of all user input
    maximum = max(x,y,z);

    // Output the result of sum, average, and max of user input
    cout << fixed << setprecision(2); // Set decimal precision to 2 places for output
    cout << "\n  You entered: " << x << ", " << y << ", " << z << endl;
    cout << "\n  The resulting sum is: " << sum << "!" << endl;
    cout << "\n  The resulting average is: " << average << "!" << endl;
    cout << "\n  The resulting max is: " << maximum << "!" << endl;

    // Prompt user to press any key to continue program exit
    cout << "\n\n  Exiting program. Press any key to continue..." << endl;
    _getch(); // Halt execution until key entry

    return 0;

}
