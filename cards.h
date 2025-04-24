#ifndef CARDS_H
#define CARDS_H

#include <string>
using namespace std;

class Card //represents the cards suit and ranks
{
private:
	string suit;
	string rank;

public:
	Card(string suit, string rank);
	
	int getValue() const; // getting value of card
	string toString() const; // returns readable string representaion 
};
#endif
