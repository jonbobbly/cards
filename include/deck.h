#ifndef DECK_H
#define DECK_H

#include <vector>
#include "card.h"

class Deck
{
	public:
		Deck();
		void buildDeck(int Suits, int Values);

		Card draw();
		std::vector<Card> draw(int n);
		void shuffle();

		bool hasCards();
		int cardsLeft();

	private:
		int _index;
		std::vector<Card> _cards;

};

#endif
