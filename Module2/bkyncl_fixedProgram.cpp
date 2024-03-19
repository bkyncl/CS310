/*
* Student Name: Brittany Kyncl
* File Name: bkyncl_fixedProgram.cpp
* Date: 3.18.24
* Description: 
*   This is a solution to the buggy program (bkyncl_buggyProgram.cpp) with 3 errors fixed.
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
#include <algorithm> // FIX: Add missing header <algorithm> for using the max() function
                     // WHY: The max() function is defined in the <algorithm> header in C++.
                     // Including this header ensures that the max() function is properly declared and available for use.
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
    cin >> x >> y >> z; // FIX: Using the output stream operator(<<) instead of input stream operator(>>)
                        // WHY: the cin operator (>>) is used to extract data from input stream into variables and (<<) is used for output.
                        // Incorrect usage will result in unusual behavior or compilation error.
    
    // Calculate sum of all user input
    sum = x + y + z;
    // Calculate average of all user input
    average = sum / 3;
    // Calculate max of all user input
    maximum = max(x,y,z); // FIX: curly braces missing here, causing compilation error
                          // WHY: the max() function requires an initializer list or curly braces around the numbers when comparing 3 or more.
                          // The braces are not required for comparing only two numbers but here we have 3

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