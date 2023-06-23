#include "Administrator.h"
#include "Player.h"
#include "Market.h"
#include <iostream>
using namespace std;


Administrator::Administrator(const char* name, const char* email, const char* username, const char* password)
    : User(name, email, username, password)
{
}


bool Administrator::signIn(const char* inputUsername, const char* inputPassword) const
{
    std::string username(inputUsername);
    std::string password(inputPassword);

    if (getUsername() == username && getPassword() == password) {
        std::cout << getName() << ", you have successfully logged in as administrator!" << std::endl;
        return true;
    }
    return false;
}


const char* Administrator::getAdministratorName() const
{
    return getName();
}

const char* Administrator::getAdministratorEmail() const
{
    return getEmail();
}
