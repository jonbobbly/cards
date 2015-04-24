#include "playmat.h"

Playmat::Playmat()
{
	Deck d;
	_decks.push_back(d);
}

Deck& Playmat::getDeck(std::string Name)
{
	int i = findDeck(Name);
	return _decks[i];
}

int Playmat::findDeck(std::string Name)
{
	int i;
	for(i = 0; i <= _deck_names.size(); i++){
		if(_deck_names[i] == Name) break;
	}
	return i;
}

void Playmat::addDeck(std::string Name, Deck d)
{
	_decks.push_back(d);
	_deck_names.push_back(Name);
}
