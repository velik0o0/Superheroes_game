#include <cstring>
#include "Hero.h"
using namespace std;
#include <iostream>
#include <fstream>
Hero::Hero(const std::string& firstName, const std::string& lastName, const std::string& nickname,
    Power power, int strength, double purchasePrice, bool isAttackMode, bool isPurchased)
    : firstName(firstName),
    lastName(lastName),
    nickname(nickname),
    power(power),
    strength(strength),
    purchasePrice(purchasePrice),
    isAttackMode(false),
    isPurchased(false) {}

const std::string& Hero::getFirstName() const
{
    return firstName;
}

const std::string& Hero::getLastName() const
{
    return lastName;
}

const std::string& Hero::getNickname() const
{
    return nickname;
}

Power Hero::getPower() const
{
    return power;
}

int Hero::getStrength() const
{
    return strength;
}

double Hero::getPurchasePrice() const
{
    return purchasePrice;
}

bool Hero::getIsAttackMode() const
{
    return isAttackMode;
}

bool Hero::getIsPurchased() const
{
    return isPurchased;
}

void Hero::setFirstName(const std::string& firstName)
{
    this->firstName = firstName;
}

void Hero::setLastName(const std::string& lastName)
{
    this->lastName = lastName;
}

void Hero::setNickname(const std::string& nickname)
{
    this->nickname = nickname;
}

void Hero::setPower(Power power)
{
    this->power = power;
}

void Hero::setStrength(int strength)
{
    this->strength = strength;
}

void Hero::setPurchasePrice(double purchasePrice)
{
    this->purchasePrice = purchasePrice;
}

void Hero::setIsAttackMode(bool isAttackMode)
{
    this->isAttackMode = isAttackMode;
}

void Hero::setIsPurchased(bool isPurchased)
{
    this->isPurchased = isPurchased;
}

Hero::~Hero()
{
    // Destructor is empty since string members automatically handle memory management.
}


std::ostream& operator<<(std::ostream& os, const Hero& hero)
{
    os <<  hero.getFirstName() << hero.getLastName() <<hero.getNickname() 
        <<hero.getPurchasePrice()<< "$ with strenght:"<< hero.getStrength() 
        <<" of type "<<hero.getPower() <<hero.getIsAttackMode()
        <<hero.getIsPurchased()<< std::endl;
  
    return os;
}

std::istream& operator>>(std::istream& is, Hero& hero)
{
    std::string firstName, lastName, nickname;
    int purchasePrice, strength;
    int powervalue;
    bool isAttackMode, isPurchased;

    is >> firstName >> lastName >> nickname >>powervalue >> strength >> purchasePrice >> isAttackMode >> isPurchased;

    hero.setFirstName(firstName);
    hero.setLastName(lastName);
    hero.setNickname(nickname);
    hero.setPower(static_cast<Power>(powervalue));
    hero.setPurchasePrice(purchasePrice);
    hero.setStrength(strength);
    hero.setIsAttackMode(isAttackMode);
    hero.setIsPurchased(isPurchased);
  
    return is;
}
