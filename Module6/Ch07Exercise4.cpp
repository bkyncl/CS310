/*
* Student Name: Brittany Kyncl
* File Name: Ch07Exercise4.cpp
* Date: 4.21.24
* Description: 
*   This program prompts the user to input a string. The program then uses the function substr to remove all the vowels from the string. 
*   For example, if str = "There", then after removing all the vowels, str = "Thr".
*   After removing all the vowels, the program outputs the modified string. 
* Input:
*   - A string input by the user.
* Output:
*   - The input string with all vowels removed.
*/

#include <iostream>
#include <conio.h>
#include <string>
#include <limits>

using namespace std;

/**
 * Validates that the input string contains only letters and spaces.
 * 
 * @param str Input string to be validated
 * @return true if the string is valid, false otherwise
 */
bool validString(string& str) {
    // Check length
    if (str.length() == 0) {
        return false;
    }
    // Loop through each character in string
    for (char c : str) {
        // If a character is not a letter and not a space, return false
        if (!isalpha(c) && c != ' ') {
            return false;
        }
    }
    return true;
}

/**
 * Determines whether a character is a vowel.
 * 
 * @param c The character to be checked
 * @return true if the character is a vowel, false otherwise
 */
bool isVowel(char c) {
    // Convert character to lower before check
    c = tolower(c);
    // true if vowel (what about sometimes y?)
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u'); 
}

/**
 * Removes all vowels from the string.
 * 
 * @param str The input string
 * @return A new string with all vowels removed
 */
string removeVowelsWithSubstr(string str) {


    // Loop through each character in the string
    for (int i = 0; i < str.length(); ++i) {
        // If current character is a vowel, remove it from the string using substr() (per assignment instructions)
        if (isVowel(str[i])) {
            // Using substr() to take everything before current vowel and concatenate it with everything after 
            // substr(0, i) takes the substring from the beginning to just before i capturing all character before current vowel
            // substr(i + 1) takes the substring starting from just after the current character
            str = str.substr(0, i) + str.substr(i + 1);                                     
            i--; // Move back one step, as the length of the string is now one character shorter
        }
    }

    return str;
}
int main() {

    // Variable for program loop option
    char choice_loop;

    // Program Welcome Message
    cout << "\n\n  This program removes the vowels from a string." << endl;

    do {
        // Prompt user to input a string
        string user_string;
        cout << "\n  Please enter a string: ";
        
        // Loop for re-entry on invalid input (only lettters and spaces)
        while (true) {
            getline(cin, user_string); // Read input
            if (validString(user_string)) { // Pass input to validation function 
                break;
            } else {
                cout << "\n  Invalid input. Please enter only letters and spaces: ";
            }
        }

        // Remove all vowels from the input string
        string result = removeVowelsWithSubstr(user_string);

        // Output the string after removing all the vowels
        cout << "\n  Your string after removing vowels: " << result << endl;

        // Prompt user for input on running the program again
        cout << "\n  Do you want to try again? (Y/N): ";
        cin >> choice_loop;

        // Clear any remaining characters from the input stream
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    } while (choice_loop == 'Y' || choice_loop == 'y'); // Program loop will only exit if the user decides to quit
    
    // Prompt user to press any key to continue
    cout << "\n\n  Exiting program. Press any key to continue..." << endl;
    _getch(); // Halt execution until key entry

    return 0;
}