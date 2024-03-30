/*
* Student Name: Brittany Kyncl
* File Name: Ch04Exercise16.cpp
* Date: 3.28.24
* Description: 
*   This program calculates royalties for a romance novel author based on different contract options offered by a publisher. 
*   The program prompts the author to enter the net price of each copy of the novel and the estimated number of copies to be sold.
*   It then calculates and outputs the royalties under each option and determines the best option for the author.
* Input:
*   - Net price of each copy of the novel
*   - Estimated number of copies to be sold
* Output:
*   - Royalties under each option
*   - Best option for the author
*/

#include <iostream>
#include <conio.h>
#include <iomanip>
#include <limits>
#include <locale>
using namespace std;

// Constants for royalty rates, fixed royalties, and required copies sold for royalty rate increase
    const double OPT1_FIXED_DELIVERY_ROYALTY = 5000;
    const double OPT1_FIXED_PUBLISHED_ROYALTY = 20000;
    const double OPT2_PERCOPY_ROYALTY_RATE = 0.125;
    const double OPT3_ROYALTY_RATE_FIRST_4000 = 0.10;
    const double OPT3_ROYALTY_RATE_OVER_4000 = 0.14;
    const int OPT3_MAX_COPIES = 4000;

/**
 * Validates uers input is a positive double.
 * Displays prompt message and ensures that input value is a positive double, 
 * else error message is displayed prompting for re-entry
 * 
 * @param prompt Input message displayed to prompt user for entry
 * @return Validated positive double input
 */
double validateDoubleInput(const string& prompt) {
    double input;
    bool validInput = false;

    cout << prompt; // Display prompt initially

     // Input validation loop to handle non-numeric input or negative values
    while (!(cin >> input) || cin.peek() != '\n' || input < 0) {
        cout << "\n  Invalid input. Please enter in only positive numbers." << endl;
        cout << prompt; // Display prompt again for re-entry
        cin.clear(); // Clear error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
    }

    return input;
}

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
/**
 * Calculates the royalties for option 1.
 * ($5,000 upon delivery of the final manuscript and $20,000 when the novel is published.)
 * 
 * @return Royalties for option 1
 */
double calculateOption1() {
    return OPT1_FIXED_DELIVERY_ROYALTY + OPT1_FIXED_PUBLISHED_ROYALTY;
}

/**
 * Calculates the royalties for option 2.
 * (12.5% of the net price of the novel for each copy of the novel sold.)
 * 
 * @param netPricePerCopy The net price of each copy of the novel
 * @param estimatedCopiesSold The estimated number of copies to be sold
 * @return Royalties for option 2
 */
double calculateOption2(double netPricePerCopy, int estimatedCopiesSold) {
    return (OPT2_PERCOPY_ROYALTY_RATE * netPricePerCopy) * estimatedCopiesSold;
}

/**
 * Calculates the royalties for option 3.
 * (10% of the net price for the first 4,000 copies sold, then 14% of the net price for the copies sold over 4,000.)
 * 
 * @param netPricePerCopy The net price of each copy of the novel
 * @param estimatedCopiesSold The estimated number of copies to be sold
 * @return Royalties for option 3
 * 
 * @note Using regular ternary expression (condition) ? value_if_true : value_if_false;
 * (copiesSold >= 4000) ? evaluate 10% royalty : evaluate 10% royalty under 4000 + 14% royalty over 4000;
 */
double calculateOption3(double netPricePerCopy, int estimatedCopiesSold) {
    return (estimatedCopiesSold <= OPT3_MAX_COPIES) ? // if copies sold under 4000
           (OPT3_ROYALTY_RATE_FIRST_4000 * netPricePerCopy) * estimatedCopiesSold : // calculate 10% royalty
           (OPT3_ROYALTY_RATE_FIRST_4000 * netPricePerCopy) * OPT3_MAX_COPIES + // else calculate 10% royalty under 4000 + 14% royalty over 4000
           (OPT3_ROYALTY_RATE_OVER_4000 * netPricePerCopy) * (estimatedCopiesSold - OPT3_MAX_COPIES);
}

/**
 * Determines the best option by comparing the total earnings of each royalty option.
 * 
 * @param royaltiesOPT1 Royalties for option 1
 * @param royaltiesOPT2 Royalties for option 2
 * @param royaltiesOPT3 Royalties for option 3
 * @return String with best conttract option
 */
string determineBestOption(double royaltiesOPT1, double royaltiesOPT2, double royaltiesOPT3) {

    if (royaltiesOPT1 >= royaltiesOPT2 && royaltiesOPT1 >= royaltiesOPT3) {
        return "Option 1\n";
    } else if (royaltiesOPT2 >= royaltiesOPT1 && royaltiesOPT2 >= royaltiesOPT3) {
        return "Option 2\n";
    } else {
        return "Option 3\n";
    }
}

int main() {
    
    // Variable for program loop option
    char choiceToLoop;

    do {
        // Variables to store user input and calculated values
        double netPricePerCopy, royaltiesOPT1, royaltiesOPT2, royaltiesOPT3;
        int estimatedCopiesSold;
        string bestContractOption;

        // Program welcome message
        cout << ("\n\n  Welcome to the Novel Royalty Calculator.") << endl;

        // Display contract options to user
        cout << ("\n  Your contract options are as follows...") << endl;
        cout << ("\n  Option 1 Payment: $5,000 upon delivery of the final manuscript and $20,000 when the novel is published.") << endl;
        cout << ("\n  Option 2 Payment: 12.5% of the net price of the novel for each copy of the novel sold.") << endl;
        cout << ("\n  Option 3 Payment: 10% of the net price for the first 4,000 copies sold, then 14% of the net price for the copies sold over 4,000.") << endl;

        // Prompt the user to enter net price and estimated number of copies sold.
        // Sending string prompt and user input as parameters to validation functions, returned valid input assigned to variables
        netPricePerCopy = validateDoubleInput("\n  Enter the net price of each copy of the novel: $");
        estimatedCopiesSold = validateIntegerInput("\n  Enter the estimated number of copies that will be sold: ");

        // Calculate royalties for each option
        // Call function to calculate fixed royalty option and assign returned value to variable
        royaltiesOPT1 = calculateOption1(); 
        // Call function to calculate fixed percentage based royalty option and assign returned value to variable
        royaltiesOPT2 = calculateOption2(netPricePerCopy, estimatedCopiesSold);
        // Call function to calculate teired percentage based royalty option and assign returned value to variable
        royaltiesOPT3 = calculateOption3(netPricePerCopy, estimatedCopiesSold);

        // Determine the best option
        // Call function to compare all contract option paremters and return the largest value as best option
        bestContractOption = determineBestOption(royaltiesOPT1, royaltiesOPT2, royaltiesOPT3);

        // Output royalties for each option
        cout << fixed << setprecision(2); // set decimal precision to 2 places
        cout << "\n\n  Royalties under each option with " << estimatedCopiesSold << " copies sold at $" << netPricePerCopy << " per copy." << endl;
        cout << "\n  Option 1: $" << royaltiesOPT1 << endl;
        cout << "\n  Option 2: $" << royaltiesOPT2 << endl;
        cout << "\n  Option 3: $" << royaltiesOPT3 << endl;

        // Output the best option
        cout << "\n  The best option in this case is: " << bestContractOption << endl;

        // Prompt user for input on running the program again
        cout << "\n  Do you want to calculate royalties again? (Y/N): ";
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