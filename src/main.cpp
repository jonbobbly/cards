#include <iostream>
#include <string> 
#include <algorithm>
#include <ctime>
#include <cstdlib>

#include "card.h"
#include "deck.h"

int main(void)
{
	std::srand( std::time(0) );
	CardPrinter cp;
	std::string std_suits = "S,H,C,D";
	std::string std_values = "A,2,3,4,5,6,7,8,9,T,J,Q,K";

	std::string long_suits = " of Spades, of Hearts, of Clubs, of Diamonds";
	std::string long_values = "Ace,2,3,4,5,6,7,8,9,Ten,Jack,Queen,King";

	cp.loadFromString(std_suits, std_values);

	Deck d;
	Card c;
	d.shuffle();

	std::string input;

	while( input != "quit"){
		std::cout << "> ";
		getline(std::cin, input);
		if(input == "d"){
			std::cout << cp.print(d.draw()) << std::endl;
		} else if (input == "long"){
			cp.loadFromString(long_suits, long_values);
		} else if (input == "short"){
			cp.loadFromString(std_suits, std_values);
		}
	}

	return 0;
}
