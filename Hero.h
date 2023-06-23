#pragma once
#pragma warning (disable:4996)
#include<cstring>
#include<string>
using namespace std;
#include <list>

enum Power { Fire, Water, Earth };

class Hero {
private:
    std::string firstName;
    std::string lastName;
    std::string nickname;
    Power power;
    int strength;
    double purchasePrice;
    bool isAttackMode;
    bool isPurchased;

public:
    Hero() = default;
    Hero(const std::string& firstName, const std::string& lastName, const std::string& nickname,
        Power power, int strength, double purchasePrice, bool isAttackMode, bool isPurchased);

    friend std::ostream& operator<<(std::ostream& os, const Hero& hero);
    friend std::istream& operator>>(std::istream& is, Hero& hero);

    const std::string& getFirstName() const;
    const std::string& getLastName() const;
    const std::string& getNickname() const;
    Power getPower() const;
    int getStrength() const;
    double getPurchasePrice() const;
    bool getIsAttackMode() const;
    bool getIsPurchased() const;

    void setFirstName(const std::string& firstName);
    void setLastName(const std::string& lastName);
    void setNickname(const std::string& nickname);
    void setPower(Power power);
    void setStrength(int strength);
    void setPurchasePrice(double purchasePrice);
    void setIsAttackMode(bool isAttackMode);
    void setIsPurchased(bool isPurchased);
    ~Hero();
};