/*
* Student Name: Brittany Kyncl
* File Name: Ch11Exercise13.cpp
* Date: 5.9.24
* Description: 
*   This program is a simple banking account manager that utilizes a hierarchy of classes 
*   defined in the BankAccount.h header file. The BankAccount class serves as the base class, 
*   providing common functionality for all types of bank accounts. Derived classes CheckingAccount and 
*   SavingsAccount inherit from BankAccount, adding additional features specific to checking 
*   and savings accounts respectively.
* Input:
*   - User numeric selections for menu options.
*   - Numeric input for transaction amounts (deposit, withdrawal).
* Output:
*   - Display of account information, including account number, account holder name, interest rate, 
*     account type, and balance.
*   - Transaction success or failure messages.
*   - Menu options for user interaction.
*/

#include <iostream>
#include <conio.h>
#include <string>
#include <limits>
#include <iomanip>
#include <vector>
#include "BankAccount.h"

using namespace std;

// This function manages the interaction with a single bank account, presenting a menu of options and executing the selected operation.
void manageAccount(BankAccount& account) {
    // Enter loop to keep displaying menu options until user entry of exit key 5
    while (true) {
        cout << "\n  ====================" << endl;
        cout << "  Account Menu" << endl;
        cout << "  ====================" << endl;
        cout << "  1. Deposit" << endl;
        cout << "  2. Withdraw" << endl;
        cout << "  3. Post Interest" << endl;
        cout << "  4. Display Account Info" << endl;
        cout << "  5. Back to Main Menu" << endl;
        cout << "  Enter your choice: ";
        char accountChoice;
        cin >> accountChoice;

        switch (accountChoice) {
            case '1': { // Deposit Operation
                cout << "\n  Enter deposit amount: $";
                double amount;
                cin >> amount;
                if (account.deposit(amount)) {
                    cout << "  Deposit successful." << endl;
                    cout << "  New Balance: $" << account.getBalance() << endl;
                } else {
                    cout << "  Invalid amount. Deposit failed." << endl;
                }
                break;
            }
            case '2': { // Withdrawal Operation
                cout << "\n  Enter withdrawal amount: $";
                double amount;
                cin >> amount;
                if (account.withdraw(amount)) {
                    cout << "  Withdrawal successful." << endl;
                    cout << "  New Balance: $" << account.getBalance() << endl;
                } else {
                    cout << "  Insufficient funds. Withdrawal failed." << endl;
                }
                break;
            }
            case '3': { // Post Interest Operation
                account.postInterest();
                cout << "  New Balance: $" << account.getBalance() << endl;
                break;
            }
            case '4': { // Display account information operation
                account.displayBankAccountInfo();
                break;
            }
            case '5': { 
                return; // Exit the function and go back to the main menu
            }
            default: {
                cout << "  Invalid choice. Please enter a number between 1 and 5." << endl;
            }
        }
    }
}
int main() {
    // Imbue the output stream with the default locale to enable thousand separator formatting
    cout.imbue(locale(""));

    // Create instances of different account types 
    CheckingAccount check_account ("John Doe", 5000.0, 0.0005, 100, 10); // Acount number 1000
    SavingsAccount saving_account("Jane Smith", 10000.0, 0.005); // Acount number 1001


    // Display all account info
    check_account.displayBankAccountInfo(); 
    saving_account.displayBankAccountInfo(); 

    // Loop to keep displaying menu until user enters exit key 3
    bool exitLoop = false;
    while (!exitLoop) {
        cout << "\n  ====================" << endl;
        cout << "  Bank Account Manager" << endl;
        cout << "  ====================" << endl;
        cout << "  1. Manage Checking Account" << endl;
        cout << "  2. Manage Savings Account" << endl;
        cout << "  3. Exit" << endl;
        cout << "  Enter your choice: ";
        char choice;
        cin >> choice;

        switch (choice) {
            case '1': { // Send checking account to manage account operation function
                cout << "\n  Managing Checking Account..." << endl;
                manageAccount(check_account);
                break;
            }
            case '2': {// Send savings account to manage account operation function
                cout << "\n  Managing Savings Account..." << endl;
                manageAccount(saving_account);
                break;
            }
            case '3': { // Exit key
                cout << "  Exiting..." << endl;
                exitLoop = true;
                break;
            }
            default: {
                cout << "  Invalid choice. Please enter a number between 1 and 3." << endl;
            }
        }
    }
    // Prompt user to press any key to continue
    cout << "\n\n  Exiting program. Press any key to continue..." << endl;
    _getch(); // Halt execution until key entry

    return 0;
}
