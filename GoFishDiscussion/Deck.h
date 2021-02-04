#pragma once
#include "Card.h"
#include <vector>
#include <algorithm> // For random_shuffle

using namespace std;

class Deck
{
private:
	vector<Card> cards;
	bool isEmpty;

	void Shuffle()
	{
		random_shuffle(cards.begin(), cards.end());
	}

public:
	// Create our Deck, acts as a stack, initialize from the beginning then pull from the top. 
	Deck()
	{
		// Number of faces
		for (int facesI = 0; facesI < 4; facesI++)
		{
			// Number of card values
			for (int valuesI = 0; valuesI < 13; valuesI++)
			{
				Card _card = Card(Card::Faces(facesI), valuesI);
				cards.push_back(_card);
			}
		}

		isEmpty = false;
	}

	Card Draw()
	{
		Card _card = cards.back();
		cards.pop_back();

		if (cards.size() == 0)
		{
			isEmpty = true;
		}

		return _card;
	}
};

