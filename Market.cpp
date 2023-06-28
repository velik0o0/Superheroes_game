#include <iostream>
#include "Hero.h"
#include <vector>
#include "Market.h"
using namespace std;

Market::Market() = default;

int Market::getNumHeroes() const {
    return heroes.size();
}
//!!
bool Market::removeHero(const std::string& heroNickname) {
    auto it = std::find_if(heroes.begin(), heroes.end(), [&heroNickname](const Hero& hero) {
        return hero.getNickname() == heroNickname;
        });

    if (it != heroes.end()) {
       heroes.erase(it);
        return true;
    }

    return false;
}
void Market::addHero(const Hero& hero) {
    heroes.push_back(hero);
    std::cout << hero.getNickname() << " successfully added to the Market" << std::endl;  
    std::cin.ignore();
}
void Market::addHeroToArch(const Hero& hero) {
    heroes.push_back(hero);
   
}

void Market::printMarket() const {
    int index = 1;
    for (const Hero& hero : heroes) {
        std::cout << index << ".: " << hero << std::endl;
        index++;
        /*.getNickname()
            << " price: " << hero.getPurchasePrice()
            << "$ type: " << hero.getPower()
            << " power: " << hero.getStrength() */
    }
}

const std::vector<Hero>& Market::getHeroes() const {
    return heroes;
}
