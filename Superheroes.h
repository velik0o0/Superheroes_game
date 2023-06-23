#include<iostream>
#include<cstring>
#include<fstream>
#include<string>
#include<vector>
using namespace std;
#pragma once
#include <list>
#pragma warning (disable:4996)

//************************


//************************************************************
//useless code ->
class Unit {
	friend istream& operator >> (istream& a, Unit& e);
	friend ostream& operator << (ostream& a, const Unit& e);
private:
	int health;
	int arm;
	int range;
	int damage;
	int stamina;
	int gold;
	int x;
	int y;
public:
	Unit();
	~Unit();
	Unit(const Unit&);
	Unit& operator=(const Unit&);

	void SetHealth(int);
	int GetHealth() const;
	void SetArm(int);
	int GetArm() const;
	void SetRange(int);
	int GetRange() const;
	void SetDamage(int);
	int GetDamage() const;
	void SetStamina(int);
	int GetStamina() const;
	void SetGold(int);
	int GetGold() const;
	void SetX(int);
	int GetX() const;
	void SetY(int);
	int GetY() const;
};

class Monster : public Unit {
private:
	int price;
	char* creature;
	int amount;
	char* race;
	char* file;
public:
	Monster();
	Monster(char*, int);

	void SetPrice(int);
	int GetPrice() const;
	void SetAmount(int);
	int GetAmount() const;
	void SetCreature(char*);
	char* GetCreature() const;
	void SetRace(char*);
	char* GetRace() const;

	vector<Monster*> Shop(char*, int);
	bool Load(int& gold, vector<Monster*>&, char*, char*, int); // returns whether you want to continue to buy monsters
	virtual void Attack(Monster* [10][10], int, int, int, int);
};

class Hero : public Unit {
private:
	int money;
	int level;
	int mana;
	int crit;
	int experience;
	int nextLvlExperience;
	char* lFile;
	char* name;
	vector<Monster*> army;
public:
	Hero();
	void SetMoney(int);
	int GetMoney() const;
	void SetLevel(int);
	int GetLevel() const;
	void SetMana(int);
	int GetMana() const;
	void SetCrit(int);
	int GetCrit() const;
	void SetExperience(int);
	int GetExperience() const;
	void SetNextLvlExperience(int);
	int GetNextLvlExperience() const;
	void SetName(char*);
	char* GetName() const;
	void SetArmy(vector<Monster*>);
	vector<Monster*> GetArmy() const;

	virtual void Cast(int, int);
	void Load(Hero*, char*);
	void Save(Hero*, char*) const;
};

class Peasant : public Monster {
public:
	Peasant();
	Peasant(char*, int);
	void Attack(Monster* [10][10], int, int, int, int);
};

class Warrior : public Hero {
public:
	Warrior();
	void Stun() const;
	void Shield() const;
};

class Mage : public Hero {
public:
	Mage();
	void Fireball() const;
	void Iceball() const;
};

class Commands {
private:
	int player;
	char* command;
public:
	Commands();
	Commands(int, char*);
	void SetPlayer(int);
	int GetPlayer() const;
	void SetCommand(char*);
	char* GetCommand() const;
	int Command(int, char*, Hero*, Hero*, Monster* [10][10]);
}; 

//**************************************************************