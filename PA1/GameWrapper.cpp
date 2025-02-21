
#include "GameWrapper.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::getline;
using std::stringstream;
using std::stoi;

GameWrapper::GameWrapper()
{
    loadCommandData();
    loadProfileData();
}

GameWrapper::~GameWrapper()
{
    if(commandInput.is_open())
    {
        commandInput.close();
    }
    if(profileInput.is_open())
    {
        profileInput.close();
    }
    writeCommand();
    writeProfile();

}

int GameWrapper::displayMenu()
{
    int option;
    int status = 0;
    while (status == 0)
    {
        cout << "Please select a menu option" << endl
        << "1. Display Game Rules" << endl
        << "2. Begin New Game" << endl
        << "3. Load Previous Game" << endl
        << "4. Add Command" << endl
        << "5. Remove Command" << endl
        << "6. Display All Commands" << endl
        << "7. Save and Exit" << endl;
        cin >> option;
        if(option >= 1 && option <= 7)
        {
            status = 1;
        }
        else
        {
            system("clear");
            cout << "Please select a valid option" << endl;
            cin.get();
            system("clear");
        }
    }
    return option;
}

void GameWrapper::runGame()
{
    int option = 0;
    srand(time(0));
     
    do
    {
        option = displayMenu();
        cin.get();
        system("clear");
        switch (option)
        {
        case 1:
            displayRules();
            cin.get();
            system("clear");
            break;
        case 2:
            newGame();
            cin.get();
            system("clear");
            break;
        case 3:
            continueGame();
            cin.get();
            system("clear");
            break;
        case 4:
            updateCommandData();
            cin.get();
            system("clear");
            break;
        case 5:
            removeCommand();
            cin.get();
            system("clear");
            break;
        case 6:
            printCommand();
            cin.get();
            system("clear");
            break;
        }
    } while (option != 7);
}

void GameWrapper::displayRules()
{
    cout << "Welcome to Linux Trivia!" << endl
        << "The goal of the game is to match the Linux command with the correct command description" << endl
        << "Getting the correct answer will gain you 2 points while getting the incorrect answer will deduct 2" << endl
        << "To save your player profile just press save and exit" << endl
        << "Have fun!" << endl;
}

void GameWrapper::loadProfileData()//used to read profile csv at execution
{
    profileInput.open("profile.csv");
    string line;
    Profile newProfile;
    
    if (profileList.getHeadPtr() != nullptr)
    {
        profileList.~List();
    }
    
    while(getline(profileInput, line))
    {
       stringstream substr(line);
       string name;
       string score;
       getline(substr, name, ',');
       newProfile.setName(name);
       getline(substr, score, ',');
       newProfile.setScore(stoi(score));
       profileList.insertAtFront(newProfile);
    }
    profileInput.close();
}

void GameWrapper::writeProfile()//used to write profile csv at termination
{
    ofstream output("profile.csv");
    Node<Profile>* pCur = profileList.getHeadPtr();

    while(pCur != nullptr)
    {
        output << pCur->getData().getName() << "," << pCur->getData().getScore() << endl;
        pCur = pCur->getNextPtr();
    }
    output.close();
}

void GameWrapper::loadCommandData()//used to read command csv at execution
{
    commandInput.open("commands.csv");
    string line;
    Command newCommand;
    
    if (commandList.getHeadPtr() != nullptr)
    {
        commandList.~List();
    }
    
    while(getline(commandInput, line))
    {
       stringstream substr(line);
       string key;
       string value;
       getline(substr, key, ',');
       newCommand.setCommand(key);
       getline(substr, value, ',');
       newCommand.setDescription(value);
       getline(substr, value, ',');
       commandList.insertAtFront(newCommand);
    }
    commandInput.close();
}

void GameWrapper::updateCommandData()//adds command
{
    Node<Command>* pCur = commandList.getHeadPtr();
    cout << "What Command Would you like to add?" << endl;
    string commandName;
    cin >> commandName;

    bool statusB = true;
    while(statusB && pCur != nullptr)
    {
        if(pCur->getData().getCommand() == commandName)
        {
            cout << "Sorry looks like that command's already been inputted.";
            cin.get();
            statusB = false;
        }
        else
        {
            pCur = pCur->getNextPtr();
        }
    }
    if(statusB)
    {
        string commandDescription;
        Command newCommand;
        cout << "What would you like the description of " << commandName << " to be?" << endl;
        cin >> commandDescription;
        newCommand.setCommand(commandName);
        newCommand.setDescription(commandDescription);
        commandList.insertAtFront(newCommand);
    }
}

