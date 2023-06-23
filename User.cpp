#include <iostream>
#include <cstring>
#include <fstream>
#include "Hero.h"
#include "Market.h"
#include "Player.h"
#include "Administrator.h"
#include "User.h"
using namespace std;
#include <utility>  // For std::move


void User::copyFrom(const User& other)
{
    name = new char[strlen(other.name) + 1];
    strcpy(name, other.name);

    email = new char[strlen(other.email) + 1];
    strcpy(email, other.email);

    username = new char[strlen(other.username) + 1];
    strcpy(username, other.username);

    password = new char[strlen(other.password) + 1];
    strcpy(password, other.password);
}

void User::free()
{
    delete[] name;
    delete[] email;
    delete[] username;
    delete[] password;
}

User::User(const char* name, const char* email, const char* username, const char* password)
{
    setName(name);
    setEmail(email);
    setUsername(username);
    setPassword(password);
}

User::User(const User& other)
{
    copyFrom(other);
}

User& User::operator=(const User& other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
    }
    return *this;
}

void User::moveFrom(User&& other)
{
    name = other.name;
    other.name = nullptr;

    email = other.email;
    other.email = nullptr;

    username = other.username;
    other.username = nullptr;

    password = other.password;
    other.password = nullptr;
}

User::User(User&& other)
{
    moveFrom(std::move(other));
}

User& User::operator=(User&& other)
{
    if (this != &other)
    {
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

const char* User::getName() const
{
    return name;
}

const char* User::getEmail() const
{
    return email;
}

const char* User::getUsername() const
{
    return username;
}

const char* User::getPassword() const
{
    return password;
}

void User::setName(const char* name)
{
    if (name == nullptr || this->name == name)
        return;

    delete[] this->name;
    size_t nameLen = strlen(name);
    this->name = new char[nameLen + 1];
    strcpy(this->name, name);
}

void User::setEmail(const char* email)
{
    if (email == nullptr || this->email == email)
        return;

    delete[] this->email;
    size_t emailLen = strlen(email);
    this->email = new char[emailLen + 1];
    strcpy(this->email, email);
}

void User::setUsername(const char* username)
{
    if (username == nullptr || this->username == username)
        return;

    delete[] this->username;
    size_t usernameLen = strlen(username);
    this->username = new char[usernameLen + 1];
    strcpy(this->username, username);
}

void User::setPassword(const char* password)
{
    if (password == nullptr || this->password == password)
        return;

    delete[] this->password;
    size_t passwordLen = strlen(password);
    this->password = new char[passwordLen + 1];
    strcpy(this->password, password);
}

User::~User()
{
    free();
}

void User::print() const
{
    std::cout << "Name: " << name << std::endl;
    std::cout << "Email: " << email << std::endl;
    std::cout << "Username: " << username << std::endl;
    std::cout << "Password: " << password << std::endl;
}

