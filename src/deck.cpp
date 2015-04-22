#include <algorithm>
#include <deque>
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

void Deck::clearDeck()
{
	_cards.clear();
}

void Deck::shuffle()
{
	std::random_shuffle(_cards.begin(), _cards.end());
}

Card Deck::draw()
{
	if(hasCards()){
		Card c = _cards[0];
		_cards.pop_front();
		return c;
	}
	Card c;
	c.v = -1;
	return c;
}

Card Deck::peek(int n)
{
	if(n <= cardsLeft()){
		return _cards[n - 1];
	}
	Card c;
	c.v = -1;
	return c;
}

std::deque<Card> Deck::draw(int n)
{
	std::deque<Card> hand;
	for(int i; i < n; i++){
		if(hasCards()){
			hand.push_back(draw());
		}
	}
	return hand;
}

void Deck::add(Card c)
{
	_cards.push_front(c);
}

bool Deck::hasCards()
{
	return _cards.size() > 0;
}

int Deck::cardsLeft()
{
	return _cards.size();
}
