#include <iostream>
#include "player.h"
#include "deck.h"
#include "cards.h"
#include "BlackJack.h"
#include "BlackJackSim.h"
using namespace std;

// entry point to the game
int main() {
	
	/*Player player(100);
	Player dealer(0);

	BlackJack testGame(dealer, player);

	cout << "Welcome!!!" << endl;

	do {

		testGame.playRound();
		cout << "your current balance is: $" << player.getBalance() << endl;

	} while (testGame.anotherRound());

	cout << "Thank you for playing. Youur final balance is: $" << player.getBalance() << endl;*/
	BlackJackSim simulator;
	simulator.simulator(100000); // Simulate 100,000 hands
	simulator.display(); // Display the results
	return 0;
}
