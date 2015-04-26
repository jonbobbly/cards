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

	cp.loadFromString(long_suits, long_values);
	
	Playmat pm;
	pm.getDeck("deck").shuffle();

	std::string input;
	std::deque<std::string> cmd;
	std::string drawDeck = "deck";
	std::string placeDeck = "hand";

	while( input != "quit" ){
		std::cout << ":";
		getline(std::cin, input);
		cmd = split(input);
		
		if(cmd[0] == "d" || cmd[0] == "draw"){
			Card c;
			c = pm.getDeck(drawDeck).draw();
			if(c.isValid()){
				pm.getDeck(placeDeck).add(c);
				std::cout << cp.print(pm.getDeck(placeDeck).peek(1)) << std::endl;
			} else {
			 	std::cout << "Out of cards in " << drawDeck;
			}
		} else if (cmd[0] == "long"){
			cp.loadFromString(long_suits, long_values);
		} else if (cmd[0] == "list"){
			for(int i = 0; i < pm.numDecks(); i++){
				if(pm.getDeckName(i) == drawDeck){
					std::cout << "<";
				}
				if(pm.getDeckName(i) == placeDeck){
					std::cout << ">";
				}
				std::cout << pm.getDeckName(i) << " ";
				std::cout << pm.getDeck(i).cardsLeft() << std::endl;
			}
		} else if (cmd[0] == "short"){
			cp.loadFromString(std_suits, std_values);
		} else if (cmd[0] == "show" && cmd.size() > 1){
			printDeck(pm.getDeck(cmd[1]), cp);
		} else if (cmd[0] == "rebuild" && cmd.size() > 1){
			pm.getDeck(cmd[0]).buildDeck(4, 13);
		} else if (cmd[0] == "shuffle" && cmd.size() > 1){
			pm.getDeck(cmd[1]).shuffle();
		} else if (cmd[0] == "add" && cmd.size() > 1){
			pm.addDeck(cmd[1]);
		} else if (cmd[0] == "clear" && cmd.size() > 1){
			pm.getDeck(cmd[1]).clearDeck();
		} else if (cmd[0] == "put" && cmd.size() > 1){
			Card c;
			int card = atoi(cmd[1].c_str());
			c = pm.getDeck(placeDeck).take(card);
			pm.getDeck(drawDeck).add(c);
		} else if (cmd[0] == "set" && cmd.size() > 2){
			if(cmd[1] == "draw"){
				drawDeck = cmd[2];
			}
			if(cmd[1] == "put"){
				placeDeck = cmd[2];
			}
		}
	}

	return 0;
}
