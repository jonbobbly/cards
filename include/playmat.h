#ifndef PLAYMAT_H
#define PLAYMAT_H

#include <deque>
#include <string>

#include "card.h"
#include "deck.h"

class Playmat {
	public:
		Playmat();

		void addDeck(std::string Name);
		void addDeck(std::string Name, Deck d);
		Deck& getDeck(std::string Name);
		Deck& getDeck(int i);
		std::string getDeckName(int i);

		void renameDeck(std::string Old, std::string New);
		void eraseDeck(std::string Name);
		int numDecks();

	private:
		int findDeck(std::string Name);
		std::deque<Deck> _decks;
		std::deque<std::string> _deck_names;
};

#endif
