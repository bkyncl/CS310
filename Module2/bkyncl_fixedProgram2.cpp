/*
* Student Name: Brittany Kyncl
* File Name: bkyncl_fixedProgram2.cpp
* Date: 3.19.24
* Description: 
*   This is a solution to the buggy program (bkyncl_buggyProgram2.cpp) with errors fixed.
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
    char choice;
    // FIX: Change the data type of 'choice' variable to char
    // WHY: 'choice' variable is used to store a character representing the user's choice ('Y' or 'N')
    // Using int data type leads to loop condition never being met.

    // Program welcome message
    cout << "\n\n  Welcome to the buggy program!" << endl;

    // Do while loop to re-start based on user input choice
    do {
        // Declare variables for user input
        double x, y, z;
        // Declare variable for output
        double sum, average, maximum;
        // FIX: Changed variable to maximum instead of max
        // WHY: Avoid using the variable name "max" as it conflicts with the max() function from the <algorithm> header.
        // Instead, choose a different name such as "maximum" to prevent naming conflicts.

        // Prompt for user input of 3 double numbers
        cout << "\n  Please enter three numbers for calculation: ";
        // Input validation loop to handle non-numerical input and prompt for re-entry
        while (!(cin >> x >> y >> z) || cin.peek() != '\n') {
            // FIX: Use the extraction operator (>>) for each variable instead of the comma operator (,)
            // WHY: The comma operator (,) results in only 'x' being assigned.
            // Without the correct extraction operator y and z are not being assigned any value from the input stream.
            cout << "\n  Invalid input. Please enter three numbers separated by spaces: ";
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
            // FIX: Missing cin.ignore() call causing infinite loop on invalid input
            // WHY:  Without cin.ignore(), invalid input remains in the input stream, causing an infinite loop.
            // The cin.ignore() call discards any remaining characters in the input buffer.
        }

        // Calculate sum of all user input
        sum = x + y + z;
        // Calculate average of all user input
        average = sum / 3;
        // Calculate max of all user input
        maximum = max({x,y,z});
    
        // Output the result of sum, average, and max of user input
        cout << fixed << setprecision(2); // Set decimal precision to 2 places for output
        cout << "\n  You entered: " << x << ", " << y << ", " << z << endl;
        cout << "\n  The resulting sum is: " << sum << "!" << endl;
        cout << "\n  The resulting average is: " << average << "!" << endl;
        cout << "\n  The resulting max is: " << maximum << "!" << endl;

        // Prompt user for program continue input choice
        cout << "\n  Do you want to continue? (Y/N): ";
        cin >> choice;

    } while (choice == 'Y' || choice == 'y'); // Continue loop if case insensitive y else exit
    // FIX: Use double equals sign (==) for comparison instead of assignment operator (=)
    // WHY: The assignment operator (=) assigns the value 'Y' to choice instead of comparing,
    // Using the comparison operator (==) checks if 'choice' is equal to 'Y' or 'y'.

    // Prompt user to press any key to continue program exit
    cout << "\n\n  Exiting program. Press any key to continue..." << endl;
    _getch(); // Halt execution until key entry

    return 0;

}