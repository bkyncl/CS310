/*
* Student Name: Brittany Kyncl
* File Name: Ch08Exercise7.cpp
* Date: 4.26.24
* Description: 
*   This program calculates the winner of an election based on user input of candidate names and votes received.
* Input:
*   - Last name of five candidates
*   - Number of votes received by each candidate
* Output:
*   - Table displaying candidate names, votes received, and percentage of total votes
*   - Winner of the election
*/

#include <iostream>
#include <conio.h>
#include <string>
#include <limits>
#include <iomanip>

using namespace std;

// Max number of candidates in election
const int CAP = 5;

/**
 * Validates that the input string contains only letters and spaces.
 * 
 * @param str Input string to be validated
 * @return true if the string is valid, false otherwise
 */
bool validString(string& str) {
    // Check length
    if (str.length() == 0) {
        return false;
    }
    // Loop through each character in string
    for (char c : str) {
        // If a character is not a letter and not a space, return false
        if (!isalpha(c)) {
            return false;
        }
    }
    return true;
}
/**
 * Validates that input is only positive integer
 * 
 * @param input the input to be validated
 * @return true if the integer is valid, false otherwise
 */
bool validInt(int& input) {
    // Check if input stream has failed, input is negative, or next character is not newline
    if (cin.fail() || input < 0 || cin.peek() != '\n') {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear newline character from input buffer
        return false;
    } else {
        return true;
    }
}
/**
 * Calculates the total number of votes received.
 * 
 * @param votes_received An array containing the number of votes received by each candidate
 * @param CAP The capacity of the array
 * @return The total number of votes received
 */
int calculateTotalVotes(int votes_received[], int CAP) {
    int total_votes = 0;
    for (int i = 0; i < CAP; ++i) {
        total_votes += votes_received[i]; // Add number of votes from each candidate to total_votes
    }
    return total_votes;
}
/**
 * Calculates the percentage of total votes received by each candidate.
 * 
 * @param votes_received An array containing the number of votes received by each candidate
 * @param percentage_of_votes An array to store the percentage of total votes received by each candidate
 * @param total_votes The total number of votes received
 * @param CAP The capacity of the arrays
 */
void calculatePercentageOfVotes(int votes_received[], float percentage_of_votes[], int total_votes, int CAP) {
    for (int i = 0; i < CAP; ++i) {
        // Cast votes_received to float for accurate division
        percentage_of_votes[i] = (static_cast<float>(votes_received[i]) / total_votes) * 100.0;
    }
}
/**
 * Finds the winner of the election based on the number of votes received.
 * 
 * @param candidates An array containing the names of the candidates
 * @param votes_received An array containing the number of votes received by each candidate
 * @param CAP The capacity of the arrays
 * @return The name of the winner
 */
string findWinner(string candidates[], int votes_received[], int CAP) {
    int max_votes = votes_received[0];
    int winner_index = 0;

    for (int i = 1; i < CAP; ++i) {
        // If votes received by i greater than current max
        if (votes_received[i] > max_votes) {
            max_votes = votes_received[i]; // Update max_votes with new max (i)
            winner_index = i; // Update winner index
        }
    }
    return candidates[winner_index];
}
/**
 * Prints a table of candidate information (names, votes received, and % of total votes)
 * 
 * @param candidates An array containing the names of the candidates
 * @param votes_received An array containing the number of votes received by each candidate
 * @param percentage_of_votes An array containing the percentage of total votes received by each candidate
 * @param total_votes Total number of votes received in the election
 * @param CAP The capacity of the arrays
 */
void printCandidateVotesTable(string candidates[], int votes_received[], float percentage_of_votes[], int total_votes, int CAP) {
    // Table header
    cout << "\n  ---------------------------------------------------------" << endl;
    cout << left << setw(20) << "  Candidate" << setw(20) << "  Votes Received" << setw(20) << "  % of Total Votes" << endl;

    // Candidate info
    for (int i = 0; i < CAP; ++i) {         
        cout << "  " << left << setw(20) << candidates[i]
             << setw(20) << votes_received[i]
             << setw(20) << fixed << setprecision(2) << percentage_of_votes[i] << endl; 
    }
    cout << "  ---------------------------------------------------------" << endl;

    // Total votes after table footer
    cout << left << setw(20) << "  Total" << "  " << setw(20) << total_votes << endl;
}

int main() {
    // Imbue the output stream with the default locale to enable thousand separator formatting
    cout.imbue(locale(""));

    // Variable for program loop option
    char choice_loop;

    // Program Welcome Message
    cout << "\n\n  This program calculates the winner of an election." << endl;

    do {

        string candidates[CAP];             // Array to store candidate names
        int votes_received[CAP];            // Array to store votes received
        float percentage_of_votes[CAP];     // Array to store percentage of votes
       
        // Prompt user to input candidate information
        cout << "\n  Enter the last name of five candidates and the number of votes received by each..." << endl;
        
        // Loop for user input until CAP is reached
        for (int i = 0; i < CAP; ++i) {
            do {
                cout << "\n  Candidate " << (i + 1) << " last name: ";
                getline(cin, candidates[i]);
            } while (!validString(candidates[i])); // Loop while input is not valid string format

            do {
                cout << "  Votes received by " << candidates[i] << ": ";
                cin >> votes_received[i];  
            } while (!validInt(votes_received[i])); // Loop while input is not valid positive integer
            
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear newline character from input buffer
        }

        // Calculate total number of votes received in the election using calculateTotalVotes()
        int total_votes = calculateTotalVotes(votes_received, CAP);
        // Calculate the percentage of total votes received by each candidate using calculatePercentageOfVotes()
        calculatePercentageOfVotes(votes_received, percentage_of_votes, total_votes, CAP);
        // Print table format of all candidate information
        printCandidateVotesTable(candidates, votes_received, percentage_of_votes, total_votes, CAP);

        // Output the winner of the election using findWinner()
        cout << "\n  The winner of the election is: " << findWinner(candidates, votes_received, CAP) << endl;

        // Prompt user for input on running the program again
        cout << "\n  Do you want to calculate election results again? (Y/N): ";
        cin >> choice_loop;

        // Clear any remaining characters from the input stream
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    } while (choice_loop == 'Y' || choice_loop == 'y'); // Program loop will only exit if the user decides to quit
    
    // Prompt user to press any key to continue
    cout << "\n\n  Exiting program. Press any key to continue..." << endl;
    _getch(); // Halt execution until key entry

    return 0;
}