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
	std::string std_suits;
	std::string std_values;

	std_suits = "S,H,C,D";
	std_values = "A,2,3,4,5,6,7,8,9,T,J,Q,K";

	cp.loadFromString(std_suits, std_values);

	Deck d;
	d.shuffle();

	std::string input;

	while( input != "quit"){
		std::cout << "> ";
		getline(std::cin, input);
		if(input == "d"){
			std::cout << cp.print(d.draw()) << std::endl;
		}
	}

	return 0;
}
