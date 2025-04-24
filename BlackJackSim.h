#ifndef BLACKJACKSIM_H
#define BLACKJACKSIM_H

#include <string>
#include <map>

using namespace std;

struct Stats {// value for wins and losses
	int win = 0;
	int loss = 0;
	int draw = 0;
};

class BlackJackSim { // this simulates the 100k hands / rounds
private:
	map<int, Stats> hitResults;
	map<int, Stats> standResults; //stats object used for the value for hitting and standing
public:
	void simulator(int rounds = 100000);
	void display() const;// show the resluts
	static bool isValidCard(int value);
};
#endif
