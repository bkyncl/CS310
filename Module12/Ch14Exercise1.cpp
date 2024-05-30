/**
 * Student Name: Brittany Kyncl
 * File Name: Ch14Exercise1.cpp
 * Date: 5.29.24
 * Description: 
 *   This program converts lengths from feet and inches to centimeters.
 *   Using exception handling during user input and conversion.
 *   Custom exceptions are used to handle scenarios such as negative input, non-numeric input, and invalid choices.
 * Input:
 *  - User input lengths in feet an inches
 * Output:
 *   - Converted lengths in centimeters
 */

#include <iostream>
#include <conio.h>
#include <sstream>
#include <exception>
#include <limits>

using namespace std;

// Constants for conversion
const double CM_PER_INCH = 2.54;
const int INCH_PER_FOOT = 12;

// Custom exception for negative numbers derived from exception class
class NegativeNumberException : public exception {
public:
    virtual const char* what() const noexcept {
        return "Negative number entered. Length cannot be negative.";
    }
};

// Custom exception for non-numeric input derived from exception class
class NonNumberException : public exception {
public:
    virtual const char* what() const noexcept {
        return "Non-numeric input entered. Please enter valid numbers.";
    }
};

// Custom exception for invalid choice input derived from exception class
class InvalidChoiceException : public exception {
public:
    virtual const char* what() const noexcept {
        return "Invalid choice entered. Must enter Y or N. Terminating execution.";
    }
};
/**
 * Function to convert feet and inches to centimeters.
 * 
 * @param feet The length in feet.
 * @param inches The length in inches.
 * @return The equivalent length in centimeters.
 */
double convertToCentimeters(int feet, int inches) {
    return (feet * INCH_PER_FOOT + inches) * CM_PER_INCH;
}
/**
 * Function to convert string to double, throwing an exception if conversion fails.
 * 
 * @param input The string input to convert.
 * @return The converted double value.
 * @throws NonNumberException if the input is not a valid number.
 */
double stringToDouble (const string& input) {
    try {
        size_t idx; // to hold index of possible unconverted characters
        // Convert the string input to a double using stod function, idx is updated with the index of the first unconverted character
        double result = stod(input, &idx); 

        // Check if entire string was converted
        if (idx != input.size()) {
            throw NonNumberException(); // If not throw NonNumberException
        }
        return result;

    } catch (...) { // Catch any possible exceptions thrown during conversion process
        throw NonNumberException(); // Throw NonNumberExceptionif conversion fails or unknown exception occurs
    }
}
/**
 * Function to prompt the user and get valid input.
 * 
 * @param prompt The prompt message to display to the user.
 * @return The validated input as a double.
 * @throws NegativeNumberException if a negative number is entered.
 * @throws NonNumberException if non-numeric input is entered.
 */
double validateInput(const string& prompt) {
    string input; // Interim user input
    double output; // Converted user input

    while (true) { // Loop until valid input is received
        try {
            cout << prompt; // Display prompt parameter
            cin >> input;
            output = stringToDouble(input); // Convert user input to double using stringToDouble function

            // Check if the number is negative
            if (output < 0) {
                throw NegativeNumberException(); // Throw NegativeNumberException
            }
            return output; // Return valid input

        } catch (const exception& e)  { // Catch any exceptions thrown during input validation
            cerr << "  Exception occurred: " << e.what() << endl; // Print exception message to the console
            cin.clear(); // Clear any error flags set in the cin stream
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard any remaining characters in the input buffer
        }
    }
}
/**
 * Function to validate choice input.
 * 
 * @param prompt The prompt message to display to the user.
 * @return The validated choice as a character ('Y' or 'N').
 * @throws InvalidChoiceException if an invalid choice is entered.
 */
char validateChoice(const string& prompt) {
    char choice; // To store user choice
    cout << prompt; // Display prompt parameter
    cin >> choice;
    choice = toupper(choice); // Convert to uppercase

    if (choice == 'Y' || choice == 'N') { // Check for valid choice options
        return choice; // Return valid choice
    } else {
        throw InvalidChoiceException(); // Throw InvalidChoiceException if an invalid choice is entered
    }
}
int main() {

    cout << "\n  Enter a length in feet and inches to output the equivalent length in centimeters..." << endl;
    while (true) {
        string input; 
        try {
            // Prompt the user to enter length in feet and validate the input
            double feet = validateInput("\n  Enter feet: "); 
            // Prompt the user to enter length in inches and validate the input
            double inches = validateInput("\n  Enter inches: "); 

            // Convert the entered lengths to centimeters
            double centimeters = convertToCentimeters(feet, inches);
            cout << "\n  " << feet << " ft. and " << inches << " in. is equivalent in length to " << centimeters << " cm." << endl;

            // Prompt the user to choose whether to perform the conversion again and validate input
            char choice = validateChoice("\n  Calculate conversion again? (Y/N): ");
            if (choice == 'N') {
                break;
            } 
        } catch (const exception& e) { // Catch any exceptions thrown during execution
            cerr << "  Exception occurred: " << e.what() << endl; // Print exception message to the console
            break; // Exit the loop
        }
    }
    
    // Prompt user to press any key to continue
    cout << "\n  Exiting program. Press any key to continue..." << endl;
    _getch(); // Halt execution until key entry
    
    return 0;
}