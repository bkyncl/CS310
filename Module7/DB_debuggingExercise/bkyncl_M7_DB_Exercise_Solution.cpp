/*
* Student Name: Brittany Kyncl
* File Name: bkyncl_M7_DB_Exercise_Solution.cpp
* Date: 4.23.24
* Description: 
*   This is the solution file to (bkyncl_M7_Exercise.cpp) with 3 bugs solved.
*   This program utilizes a two-dimensional array to generate and display a multiplication table.
*   Using nested loops to populate the array with products of corresponding row and column indices.
*   The multiplication table is then displayed to the user, who can input two numbers to retrieve the product from the table.
* Input:
*   - The user inputs two numbers between 1 and SIZE, where SIZE is a constant representing the dimensions of the multiplication table.
* Output:
*   - Prints the multiplication table
*   - Prints the product of the corresponding numbers in the multiplication table.
*/

#include <iostream>
#include <conio.h>
#include <limits>
using namespace std;

// Define constant size for 2D array
const int SIZE = 10;

/**
 * Function to print multiplication table
 * 
 * @param table: 2D array representing the multiplication table
 */
void printMultiplicationTable(int table[SIZE][SIZE]) {

    cout << "\n\t---------------- MULTIPLICATION TABLE ----------------" << endl;
    // Outer loop for each row
    for (int i = 0; i < SIZE; ++i) {            // FIX: Outer & inner loop conditions should use < instead of <=
        // Nested loop for each column          // WHY: <= was casuing the loops to iteratie one extra time leading
        for (int j = 0; j < SIZE; ++j) {        // to attempts to access elements outside the bounds of the array
            cout << table[i][j] << "\t"; 
        }
        cout << endl; // Move to new line after printing each row
    }
    cout << "\t------------------------------------------------------" << endl;
}
int main() {
    // Declare and Initialize 2D array using constant dimensions of SIZE by SIZE
    int multiplicationTable[SIZE][SIZE];
    // Varaibles to store user input
    int num1, num2;

    // Populate the multiplication table using nested for loop
    for (int i = 0; i < SIZE; ++i) { 
        for (int j = 0; j < SIZE; ++j) {  // FIX: Use j as inner loop variable
                                          // WHY: Using the same variable as the outer loop cuases confusion and incorrect behavior
                                          // when populating the 2D array using row and column indicies

            multiplicationTable[i][j] = (i + 1) * (j + 1); // FIX: Calculate and store the product of row i and column j
                                                           // WHY: i should represent row index and j for column index
        }
    }

    // Print the multiplication table
    printMultiplicationTable(multiplicationTable);

    cout << "\nEnter two numbers separated by spaces to multiply: ";
    // Check if extraction fails or input is out of range
    while (!(cin >> num1 >> num2) || num1 < 1 || num1 > SIZE || num2 < 1 || num2 > SIZE) {
        cout << "Invalid input! Please enter two integers between 1 and " << SIZE << ": ";
        cin.clear(); // Clear error state
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
    }
   
    // Print the product of the entered numbers by accessing the element in the 2D array at the indicies (num1-1) and (num2-1) 
    // -1 for zero indexing of the correct row and column of the 2D array
    cout << "The product: " << multiplicationTable[num1 - 1][num2 - 1] << endl;

    cout << "\nExiting program. Press any key to continue..." << endl;
    _getch(); // Halt execution until key entry

    return 0;
}