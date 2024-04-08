/*
* Student Name: Brittany Kyncl
* File Name: bkyncl_M4_DB_Exercise_Solution.cpp
* Date: 4.4.24
* Description: 
*   This is a solution to the buggy program (bkyncl_M4_DB_Exercise.cpp) with errors fixed.
*   This program takes in two integers, the number of terms to print in Fibonacci series 
*   and the highest value to print in a Fibonacci series. Utilizing reptition control 
*   statements with a do-while to prompt the user until valid input is given
*   then a for loop and a while loop to generate and print the Fibonacci series.
* Input:
*   - Number of terms to print in the first series.
*   - Highest value in the second series.
* Output:
*   - The Fibonacci series up to the specified number of terms.
*   - The Fibonacci series up to the specified highest value.
*/

#include <iostream>
#include <conio.h>
#include <limits>
#include <iomanip>
using namespace std;

int main() {

    // Declare variables for sequence and user input
    int termLimit, valueLimit;
    double term1=0, term2=1, temp=0;

    // Program welcome message
    cout << "\n  The Fibonacci sequence is a series where the next term is the sum of the previous two terms..." << endl;

    // Prompt user to enter the number of terms to print in the sequence and the highest value in the second series
    do {
        cout << "\n  Enter the desired number of terms to print in the first series\n  and the highest value in the second series: ";
        cin >> termLimit >> valueLimit;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    } while (cin.fail() || termLimit <=0 || valueLimit <= 0); // Repeat while input is non-integer or <= 0
                                                              // FIX: added missing semicolon after do while condition
                                                              // WHY: Semicolon needed in do while as condition is after curly braces
    cout << fixed; // Set output to fixed-point notation
    cout << setprecision(0); // Set precision to 0 decimal places

    // Display the resulting series up to a specific number of terms
    cout << "\n  Fibbonacci Series up to " << termLimit << " terms: ";
    // For loop to iterate until i reaches our termLimit
    for (int i=0; i < termLimit; i++) { // FIX: Increment i in the loop condition
                                        // WHY: Decrementing i causes infinite loop as i will never reach termLimit
        cout << term1 << " "; // Output current term
        temp = term1 + term2; // Calculate next term held in temp
        term1 = term2; // Update term1 to hold term2 value
        term2 = temp; // term2 will now hold calculated next term value
    }
    cout << endl;

    // FIX: Re-set variables term1, term2, and temp to intial values for new sequence
    // WHY: We need to prevent carryover of state from first loop to generate Fibonacci correctly
    term1=0, term2=1, temp=0;

    // Display the resulting series up to a specific value
    cout << "\n  Fibbonacci Series up to value "  << valueLimit << ": ";
    // while loop to iterate until term1 reaches our valueLimit
    while (term1 <= valueLimit) {
        cout << term1 << " "; // Output current term
        temp = term1 + term2; // Calculate next term held in temp
        term1 = term2; // Update term1 to hold term2 value
        term2 = temp; // term2 will now hold calculated next term value
        // FIX: Must update term2 to hold temp not term1
        // WHY: Assigning term2 to term1 results in them having same value, making loop repeat the same numbers endlessly
    }
    cout << endl;

    // Prompt user to press any key to continue program exit
    cout << "\n\n  Exiting program. Press any key to continue..." << endl;
    _getch(); // Halt execution until key entry

    return 0;
}