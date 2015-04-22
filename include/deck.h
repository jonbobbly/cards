#ifndef DECK_H
#define DECK_H

#include <deque>
#include "card.h"

class Deck
{
	public:
		Deck();
		void buildDeck(int Suits, int Values);
		void clearDeck();

		Card draw();
		Card peek(int n);
		std::deque<Card> draw(int n);
		void add(Card c);

		void shuffle();

		bool hasCards();
		int cardsLeft();

	private:
		int _index;
		std::deque<Card> _cards;

};

#endif
