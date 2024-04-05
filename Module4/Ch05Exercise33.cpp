/*
* Student Name: Brittany Kyncl
* File Name: Ch05Exercise33.cpp
* Date: 4.4.24
* Description: 
*   This program calculates the number of dishes a chef can prepare within a given time period
*   It takes input for the time (minutes) to prepare the first dish (a), then additional time to prepare each following dish (b),
*   and the total time allotted to prepare all dishes (t). It then iteratively calculates the number of dishes 
*   a chef can prepare within allotted time, considering that each dish takes progressively longer to prepare.
*   The program offers choice to continue caclulating new inputs until the user decides to quit.
* Input:
*   - Time to prepare the first dish (a)
*   - Additional time to prepare each following dish (b)
*   - Total time allotted to prepare all dishes (t)
* Output:
*   - Number of dishes chef can prepare within the allotted time
*/

#include <iostream>
#include <conio.h>
#include <iomanip>
#include <limits>
#include <locale>
using namespace std;

/**
 * Validates user input is positive integer.
 * Displays prompt message and ensures that input value is a positive integer,
 * else error message is displayed prompting for re-entry
 * 
 * @param prompt Input message displayed to prompt user for entry
 * @return Validated positive integer input
 */
int validateIntegerInput(const string& prompt) {
    int input;
    cout << prompt; // Display prompt initially

     // Input validation loop to handle non-numeric input, negative values, and out-of-range values
    while (!(cin >> input) || cin.peek() != '\n' || input < 0) {
        cout << "\n  Invalid input. Please enter only positive integers." << endl;
        cout << prompt; // Display prompt again for re-entry
        cin.clear(); // Clear error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
    }

    return input;
}
int main() {
    
    // Variable for program loop option
    char choiceToLoop;

    do {
        
        // Program welcome message
        cout << ("\n\n  Welcome to the Cooking time Calculator.") << endl;

        // user variables
        int a, b, t;

        // Prompt the user to enter values of a, b, and t
        a = validateIntegerInput("\n  Enter the time (in minutes) to prepare the first dish (a): ");
        b = validateIntegerInput("\n  Enter the additonal time (in minutes) to prepare each following dish (b): ");
        t = validateIntegerInput("\n  Enter the total time (in minutes) allotted to prepare all dishes (t): ");

        // variables to keep count of dishes and prep time
        int numDishes = 0, prepareTime = a; // Inialize starting prept time with the time to prepare first dish (a)
        
        // Calculate the number of dishes chef can prepare in allotted time
        // While accumulated preptime is <= allotted prep time continue else exit
        while (prepareTime <= t) { 
            numDishes++; // Increment and count number of dishes prepared
            cout << "\n  Dish "<< numDishes << " prep time: " << a << " minute(s). Accumulated prep time: " << prepareTime << " minute(s)." << endl;
            a += b; // Update a value with next dish prep time (previous dish prep time + b)
            prepareTime += a; // add following dish to total prepare time
        }

        // Ouput the result
        cout << "\n  So, you could prepare " << numDishes << " dishes within " << t << " minutes." << endl;

        // Prompt user for input on running the program again
        cout << "\n  Do you want to calculate how many dishes you can make again? (Y/N): ";
        cin >> choiceToLoop;

        // Clear any remaining characters from the input stream
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choiceToLoop != 'Y' && choiceToLoop != 'y') {
            break;
        }

    } while (true); // Program loop will only exit if the user decides to quit
    
    // Prompt user to press any key to continue
    cout << "\n\n  Exiting program. Press any key to continue..." << endl;
    _getch(); // Halt execution until key entry

    return 0;
}