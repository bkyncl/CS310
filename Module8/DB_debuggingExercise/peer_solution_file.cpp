// Author: Timothy Jelinek
// Date: 4/29/2024
// Description: This program states Justin's bowling shoe size, the syle of the shoes, the color of the bowling ball he uses, and the pattern of the bowling ball.
// Bugs solved by britt kyncl 5.4.24

#include <iostream>
#include <conio.h>
#include <string>
 
using namespace std;

class BowlingBall {
public:
    string color; // The color of the bowling ball
    string pattern; // The pattern of the bowling ball
};

class BowlingShoes { // FIX: Typo in class declaration changed 'lass' to 'class'
public:
    int size; // The size of the bowling shoes
    string style; // The style of the bowling shoes
};

int main() {

    // Create a BowlingBall object
    BowlingBall justinBall;
    justinBall.color = "blue"; // FIX: missing '.' after 'justinBall'
    justinBall.pattern = "striped";

    // Create a BowlingShoes object
    BowlingShoes justinShoes;
    justinShoes.size = 10;
    justinShoes.style = "glow-in-the-dark";

    // Print the size and style of the bowling shoes
    cout << "Justin has a " << justinBall.color << ", " << justinBall.pattern << " bowling ball." << endl;
    cout << "Justin has a size " << justinShoes.size << ", " << justinShoes.style << " pair of bowling shoes." << endl;
    
    cout << "\nPress any key to exit the program.";
    _getch(); // pause the program so the user can see the output

    return 0;
}