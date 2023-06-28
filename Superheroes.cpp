
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
void deletePlayer(std::vector<Player>& players, const std::string& username)
{
    auto it = std::find_if(players.begin(), players.end(), [&username](const Player& player) {
        return player.getUsername() == username;
        });

    if (it != players.end()) {
        players.erase(it);
        std::cout << "Player " << username << " successfully deleted." << std::endl;
    }
    else {
        std::cout << "Player " << username << " not found." << std::endl;
    }
}

void showPlayers(const std::vector<Player>& players)
{
    int i = 1;
    std::cout << "Players:" << std::endl;
    for (const Player& player : players)
    {
        std::cout << i++<<". " << player.getPlayerName();

        const std::vector<Hero>& heroes = player.getHeroes();
        if (heroes.empty())
        {
            std::cout << " has no heroes." << std::endl;
        }
        else
        {
            std::cout << " has heroes:" << std::endl;
            int j = 1;
            for (const Hero& hero : heroes)
            {
                std::cout << i-1 << "." << j++ << ": " << hero.getFirstName() << " "
                    << hero.getLastName() << " " << hero.getNickname() << std::endl;
            }

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
        std::cout << i++ << ". " << player.getPlayerName() << " with email: "
            << player.getPlayerEmail() << ", username: "
            << player.getPlayerUsername() << " and password: "
            << player.getPlayerPassword(); 

        const std::vector<Hero>& heroes = player.getHeroes();
        if (heroes.empty())
        {
            std::cout << " has no heroes." << std::endl;
        }
        else {
            int j = 1;
            for (const Hero& hero : heroes)
            {
                std::cout << " has heroes:" << std::endl;
                cout << hero;
                /*std::cout << i << "." << j++ << ": " << hero.getNickname() << " "
                    << hero.getFirstName() << " " << hero.getLastName()
                    << hero.getPower() << " " << hero.getStrength() <<" with attack mode:"
                    << hero.getIsAttackMode()  << std::endl;*/
            }
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
        std::cout << " "<<admin.getAdministratorName() << " with email: "
            << admin.getAdministratorEmail() << std::endl;

    }
}
void printPlayers(const std::vector<Player>& players) {
    int place = 1;
    for (const Player& player : players) {
        std::cout <<place++<< " player: " << player.getName() << ", money balance: " << player.getMoneyBalance() << std::endl;
    }
}
/*bool compareByMoneyBalance(const Player& player1, const Player& player2) {
    return player1.getMoneyBalance() > player2.getMoneyBalance();
}*/

void sortByMoneyBalance(std::vector<Player>& players) {
    for (size_t i = 0; i < players.size() - 1; ++i) {
        size_t maxIndex = i;
        for (size_t j = i + 1; j < players.size(); ++j) {
            if (players[j].getMoneyBalance() > players[maxIndex].getMoneyBalance()) {
                maxIndex = j;
            }
        }
        if (maxIndex != i) {
            std::swap(players[i], players[maxIndex]);
        }

    }
}
/*void sortByMoneyBalance(std::vector<Player>& players) {
    for (size_t i = 0; i < players.size() - 1; ++i) {
        for (size_t j = 0; j < players.size() - i - 1; ++j) {
            if (compareByMoneyBalance(players[j], players[j + 1])) {
                std::swap(players[j], players[j + 1]);
            }
        }
    }
}*/

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
    Market ArchivedMarket;
    int periodicMoney = 200;

    std::string AdminsFileName = "admins_data.txt";
    std::ifstream fileAdmins(AdminsFileName);
    if (fileAdmins && fileAdmins.tellg() > 0) {

        loadAdministratorsFromFile(administrators, AdminsFileName);
        fileAdmins.close();
    }
    else {
        Administrator MainAdmin("Victor", "victor@abv.bg", "Victor16", "ParolataNaVictor123");
        administrators.emplace_back(MainAdmin);
    }

    
    std::string PlayersFileName = "player_data.txt";
    std::ifstream filePlayers(PlayersFileName);
    if (filePlayers && filePlayers.tellg() > 0) {
        
        loadPlayersFromFile(players, PlayersFileName);
        filePlayers.close();
    }

    const Administrator* signedInAdmin = nullptr;

    while (true) {

        std::cout << "Choose to:" << std::endl
            << "1. Sign in as admin" << std::endl
            << "2. Sign in as player"<<std::endl;
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
              
                continue;
            }

            if (MainMarket.getNumHeroes() == 0) {
                cout << "The market is empty, add three new heroes"<<std::endl;
                
                cout << "Hero one: (firstName, lastName, nickname, power, strength, purchasePrice)  "<<std::endl;
                Hero hero1;
                cin >> hero1;
                MainMarket.addHero(hero1);
                ArchivedMarket.addHeroToArch(hero1);
                
                cout << "Hero two:"<<std::endl;
                Hero hero2;
                cin >> hero2;
                MainMarket.addHero(hero2);
                ArchivedMarket.addHeroToArch(hero2);

                cout << "Hero three:"<<std::endl;
                Hero hero3;
                cin >> hero3;
                MainMarket.addHero(hero3);
                ArchivedMarket.addHeroToArch(hero3);
               
               
            }

            while (true) {
                string command;
                std::cout << "Enter command: "<<std::endl;
               //std::cin.ignore();
                std::getline(std::cin, command);

                if (command == "sign out") {
                    //signedInAdmin = nullptr;
                    //std::cout << signedInAdmin->getAdministratorName() << ", you have successfully signed out." << std::endl;
                    break;
                }
                else if (command == "add admin") {
                    std::string name, email, username, password;
                    std::cout << "Enter name: ";
                    std::getline(std::cin, name);
                    std::cout << "Enter email: ";
                    std::getline(std::cin, email);
                    do {
                        std::cout << "Enter username (maximum 16 characters): ";
                        std::getline(std::cin, username);

                        if (username.length() > 16) {
                            std::cout << "Username exceeds the maximum length of 16 characters. Please try again." << std::endl;
                        }
                    } while (username.length() > 16);

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
                    do {
                        std::cout << "Enter username (maximum 16 characters): ";
                        std::getline(std::cin, username);

                        if (username.length() > 16) {
                            std::cout << "Username exceeds the maximum length of 16 characters. Please try again." << std::endl;
                        }
                    } while (username.length() > 16);

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
                    std::string username;
                 
                    std::cout << "Enter username: ";
                    std::getline(std::cin, username);
                   
                    deletePlayer(players, username);

                }
                else if (command == "add hero")
                {
                    std::cout << "You can:" << std::endl << "1. add a new hero to the market"
                        << std::endl << "2. add a hero from archives"<<std::endl;
                    int methodOfAdding;
                    std::cin >> methodOfAdding;
                    if (methodOfAdding == 1) {
                        Hero newHero;
                        std::cout << "Enter Hero details:\n";
                        std::cin >> newHero;

                        MainMarket.addHero(newHero);
                        std::cin.ignore();
                        ArchivedMarket.addHeroToArch(newHero);
                        
                    }
                    else if (methodOfAdding == 2) {
                        ArchivedMarket.printMarket();
                        int choice;
                        cout << "Enter the number of the hero you want to add: ";
                        cin >> choice;

                        // Add the selected hero to the player's collection
                        const vector<Hero>& heroes = ArchivedMarket.getHeroes();
                        if (choice >= 1 && choice <= heroes.size())
                        {
                            const Hero& heroToAdd = heroes[choice - 1];
                            MainMarket.addHero(heroToAdd);
                            std::cin.ignore();
                        }
                        else
                        {
                            cout << "Invalid number." << endl;
                        }

                    }
                    else {
                        std::cout << "invalid choice";
                    }
                }
                else if (command == "show players") {
                    showPlayersToAdmin(players);
                }
                else if (command == "show administrators") {
                    showAdmins(administrators);
                }
                else {
                    std::cout << "Invalid command. Try another one!" << std::endl;
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
                if (counter <3) {
                    cout << "Enter command:" << std::endl;
                    // std::cin.ignore();
                    
                    
                    
                }
                if (counter >= 3&&logedout==0) {
                    std::cout << "limit reached. You need to sign out!"
                        <<std::endl<<"Enter command:";
                    

                }
                std::getline(std::cin, command);

                if (command == "sign out") {
                    std::cout << signedInPlayer->getPlayerName() << ", you have successfully signed out." << std::endl;

                    savePlayersToFile(players, PlayersFileName);
                    saveAdministratorsToFile(administrators, AdminsFileName);

                    // counter = 3;
                    logedout = 1;
                    continue;//!
                    //break;


                }

                /* if (counter>2) {
                     std::cout << "Invalid command. Enter valid one:" << std::endl;
                     break;}*/

                if (counter<3){
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
                        std::cin.ignore();
                        counter++;

                        //continue;
                        //break;
                    }
                    else if (command == "delete profile")
                    {

                        deletePlayer(players, signedInPlayer->getUsername());
                        counter = 3;
                        //  continue;
                          //break;
                    }
                    else if (command == "show balance")
                    {

                        cout << signedInPlayer->getMoneyBalance() << std::endl;
                        counter++;
                        //continue;
                        //break;
                    }
                    else if (command == "set to attack")
                    {
                        string heronickname;
                        cout << "enter nicnkame of the superhero" << std::endl;
                        cin >> heronickname;
                        signedInPlayer->setHeroAttackMode(heronickname);
                        counter++;
                        // continue;
                         //break;
                    }
                    else if (command == "set to defense")
                    {
                        string heronickname;
                        cout << "enter nicnkame of the superhero:" << std::endl;
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
                        cout << "Enter the username of the player you want to attack" << std::endl;
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
                        std::cout << "Invalid command. Try another one!" << std::endl;
                        // continue;
                         //break;
                    }
                }


            }
        }

        else {
        std::cout << "invalid choice"<<std::endl;
        continue;
        }
    }
}


