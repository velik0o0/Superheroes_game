#include "Player.h"
#include "Market.h"
#include "Hero.h"
#include <iostream>
using namespace std;
#include <stdlib.h>

Player::Player(const char* name, const char* email, const char* username, const char* password, double moneyBalance)
    : User(name, email, username, password), moneyBalance(moneyBalance), heroes(), LogsCounter(0)
{
    heroes = std::vector<Hero>();
}

bool Player::signIn(const char* inputUsername, const char* inputPassword) const
{
    std::string username(inputUsername);
    std::string password(inputPassword);

    if (getUsername() == username && getPassword() == password) {
        std::cout << getName() << ", you have successfully logged in as a player!" << std::endl;
        std::cin.ignore();
        return true;
    }
    return false;
}
Player& Player::operator=(const Player& other)
{
    if (this == &other)
    {
        return *this;
    }
    User::operator=(other);

    moneyBalance = other.moneyBalance;
    heroes = other.heroes;

    return *this;
}
bool Player::operator==(const Player& other) const
{
    return (getName() == other.getName() &&
        getEmail() == other.getEmail() &&
        getUsername() == other.getUsername() &&
        getPassword() == other.getPassword());
}
void Player::addHero(const Hero& hero)
{
    heroes.push_back(hero);
}
void Player::buyHero(Market& market)
{
    int choice;
    cout << "Enter the index of the hero you want to buy: ";
    cin >> choice;

    // Add the selected hero to the player's collection
    const vector<Hero>& heroes = market.getHeroes();
    if (choice >= 1 && choice <= heroes.size())
    {
        const Hero& hero = heroes[choice - 1];
       /*if (hero.getIsPurchased())
        {
            cout << "Hero is already purchased." << endl;
        }else
        {*/ 
        
            double price = hero.getPurchasePrice();
            if (moneyBalance >= price)
            {
                moneyBalance -= price;
                addHero(hero);
                cout << "Hero purchased successfully!" << endl;
                market.removeHero(hero.getNickname());
            }
            else
            {
                cout << "Not enough money to purchase the hero." << endl;
            }
        //}
    }
    else
    {
        cout << "Invalid choice." << endl;
    }


}

void Player::setHeroAttackMode(const std::string& heroNickname)
{
    for (Hero& hero : heroes)
    {
        if (hero.getNickname() == heroNickname)
        {
            if (hero.getIsAttackMode())
            {
                std::cout << "The hero is already in attack mode." << std::endl;
            }
            else
            {
                hero.setIsAttackMode(true);
                cout << "Attack mode for hero " << heroNickname << " is set to true." << endl;
                return;
            }
        }
        else  cout << "Hero with nickname " << heroNickname << " not found." << endl;
    }
}
void Player::setHeroDefenseMode(const std::string& heroNickname)
{
    for (Hero& hero : heroes)
    {
        if (hero.getNickname() == heroNickname)
        {
            if (!hero.getIsAttackMode())
            {
                std::cout << "The hero is already in defense mode." << std::endl;
            }
            else
            {
                hero.setIsAttackMode(false);
                cout << "Defense mode for hero " << heroNickname << " is set to true." << endl;
                return;
            }
        }else cout << "Hero with nickname " << heroNickname << " not found." << endl;
    } 
}

const char* Player::getPlayerName() const
{
    return getName();
}
const char* Player::getPlayerUsername() const {
    return getUsername();
}
const char* Player::getPlayerPassword() const {
    return getPassword();
}
const char* Player::getPlayerEmail() const
{
    return getEmail();
}
size_t Player::getLogsCounter()  const
{
    return LogsCounter;
}
size_t Player::getHeroesCount() const {
    return heroes.size();
}
double Player::getMoneyBalance() const
{
    return moneyBalance;
}
void Player::setHeroes(const std::vector<Hero>& newHeroes)
{
    heroes = newHeroes;
}

