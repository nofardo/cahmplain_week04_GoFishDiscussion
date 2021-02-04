#pragma once
#include <string>

class Card
{
public:
	enum Faces
	{
		HEARTS,
		DIAMONDS,
		SPADES,
		CLUBS
	};

	enum Names
	{
		Ace,
		Two,
		Three,
		Four,
		Five,
		Six,
		Seven,
		Eight,
		Nine,
		Ten,
		Jack,
		Queen,
		King
	};

	Card(Faces face, int value)
	{
		_face = face;
		_cardValue = value;
		_cardName = Names(value + 1);
	}

	int GetValue()
	{
		return _cardValue;
	}

	string GetFace()
	{
		return to_string(_face);
	}

	string GetCardFullName()
	{
		return to_string(_face) + " of " + to_string(_cardName);
	}

private:
	int _cardValue;
	Names _cardName;
	Faces _face;
};


