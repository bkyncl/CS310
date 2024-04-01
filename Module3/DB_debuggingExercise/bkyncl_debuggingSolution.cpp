/*
* Student Name: Brittany Kyncl
* File Name: bkyncl_debuggingSolution.cpp
* Date: 3.27.24
* Description: 
*   This is a solution to the buggy program (bkyncl_debuggingExercise.cpp) with errors fixed.
*   This program takes in a student grade (double) and returns a letter grade and corresponding grade feedback.
*   Utilizing both if-else and switch statements to control flow based on conditions.
* Input:
*   - Student grade in percentage format (1-100)
* Output:
*   - Char letter grade based on grading scale
*   - String feedback based on letter grade
*/

#include <iostream>
#include <conio.h>
#include <limits>
using namespace std;

int main() {

    // Declare choice variable for do while loop
    char choice; // FIX: Change the data type of 'choice' variable to char
                // WHY: 'choice' variable is used to store a character representing the user's choice ('Y' or 'N')
                // Using int data type leads to loop condition never being met.

    // Program welcome message
    cout << "\n\n  Welcome to the grade checker program!" << endl;

    // Do while loop to re-start based on user input choice
    do {
        // Declare input variable for student percentage grade
        double studentGrade; // FIX: Move the declaration of 'studentGrade' variable above the prompt for user input.
                             // WHY: Declaring 'studentGrade' after the prompt results in undefined behavior as the variable
                             // is being used before it's declared.

        // Prompt user to enter in student's current grade
        cout << "\n  Enter student's grade in percentage format (0-100): ";

        // Validate input only numerical and between a specified range (1-100)
        while (!(cin >> studentGrade) || studentGrade < 0 || studentGrade > 100) {
            cout << "\n  Invalid input. Enter a number between 0-100: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        // Clear any remaining characters from the input stream
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // Declare output variables for determined char letter grade and string feedback
        char letterGrade;
        string performanceFeedback;

        // Output strings for identifying which selection control statement was used
        string ifElseIfElseSuggestion = "\n  The if-else-statement determined letter grade: ";
        string switchStatementSuggestion = "\n  The switch-statement determined grade feedback: ";
        
        // Display intial input to user
        cout << "\n  Entered percentage grade: " << studentGrade << "%" << endl;

        // Determine letter grade using if-else control statement based on studentGrade
        if (studentGrade >= 90) {
            letterGrade = 'A';
        } else if (studentGrade >= 80) {    //FIX: Change assignment statements to assign char to letterGrade instead of studentGrade
            letterGrade = 'B';              //WHY: Trying to assign a character literal directly to a double variable can cause compilation errors
        } else if (studentGrade >= 70) {    // or unpredictable behavior, as the double variable may now hold the ASCII value of the intended char 
            letterGrade = 'C';
        } else if (studentGrade >= 60) {
            letterGrade = 'D';
        } else {
            letterGrade = 'F';
        }
        // Display results of if-else selection control statement based on grading scale
        cout << ifElseIfElseSuggestion << letterGrade << endl;

        // Determine feedback using switch control statement based on letterGrade
        switch (letterGrade) { // FIX: Change switch condition to letterGrade instead of studentGrade
                               // WHY: Comparing a double (studentGrade) with a char causes a compilation error because they are not compatible for direct comparison.
            case 'A':
                performanceFeedback = "Congratulations! This grade is exceptional.";
                break;
            case 'B':
                performanceFeedback = "Well done! This grade is above average.";
                break;
            case 'C':
                performanceFeedback = "This grade meets standard requirements.";
                break;
            case 'D':
                performanceFeedback = "This grade is passing but there's room for improvement.";
                break;
            default:
                performanceFeedback = "Unfortunately, this is not a passing grade.";
                break;
        }
        // Display results of switch selection control statement based on letterGrade
        cout << switchStatementSuggestion << performanceFeedback << endl;

        // Prompt user if they want to enter another grade
        cout << "\n  Do you want to enter another grade? (Y/N): ";
        cin >> choice;

    } while (choice == 'Y' || choice == 'y'); // Continue loop if case insensitive y else exit

    // Prompt user to press any key to continue program exit
    cout << "\n\n  Exiting program. Press any key to continue..." << endl;
    _getch(); // Halt execution until key entry

    return 0;

}