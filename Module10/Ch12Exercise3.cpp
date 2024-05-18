/**
 * Student Name: Brittany Kyncl
 * File Name: Ch12Exercise3.cpp
 * Date: 5.18.24
 * Description: 
 *   This program calculates the winner of an election based on user input.
 *   It utilizes a dynamic array (vector) to store candidate information (names, votes, percentage of votes).
 *   The candidate data is organized using a struct called Candidate. After collecting candidate information, 
 *   it calculates the total number of votes received and the percentage of total votes received by each candidate.
 *   Finally, it displays a table showing candidate names, votes received, percentage of votes, total votes, and then displays the winner (or winners in case of tie).
* Input:
*   - The number of candidates
*   - Last name of each of the candidates
*   - Number of votes received by each candidate
* Output:
*   - Table displaying candidate names, votes received, and percentage votes, total votes
*   - Winner of the election
*/

#include <iostream>
#include <conio.h>
#include <string>
#include <limits>
#include <iomanip>
#include <vector>
#include "ElectionFunctions.h"

using namespace std;

int main() {
    // Imbue the output stream with the default locale to enable thousand separator formatting
    cout.imbue(locale(""));

    // Variable for program loop option
    char choice_loop;

    // Program Welcome Message
    cout << "\n\n  This program calculates the winner of an election." << endl;

    do {
        int num_candidates;
        //Prompt user to enter number of candidates and store in num_candidates
        do {
            cout << "\n  Please enter the number of candidates: ";
            cin >> num_candidates;
        } while (!validInt(num_candidates) || num_candidates == 0); // Loop while input is not valid positive integer

        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear newline character from input buffer

        vector<Candidate> candidates;       // Dynamic array (vector) to store candidates (names, votes received, percentage of votes received) 
        candidates.reserve(num_candidates); // Preallocate memory based on user input for number of elements in candidates vector
       
        // Prompt user to input candidate information
        cout << "\n  Enter the last name and the number of votes received by each of the " << num_candidates << " candidates..." << endl;
        
        // Loop for user input until num_candidates is reached
        for (int i = 0; i < num_candidates; i++) {
            string name;
            int votes;
            do {
                cout << "\n  Candidate " << (i + 1) << " last name: ";
                getline(cin, name);
            } while (!validString(name)); // Loop while input is not valid string format

            do {
                cout << "  Votes received by " << name << ": ";
                cin >> votes;  
            } while (!validInt(votes)); // Loop while input is not valid positive integer
            
            // Use emplace_back to directly construct a Candidate object in place at the end of the candidates vector
            // Passing user entered name and votes as constructor arguments
            candidates.emplace_back(name, votes);
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear newline character from input buffer
        }

        // Calculate total number of votes received in the election using calculateTotalVotes()
        int total_votes = calculateTotalVotes(candidates);
        // Calculate the percentage of total votes received by each candidate using calculatePercentageOfVotes()
        calculatePercentageOfVotes(candidates, total_votes);
        // Print table format of all candidate and election information
        printCandidateVotesTable(candidates, total_votes);

        // Store returned index/indices from findWinnerIndices() in winner_indicies vector
        vector<int> winner_indices = findWinnerIndices(candidates);

        // If winner_indices contians only 1 index then single winner result
        if (winner_indices.size() == 1) {
            // Retrieve name of winner using first index and display
            int winner_index = winner_indices[0];
            cout << "\n  The winner of the election is: " << candidates[winner_index].name << endl;
        } else { 
            // If multiple indices in vector then tie result
            cout << "\n  There is a tie between the following candidates: \n";
            // Iterate through each index in winner_indices and display winner name
            for (int winner : winner_indices) {
                cout << "  - " << candidates[winner].name << endl;
            }
        }

        // Prompt user for input on running the program again
        cout << "\n  Do you want to calculate election results again? (Y/N): ";
        cin >> choice_loop;

        // Clear the candidates vector, winner_indices vector, and input buffer before the loop repeats
        candidates.clear();
        winner_indices.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    } while (choice_loop == 'Y' || choice_loop == 'y'); // Program loop will only exit if the user decides to quit
    
    // Prompt user to press any key to continue
    cout << "\n\n  Exiting program. Press any key to continue..." << endl;
    _getch(); // Halt execution until key entry

    return 0;
}