void GameWrapper::removeCommand()
{
    string commandName;
    cout << "Which command would you like to remove?" << endl;
    cin >> commandName;

    Node<Command>* pCur = commandList.getHeadPtr(); 
    bool status = true;
    while(status && pCur != nullptr)
    {
        if(pCur->getData().getCommand() == commandName)
        {
            commandList.removeNode(pCur->getData());
            cout << "Command removed";
            cin.get();
            status = false;
        }
        else
        {
            pCur = pCur->getNextPtr();
        }
    }
    if(status)
    {
        cout << "Command not found please try again." << endl;
        removeCommand();
    }
}

void GameWrapper::writeCommand()//used to write profile csv at termination
{
    ofstream output("commands.csv");
    Node<Command>* pCur = commandList.getHeadPtr();

    while(pCur != nullptr)
    {
        output << pCur->getData().getCommand() << "," << pCur->getData().getDescription() << endl;
        pCur = pCur->getNextPtr();
    }
    output.close();
}

void GameWrapper::printCommand()
{
    Node<Command>* pCur = commandList.getHeadPtr();

    while(pCur != nullptr)
    {
        cout << pCur->getData().getCommand() << "," << pCur->getData().getDescription() << endl;
        pCur = pCur->getNextPtr();
    }
}

void GameWrapper::newGame()
{
    Profile newProfile;
    string playerName;
    int roundCount;

    cout << "Input player name" << endl;
    cin >> playerName;
    cout << "Please select how many rounds you'd like to play" << endl;
    cin >> roundCount;
    newProfile.setName(playerName);
    newProfile.setRounds(roundCount);

    int i = 0;
    while (i < newProfile.getRounds())
    {
        displayChoices(newProfile);
    }
    
    Node<Profile>* pCur = profileList.getHeadPtr();
    bool status = true;
    while(status && pCur != nullptr)
    {
        if(pCur->getData().getName() == playerName)
        {
            profileList.removeNode(pCur->getData());
            status = false;
            profileList.insertAtFront(newProfile);
        }
        else
        {
            pCur = pCur->getNextPtr();
        }
    }
    if(status)
    {
        profileList.insertAtFront(newProfile);
    }
}

void GameWrapper::continueGame()
{
    string playerName;
    cout << "Which profile would you like to continue playing on?" << endl;
    cin >> playerName;

    Node<Profile>* pCur = profileList.getHeadPtr();
    bool status = true;
    while(status && pCur != nullptr)
    {
        if(pCur->getData().getName() == playerName)
        {
            
            status = false;
        }
        else
        {
            pCur = pCur->getNextPtr();
        }
    }
    if(status)
    {
        cout << "Looks like you haven't played before, starting new game!" << endl;
        newGame();
    }
    else
    {
        int rounds;
        cout << "Welcome back " << pCur->getData().getName() << ", looks like you ended with " << pCur->getData().getScore() << " points!" << endl;
        cout << "How many rounds would you like to play?" << endl;
        cin >> rounds;
        pCur->getData().setRounds(rounds);
        int i = 0;
        while (i < pCur->getData().getRounds())
        {
            displayChoices(pCur->getData());
        }
    }

}

Node<Command>* GameWrapper::commandSelect()//decides what the distractors and correct answer wil be
{
    int num = rand()% 30 + 1;
    Node<Command>* pCur = commandList.getHeadPtr();

    int i = 0;
    while(i < num && pCur != nullptr)
    {
        pCur = pCur->getNextPtr();
        num--;
    }
    return pCur;
}

void GameWrapper::displayChoices(Profile& playerProfile)//main "game" component; where points and rounds are updateds
{
    Node<Command> *distractor1, *distractor2, *distractor3, *correctAnswer;

    distractor1 = commandSelect();
    distractor2 = commandSelect();
    distractor3 = commandSelect();
    correctAnswer = commandSelect();
    if (distractor1 == nullptr || distractor2 == nullptr || distractor3 == nullptr || correctAnswer == nullptr) {
        cout << "Error: One or more distractors or the correct answer are null." << endl;
        return;  // Exit the function early to avoid segmentation fault
    }
    cout << correctAnswer->getData().getCommand() << endl;
    cout << "Which description matches this command?" << endl;
    cout << "1. " << distractor1->getData().getDescription() << endl;
    cout << "2. " << distractor2->getData().getDescription() << endl;
    cout << "3. " << correctAnswer->getData().getDescription() << endl;
    cout << "4. " << distractor3->getData().getDescription() << endl;

    int choice;
    cin >> choice;
    if(choice == 3)
    {
        cout << "Correct!" << endl;
        playerProfile.setScore(playerProfile.getScore() + 2);
    }
    else
    {
        cout << "Sorry, incorrect" << endl;
        playerProfile.setScore(playerProfile.getScore() - 2);
    }
    playerProfile.setRounds(playerProfile.getRounds() - 1);
}
