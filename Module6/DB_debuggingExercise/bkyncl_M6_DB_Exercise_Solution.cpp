/*
* Student Name: Brittany Kyncl
* File Name: bkyncl_M6_DB_Exercise_solution.cpp
* Date: 4.18.24
* Description: 
*   This is the solution file to (bkyncl_M6_Exercise.cpp)
*   This program uses Enums to represent character classes.
*   It prompts the user to choose a character class from a menu and creates a character based on the selection.
* Input:
*   - An integer representing the selected character class (1-4).
* Output:
*   - The chosen character class is displayed.
*/

#include <iostream>
#include <conio.h>
#include <limits>
using namespace std;

// Enum to represent different character classes
enum CharacterClass { // FIX: change parenthesis to curly braces for enum declaration
    WARRIOR = 1,
    MAGE = 2,
    ROGUE = 3,
    ARCHER = 4
};
/**
 * Function to display the chosen class and race of character
 * 
 * @param choice_input The selected character class
 */
void createCharacter(CharacterClass choice_input) {
    cout << "\n  Creating character..." << endl;
    cout << "\n  Your chosen character is: ";
    switch (choice_input) {
        case WARRIOR:
            cout << "Warrior" << endl;
            break;
        case MAGE:
            cout << "Mage" << endl;
            break;
        case ROGUE:
            cout << "Rogue" << endl;
            break;
        case ARCHER:
            cout << "Archer" << endl;
            break;
    }
}

int main() {
    // Variable to store user input
    int choice_input;

    // Display character creation menu prompting user input
    cout << "\n  ===== Character Creation =====" << endl;
    cout << "  Choose your class:" << endl;
    cout << "  1. Warrior" << endl;
    cout << "  2. Mage" << endl;
    cout << "  3. Rogue" << endl;
    cout << "  4. Archer" << endl;

    do {
        cout << "  Enter (1-4): ";
        
        // Check if the input is not an integer
        if (!(cin >> choice_input) || choice_input < 1 || choice_input > 4) {
            cin.clear(); // Clear the fail flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the remaining input
            continue; // Continue to the next iteration of the loop
        } else {
            break;
        }

    } while (true); // loop while input is not valid

    // Convert user input to enum value
    CharacterClass chosen_class = static_cast<CharacterClass>(choice_input); // FIX: Correctly pass 'choice_input' instead of 'chosen_class'
                                                                             // WHY: passing an undefined variable produced no resulting switch case

    // Create character based on user choice and display
    createCharacter(chosen_class);

    // Prompt user to press any key to continue program exit
    cout << "\n\n  Exiting program. Press any key to continue..." << endl;
    _getch(); // Halt execution until key entry

    return 0;
}