// Discussionboardweek3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// EDIT: Bugs fixed, 5 in total, by Brittany Kyncl on 3.28.24 (see comments for explanation)

#include <iostream>
#include <conio.h> // Include the <conio.h> header for _getch()

int main() {
    int number = 10;

    if (number > 0) { // FIX: Deleted extra 'f' in 'if' causing compilation error
                      // WHY: Keywords like if need correct syntax to be properly executed.
        std::cout << "The number is positive." << std::endl;
    }
    else {
        std::cout << "The number is not positive." << std::endl;
    }

    if (number < 20) { // FIX: 'num' replaced with declared variable 'number'
                       // WHY: Using undeclared varaible 'num' instead of declared variable 'number' caused compilation error.
        std::cout << "The number is less than 20." << std::endl; // FIX: 'end1' should be 'endl' with an l not a #1.
                                                                 // WHY: 'endl' if the correct syntax for newline in c++, mispelling caused compilation error
                                                                 // NOTE: This was a good one, as 1 & l look almost identical in certain text editors
    }

    // FIX: Added _getch() to halt program execution at the end of main()
    // WHY: Including _getch() ensures that the program window remains open after execution, 
    // allowing the user to review the program output before closing the console window.
    // NOTE: While not technically an error, it's inclusion adds usability
    std::cout << "Press any key to exit..." << std::endl;
    _getch(); // Wait for any key press before exiting

    return 0;
} // FIX: Added missing closing brackets here for main()
  // WHY: Opening and closing curly braces signify the start and end of a function like main().
  // Without a closing bracket the function definition is incomplete and won't compile.

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file