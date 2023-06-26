
#include "Hero.h"
#include "Market.h"
#include "Player.h"
#include "Administrator.h"
#include "User.h"
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
#include <utility>  


void savePlayersToFile(const std::vector<Player>& players, const std::string& fileName) {
    std::ofstream file(fileName);

    if (file.is_open()) {
        for (const Player& player : players) {
            file << "Name: " << player.getPlayerName() << '\n';
            file << "Email: " << player.getPlayerEmail() << '\n';
            file << "Username: " << player.getPlayerUsername() << '\n';
            file << "Password: " << player.getPlayerPassword() << '\n';
            file << "Money Balance: " << player.getMoneyBalance() << '\n';

            const std::vector<Hero>& heroes = player.getHeroes();
            file << "Heroes:\n";
            for (const Hero& hero : heroes) {
                file << hero <<'\n';
            }

            file << "Logs Counter: " << player.getLogsCounter() << '\n';
            file << "--------------------------\n";
        }

        file.close();
        std::cout << "Player data saved to file successfully.\n";
    }
    else {
        std::cout << "Failed to open file for saving player data.\n";
    }
}
void loadPlayersFromFile(std::vector<Player>& players, const std::string& fileName) {
    std::ifstream file(fileName);

    if (file.is_open()) {
        players.clear();

        std::string line;
        while (std::getline(file, line)) {
            if (line == "Name: ") {
                std::string name, email, username, password;
                double moneyBalance;
                size_t logsCounter;
                std::vector<Hero> heroes;

                std::getline(file, name);
                std::getline(file, email);
                std::getline(file, username);
                std::getline(file, password);
                file >> moneyBalance;

                std::string heroesHeader;
                std::getline(file, heroesHeader); // Read the "Heroes:" header

                std::string heroName;
                while (std::getline(file, heroName) && !heroName.empty()) {
                    Hero hero;
                    file >> hero;
                    heroes.push_back(hero);
                }

                file >> logsCounter;

                std::string divider;
                std::getline(file, divider); // Read the "--------------------------" divider

                Player player(name.c_str(), email.c_str(), username.c_str(), password.c_str(), moneyBalance);
                player.setLogsCounter(logsCounter);
                player.setHeroes(heroes);
                players.push_back(player);
            }
        }

        file.close();
        std::cout << "Player data loaded from file successfully.\n";
    }
    else {
        std::cout << "Failed to open file for loading player data.\n";
    }
}
void saveAdministratorsToFile(const std::vector<Administrator>& administrators, const std::string& fileName2) {
    std::ofstream file(fileName2);

    if (file.is_open()) {
        for (const Administrator& admin : administrators) {
            file << "Name: " << admin.getName() << '\n';
            file << "Email: " << admin.getEmail() << '\n';
            file << "Username: " << admin.getUsername() << '\n';
            file << "Password: " << admin.getPassword() << '\n';
            
        }

        file.close();
        std::cout << "Administrator data saved to file successfully.\n";
    }
    else {
        std::cout << "Failed to open file for saving administrator data.\n";
    }
}

void loadAdministratorsFromFile(std::vector<Administrator>& administrators, const std::string& fileName2) {
    std::ifstream file(fileName2);

    if (file.is_open()) {
        administrators.clear();

        std::string line;
        while (std::getline(file, line)) {
            if (line == "Name: ") {
                std::string name, email, username, password;
              
                std::getline(file, name);
                std::getline(file, email);
                std::getline(file, username);
                std::getline(file, password);
              
                
                Administrator admin(name.c_str(), email.c_str(), username.c_str(), password.c_str());
                administrators.push_back(admin);
            }
        }

        file.close();
        std::cout << "Administrator data loaded from file successfully.\n";
    }
    else {
        std::cout << "Failed to open file for loading administrator data.\n";
    }
}

