#ifndef BLACKJACK_H
#define BLACKJACK_H
#include "player.h"
#include "deck.h"
using namespace std;
class BlackJack 
{// managing the game logic

private:
	Deck deck; //Deck Object and reference to player and dealer
	Player &player;
	Player &dealer;

public:
	BlackJack(Player& dealer, Player& player); // initilizes the game to the player and dealer

	// constructors 
	void playerHand() const;
//Day 8
	void playerTurn();
	void dealerTurn();
//-----

	void dealerHand(bool Reveal) const;
	void playRound();
	void reset();
	void dealFirstCards();
	void reshuffle();

//Day 8
	void whoWon();
	void adjust(int outcome);
	bool checkGame(const Player& player) const;
//-----

//day 9
	bool anotherRound();
	int getChoice(); 
//-----
};
#endif
