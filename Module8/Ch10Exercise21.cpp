/*
* Student Name: Brittany Kyncl
* File Name: Ch10Exercise21.cpp
* Date: 5.3.24
* Description: 
*   This program is a simple banking account manager. It allows users to perform various operations 
*   such as deposit, withdrawal, change account type, view account balance, add interest, and display account information.
*   The program utilizes a BankAccount class which models individual bank accounts.
* Input:
*   - User input for menu options and transaction amounts.
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

using namespace std;

/* BankAccount class to model functionality and mangement of bank accounts
*  Inclusing depositing/withdrawing funds, applying interest, and displaying/changing acctount information and attributes.
*/
class BankAccount {
public:
    // Enum defining the account types
    enum AccountType {Checking, Savings};
private:
    string m_name;            // account holders name
    int m_acc_id;             // account number id
    AccountType m_acc_type;   // account type
    double m_balance;         // account balance
    double m_interest_rate;   // account interest rate
    static int m_next_acc_id; // static member variable for automatic acount number

public:
    // Default constructor initializes account with default values.
    BankAccount() : m_acc_id(m_next_acc_id++), m_acc_type(Checking), m_balance(0.0) {
        // Set the default interest rate based on the account type
        m_interest_rate = (m_acc_type == Checking) ? 0.0001 : 0.0035;
    }
    // Parameterized constructor creates an account with specified name, type, and initial balance.
    BankAccount(const string& name, AccountType acc_type, double balance) 
        : m_name(name), m_acc_id(m_next_acc_id++), m_acc_type(acc_type), m_balance(balance) {
            // Set the default interest rate based on the account type
            m_interest_rate = (acc_type == Checking) ? 0.0001 : 0.0035;
        }
    // Destructor performs any necessary cleanup (not needed in this case).
    ~BankAccount() {}

    // Getter methods to retrieve account info (name, account num, account type, balance, interest rate)
    string getAccountHolderName() const{ return m_name; }
    int getAccountNumber() const { return m_acc_id; }
    string getAccountType() const { return (m_acc_type == Checking ? "Checking" : "Savings"); }
    double getBalance() const { return m_balance; }
    double getInterestRate() const { return m_interest_rate; }
    
    // Setters methods to modify account information
    void setName(const string& name) { m_name = name; }
    void setInterestRate(double intr_rate = -1, bool use_default = true) {
        if (use_default) {
            // Set the default interest rate based on the account type
            m_interest_rate = (m_acc_type == Checking) ? 0.0001 : 0.0035;
        } else {
            // Set custom interest rate
            m_interest_rate = intr_rate;
        }
    }
    void setAccountType(AccountType acc_type) {
        m_acc_type = acc_type;
        // Set the default interest rate based on the new account type
        m_interest_rate = (acc_type == Checking) ? 0.0001 : 0.0035;
    }

    // Method to deposit into the account
    bool deposit(double amount) {
        if (amount > 0) {
            m_balance += amount;
            return true;
        } else {
            return false;
        }
    }

    // Method to withdraw from the account
    bool withdraw(double amount) {
        if (m_balance >= amount && amount > 0) {
            m_balance -= amount;
            return true;
        } else {
            return false;
        }
    }

    // Method to apply interest to account balance
    bool applyInterest () {
        double interest_earned = m_balance * m_interest_rate;
        return deposit(interest_earned);
    }

    // Method to display all account information to user
    void displayBankAccountInfo() const {
        cout << "\n  Account Number: " << m_acc_id << endl;
        cout << "  Account Holder: " << m_name<< endl;
        cout << "  Interest Rate: " << fixed << setprecision(2) << m_interest_rate * 100 << "%" << endl;
        cout << "  Account Type: " << (m_acc_type == Checking ? "Checking" : "Savings") << endl;
        cout << "  Balance: $" << fixed << setprecision(2) << m_balance << endl;
    }

};
// Static member initialization
int BankAccount::m_next_acc_id = 1000; // Initialize m_next_acc_id to 1000

