/*
* Student Name: Brittany Kyncl
* File Name: Ch03Exercise7.cpp
* Date: 3.22.24
* Description: 
*   This program calculates the interest on unpaid credit card balances based on user-entered data such as net balance, 
*   payment made, billing cycle duration, and monthly interest rate.
* Input:
*   - Net balance of the credit card
*   - Payment made during the billing cycle
*   - Number of days in the billing cycle
*   - Number of days payment is made before billing cycle
*   - Monthly interest rate in decimal format (e.g., 0.05 for 5%)
* Output:
*   - Original net balance
*   - Payment made
*   - Duration of the billing cycle
*   - Number of days before the billing cycle when payment is made
*   - Monthly interest rate
*   - Average daily balance during the billing cycle
*   - Interest on the unpaid balance
*/

#include <iostream>
#include <conio.h>
#include <iomanip>
#include <limits>
#include <locale>
using namespace std;

/**
 * Validates uers input is numberic within a specified range.
 * Displays prompt message and ensures that input value is a positive number or in correct decimal format
 * If an upper limit is provided, the input value must not exceed this limit.
 * 
 * @param prompt Input message displayed to prompt user for entry
 * @param upperLimit Sets valid max valid input limit for percentage input (decimal format) by default 
 * it's set to maximum value of type double to allow any positive value
 * @return Validated positive numeric input or valid decimal format, based on passed upperLimit range.
 * 
 * @note For decimal input, upperLimit ensures correct format, e.g., 0.5 for 50%.
 */
double validateInput(const string& prompt, double upperLimit = numeric_limits<double>::max()) {
    double input;
    bool validInput = false;

    cout << prompt; // Display prompt initially

     // Input validation loop to handle non-numeric input, negative values, and out-of-range values
    while (!(cin >> input) || cin.peek() != '\n' || input < 0 || input > upperLimit) {
        cout << "\n  Invalid input. Please enter in valid number format." << endl;
        cout << prompt; // Display prompt again for re-entry
        cin.clear(); // Clear error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
    }

    return input;
}

/**
 * Validates user input is positive integer.
 * Displays prompt message and ensures that input value is a positive integer.
 * 
 * @param prompt Input message displayed to prompt user for entry
 * @return Validated positive integer input
 */
int validateDaysInput(const string& prompt) {
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

    // Declare variables for input calculations
    double netBalance, payment, interestRate, averageDailyBalance;
    // d1 : number of days in billing cycle, d2 : number of days payment made before billing cycle
    int d1, d2;
    // Declare output variable for interest on unpaid balance
    double interest;

    // Program welcome message
    cout << ("\n\n  Welcome to the Credit Card Interest Calculator.") << endl;

    // Prompt the user to enter the net balance, payment made, days in bliing cycle, days payment made before billing cycle, and monthly interest rate.
    // Sending string prompt as parameter and returning validated numeric input
    netBalance = validateInput("\n  Enter the net balance: ");
    payment = validateInput("\n  Enter the payment made: ");
    d1 = validateDaysInput("\n  Enter the number of days in the billing cycle: ");
    d2 = validateDaysInput("\n  Enter the number of days payment is made before the billing cycle: ");
    interestRate = validateInput("\n  Enter the monthly interest rate in decimal format (e.g., 0.05 for 5%): ", 1); // Second parameter sets upper limit of 1 for decimal percentage validation

    // Calculate average daily balance
    averageDailyBalance = (netBalance * d1 - payment * d2) / d1;

    // Calculate interest
    interest = averageDailyBalance * interestRate;

    // Format the output to two decimal places with the thousands separator
    cout << fixed << setprecision(2);
    locale loc("");
    cout.imbue(loc);

    // Display output to user > original input > calculated average daily balance and interest on unpaid balance
    cout << ("\n\n  Displaying calculations...") << endl;
    cout << "\n  Net Balance: $" << netBalance << endl;
    cout << "\n  Payment Made: $" << payment << endl;
    cout << "\n  Days in Billing Cycle: " << d1 << endl;
    cout << "\n  Days Payment Made Before Billing Cycle: " << d2 << endl;
    cout << "\n  Monthly Interest Rate: " << interestRate*100 << "%" << endl;
    cout << "\n  Average Daily Balance: $" << averageDailyBalance << endl;
    cout << "\n  Interest on Unpaid Balance: $" << interest << endl;


    // Prompt user to press any key to continue
    cout << "\n\n  Press any key to continue..." << endl;
    _getch(); // Halt execution until key entry

    return 0;
}