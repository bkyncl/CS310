// Author: Timothy Jelinek
// Date: 4/18/2024
// Bugs fixed by brittany kyncl 4.25.24

#include <iostream>
#include <conio.h>
 
using namespace std;



int main() {
    // declare array
    int numbers[6][2] = {
        {12, 48},
        {30, 15},
        {20, 25},
        {31, 21},
        {89, 98},
        {54, 62}
    };

    // This runs through the array and prints the numbers row by row
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 2; ++j) {          // FIX: added missing 'for' in inner for loop
            cout << "\t" << numbers[i][j];    // FIX: Typo mispelled numbers as nmbrs, trying to access unedefined array instead of the numbers arrray.
        }
        cout << endl; // FIX: Added missing 'cout << endl;' statement after inner loop to print each row of array on new line.
    }

    cout << "\nPress any key to exit the program.";
    _getch(); // pause the program so the user can see the output

    return 0;
}
