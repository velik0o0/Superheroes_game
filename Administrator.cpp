#pragma once
#include<cstring>
#include<string>
using namespace std;
#pragma once
#include "Player.h"
#pragma warning (disable:4996)
#include "User.h"
#include "Market.h"
#include <vector>


class Administrator : public User
{
public:
	Administrator() = default;
	Administrator(const char* name, const char* email, const char* username, const char* password);

	/*void addAdmin(const Administrator& newAdministrator, std::vector<Administrator>& administrators);
	void addPlayer(const Player& newPlayer, std::vector<Player>& players);
	void addHeroToMarket(Market& market, const Hero& newHero);
	void deletePlayer(Player& player);*/
	

	bool signIn(const char* inputUsername, const char* inputPassword) const;

	//using User::name;   
	//using User::email;   
	const char* getAdministratorName() const;
	const char* getAdministratorEmail() const;
};
