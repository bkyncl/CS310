/*
* Student Name: Brittany Kyncl
* File Name: ElectionFunctions_H
* Date: 5.18.24
* Description: 
*   This file contains functions for handling election data. It defines a struct Candidate to represent individual candidates, 
*   along with functions for validating input, calculating total votes, calculating percentage of votes, finding the winner of the election,
*   handling ties, and printing candidate information.
*/
#ifndef ELECTIONFUNCTIONS_H
#define ELECTIONFUNCTIONS_H
#include <iostream>
#include <string>
#include <iomanip>
#include <limits>
#include <vector>

using namespace std;

// Define a struct to represent a candidate
struct Candidate {
    string name;        // Name of the candidate
    int votes;          // Number of votes received by the candidate
    float percentage;   // Percentage of total votes received by the candidate

    // Constructor to initalize the Candidate struct
    Candidate(const string& name, int votes = 0, float percentage = 0.0) : name(name), votes(votes), percentage(percentage) {}
};
/**
 * Validates that the input string contains only letters and spaces.
 * 
 * @param str Input string to be validated
 * @return true if the string is valid, false otherwise
 */
bool validString(string& str) {
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
 * Prints a table of all candidate information (names, votes received, and % of total votes) as well as total votes in election
 * 
 * @param candidates A vector containing Candidate structs representing all candidates in the election
 * @param total_votes Total number of votes received in the election
 */
void printCandidateVotesTable(const vector<Candidate>& candidates, int total_votes) {
    // Table header
    cout << "\n  ---------------------------------------------------------" << endl;
    cout << left << setw(20) << "  Candidate" << setw(20) << "  Votes Received" << setw(20) << "  % of Total Votes" << endl;

    // Iterate through each element in vector and print candidate info
    for (const Candidate& candidate : candidates) {         
        cout << "  " << left << setw(20) << candidate.name
             << setw(20) << candidate.votes
             << setw(20) << fixed << setprecision(2) << candidate.percentage << endl; 
    }
    cout << "  ---------------------------------------------------------" << endl;

    // Total votes after table footer
    cout << left << setw(20) << "  Total" << "  " << setw(20) << total_votes << endl;
}
/**
 * Calculates the total number of votes received by all candidates in election
 * 
 * @param candidates A vector containing Candidate structs representing all candidates in the election
 * @return The total number of votes received
 */
int calculateTotalVotes(const vector<Candidate>& candidates) {
    // Initialize a variable to hold the total number of votes
    int total_votes = 0;
    // Iterate over each candidate in the candidates vector
    for (const Candidate& candidate : candidates) {
        total_votes += candidate.votes; // Add votes from current candidate to total_votes
    }
    // Retur the calculated number of total votes received in election
    return total_votes;
}
/**
 * Calculates the percentage of total votes received by each candidate and updates
 * the percentage member variable of each Candidate object in the candidates vector.
 * 
 * @param candidates A vector containing Candidate structs representing all candidates in the election
 * @param total_votes The total number of votes received
 */
void calculatePercentageOfVotes(vector<Candidate>& candidates, int total_votes) {
    // Iterate over each candidate in the candidates vector
    for (Candidate& candidate : candidates) {
        // Calculate the percentage of votes received by the candidate relative to the total votes
        // Update the percentage member variable of the current candidate object
        candidate.percentage = (static_cast<float>(candidate.votes) / total_votes) * 100.0; 
    }
}
/**
 * Finds the index or indices of the winner(s) of the election based on the number of votes received.
 * NOTE: Modified from original to handle and return elections that result in a tie.
 * 
 * @param candidates A vector containing Candidate structs representing all candidates in the election
 * @return A vector of indices representing the winner(s) of the election. If there is a tie, all tied indices are returned.
 */
vector<size_t> findWinnerIndices(const vector<Candidate>& candidates) {
    vector<size_t> winners_indices; // Vector to store indices of the winner(s)
    int max_votes = 0; // Variable to store the maximum number of votes

    // Find the maximum number of votes
    for (const Candidate& candidate : candidates) {
        // Update max_votes to store returned maximum value of votes
        max_votes = max(max_votes, candidate.votes);
    }

    // Find the indices of the candidates with the maximum number of votes (possible winners)
    for (size_t i = 0; i < candidates.size(); i++) {
        if (candidates[i].votes == max_votes) {
            winners_indices.push_back(i); // Add index of candidate with maximum votes to winners_indices
        }
    }

    return winners_indices;
}
/**
 * Finds the index of the winner of the election based on the number of votes received.
 * NOTE: Original version of function to find election winner
 * 
 * @param candidates A vector containing Candidate structs representing all candidates in the election
 * @return The index of the winning candidate
 */
size_t findWinnerIndex(const vector<Candidate>& candidates) {
    size_t winner_index = 0; // Initialize the index of the winner to the first candidate

    // Comparisons of winnder_index with other candidates start from second candidate (index 1) onwards
    for (size_t i = 1; i < candidates.size(); ++i) { 
        // Check if the current candidate has more votes than the current winner
        if (candidates[i].votes > candidates[winner_index].votes) {
            // Update the index of the winner
            winner_index = i;
        }
    }
    // Return the index of the winning candidate
    return winner_index;
}
#endif // ELECTIONFUNCTIONS_H
