#ifndef BLACKJACKSIM_H
#define BLACKJACKSIM_H

#include <string>
#include <map>

using namespace std;

struct Stats {
	int win = 0;
	int loss = 0;
	int draw = 0;
};

class BlackJackSim {
private:
	map<int, Stats> hitResults;
	map<int, Stats> standResults;
public:
	void simulator(int rounds = 100000);
	void display() const;
	static bool isValidCard(int value);
};
#endif