// Function to view all accounts
void viewAllAccounts(const BankAccount accounts[], int size) {
    cout << "\n  Displaying All Accounts..." << endl;
    for (int i = 0; i < size; ++i) {
        accounts[i].displayBankAccountInfo();
    }
}
// Function to apply interest rate on all acounts
void applyInterestOnAll(BankAccount accounts[], int size) {
    int num_fails = 0; // Holds num of fails
    int failed_indicies[size]; // Array to hold indicies of failed updates
    double prev_balance, new_balance;

    cout << "\n  Applying Interest On All Accounts... " << endl;
    for (int i = 0; i < size; i++) {
        prev_balance = accounts[i].getBalance();
        if (!accounts[i].applyInterest()) {
            failed_indicies[num_fails++] = i; // Store index of failed attempt and increment num of fails
        } else {
            cout << "\n  Account ID: " << accounts[i].getAccountNumber() << endl;
            cout << "  Account Interest: " << accounts[i].getInterestRate() * 100 << "%" << endl;
            cout << "  Prev Balance: $" << prev_balance << endl;
            cout << "  New Balance: $" << accounts[i].getBalance() << endl;
        }
    }
    if (num_fails > 0) {
        cout << "  [UPDATE FAILURE] Interest could not be applied to the following accounts.." << endl;
        for (int j = 0; j < num_fails; j++) {
            // Print out accounts matching indicies of failed attempts
            cout << "  - Account Number: " << accounts[failed_indicies[j]].getAccountNumber() << endl;
        }
    } else {
        cout << "\n  [UPDATE SUCCESS] Interest Applied on all accounts..." << endl;
    }
}
// Function to prompt the user for an account name or number and find its index
int findVerifiedAccountIndex(const BankAccount accounts[], int size) {
    string account_name;
    int index = -1;
    while (index == -1) {
        cout << "\n  Please Enter your account name or account number: ";
        cin >> account_name; // Assuming the user enters the account name or account number
        for (int i = 0; i < size; i++) {
            // Search for match both by account name and account number
            if (accounts[i].getAccountHolderName() == account_name || to_string(accounts[i].getAccountNumber()) == account_name) {
                index = i;
            }
        }
        if (index == -1) {
            cout << "  Account not found. Please try again." << endl;
        }
    }
    return index;
}
// Function to manage individual accounts
void manageIndividualAccount(BankAccount accounts[], int size, int index) {
    char choice;
    double amount;
    int new_type;
    do {
        // Display customer menu options
        cout << "\n  Hello " << accounts[index].getAccountHolderName() << ", what can I help you with today?\n";
        cout << "  1. Deposit\n";
        cout << "  2. Withdraw\n";
        cout << "  3. Change Account type\n";
        cout << "  4. Display Account Balance\n";
        cout << "  5. Display Account Information\n";
        cout << "  6. Exit\n";
        cout << "  Enter your choice: ";
        cin >> choice;

        // Process customer's choice
        switch (choice) {
            case '1': {
                cout << "\n  Enter deposit amount: $";
                cin >> amount;
                // Deposit returns bool flag of transaction fail or success
                if (accounts[index].deposit(amount)) {
                    cout << "  [TRANSACTION SUCCESS]" << endl;
                } else {
                    cout << "  [TRANSACTION FAILED]: Cannot deposit negative funds or invalid amount" << endl;
                }
                cout << "  Account Balance: $" << fixed << setprecision(2) << accounts[index].getBalance() << endl;
                break;
            }
            case '2': {
                cout << "\n  Enter withdrawal amount: $";
                cin >> amount;
                // withdraw returns bool flag of transaction fail or success
                if (accounts[index].withdraw(amount)) {
                    cout << "  [TRANSACTION SUCCESS]" << endl;
                } else {
                    cout << "  [TRANSACTION FAILED]: Insufficient funds or invalid amount" << endl;
                }
                cout << "  Account Balance: $" << fixed << setprecision(2) << accounts[index].getBalance() << endl;
                break;
            }
            case '3': {
                // prompt for new account type
                cout << "\n  Enter new account type (0 for Checking, 1 for Savings): ";
                cin >> new_type;
                // Input validation for new_type for Enum AccountType (Checking or Savings)
                if (new_type == 0 || new_type == 1) {
                    accounts[index].setAccountType(BankAccount::AccountType(new_type));
                    cout << "  [UPDATE SUCCESS]" << endl;
                    accounts[index].displayBankAccountInfo();
                } else {
                    cout << "  Invalid account type." << endl;
                }
                break;
            }
            case '4':
                // Access and display account type and account balance
                cout << "\n  " << accounts[index].getAccountType() << " Account Balance: $" << fixed << setprecision(2) << accounts[index].getBalance() << endl;
                break;
            case '5':
                cout << "\n  Displaying Account Infomration...";
                accounts[index].displayBankAccountInfo();
                break;
            case '6':
                cout << "\n  Exiting customer menu..." << endl;
                break;
            default:
                cout << "  Invalid choice. Please try again." << endl;
        }
    } while (choice != '6');
}
int main() {
    // Imbue the output stream with the default locale to enable thousand separator formatting
    cout.imbue(locale(""));

    // Creating an array of 10 bankAccount objects
    BankAccount accounts[10] = {
        BankAccount("John", BankAccount::AccountType::Checking, 5630.50),
        BankAccount("Jane", BankAccount::AccountType::Checking, 2640.23),
        BankAccount("Gregson", BankAccount::AccountType::Savings, 25020.89),
        BankAccount("Tara", BankAccount::AccountType::Checking, 560.15),
        BankAccount("Kimothy", BankAccount::AccountType::Savings, 1502.75),
        BankAccount("Shandra", BankAccount::AccountType::Savings, 45000.67),
        BankAccount("Frog", BankAccount::AccountType::Checking, 2503.35),
        BankAccount("Sperika", BankAccount::AccountType::Savings, 3476.12),
        BankAccount("Mattison", BankAccount::AccountType::Savings, 2904.50),
        BankAccount("Quarks", BankAccount::AccountType::Checking, 165.25)
    };

    // Program Welcome Message
    cout << "\n\n  Welcome to Banking Account Manager" << endl;
    char menu_choice;
    int verified_index;
    do {
        // Display menu options before customer menu
        cout << "\n  Select an option:\n";
        cout << "  1. View All Accounts\n";
        cout << "  2. Apply Interest For All Accounts\n";
        cout << "  3. Manage Individual Account\n";
        cout << "  4. Exit\n";
        cout << "  Enter your choice: ";
        cin >> menu_choice;

        switch (menu_choice) {
            case '1':
                // View all accounts
                viewAllAccounts(accounts, 10);
                break;
            case '2': 
                // Apply interest rate to all accounts at once
                applyInterestOnAll(accounts,10);
                break;
            case '3':
                // Get returned verified index of user for individual operations
                verified_index = findVerifiedAccountIndex(accounts,10);
                // Pass user verified index to individual management function
                manageIndividualAccount(accounts,10,verified_index);
                break;
            case '4':
                break;
            default:
                cout << "  Invalid choice. Please try again." << endl;
        }
    } while (menu_choice != '4');

    // Prompt user to press any key to continue
    cout << "\n\n  Exiting program. Press any key to continue..." << endl;
    _getch(); // Halt execution until key entry

    return 0;
}
