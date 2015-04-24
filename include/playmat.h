#ifndef PLAYMAT_H
#define PLAYMAT_H

#include <deque>
#include <string>

#include "card.h"
#include "deck.h"

class Playmat {
	public:
		Playmat();

		void addDeck(std::string Name, Deck d);
		Card drawDeck(std::string Name);

	private:
		int findDeck(std::string Name);
		std::deque<Deck> _decks;
		std::deque<std::string> _deck_names;
};

#endif