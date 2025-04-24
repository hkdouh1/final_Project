#include <iostream>
#include <string>
#include "BlackJack.h"

using namespace std;

BlackJack::BlackJack(Player& dealer, Player& player) : dealer(dealer), player(player) {}

void BlackJack::playerHand() const {
	cout << "This is your hand: " << endl;
	cout << player.showHand();
	cout << "Total: " << player.getHandValue() << endl << endl;

}

void BlackJack::dealerHand(bool Reveal) const {
	cout << "This is the Dealer's Hand: " << endl;
	if (Reveal) {
		cout << dealer.showHand();
		cout << "Total: " << dealer.getHandValue() << endl << endl;
	}
	else {
		cout << dealer.getCardAt(0).toString() << endl;
		cout << "There is one card that is hidden..." << endl;
	}
}

void BlackJack::playRound() {

	reset();
	dealFirstCards();
	playerHand();
	dealerHand(false);

	//need to add checkGame if Blackjack or not 
	if (checkGame(player)) {
		cout << "Blackjack!!! You Win!!!" << endl;
		adjust(1);
		return;
	}

	playerTurn();
	/*
	* this doesnt work. i always need to see who wins at the end of the round
	!player.isLose() ? dealerTurn() : whoWon();
	*/

	//correct way check if player !> 21 and shows who won either way
	if (!player.isLose()) {
		dealerTurn();
	}

	whoWon();
}

void BlackJack::reset() {

	dealer.clearHand();
	player.clearHand();

}

void BlackJack::dealFirstCards() {
	


	dealer.addCard(deck.dealCard());
	player.addCard(deck.dealCard());
	dealer.addCard(deck.dealCard());
	player.addCard(deck.dealCard());
	reshuffle();

}

void BlackJack::reshuffle() {
	if (deck.needsReshuffle()) {
		cout << "The deck is being reshuffled..." << endl;
		deck.shuffle();
	}
}

void BlackJack::playerTurn() {
	int choice;
	bool v = true;

	cout << endl << endl;
	playerHand();

	while (v) {

		if (player.isLose()) {
			cout << "You busted!" << endl;
			v = false;
		}

		choice = getChoice();

		if (choice == 1) {
			player.addCard(deck.dealCard());
			playerHand();
		}
		else {
			break;
		}
	}
}

void BlackJack::dealerTurn() {
	cout << endl << endl;
	dealerHand(true);

	while (dealer.getHandValue() < 17) {
		cout << "Dealer Hits" << endl;
		dealer.addCard(deck.dealCard());
		dealerHand(true);
	}

	cout << (dealer.isLose() ? "Dealer Busted" : "Dealer Stands");
}

void BlackJack::adjust(int outcome) {
	if (outcome == 1) {
		player.updateBalance(player.getBalance() + 1); // win
	}
	else if (outcome == -1) {
		player.updateBalance(player.getBalance() - 1); // lose thats why you subtract 1
	}
	//else draw (outcome = 0) nothing changes
}

void BlackJack::whoWon() {// compare whowon to adjuct to get the balance
	int pTotal = player.getHandValue();
	int dTotal = dealer.getHandValue();

	cout << "Final Hands" << endl;

	playerHand();
	dealerHand(true);
	if (player.isLose()) 
	{
		cout << "You Lose, Dealer Wins" << endl;
		adjust(-1); // you lost
	}
	else if (dealer.isLose()) 
	{
		cout << "Dealer Lost, You Win!" << endl;
		adjust(1);// you won
	}
	else if (pTotal > dTotal) {
		cout << "You Win!" << endl;
		adjust(1);// round win
	}
	else if (pTotal < dTotal) {
		cout << "Dealer Wins!" << endl;
		adjust(-1);// round lost
	}
	else {
		cout << "DRAW!!!" << endl;
		adjust(0);
	}

	cout << "Your Current Balance: $" << player.getBalance() << endl;
}

bool BlackJack::checkGame(const Player& player) const {
	return (this->player.getHandValue() == 21 and this->player.getHand().size() == 2);
}

//Day 9:
bool BlackJack::anotherRound() {
	int choice;
	cout << "Another Round??? \n1) Yes \n2) No" << endl;
	cout << "------" << endl;
	cin >> choice;
	return (choice == 1 ? true : false);
}

int BlackJack::getChoice() {
	int choice;

	do {
		cout << "Choose: \n1) Hit\n2) Stand " << endl;
		cout << "---------" << endl;
		cin >> choice;

		if (choice != 1 && choice != 2) {
			cout << "Invalid Entry. Only use 1 -- HIT or 2 -- Stand" << endl;
		}

	} while (choice != 1 && choice != 2);

	return choice;
}
