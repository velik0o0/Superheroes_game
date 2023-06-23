
#pragma once
#include "Hero.h"
#include <vector>
#pragma warning (disable:4996)

class Market {
private:
	std::vector<Hero> heroes;

public:
	Market();

	int getNumHeroes() const;
	const std::vector<Hero>& getHeroes() const;

	
	void addHero(const Hero& hero);
	
	void printMarket() const;

};


