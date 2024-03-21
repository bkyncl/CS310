/*
Rebecca Hahn
03/20/2024

This program contains errors.

EDIT: Bugs fixed (Brittany Kyncl) potentially

*/

#include <iostream>
#include <iomanip>
#include <conio.h>
// FIX: Added missing <conio.h> header here.
// WHY: The program uses _getch() to pause execution which is provided by this header file.
#include <locale>
// FIX: Added missing <locale> header here.
// WHY: The program uses std::locale function to handle locale-specific formatting and parsing of data, which is provided by this header file.

int main()
{
    // Variable declaration 
    double netBalance; // FIX: Added missing semicolon here.
                       // WHY: Semicolons are required to mark the end of statements in c++, 
                       // otherwise the compiler will interpret the next lines as part of the same statement resulting in syntax error.
    double payment;
    double d1;
    double d2;
    double interestRate;

    // Input/output

    std::cout << "What is the net balance?\n";
    std::cin >> netBalance;

    std::cout << "What is the payment made?\n";
    std::cin >> payment;

    std::cout << "What is the number of days in billing cycle?\n";
    std::cin >> d1;

    std::cout << "What is the number of days payment is made before the billing cycle?\n";
    std::cin >> d2;

    std::cout << "What is the interest rate per month?\n";
    std::cin >> interestRate;

    // Calculations

    double averageDailyBalance = (netBalance * d1 - payment * d2) / d1;

    double interest = averageDailyBalance * interestRate;

    // Print out

    std::cout << std::fixed << std::setprecision(2); // set the decimal to two places.
    std::locale loc(""); // for the thousands separator
    std::cout.imbue(loc); // for the thousands separator
    std::cout << "The selected locale is: " << loc.name() << '\n';

    std::cout << "interest: " << interest << "\n";

    std::cout << "Done!\n";
    _getch();

    return 0; // FIX: Added missing return statement here.
              // WHY: The main function requires a return value (int) to indicate successful termination of execution.
}
