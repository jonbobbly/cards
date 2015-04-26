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
		std::deque<Card> draw(int n);
		Card peek(int n);
		void add(Card c);
		Card take(int i);

		void shuffle();

		bool hasCards();
		int cardsLeft();

	private:
		int _index;
		std::deque<Card> _cards;

};

#endif
