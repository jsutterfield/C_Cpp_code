//
// guessing_game.cpp
//
// Created by James Sutterfield
// Last Modified: 9/3/13
//

#include <iostream>
using namespace std;

void playOneGame(void);
char getUserResponseToGuess(int guess);
int getMidpoint(int low, int high);
bool shouldPlayAgain(void);

int main()
{
    do {
        playOneGame();
    } while (shouldPlayAgain());
}

/**
 * Plays one Guessing game
 * 
 * Inputs: None
 * Outputs: None
 */
void playOneGame(void)
{
    int guess;
    int low = 1; // initialize to lowest possible guess
    int high = 100; // initialize to highest possible guess
    char response;
    cout << "Please think of a number between 1 and 100" << endl;
    cout << "(c to continue) ";
    cin >> response;
    guess = getMidpoint(low, high);
    while ((response = getUserResponseToGuess(guess)) != 'c') {
        if (response == 'h')
            low = guess + 1;
        else
            high = guess - 1;
        guess = getMidpoint(low, high);
    }
    cout << "Your number was " << guess << "!" << endl;
}

/**
 * Calculates and returns the midpoint between two numbers
 *
 * Inputs: Low number, high number
 * Outputs: Midpoint between low and high (if no exact midpoint, it will return
 * the lower of the two options
 */
int getMidpoint(int low, int high)
{
    int mid;
    if (low == high)
        mid = low;
    else
        mid = low + ((high - low) / 2);
    return mid;
}

/**
 * Prompts user if they would like to play the game again
 *
 * Inputs: None
 * Outputs: 'y' for yes, or 'n' for no
 */
bool shouldPlayAgain(void)
{
    char response;
    while (true) {
        cout << "Would you like to play again? (y/n): " << endl;
        cin >> response;
        if (response == 'y') 
            return true;
        else if (response == 'n')
            return false;
        cout << "Please enter only 'y' or 'n'" << endl;
    }
}

/**
 * Asks user if the current guess is the number they are thinking of, retrieves
 * their response.
 *
 * Inputs: Current guess
 * Ouputs: 'c' for correct, 'h' for their number is higher, 'l' for their number
 * is lower
 */
char getUserResponseToGuess(int guess)
{
    char response;
    while (true) {
        cout << "Is it " << guess << "? (h/l/c): " << endl; 
        cin >> response;
        if (response == 'h' || response == 'l' || response == 'c')
            return response;
        cout << "Please enter only 'h', 'l', or 'c'" << endl;
    }
}
