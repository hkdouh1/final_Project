#include "player.h"
#include <sstream>
using namespace std;

Player::Player(int startingBalance) : value(0), balance(startingBalance) {}

void Player::addCard(const Card& card)
{
	hand.push_back(card);
	value += card.getValue();

	if (value > 21)
	{
		for (const Card& c : hand)
		{
			if (c.getValue() == 11 && value > 21)
			{
				value -= 10;
			}
		}
	}
}

int Player::getHandValue() const
{
	return value;
}

string Player::showHand() const
{
	stringstream ss;
	
	for (const Card& card : hand)
	{
		ss << card.toString() << ", ";
	}

	string result = ss.str();
	return result.substr(0, result.length() - 2);
}

int Player::getBalance() const
{
	return balance;
}

void Player::updateBalance(int amount)
{
	balance += amount;
}

// missing this step, had to define clearHand() method and implement it
void Player::clearHand()
{
	hand.clear(); // clear the hand vector
	value = 0;
}

Card Player::getCardAt(int index) const {
	if (index < 0 || index >= hand.size()) {
		throw std::out_of_range("Invalid card index");
	}
	return hand.at(index);
}

bool Player::isLose() const {
	return value > 21;
}

const vector<Card>& Player::getHand() const {
	return hand;
}
