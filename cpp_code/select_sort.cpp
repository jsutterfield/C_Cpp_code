//
// select_sort.cpp
//
// Created by James Sutterfield
// Last Modified: 9/16/13
//

#include <iostream>
#include <string>
using namespace std;

const int ARRAY_SIZE = 5;

void initializeArrays(string n[], int s[], int size);
void sort_scores(string n[], int s[], int size);
void print_scores(string n[], int s[], int size);

// Takes in 5 names and scores from the user, orders the scores
// using a selection sort, and prints the results to standard
// output.
int main() {

    string names[ARRAY_SIZE];
    int scores[ARRAY_SIZE];

    initializeArrays(names, scores, ARRAY_SIZE);
    sort_scores(names, scores, ARRAY_SIZE);
    print_scores(names, scores, ARRAY_SIZE);

    return 0;
}

/**
 * Prompts user to enter 5 names and scores
 *
 * Inputs: Name and Scores array, and the length of those arrays
           5 strings and 5 ints from standard input
 * Outputs: None
 */
void initializeArrays(string n[], int s[], int size)
{
    for (int i = 0; i < size; i++) {
        cout << "Enter the name for score #" << i + 1 << ": ";
        cin >> n[i];
        cout << "Enter the score for score #" << i + 1 << ": ";
        cin >> s[i];
    }
}

/**
 * Sorts the scores in descending order. Names in the associated
 * array are reordered along with the scores.
 *
 * Inputs: Name and Scores array, and the length of those arrays
 * Outputs: None
 */
void sort_scores(string n[], int s[], int size)
{
    int highest_val, highest_index;
    string temp_string;
    for (int i = 0; i < size - 1; i++) {
        highest_index = i;
        highest_val = s[i];
        for (int j = i + 1; j < size; j++)
            if (s[j] > highest_val) {
                highest_index = j;
                highest_val = s[j];
            }
        if (highest_index > i) {
            s[highest_index] = s[i];
            s[i] = highest_val;
            temp_string = n[i];
            n[i] = n[highest_index];
            n[highest_index] = temp_string;
        }
    }
}

/**
 * Prints the sorted scores and names
 *
 * Inputs: Name and Scores array, and the length of those arrays
 * Outputs: Sorted scores and names to standard output
 */
void print_scores(string n[], int s[], int size)
{
    cout << "Top Scorers:" << endl;
    for (int i = 0; i < size; i++)
        cout << n[i] << ": " << s[i] << endl;
}
