/**
 * Student Name: Brittany Kyncl
 * File Name: Ch13Exercise17.cpp
 * Date: 5.25.24
 * Description: 
 *   This program demonstrates the usage of C++11 random number generation features
 *   to generate 25 random real numbers within a specified range. It utilizes the
 *   `<random>` and `<chrono>` libraries to ensure randomness and uniqueness of 
 *   generated numbers. The program prints the generated numbers to the console.
 * Output:
 *   - 25 random real numbers printed to the console
 */

#include <iostream>
#include <conio.h>
#include <random>
#include <chrono>

using namespace std;
/**
 * Generates and prints 25 random real numbers within the specified range of min and max.
 * 
 * @param eng The random number generator engine to use.
 * @param min The minimum value of the range for random numbers.
 * @param max The maximum value of the range for random numbers.
 * 
 * @return void
 */
void printRandom(default_random_engine& eng, double min, double max) {
    // Initialize a uniform distribution of randmon numbers generation in range min and max
    uniform_real_distribution<double> dist(min, max);
    
    // Generate and output 25 random real numbers
    cout << "\n  25 random real numbers between " << min << " and " << max << ":\n";
    for (int i = 0; i < 25; ++i) {
        // Generate a random number by calling the uniform distribution object with the random engine
        double num = dist(eng); // Returning a random number within the specified range      
        cout << "  " << num << "\t";
        if ((i + 1) % 5 == 0) { // Output a newline every 5 numbers
            cout << endl;
        }
    }
    cout << endl;
}

int main() {
    // Use chrono to generate a seed using system current time as source to ensure uniqueness
    unsigned seed = chrono::steady_clock::now().time_since_epoch().count();
    // Initialize random number engine and feed it the generated seed using sysems current time
    default_random_engine eng(seed);

    // Define the range for random numbers
    double min = 10.0;
    double max = 100.0;

    // Call the function to print 25 random real numbers three times to demonstrate random generation
    printRandom(eng, min, max);
    printRandom(eng, min, max);
    printRandom(eng, min, max);
    
    // Prompt user to press any key to continue
    cout << "  Exiting program. Press any key to continue..." << endl;
    _getch(); // Halt execution until key entry
    
    return 0;
}