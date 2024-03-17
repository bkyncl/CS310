/*
* Student Name: Brittany Kyncl
* File Name: Ch02Exercise13.cpp
* Date: 3.15.24
* Description: 
*   This program calculates the selling price and final price of an item
*   based on the original price, markup percentage, and sales tax rate.
* Input:
*   The program prompts the user to enter:
*   - Original price of the item
*   - Markup percentage applied by the store
*   - Sales tax rate
* Output:
*   The program then computes and displays:
*   - Original price of the item
*   - Markup percentage
*   - Selling price of the item
*   - Sales tax rate
*   - Sales tax amount
*   - Final price of the item (selling price + sales tax)
*/

#include <iostream>
#include <conio.h>
#include <iomanip>
#include <limits>
using namespace std;

/**
 * Validates user input to ensure it is a positive number (non-negative and non-string).
 * Displays the given prompt to the user and repeatedly prompts for input until a valid positive number is entered.
 * 
 * @param prompt The prompt message displayed to the user.
 * @return The validated positive number entered by the user.
 */
double validateInput(const string& prompt) {
    // Declare variables to store user input and bool flag to track if input is valid or not
    double input;
    bool validInput = false;

    // do while loop to perform iterative input validation and user prompt display
    do {
        cout << prompt; // Display prompt
        if (cin >> input) { // Check if the input is sucessfully read
            if (input > 0) { // Check if input is positive
                validInput = true; // Set flag to true for valid input
            } else {
                cout << "\n  Invalid input. Please enter a non-negative number." << endl; // Display error message to user
            }
        } else { // Error handling in case of string input
            cin.clear(); // Clear error flag on cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard the invalid input
            cout << "\n  Invalid input. Please enter a valid number." << endl; // Display error message to user
        }
    } while (!validInput); // Continue loop or exit loop based on validInput flag

    return input; // Return validated input
}

int main() {

    // Declare input variables
    double originalPrice, markupPercentage, salesTaxRate;
    // Declare output variables
    double sellingPrice, salesTaxAmount, finalPrice;

    // Program welcome message
    cout << ("\n\n  Welcome to the store price calculator.") << endl;

    // Prompt user for input and assign it to the variable using validateInput function
    // Sending string prompt as parameter and returning validated double input for assignment
    originalPrice = validateInput("\n  Please enter item original price: ");
    markupPercentage = validateInput("\n  Please enter item markup percentage: ");
    salesTaxRate = validateInput("\n  Please enter sales tax rate: ");

    // Calculate the markup amount based on the original price and markup percentage
    double markupAmount = originalPrice * (markupPercentage /100);

    // Calculate the selling price by adding the markup amount to the original price
    sellingPrice = originalPrice + markupAmount;
   
    // Calculate the sales tax based on the selling price and tax rate
    salesTaxAmount = sellingPrice * (salesTaxRate / 100);

    // Calculate the final price by adding the selling price and the sales tax ammount
    finalPrice = sellingPrice + salesTaxAmount;

    // Program output message
    cout << ("\n\n  Displaying calculations...") << endl;
   
    // Output of original price, markup percentage, selling price, sales tax rate, 
    // sales tax ammount, and the final price
    cout << fixed << setprecision(2); // Set decimal precision to 2 places for output
    cout << "\n  Original Price: $" << originalPrice << endl;
    cout << "\n  Markup Percentage: " << markupPercentage << "%" << endl;
    cout << "\n  Selling Price: $" << sellingPrice << endl;
    cout << "\n  Sales Tax Rate: " << salesTaxRate << "%" << endl;
    cout << "\n  Sales Tax: $" << salesTaxAmount << endl;
    cout << "\n  Final Price: $" << finalPrice << endl;

    // Prompt user to press any key to continue
    cout << "\n\n  Press any key to continue..." << endl;
    _getch(); // Halt execution until key entry

    return 0;
}