void addAdmin(std::vector<Administrator>& administrators, const Administrator& newAdministrator)
{
    administrators.push_back(newAdministrator);
    std::cout << "New administrator added.\n";
}
void addPlayer(std::vector<Player>& players, const Player& newAdministrator)
{
    players.push_back(newAdministrator);
    std::cout << "New player added.\n";
}
void deletePlayer(std::vector<Player>& players, const Player& player)
{
    for (auto it = players.begin(); it != players.end(); ++it)
    {
        if (*it == player)
        {
            players.erase(it);
            std::cout << "Player deleted.\n";
            return;
        }
    }
    std::cout << "Player not found.\n";
}
void showPlayers(const std::vector<Player>& players)
{
    int i = 1;
    std::cout << "Players:" << std::endl;
    for (const Player& player : players)
    {
        cout << i++;
        std::cout << player.getPlayerName() <<  " with heroes:" << std::endl;

        const std::vector<Hero>& heroes = player.getHeroes();
        int j = 1;
        for (const Hero& hero : heroes)
        {
            std::cout << i<<"."<<j++<<": " << hero.getNickname() << " " 
                << hero.getFirstName() << " " << hero.getLastName() << std::endl;
        }

        std::cout << "-----------------------" << std::endl;
    }
}
void showPlayersToAdmin(const std::vector<Player>& players)
{
    int i = 1;
    std::cout << "Players:" << std::endl;
    for (const Player& player : players)
    {
       std:: cout << i++;
        std::cout << player.getPlayerName() << " with email "  
            << player.getPlayerEmail() << ", username: " 
            << player.getPlayerUsername() << " and password " 
            << player.getPlayerPassword() << "has heroes:"<< std::endl;

        const std::vector<Hero>& heroes = player.getHeroes();
        int j = 1;
        for (const Hero& hero : heroes)
        {

            std::cout << i << "." << j++ << ": " << hero.getNickname() << " "
                << hero.getFirstName() << " " << hero.getLastName() 
                << hero.getPower() << " " << hero.getStrength() <<" with attack mode:"
                << hero.getIsAttackMode()  << std::endl;
        }

        std::cout << "-----------------------" << std::endl;
    }
}
void showAdmins(const std::vector<Administrator>& administrators)
{
    int i = 1;
    std::cout << "Admins:" << std::endl;
    for (const Administrator& admin: administrators)
    {
        cout << i++;
        std::cout << admin.getAdministratorName() << " with email "
            << admin.getAdministratorEmail() << std::endl;

    }
}
bool compareByMoneyBalance(const Player& player1, const Player& player2) {
    return player1.getMoneyBalance() > player2.getMoneyBalance();
}

void printPlayers(const std::vector<Player>& players) {
    int place = 1;
    for (const Player& player : players) {
        std::cout <<place++<< " player: " << player.getName() << ", money balance: " << player.getMoneyBalance() << std::endl;
    }
}

void sortByMoneyBalance(std::vector<Player>& players) {
    for (size_t i = 0; i < players.size() - 1; ++i) {
        for (size_t j = 0; j < players.size() - i - 1; ++j) {
            if (compareByMoneyBalance(players[j], players[j + 1])) {
                std::swap(players[j], players[j + 1]);
            }
        }
    }
}
bool isValidPassword(const string& password)
{
    bool hasCapitalLetter = false;
    bool hasSmallLetter = false;
    bool hasNumber = false;

    for (char c : password)
    {
        if (c >= 'A' && c <= 'Z')
            hasCapitalLetter = true;
        else if (c >= 'a' && c <= 'z')
            hasSmallLetter = true;
        else if (c >= '0' && c <= '9')
            hasNumber = true;

        // If all requirements are met, exit the loop early
        if (hasCapitalLetter && hasSmallLetter && hasNumber)
            break;
    }

    // Check if all requirements are met
    return hasCapitalLetter && hasSmallLetter && hasNumber;
}


