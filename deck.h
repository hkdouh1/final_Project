#ifndef DECK_H
#define DECK_H

#include <vector>
#include "cards.h"
using namespace std;

class Deck 
{ // managing the collection of cards
private:
	vector<Card> cards;
	const int RESHUFFLE_THRESHOLD = 100;

public:// constructors for shuffle and reshuffle and dealing
	Deck();
	void shuffle();
	Card dealCard();
	bool needsReshuffle() const;


};

#endif
