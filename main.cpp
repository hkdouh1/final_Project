#include <iostream>
#include "player.h"
#include "deck.h"
#include "cards.h"
#include "BlackJack.h"
#include "BlackJackSim.h" // Include the simulation header
using namespace std;

int main() {
    cout << "Welcome to Blackjack!" << endl;
    int choice;

    do {
        cout << "Choose an option:" << endl;
        cout << "1) Play Blackjack" << endl;
        cout << "2) Run Simulation (100,000 hands)" << endl;
        cout << "3) Quit" << endl;
        cin >> choice;

        if (choice == 1) {
            // Interactive Gameplay
            Player player(100);
            Player dealer(0);
            BlackJack testGame(dealer, player);

            cout << "Let's Play Blackjack!" << endl;
            do {
                testGame.playRound();
                cout << "Your current balance is: $" << player.getBalance() << endl;
            } while (testGame.anotherRound());

            cout << "Thank you for playing. Your final balance is: $" << player.getBalance() << endl;
        }
        else if (choice == 2) {
            // Run Simulation
            BlackJackSim simulator;
            simulator.simulator(100000); // Simulate 100,000 hands
            simulator.display(); // Display the results
        }
        else if (choice == 3) {
            cout << "Goodbye! Thanks for playing!" << endl;
        }
        else {
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 3);

    return 0;
}
