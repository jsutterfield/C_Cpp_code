//
// poker_hand.cpp
//
// Created by James Sutterfield
// Last Modified: 9/8/13
//

#include <iostream>
using namespace std;

const int HAND_SIZE = 5;

bool  containsPair(int hand[]);
bool  containsTwoPair(int hand[]);
bool  containsThreeOfaKind(int hand[]);
bool  containsStraight(int hand[]);
bool  containsFullHouse(int hand[]);
bool  containsFourOfaKind(int hand[]);
void  get_hand(int hand[]);
void  sort_hand(int hand[]);

/**
 * Simulates a hand of poker. Prompts user to enter 5 cards and displays the
 * most valuable hand possible. 
 *
 * Please note: the order in which the hand is evaluated is important. It 
 * starts with the highest possible hand and works its way down, checking each 
 * possible hand with a separate function. Because of this, changing the order in 
 * which the hand is evaluated does not ensure the program will print correct 
 * results (eg, containsTwoPair needs to be run before containsPair. 
 * ContainsPair only checks if one pair is present and will return true, even
 * if there are actually two pairs). Also, 2 of the functions, containsStraight
 * and containsFullHouse, rely on the hand being sorted, which is accomplished
 * before it is checked using the sort_hand function
 *
 * Inputs: 5 integers from standard input which make up a poker hand
 * Ouputs: The best possible poker hand from that hand
 */
main()
{
    int hand[HAND_SIZE];

    get_hand(hand);
    sort_hand(hand);

    if (containsFourOfaKind(hand))
        cout << "Four of a kind!";
    else if (containsFullHouse(hand))
        cout << "Full House!";
    else if (containsStraight(hand))
        cout << "Straight!";
    else if (containsThreeOfaKind(hand))
        cout << "Three of a kind!";
    else if (containsTwoPair(hand))
        cout << "Two Pair!";
    else if (containsPair(hand))
        cout << "Pair!";
    else
        cout << "High Card!";

    cout << endl;
}

/**
 * Prompts user to enter 5 ints which comprise the poker hand.
 *
 * Inputs: 5 ints from standard input
 * Outputs: None
 */
void get_hand(int hand[])
{
    cout << "Enter five numeric cards, no face cards. Use 2 - 9" << endl;
    for (int i = 0; i < HAND_SIZE; i++) {
        cout << "Card " << i + 1 << ": ";
        cin >> hand[i];
    }
}

/**
 * Sorts hand in ascending order.
 *
 * Inputs: Integer array (the hand)
 * Ouputs: None
 */
void sort_hand(int hand[])
{
    int temp_card;
    for (int i = 0; i < HAND_SIZE - 1; i++)
        for (int j = i + 1; j < HAND_SIZE; j++)
            if (hand[i] > hand[j]) {
                temp_card = hand[j];
                hand[j] = hand[i];
                hand[i] = temp_card;
            }
}

/**
 * Checks if the hand contains four of a kind.
 *
 * Inputs: Integer array (the hand)
 * Ouputs: Boolean
 */
bool  containsFourOfaKind(int hand[])
{
    int card_count = 1;
    for (int i = 0; i < 2; i++, card_count = 1)
        for (int j = i + 1; j < HAND_SIZE; j++) {
            if (hand[j] == hand[i])
                card_count++;
            if (card_count == 4)
                return true;
        }
    return false;
}

/**
 * Checks if the hand contains a full house.
 *
 * Inputs: integer array (the hand)
 * Ouputs: Boolean
 */
bool  containsFullHouse(int hand[])
{
    if (hand[0] == hand[1] && hand[2] == hand[3] && hand[3] == hand[4])
        return true;
    else if (hand[0] == hand[1] && hand[1] == hand[2] && hand[3] == hand[4])
        return true;
    return false;
}

/**
 * Checks if the hand contains a straight.
 *
 * Inputs: integer array (the hand)
 * Ouputs: Boolean
 */
bool  containsStraight(int hand[])
{
    for (int i = 0; i < HAND_SIZE -1; i++)
        if (hand[i] != hand[i+1] - 1)
            return false;
    return true;
}

/**
 * Checks if the hand contains three of a kind.
 *
 * Inputs: integer array (the hand)
 * Ouputs: Boolean
 */
bool  containsThreeOfaKind(int hand[])
{
    int card_count = 1;
    for (int i = 0; i < 3; i++, card_count = 1)
        for (int j = i + 1; j < HAND_SIZE; j++) {
            if (hand[j] == hand[i])
                card_count++;
            if (card_count == 3)
                return true;
        }
    return false;
}

/**
 * Checks if the hand contains two pair.
 *
 * Inputs: integer array (the hand)
 * Ouputs: Boolean
 */
bool  containsTwoPair(int hand[])
{
    bool pair1 = false;
    bool pair2 = false;

    for (int i = 0; i < HAND_SIZE -1; i++)
        for (int j = i + 1; j < HAND_SIZE; j++){
            if (hand[i] == hand[j]) {
                if (!pair1)
                    pair1 = true;
                else
                    pair2 = true;
                break;
            }
        }
    return pair1 && pair2;
}

/**
 * Checks if the hand contains a pair.
 *
 * Inputs: integer array (the hand)
 * Ouputs: Boolean
 */
bool  containsPair(int hand[])
{
    for (int i = 0; i < HAND_SIZE -1; i++)
        for (int j = i + 1; j < HAND_SIZE; j++)
            if (hand[i] == hand[j])
                return true;
    return false;
}
