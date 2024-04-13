/*
* Student Name: Brittany Kyncl
* File Name: Ch06Exercise14.cpp
* Date: 4.12.24
* Description: 
*   This program calculates the billing amount for tax preparation services based on the following rules:
*   - If a person has low income (<= 25,000) and the consulting time is less than or equal to 30 minutes, there are no charges; 
*     otherwise, the service charges are 40% of the regular hourly rate for the time over 30 minutes.
*   - For others, if the consulting time is less than or equal to 20 minutes, there are no service charges; 
*     otherwise, service charges are 70% of the regular hourly rate for the time over 20 minutes.
* Input:
*   - Hourly rate
*   - Total consulting time (in minutes)
*   - User income (to determine low income status)
* Output:
*   - Billing amount
*/

#include <iostream>
#include <iomanip>
#include <conio.h>
#include <limits>
#include <locale>
using namespace std;

// Constants for low-income threshold, minimum consulting time, and service charge rate
const double LOW_INCOME_THRESHOLD = 25000.0;
const int LOW_MIN_TIME = 30;
const double LOW_SERVICE_RATE = 0.4;
// Constants for others (non-low-income) minimum consulting time and service charge rate
const int OTHER_MIN_TIME = 20;
const double OTHER_SERVICE_RATE = 0.7;
/**
 * Calcluates total billing amount for client
 * 
 * @param low_income bool flag for low income calculation
 * @param consulting_time billable time (in minutes) spent with consultant
 * @param hourly_rate rate charged per hour
 * @return calculated total billing amount client will be charged
 */
double calculateBillingAmount(bool low_income, int consulting_time, double hourly_rate) {
    // Initialize total billing amount to 0
    double total_billing_amount = 0;

    // Check if client is low income
    if (low_income) {
        // If low income, check if the consulting time is greater than 30 minutes
        if (consulting_time > LOW_MIN_TIME) {
            total_billing_amount = ((consulting_time - LOW_MIN_TIME) / 60.0) * hourly_rate * LOW_SERVICE_RATE;
        }
    } else {
        // If not low income, check if the consulting time is greater than 20 minutes
        if (consulting_time > OTHER_MIN_TIME) {
            total_billing_amount = ((consulting_time - OTHER_MIN_TIME) / 60.0) * hourly_rate * OTHER_SERVICE_RATE;
        }
    } 
    // Return calculated billing amount, which may be 0 in cases where (low_income && time <= 30) or (!low_income && time <=20)
    return total_billing_amount;
}
/**
 * Function to display reciept for client transaction
 * Including billable time displayed in hours and minutes, 
 * low income eligiblity, user income, hourly rate, and resulting billing amount.
 * 
 * @param low_income bool flag for lowIncome calculation
 * @param consulting_time billable time (in minutes) spent with consultant
 * @param hourly_rate fixed rate charged per hour
 * @param userIncome total entered income of user
 * @param total_billing_amount calculated billing amount per calculate_billing_amount()
 */
void printClientReceipt(bool low_income, int consulting_time, double hourly_rate, double userIncome,  double total_billing_amount) {
    // Convert consulting time to hours and minutes
    int hours = consulting_time / 60;
    int minutes = consulting_time % 60;

    cout << "\n  ---------- Receipt ----------" << endl;
    cout << "\n  Total Income: $" << fixed << setprecision(2) << userIncome << endl;
    cout << "\n  Low income: " << boolalpha << low_income << endl;
    cout << "\n  Consulting time: "<< hours << " hour(s) and " << minutes << " minute(s)" << endl;
    cout << "\n  Hourly rate: $" << hourly_rate << endl;
    cout << "\n  Billing amount: $" << fixed << setprecision(2) << total_billing_amount << endl;
    cout << "\n  --------- Thank You! ---------\n" << endl;
}
/**
 * Validates user input is numeric positive
 * else error message is displayed prompting for re-entry
 * 
 * @param prompt Input message displayed to prompt user for entry
 * @return Validated double numerical input
 */
double validateInput(const string& prompt) {
    double input;
    cout << prompt; // Display prompt initially

    // Input validation loop to handle non-numeric input, negative values, and 0 input
    while (!(cin >> input) || cin.peek() != '\n' || input < 0) {
        cout << "\n  Invalid input. Please enter positive numeric values." << endl;
        cout << prompt;
        cin.clear(); // Clear error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
    }

    return input;
}

int main() {
    // Imbue the output stream with the default locale to enable thousand separator formatting
    cout.imbue(locale(""));

    // Variable for program loop option
    char choice_loop;

    // Program Welcome Message
    cout << "\n\n  This program calculates the billing amount for tax preparation assistance." << endl;
    cout << "\n  For qualifying low income (<= $25,000) individuals, service charges are:" << endl;
    cout << "  No service charge for consulting time <= 30 minutes." << endl;
    cout << "  40% of the regular hourly rate for consulting time > 30 minutes." << endl;
    cout << "\n  For non low income qualifying individuals service charges are:" << endl;
    cout << "  No service charge for consulting time <= 20 minutes." << endl;
    cout << "  70% of the regular hourly rate for consulting time > 20 minutes." << endl;

    do {
        // Prompt user to enter hourly rate, consulting time, and their income and validate input
        double hourly_rate = validateInput("\n  Enter the hourly rate: $");
        int consulting_time = static_cast<int>(validateInput("\n  Enter the total consulting time (in minutes): "));
        double user_income = validateInput("\n  Enter the total income: ");

        // Set low_income flag if user income is qualifies for low income status (<=25000)
        bool low_income = (user_income <= LOW_INCOME_THRESHOLD) ? true : false;

        // Calculate billing amount based on lowIncome flag, the consulting time, and the hourly rate
        double total_billing_amount = calculateBillingAmount(low_income, consulting_time, hourly_rate);

        // Ouput the results
        cout << "\n\n  Your total billing amount will be: $" << fixed << setprecision(2) << total_billing_amount << endl;
        // Display customer receipt
        printClientReceipt(low_income, consulting_time, hourly_rate, user_income, total_billing_amount);

        // Prompt user for input on running the program again
        cout << "\n  Do you want to calculate the billing amount again? (Y/N): ";
        cin >> choice_loop;

        // Clear any remaining characters from the input stream
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    } while (choice_loop == 'Y' || choice_loop == 'y'); // Program loop will only exit if the user decides to quit
    
    // Prompt user to press any key to continue
    cout << "\n\n  Exiting program. Press any key to continue..." << endl;
    _getch(); // Halt execution until key entry

    return 0;
}