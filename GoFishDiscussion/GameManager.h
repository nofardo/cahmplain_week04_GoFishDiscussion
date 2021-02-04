#pragma once
#include "Deck.h"
#include "Player.h"
#include <vector>

class GameManager
{
private:
	Deck deck;
	vector<Player> players;
	bool gameOver;
	bool firstRound;

	void DealCards()
	{
		int cardsToDeal;
		
		if (players.size() == 2)
			cardsToDeal = 7;
		else
			cardsToDeal = 5;
		
		// Deal cards in a circle to players
		for (int i = 0; i < cardsToDeal; i++)
		{
			// Deal card number i to each player
			for (Player _player : players)
			{
				// Draw a card from the deck. 
				Card _card = deck.Draw();

				// Give card to the player. 
				_player.AddCard(_card);
			}
		}
	}

	void StartGameRounds()
	{
		while (gameOver == false)
		{
			// Set the current player
			Player currentPlayer = players.front();

			// Move that player to the back of the queue. 
			players.erase(players.begin());
			players.push_back(currentPlayer);

			// Check if user has cards to place down. 
			currentPlayer.CheckForFourOfAKind();

			// This should be in while loop (while player turn)
			// Choosed random player to ask for Card.

			// Choose random Card to ask for. 

			// Ask for Card (remove from target player)

			// If Vector of cards returned == 0
			// Draw card
			// Check for four of a kind
			// Check if player hand is empty or deck is empty (set gameOver = true)
			// Go to next turn. 


			// If not
			// Add vector of cards to hand. 
			// Check for four of a kind.
			// Check if target player hand is empty (Possible to take all of their cards if they only have one value)
			// Check if current player hand is empty. 
			// Restart at (while player turn) loop. 

		}

	}



	Player GetWinner()
	{
		// throw Not implemented.
		throw new exception("Not Implemented");
	}

public:
	GameManager(int numOfPlayers)
	{
		gameOver = false;
		firstRound = true;

		// Initialize the players and place them in a queue.
		for (int i = 0; i < numOfPlayers; i++)
		{
			// Create a named player (Player 1)
			Player _player("Player " + to_string(i+1));
			
			// Add player to our queue.
			players.push_back(_player);
		}

		// Initialize our deck (acts as a stack)
		deck = Deck::Deck();

		// Deal cards to Players
		DealCards();

		// Start the games rounds
		StartGameRounds();
	}

};

