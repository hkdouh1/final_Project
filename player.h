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
	void clearHand(); // missed this when being used in BlackJackSim.cpp, needed to define it in player.h 
	int getHandValue() const;
	string showHand() const;
	int getBalance() const;
	void updateBalance(int amount);
	bool isLose() const;

	Card getCardAt(int index) const;

	const vector<Card>& getHand() const;
};

#endif
