#include <vector>
#include <string>
#include <sstream>
#include <fstream>
#include "card.h"

std::string CardPrinter::print(Card c)
{
	return _values[c.v - 1] + _suits[c.s - 1];
}

void CardPrinter::loadFromFile(std::string file)
{
	std::string input;
	std::ifstream card_file(file.c_str());

	_values.clear();
	_suits.clear();
	
	getline(card_file, input);
	while( !input.empty() ){
		_suits.push_back(input);
		getline(card_file, input);
	}

	getline(card_file, input);
	while( !input.empty() ){
		_values.push_back(input);
		getline(card_file, input);
	}

	card_file.close();
}

void CardPrinter::loadFromString(std::string suits, std::string values)
{
	std::stringstream ss;
	std::string str;
	ss << suits;

	while( !ss.eof() ){
		getline(ss, str, ',');
		_suits.push_back(str);
	}

	ss.clear();
	ss << values;

	while( !ss.eof() ){
		getline(ss, str, ',');
		_values.push_back(str);
	}
}
