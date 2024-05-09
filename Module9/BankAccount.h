/*
* Student Name: Brittany Kyncl
* File Name: BankAccount.h
* Date: 5.9.24
* Description: 
*   This file defines a hierarchy of classes for managing bank accounts. 
*   The base class, BankAccount, provides attributes and functionality common to all types of bank accounts. 
*   Including account holder, account number, balance, deposit, withdrawal, interest posting, and account information display.
*   Derived classes CheckingAccount and SavingsAccount inherit from BankAccount and provide 
*   additional features specific to checking and savings accounts respectively, such as minimum balance requirements 
*   and service charges for checking accounts, checks, and interest rates for savings and checking accounts.
*/
#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include <iostream>
#include <string>
#include <iomanip>

// Base class BankAccount
class BankAccount {
protected:
    std::string m_name;            // Account holder's name
    int m_acc_id;                  // Account number id
    double m_balance;              // Account balance
    static int m_next_acc_id;      // Static member variable for automatic account number generation
public:
    BankAccount() : m_name(""), m_acc_id(m_next_acc_id++), m_balance(0.0) {}
    // Parameterized constructor
    BankAccount(const std::string& name, double balance) : m_name(name), m_acc_id(m_next_acc_id++), m_balance(balance){}

    // Setters and getters for account holder name, account number, and get balance
    void setAccountHolderName(const std::string& name) { m_name = name; }
    std::string getAccountHolderName() const { return m_name; }
    void setAccountNumber(double id) { m_acc_id = id; }
    int getAccountNumber() const { return m_acc_id; }
    double getBalance() const { return m_balance; }

    // Transaction methods
    virtual bool deposit(double amount) {
        if (amount > 0) {
            m_balance += amount;
            return true;
        } else {
            return false;
        }
    }
    virtual bool withdraw(double amount) = 0;
    virtual void postInterest() = 0;

    // Display method
    virtual void displayBankAccountInfo() const {
        std::cout << "\n  Account Number: " << m_acc_id << std::endl;
        std::cout << "  Account Holder: " << m_name << std::endl;
        std::cout << "  Balance: $" << std::fixed << std::setprecision(2) << m_balance << std::endl;
    }

};

// Static member initialization
int BankAccount::m_next_acc_id = 1000; // Initialize m_next_acc_id to 1000

// Derived Class CheckingAccount
class CheckingAccount : public BankAccount {
private:
    double m_interestRate;    // Interest rate for the checking account
    double m_minimumBalance;  // Minimum balance required for the checking account
    double m_serviceCharges;  // Service charges for the checking account
public:
    CheckingAccount() : m_interestRate(0.0), m_minimumBalance(0.0), m_serviceCharges(0.0) {}
    // Parameterized Constructor
    CheckingAccount(const std::string& name, double balance, double interestRate, double minimumBalance, double serviceCharges)
        : BankAccount(name, balance), m_interestRate(interestRate), m_minimumBalance(minimumBalance), m_serviceCharges(serviceCharges) {}

    // Setters and Getters for interest rate, minimum balance, and service charges
    void setInterestRate(double rate) { m_interestRate = rate; }
    double getInterestRate() const { return m_interestRate; }
    void setMinimumBalance(double minBalance) { m_minimumBalance = minBalance; }
    double getMinimumBalance() const { return m_minimumBalance; }
    void setServiceCharges(double charges) { m_serviceCharges = charges; }
    double getServiceCharges() const { return m_serviceCharges; }

    // Method to post interest to checking account
    void postInterest() override{
        double interest = getBalance() * m_interestRate; // Calculate interest
        if (deposit(interest)) {
            std::cout << "\n  Interest Applied: " << std::fixed << std::setprecision(2) << m_interestRate * 100 << "%" << std::endl;
        } else {
            std::cout << "  Error: Unable to post interest." << std::endl;
        }
    }

    // Method to check if balance is below minimum balance
    bool balanceBelowMinimum() const {
        return getBalance() < m_minimumBalance;
    }

    // Method to write a check
    bool writeCheck(double amount) {
        if (withdraw(amount)) {
            return true;
        } else {
            return false;
        }
    }
    // Method to withdraw specific for checking (if below min balance fee applied)
    bool withdraw(double amount) override {
        double totalAmount = amount; // Total amount to withraw
        double projectedBalance = getBalance() - totalAmount; // Projected balance after withdrawal

        // Check if the total amount is greater than the available balance or if the amount is negative
        if (totalAmount > getBalance() || totalAmount < 0) {
            return false;
        }
        
        // Check if the transaction would result in a balance below the minimum
        if (projectedBalance < m_minimumBalance) {
            // Add service charge to the total amount
            totalAmount += m_serviceCharges;
            
            // Check if the resulting balance would be negative after deducting the total amount
            if (projectedBalance - m_serviceCharges < 0) {
                std::cout << "  Withdrawal cannot be completed." << std::endl;
                std::cout << "  Requested withdrawal plus min balance service charge exceeds account balance." << std::endl;
                return false;
            }
            
            std::cout << "  Account below minimum balance of $" << m_minimumBalance << std::endl;
            std::cout << "  A service charge of $" << m_serviceCharges << " will be applied." << std::endl;
        }
        
        // update balance
        m_balance -= totalAmount;
        return true;
    }
    // Method to display CheckingAccount information
    void displayBankAccountInfo() const override{
        BankAccount::displayBankAccountInfo();
        std::cout << "  Account Type: Checking" << std::endl;
        std::cout << "  Interest Rate: " << std::fixed << std::setprecision(2) << m_interestRate * 100 << "%" << std::endl;
        std::cout << "  Minimum Balance: $" << m_minimumBalance << std::endl;
        std::cout << "  Service Charges: $" << m_serviceCharges << std::endl;
    }
};
// Derived Class SavingsAccount
class SavingsAccount : public BankAccount {
private:
    double m_interestRate; // Interest rate for the savings account
public:
    SavingsAccount() : m_interestRate(0.0) {}
    // Parameterized constructor for SavingsAccount
    SavingsAccount(const std::string& name, double balance, double interestRate)
        : BankAccount(name, balance), m_interestRate(interestRate) {}

    // Setters and getters for interest rate
    void setInterestRate(double rate) { m_interestRate = rate; }
    double getInterestRate() const { return m_interestRate; }

    // Method to post interest for SavingsAccount
    void postInterest() override{
        double interest = getBalance() * m_interestRate; // Calculate interest
        if (deposit(interest)) {
            std::cout << "\n  Interest Applied: " << std::fixed << std::setprecision(2) << m_interestRate * 100 << "%" << std::endl;
        } else {
            std::cout << "  Error: Unable to post interest." << std::endl;
        }
    }
    // Method to withdraw specific for savings account
    bool withdraw(double amount) override {
        if (amount <= getBalance() && amount > 0) {
            m_balance -= amount; // Update balance
            return true;
        } else {
            return false;
        }
    }
    // Method to display SavingsAccount information
    void displayBankAccountInfo() const override{
        BankAccount::displayBankAccountInfo();
        std::cout << "  Account Type: Savings" << std::endl;
        std::cout << "  Interest Rate: " << std::fixed << std::setprecision(2) << m_interestRate * 100 << "%" << std::endl;
    }
};
#endif // BANKACCOUNT_H
