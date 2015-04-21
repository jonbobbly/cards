#ifndef CARD_H
#define CARD_H

#include <deque>
#include <string>

class Card
{
	public:
		int v; //value
		int s; //suit

		bool isValid();
};

class CardPrinter
{
	public:
		std::string print(Card c);
		void loadFromFile(std::string file);
		void loadFromString(std::string suits, std::string values);

	private:
		std::deque<std::string> _values;
		std::deque<std::string> _suits;
};

#endif
