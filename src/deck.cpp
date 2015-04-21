#include <algorithm>
#include <vector>
#include <string>
#include "deck.h"

Deck::Deck()
{
	buildDeck(4, 13);
}

void Deck::buildDeck(int Suits, int Values)
{
	int curSuit;
	int curValue;
	Card c;

	_cards.clear();
	for(curSuit = 1; curSuit <= Suits; curSuit++){
		for(curValue = 1; curValue <= Values; curValue++){
			c.s = curSuit;
			c.v = curValue;
			_cards.push_back(c);
		}
	}
}

void Deck::shuffle()
{
	std::random_shuffle(_cards.begin(), _cards.end());
}

Card Deck::draw()
{
	if(_index > _cards.size()) _index = 0;
	return _cards[_index++];
}
