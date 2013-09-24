//
// blackjack.cpp
//
// Created by James Sutterfield
// Last Modified: 8/27/13
//

#include <iostream>
#include <stdlib.h>
using namespace std;

#define MIN_CARD 1
#define MAX_CARD 14
#define MAX_SCORE 21
#define FACECARD_THRESHOLD 10

typedef int card;
typedef int hand;

int play_game(void);
card get_card(void);
hand player_hits(hand player_hand);
hand dealer_hits(hand dealer_hand, card dealer_hide);
void print_hands(card player_first, card player_second, card dealer_show);
char play_again(void);

int main()
{
    char again = 'y';

    do {
        play_game();
    } while ((again = play_again()) == 'y');

    return 0;
}

/**
 * Simulates game of blackjack.
 * 
 * Inputs: None
 * Outputs: 0, however that value is largely meaningless. Just used to allow
 * early exit of the function if the player busts
 */
int play_game(void)
{
    hand player_hand, dealer_hand;
    card player_first, player_second, dealer_hide, dealer_show;

    player_hand = (player_first = get_card()) + (player_second = get_card());
    dealer_hand = (dealer_hide = get_card()) + (dealer_show = get_card());
    print_hands(player_first, player_second, dealer_show);
    player_hand = player_hits(player_hand);

    if (player_hand > MAX_SCORE) {
        cout << "BUST!" << endl;
        return 0;
    }

    dealer_hand = dealer_hits(dealer_hand, dealer_hide);

    if (dealer_hand == player_hand)
        cout << "Push." << endl;
    else if (player_hand > dealer_hand || dealer_hand > MAX_SCORE)
        cout << "You win!" << endl;
    else
        cout << "You lose..." << endl;
}

/**
 * Randomly pick a new card. Minimum card value is 1, Maximum is 14 (to account
 * for face cards). Any card value over 14 is returned as 10
 *
 * Inputs: None
 * Outputs: New card
 */
card get_card(void)
{
    card new_card;
    new_card = rand() % MAX_CARD + MIN_CARD;
    return (new_card < FACECARD_THRESHOLD) ? new_card : FACECARD_THRESHOLD;
}

/**
 * Displays the player's initial hand and the dealer's show card
 *
 * Inputs: Player's first 2 cards and dealer's 1 show card
 * Outputs: None
 */
void print_hands(card player_first, card player_second, card dealer_show)
{
    cout << "Your First cards: " << player_first << ", " << player_second << endl;
    cout << "Total: " << player_first + player_second << endl;
    cout << "Dealer show card: " << dealer_show << endl;
}

/**
 * Prompts user with whether they would like additional cards for their hand
 *
 * Inputs: Player's current hand
 * Outpts: Player's hand after additional cards have been added
 */
hand player_hits(hand player_hand)
{
    char resp = 'y';
    card hit_card;

    while (resp == 'y') {
        cout << "Do you want another card? (y/n): ";
        cin >> resp;
        if (resp == 'n')
            break;
        else if (resp != 'y') {
            cout << "Please enter only 'y' or 'n'" << endl;
            resp = 'y';
            continue;
        }
        player_hand += (hit_card = get_card());
        cout << "Card: " << hit_card << endl;
        cout << "Total: " << player_hand << endl;
        
        if (player_hand > MAX_SCORE)
            break;
    }
    return player_hand;
}

/**
 * Adds cards to dealer's hand until dealer's hand is greater than or equal
 * to 17
 *
 * Inputs: Dealer's current hand
 * Outputs: Dealer's hand after additionals cards have been added
 */
hand dealer_hits(hand dealer_hand, card dealer_hide)
{
    card hit_card;
    char resp;

    cout << "Dealer flips over hide card..." << endl;
    cout << "It's a " << dealer_hide << endl;
    cout << "Dealer Total: " << dealer_hand <<endl;
    while (dealer_hand < 17) {
        cout << "(c to continue) ";
        cin >> resp;
        cout << "Dealer hits..." << endl;
        dealer_hand += (hit_card = get_card());
        cout << "Card: " << hit_card << endl;
        cout << "Dealer Total: " << dealer_hand << endl;
    }

    return dealer_hand;
}

/** 
 * Prompts user with whether they would like to play again
 *
 * Inputs: None
 * Outputs: char 'y' for the affirmative, or 'n' for the negative
 */
char play_again(void)
{
    char again;
    while (true) {
        cout << "Would you like to play again? (y/n): " << endl;
        cin >> again;
        if (again == 'y' || again == 'n'){
            cout << endl;
            return again;
        }
        cout << "Please enter only 'y' or 'n'" << endl;
    }
}
