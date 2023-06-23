#pragma once
#pragma warning (disable:4996)
#include "User.h"
#include "Market.h"
#include "Hero.h"
#include <vector>

class Player : public User
{
private:
    double moneyBalance;
    size_t LogsCounter;
    std::vector<Hero> heroes;

public:
    Player() = default;
    Player(const char* name, const char* email, const char* username, const char* password, double moneyBalance);

    Player& operator=(const Player& other);
    bool operator==(const Player& other) const;
    
    void buyHero(Market& market);
   
    bool signIn(const char* inputUsername, const char* inputPassword) const;

    const char* getPlayerName() const;
    const char* getPlayerUsername() const;
    const char* getPlayerPassword() const;
    size_t getLogsCounter() const;
    const char* getPlayerEmail() const;
    double getMoneyBalance() const;
    size_t getHeroesCount() const;
    const std::vector<Hero>& getHeroes() const ;
    void setHeroes(const std::vector<Hero>& newHeroes);
    bool removeHero(const std::string& heroNickname);
        void setMoneyBalance(double balance);
    void setHeroAttackMode(const std::string& heroNickname);
        void setHeroDefenseMode(const std::string& heroNickname);
    void setLogsCounter(size_t counter);
    void attackAnotherPlayer(Player& opponent);
    void addHero(const Hero& hero);
    bool hasHero(const Hero& hero) const;
};