int main()
{
    std::vector<Administrator> administrators;
    std::vector<Player> players;
    Market MainMarket;
    int periodicMoney = 200;
    std::string AdminsFileName = "admins_data.txt";
    std::ifstream file(AdminsFileName);
    if (file && file.tellg() > 0) {

        loadAdministratorsFromFile(administrators, AdminsFileName);
        file.close();
    }
    else {
        Administrator MainAdmin("Victor", "victor@abv.bg", "Victor16", "ParolataNaVictor123");
        administrators.emplace_back(MainAdmin);
    }
    const Administrator* signedInAdmin = nullptr;
    std::string PlayersFileName = "player_data.txt";
    if (file && file.tellg() > 0) {
        // File is not empty, load data from file
        loadPlayersFromFile(players, PlayersFileName);
        file.close();
    }

    while (true) {

        std::cout << "Choose to:" << std::endl
            << "1. Sign in as admin" << std::endl
            << "2. Sign in as player";
        int usertype;
        std::cin >> usertype;

        if (usertype == 1)
        {
            std::string inputUsername;
            std::string inputPassword;

            std::cout << "Enter Username: ";
            std::cin >> inputUsername;

            std::cout << "Enter Password: ";
            std::cin >> inputPassword;

            for (const Administrator& admin : administrators) {
                if (admin.signIn(inputUsername.c_str(), inputPassword.c_str())) {
                    signedInAdmin = &admin;
                    //  std::cout << signedInAdmin->getAdministratorName() << ", you have successfully logged in as an administrator!" << std::endl;
                    break;
                }
            }

            if (signedInAdmin == nullptr) {
                std::cout << "Invalid username or password. Please try again." << std::endl;
                // Handle unsuccessful sign-in
                continue;
            }

            if (MainMarket.getNumHeroes() == 0) {
                cout << "The market is empty, add three new heroes";
                cout << "Hero one: (firstName, lastName, nickname, power, strength, purchasePrice)  ";
                Hero hero1;
                cin >> hero1;
                /*cout << "Hero two:";
                Hero hero2;
                cin >> hero2;
                cout << "Hero three:";
                Hero hero3;
                cin >> hero3;*/
                MainMarket.addHero(hero1);
                /*MainMarket.addHero(hero2);
                MainMarket.addHero(hero3);*/

            }
            while (true) {
                string command;
                std::cout << "Enter command: ";
                // std::cin.ignore();
                std::getline(std::cin, command);

                if (command == "sign out") {
                    std::cout << signedInAdmin->getAdministratorName() << ", you have successfully signed out." << std::endl;
                    signedInAdmin = nullptr;
                    break;
                }
                else if (command == "add admin") {
                    std::string name, email, username, password;
                    std::cout << "Enter name: ";
                    std::getline(std::cin, name);
                    std::cout << "Enter email: ";
                    std::getline(std::cin, email);
                    std::cout << "Enter username: ";
                    std::getline(std::cin, username);
                    std::cout << "Enter password: ";
                    std::getline(std::cin, password);
                    /* if (!isValidPassword(password)) {
                         cout << "invalid password";
                         break;
                     }*/
                    Administrator newAdmin(name.c_str(), email.c_str(), username.c_str(), password.c_str());
                    addAdmin(administrators, newAdmin);

                }
                else if (command == "add player")
                {
                    std::string name, email, username, password;

                    std::cout << "Enter name: ";
                    std::getline(std::cin, name);
                    std::cout << "Enter email: ";
                    std::getline(std::cin, email);
                    std::cout << "Enter username: ";
                    std::getline(std::cin, username);
                    std::cout << "Enter password: ";
                    std::getline(std::cin, password);
                    /*if (!isValidPassword(password)) {
                        cout << "invalid password";
                        break;
                    }*/
                    Player newPlayer(name.c_str(), email.c_str(), username.c_str(), password.c_str(), 200);
                    addPlayer(players, newPlayer);


                }
                else if (command == "delete player")
                {
                    std::string name, email, username, password;
                    std::cout << "Enter name: ";
                    std::getline(std::cin, name);
                    std::cout << "Enter email: ";
                    std::getline(std::cin, email);
                    std::cout << "Enter username: ";
                    std::getline(std::cin, username);
                    std::cout << "Enter password: ";
                    std::getline(std::cin, password);
                    Player newPlayer(name.c_str(), email.c_str(), username.c_str(), password.c_str(), 200);
                    deletePlayer(players, newPlayer);

                }
                else if (command == "add hero to market")
                {
                    Hero newHero;
                    std::cout << "Enter Hero details:\n";
                    std::cin >> newHero;

                    MainMarket.addHero(newHero);

                }
                else if (command == "show players") {
                    showPlayersToAdmin(players);
                }
                else if (command == "show administrators") {
                    showAdmins(administrators);
                }
                else {
                    std::cout << "Invalid command. Enter valid one:" << std::endl;
                }
            }

        }

        //user Player:
        else if (usertype == 2)
        {
            Player* signedInPlayer = nullptr;
            std::string inputUsername;
            std::string inputPassword;

            std::cout << "Enter Username: ";
            std::cin >> inputUsername;

            std::cout << "Enter Password: ";
            std::cin >> inputPassword;

            for (Player& player : players) {
                if (player.signIn(inputUsername.c_str(), inputPassword.c_str())) {
                    signedInPlayer = &player;
                    // std::cout << signedInPlayer->getPlayerName() << ", you have successfully logged in as a player!" << std::endl;
                    break;
                }
            }

            if (signedInPlayer == nullptr) {
                std::cout << "Invalid username or password. Please try again." << std::endl;
                // Handle unsuccessful sign-in
                continue;
            }

            signedInPlayer->setLogsCounter(signedInPlayer->getLogsCounter() + 1);

            bool isHighestLogsCounter = true;
            for (const Player& player : players) {
                if (player.getLogsCounter() >= signedInPlayer->getLogsCounter()) {
                    isHighestLogsCounter = false;
                    break;
                }
            }
            if (isHighestLogsCounter) {
                for (Player& player : players) {
                    double currentBalance = player.getMoneyBalance();
                    player.setMoneyBalance(currentBalance + periodicMoney);
                }
            }

            //commands of a player:
            string command;
            int counter = 0;
            bool logedout = 0;

            while (logedout == 0)
            {
                cout << "Enter command:";
               // std::cin.ignore();
                std::getline(std::cin, command);


                if (command == "sign out") {
                    std::cout << signedInPlayer->getPlayerName() << ", you have successfully signed out." << std::endl;

                    savePlayersToFile(players, PlayersFileName);
                    saveAdministratorsToFile(administrators, AdminsFileName);

                    // counter = 3;
                    logedout = 1;
                 //   continue;
                    //break;


                }

                /* if (counter>2) {
                     std::cout << "Invalid command. Enter valid one:" << std::endl;
                     break;}*/

                if (counter >= 3) {
                    std::cout << "limit reached. sign out";
                    continue;

                }
                if (command == "show market")
                {
                    MainMarket.printMarket();
                    counter++;
                    // continue;
                     //break;
                }
                else if (command == "buy hero")
                {
                    signedInPlayer->buyHero(MainMarket);
                    counter++;
                    //continue;
                    //break;
                }
                else if (command == "delete profile")
                {

                    deletePlayer(players, *signedInPlayer);
                    counter = 3;
                    //  continue;
                      //break;
                }
                else if (command == "show balance")
                {

                    cout << signedInPlayer->getMoneyBalance();
                    counter++;
                    //continue;
                    //break;
                }
                else if (command == "set to attack")
                {
                    string heronickname;
                    cout << "enter nicnkame of the superhero";
                    cin >> heronickname;
                    signedInPlayer->setHeroAttackMode(heronickname);
                    counter++;
                    // continue;
                     //break;
                }
                else if (command == "set to defense")
                {
                    string heronickname;
                    cout << "enter nicnkame of the superhero";
                    cin >> heronickname;
                    signedInPlayer->setHeroDefenseMode(heronickname);
                    counter++;
                    //continue;
                    //break;
                }
                else if (command == "attack player")
                {

                    Player* opponentPlayer = nullptr;
                    std::string opponentUsername;
                    cout << "Enter the username of the player you want to attack";
                    cin >> opponentUsername;
                    for (Player& player : players) {

                        if (player.getUsername() == opponentUsername)
                        {
                            opponentPlayer = &player;
                            break;
                        }
                    }
                    if (opponentPlayer == nullptr)
                    {
                        cout << "Player not found." << endl;
                        continue;
                    }

                    signedInPlayer->attackAnotherPlayer(*opponentPlayer);

                    counter++;
                    // break;
                }
                else if (command == "show players")
                {
                    showPlayers(players);
                    counter++;
                    // continue;
                     //break;
                }
                else if (command == "show leadboard") {
                    sortByMoneyBalance(players);
                    printPlayers(players);
                    // break;
                }
                else {
                    std::cout << "Invalid command. Enter valid one:" << std::endl;
                    // continue;
                     //break;
                }


            }
        }
    }
}

