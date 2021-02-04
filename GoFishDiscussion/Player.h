#pragma once
#include <vector>
#include <iostream>
#include "Card.h"

using namespace std;

class Player
{

private:
	vector<Card> hand;
	string name;
	vector<Card> fourOfAKindPile;

	void MoveFourOfAKind(int position)
	{
		// No need to worry about i
		// As we erase from hand vector,
		// The next card will we need to move goes to the current position. 
		for (int i = position; i < position + 4; i++)
		{
			fourOfAKindPile.push_back(hand[position]);
			hand.erase(hand.begin() + position);
		}
	}

public:
	Player(string name)
	{
		this->name = name;
	}

	// Display all cards in Hand. 
	void DisplayHand()
	{
		for (Card card : hand)
		{
			cout << card.GetCardFullName() << " ";
		}

		// formatting
		cout << endl;
	}

	// Maintain sort through modified insertion sort.
	// This sorts as cards come in to the deck. 
	// That way we don't need to sort our entire hand when adding a single card. 
	// (7 elements every time vs 1 element at a time)
	void AddCard(Card _card)
	{
		hand.push_back(_card);

		int in;

		int out = hand.size() - 1;

		// Start insertion sort at the end of the hand as we know
		// that the hand is already sorted as cards come in. 
		// (-2) due to -1 being the end of the hand index and 
		// -1 more due to us inserting the unsorted new card already. 
		for (int out = hand.size() - 2; out < hand.size(); out++)
		{
			Card _tmpCard = hand[out];
			in = out;

			// Start from the sorted side and shift elements to the right
			// as we search for where our card should go. 
			// Upon exiting this loop we will have found where the card should go. 
			while (in > 0 && hand[in - 1].GetValue() >= _tmpCard.GetValue())
			{
				// Shift card to the right. 
				hand[in] = hand[in - 1];

				// Decement in so we can scan card to the left. 
				in--;
			}

			// Insert our card into it's proper place. 
			hand[in] = _tmpCard;
		}
	}

	void CheckForFourOfAKind()
	{
		int previousCardValue = hand.back().GetValue();
		//int cardValue;
		//int previousCardValue;
		int numOfCardValue = 1;

		// Reverse loop as we may remove cards 
		// don't want to reduce the size of the vector
		// after we have told our loop to continue through the vector size. 
		// -2 (-1 for index) (-1 as we can skip check on first card since it's initialized above.)
		for (int i = hand.size() - 2; i >= 0; i--)
		{
			if (hand[i].GetValue() == previousCardValue)
			{
				numOfCardValue++;

				// Check if we have four of a kind. 
				if (numOfCardValue == 4)
				{
					//previousCardValue = hand[i].GetValue();

					// Means we have four of a kind from this position to position+3
					// This function will move those at (i) from our hand to the 4 of a kind pile. 
					MoveFourOfAKind(i);
					
					// Reset the number of cards. (0 is only after we place a 4 of a kind down)
					numOfCardValue = 0;

					// Continue to next (left) card. 
					continue;
				}
			}
			else 
			{
				// Card is not the same as previous so reset this to 1 (different than 0 above)
				numOfCardValue = 1;

				// Set the previous card before we move on. 
				previousCardValue = hand[i].GetValue();

				// Continue
				continue;
			}
		}
	}
};

