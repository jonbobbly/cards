#ifndef DECK_H
#define DECK_H

#include <deque>
#include "card.h"

class Deck
{
	public:
		Deck();
		void buildDeck(int Suits, int Values);

		Card draw();
		std::deque<Card> draw(int n);
		void shuffle();

		bool hasCards();
		int cardsLeft();

	private:
		int _index;
		std::deque<Card> _cards;

};

#endif
