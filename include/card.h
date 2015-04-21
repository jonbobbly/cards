#ifndef CARD_H
#define CARD_H

#include <vector>
#include <string>

class Card
{
	public:
		int v; //value
		int s; //suit
};

class CardPrinter
{
	public:
		std::string print(Card c);
		void loadFromFile(std::string file);
		void loadFromString(std::string suits, std::string values);

	private:
		std::vector<std::string> _values;
		std::vector<std::string> _suits;
};

#endif
