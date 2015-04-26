#include "playmat.h"

Playmat::Playmat()
{
	Deck d;
	d.clearDeck();
	addDeck("hand", d);

	d.buildDeck(4, 13);
	addDeck("deck", d);
}

Deck& Playmat::getDeck(std::string Name)
{
	int i = findDeck(Name);
	return _decks[i];
}

Deck& Playmat::getDeck(int i)
{
	return _decks[i];
}

std::string Playmat::getDeckName(int i)
{
	return _deck_names[i];
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

void Playmat::renameDeck(std::string Old, std::string New)
{
	int i = findDeck(Old);
	_deck_names[i] = New;
}

void Playmat::eraseDeck(std::string Name)
{
	int i = findDeck(Name) - 1;
	_decks.erase(_decks.begin()+i);
	_deck_names.erase(_deck_names.begin()+i);
}

int Playmat::numDecks()
{
	return _decks.size();
}
