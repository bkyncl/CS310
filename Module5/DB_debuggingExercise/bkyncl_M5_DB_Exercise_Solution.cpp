/*
* Student Name: Brittany Kyncl
* File Name: bkyncl_M5_DB_Exercise.cpp
* Date: 4.9.24
* Description: 
*   This the solution file to (bkyncl_M5_DB_Exercise.cpp) with 3 bugs fixed.
*   This program prompts user to enter a number and uses check_prime() to check if it is prime.
*   It then uses check_prime() to print all prime numbers up to 100.
* Input:
*   - An number to check if it is prime.
* Output:
*   - bool result if number is prime or not.
*   - All prime numbers up to 100.
*/

#include <iostream>
#include <conio.h>
#include <limits>
#include <cmath>
using namespace std;

/**
 * Function to check if a given number is prime
 * 
 * @param num The number to check
 * @return True if prime, False otherwise
*/
// FIX: Change return type from void to bool
bool check_prime(int num) {
    // We only need to check divisibility up to the square root of num
    int sqrtNum = sqrt(num);

    if (num <=1) { // Prime numbers are greater than 1
        return false; // Bug fix: Added return statement
    }

    // Check divisibility of num by numbers from 2 to sqrtNum
    for (int i=2; i <= sqrtNum; i++) {
        // If num is divisible by any number in the range, it is not prime
        if (num % i == 0) {
            return false; // Bug fix: Added return statement
        } 
    }

    // If num is not divisble by any number in the range, it is prime
    return true;
}
int main() {
    int userNum;

    // Prompt user to enter a number until a valid integer is provided
    do {
        cout << "\n  Enter a number to check if it is prime: ";
        if (cin >> userNum && cin.peek() == '\n') {
            break;    
        } else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        }
    } while (true);

    // Check if user input is prime using check_prime() and display result
    // NOTE: boolalpha manipulator is used to print boolean values as 'true' or 'false' instead of '1' or '0'
    cout << "\n  Is " << userNum << " prime: " << boolalpha << check_prime(userNum) << endl;

    // Display all prime numbers up to 100
    cout << "\n  Prime numbers up to 100..." << "\n  ";
    // Iterate through 2-100 and call check_prime(i) each iteration
    for (int i=2; i <= 100; i++) {
        if (check_prime(i)) { // FIX: Added missing parenthesis around conditional check
            cout << i << " "; // When i is prime it is displayed
        }
    }

    // Prompt user to press any key to continue program exit
    cout << "\n\n  Exiting program. Press any key to continue..." << endl;
    _getch(); // Halt execution until key entry

    return 0;
}