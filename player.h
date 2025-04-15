#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include <string>
#include "cards.h"
using namespace std;

class Player 
{
private:
	vector<Card> hand;
	int value;
	int balance;


public:
	Player(int straightBalance = 100);
	void addCard(const Card& card);
	int getHandValue() const;
	string showHand() const;
	int getBalance() const;
	void updateBalance(int amount);

};

#endif