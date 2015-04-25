#include <iostream>
#include <string> 
#include <sstream>
#include <algorithm>
#include <deque>
#include <ctime>
#include <cstdlib>

#include "card.h"
#include "deck.h"
#include "playmat.h"

std::deque<std::string> split(const std::string &s){
	std::deque<std::string> tokens;
	std::stringstream ss(s);
	std::string item;
	while( getline(ss, item, ' ') ){
		if( !item.empty() ) tokens.push_back(item);
	}
	return tokens;
}

void printDeck(Deck d, CardPrinter cp) {
	for(int i = 1; i <= d.cardsLeft(); i++){
		std::cout << i << ": " << cp.print(d.peek(i)) << std::endl;
	}
}

int main(void)
{
	std::srand( std::time(0) );
	CardPrinter cp;

	std::string std_suits = "S,H,C,D";
	std::string std_values = "A,2,3,4,5,6,7,8,9,T,J,Q,K";

	std::string long_suits = " of Spades, of Hearts, of Clubs, of Diamonds";
	std::string long_values = "Ace,2,3,4,5,6,7,8,9,Ten,Jack,Queen,King";

	cp.loadFromString(std_suits, std_values);
	
	Playmat pm;
	pm.getDeck("deck").shuffle();

	std::string input;
	std::deque<std::string> cmd;
	std::string drawDeck = "deck";
	std::string placeDeck = "deck";

	while( input != "quit" ){
		std::cout << drawDeck << "(" << pm.getDeck(drawDeck).cardsLeft() << ")/";
		std::cout << placeDeck << "(" << pm.getDeck(placeDeck).cardsLeft() << ")/";
		std::cout << pm.getDeck("hand").cardsLeft() << "> ";
		getline(std::cin, input);
		cmd = split(input);
		
		if(cmd[0] == "d" || cmd[0] == "draw"){
			pm.getDeck("hand").add( pm.getDeck(drawDeck).draw() );
			std::cout << cp.print( pm.getDeck("hand").peek(1) ) << std::endl;
		} else if (cmd[0] == "long"){
			cp.loadFromString(long_suits, long_values);
		} else if (cmd[0] == "short"){
			cp.loadFromString(std_suits, std_values);
		} else if (cmd[0] == "show" && cmd.size() > 1){
			printDeck(pm.getDeck(cmd[1]), cp);
		} else if (cmd[0] == "rebuild" && cmd.size() > 1){
			pm.getDeck(cmd[0]).buildDeck(4, 13);
		} else if (cmd[0] == "shuffle" && cmd.size() > 1){
			pm.getDeck(cmd[1]).shuffle();
		}
	}

	return 0;
}
