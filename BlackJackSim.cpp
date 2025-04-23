#include "BlackJackSim.h"
#include "deck.h"
#include "player.h"
#include "cards.h"
#include <ctime> 
#include <iostream>
#include <cstdlib>


void BlackJackSim::simulator(int rounds) {
	srand(static_cast<unsigned int>(time(0)));

	for (int i = 0; i < rounds; ++i) {
		Deck deck;
		deck.shuffle();

		Player dealer(0), player(0);
		dealer.clearHand();
		player.clearHand();

		dealer.addCard(deck.dealCard());
		dealer.addCard(deck.dealCard());

		player.addCard(deck.dealCard());
		player.addCard(deck.dealCard());

		int startingValue = player.getHandValue();


		if (!isValidCard(startingValue)) continue;

		//randomly generate 0 or 1
			//0 -- stand 1 -- for hit
		bool randomHit = rand() % 2;

		if (randomHit) {
			player.addCard(deck.dealCard());
		}

		while (dealer.getHandValue() < 17) {
			dealer.addCard(deck.dealCard());
		}

		bool dealerBust = dealer.getHandValue() > 21;
		bool playerBust = player.getHandValue() > 21;

		Stats& stats = randomHit ? hitResults[startingValue] : standResults[startingValue];
		if (dealerBust)
			stats.win++;
		else if (dealer.getHandValue() < player.getHandValue())
			stats.win++;
		else if (playerBust)
			stats.loss++;
		else if (dealer.getHandValue() > player.getHandValue())
			stats.loss++;
		else
			stats.draw++;
	}
}

//Helper function no need for it in the .h 
bool BlackJackSim::isValidCard(int value) {
	return value >= 4 and value <= 20;
}

void BlackJackSim::display() const {
	cout << "\nAfter Runnning the Simulation of 100 thousand hands the results are: " << endl;
	cout << " Starting Value  |  Hit (W\\L\\D)  |  Stand (W\\L\\D)" << endl;
	cout << "------------------------------------------------------" << endl;

	//complete the for loop that runs from the vaild (4 - 20) cards to show if win loss and draw for hit and stand

	for (int value = 4; value <= 20; ++value)
	{
		const Stats& hitStats = hitResults.at(value);
		const Stats& standStats = standResults.at(value);

		cout << "       " << value << "      | " << hitStats.win << "/" << hitStats.loss << "/" << hitStats.draw 
			<< "    |  " << standStats.win << "/" << standStats.loss << "/" << standStats.draw
			<< "\n";
	}

}