//!!!
bool Player::removeHero(const std::string& heroNickname)
{
    //tova ne znam kak raboti
    auto it = std::find_if(heroes.begin(), heroes.end(), [&heroNickname](const Hero& hero) {
        return hero.getNickname() == heroNickname;
        });

    if (it != heroes.end())
    {
        heroes.erase(it);
        return true;
    }

    return false;
}
const std::vector<Hero>& Player::getHeroes() const {
    return heroes;
}
void Player::attackAnotherPlayer(Player& opponent)
{
    int attackingHeroIndex;
    std::cout << "your heroes:" << std::endl;
    int index = 1;
    for (const Hero& hero : heroes)
    {               
       cout << index++ << ". " << hero;
           
    }
    std::cout << "Choose the index of your hero you want to use for the attack: "<<std::endl;
    std::cin >> attackingHeroIndex;

    if (attackingHeroIndex < 1 || attackingHeroIndex > heroes.size())
    {
        std::cout << "Invalid hero index." << endl;
        return;
    }
    Hero& attackingHero = heroes[attackingHeroIndex - 1];

    if (opponent.heroes.empty())
    {
        std::cout << "Opponent has no heroes. You win!";
        setMoneyBalance(getMoneyBalance() + 50);  //50 can be replaced
        opponent.setMoneyBalance(opponent.getMoneyBalance() - attackingHero.getStrength());
        return;
    }

    else {

        int attackedHeroIndex;

        int methodOfAttack;
        std::cout << "You can choose to:\n"
            << "1. Attack particular hero of your opponent\n"
            << "2. Attack random hero of your opponent" << std::endl;
        std::cin >> methodOfAttack;

        if (methodOfAttack == 2) {
            
                srand(time(0));
                attackedHeroIndex = (rand() % opponent.getHeroesCount())+1;
            
        }
        
       if (methodOfAttack == 1)
       {
            std::cout << "Choose the index of the opponent's hero to be attacked: " << std::endl;
            int index = 1;
            for (const Hero& hero : opponent.getHeroes())
            {
              
                cout << index++ << ". " << hero.getNickname() << std::endl;

            }
            std::cin >> attackedHeroIndex;

            if (attackedHeroIndex < 1 || attackedHeroIndex > opponent.getHeroesCount())
            {
                cout << "Invalid hero index." << endl;
                return;
            }
            Hero& attackedHero = opponent.heroes[attackedHeroIndex - 1];

            cout << attackingHero.getPower() << " " << attackedHero.getPower() << endl;
            //tipovete sili ne suvpadat => promenq se seialta
            if (attackingHero.getPower() != attackedHero.getPower())
            {
                if ((attackingHero.getPower() == Power::Fire && attackedHero.getPower() == Power::Earth)
                    || (attackingHero.getPower() == Power::Earth && attackedHero.getPower() == Power::Water)
                    || (attackingHero.getPower() == Power::Water && attackedHero.getPower() == Power::Fire))
                {
                    attackingHero.setStrength(attackingHero.getStrength() * 2);
                }
                else   attackedHero.setStrength(attackedHero.getStrength() * 2);


            }

            //tipovete sili suvpadat ili ne suvpadat i veche e promenena silata 
            //&& opponent - attack mode
            if (attackedHero.getIsAttackMode() == true)
            {
                if (attackingHero.getStrength() > attackedHero.getStrength())
                {
                    int diff = attackingHero.getStrength() - attackedHero.getStrength();
                    std::cout << "Attack successful! You defeated the opponent's hero." << endl;
                    setMoneyBalance(getMoneyBalance() + diff);
                    opponent.setMoneyBalance(opponent.getMoneyBalance() - diff);

                    opponent.removeHero(attackedHero.getNickname());
                }

                else if (attackingHero.getStrength() < attackedHero.getStrength())
                {
                    int diff = attackedHero.getStrength() - attackingHero.getStrength();
                    std::cout << "Attack unsuccessful! Your opponent defeated you!" << endl;
                    setMoneyBalance(getMoneyBalance() - 2 * diff);
                    opponent.setMoneyBalance(opponent.getMoneyBalance() + 50);//50 can be replaced

                    opponent.removeHero(attackedHero.getNickname());
                }
                else
                {
                    std::cout << "Attack failed! Both heroes have the same strength." << endl;
                    setMoneyBalance(getMoneyBalance() - 80);//80 can be replaced

                }
            }
            //tipovete sili suvpadat ili ne suvpadat i veche e promenena silata 
            //&& opponent -defense mode
            if (attackedHero.getIsAttackMode() == false)
            {
                if (attackingHero.getStrength() > attackedHero.getStrength())
                {
                    int diff = attackingHero.getStrength() - attackedHero.getStrength();
                    std::cout << "Attack successful! You defeated the opponent's hero." << endl;
                    setMoneyBalance(getMoneyBalance() + diff);

                    opponent.removeHero(attackedHero.getNickname());
                }
                else if (attackingHero.getStrength() < attackedHero.getStrength())
                {
                    int diff = attackedHero.getStrength() - attackingHero.getStrength();
                    std::cout << "Attack unsuccessful! Your opponent defeated you!" << endl;
                    setMoneyBalance(getMoneyBalance() - 2 * diff);

                    opponent.removeHero(attackedHero.getNickname());
                }
                else
                {
                    std::cout << "Attack failed! Both heroes have the same strength." << endl;
                    setMoneyBalance(getMoneyBalance() - 80);//80 can be replaced

                }
            }
            
       }
       else
       {
                std::cout << "invalid index\n";
        }

    
    }
}
void Player::setMoneyBalance(double balance)
{
    if (balance < 0) { moneyBalance = 0; }
    else moneyBalance = balance;
    
}
void Player::setLogsCounter(size_t counter)
{
    LogsCounter = counter;
}
