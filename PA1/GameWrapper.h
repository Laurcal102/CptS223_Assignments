#pragma once

#include <fstream>
#include "List.h"
#include "Command.h"
#include "Profile.h"

using std::ofstream;
using std::ifstream;

class GameWrapper
{
    public:
    GameWrapper();
    ~GameWrapper();

    int displayMenu();
    void displayRules();

    void loadProfileData();
    void writeProfile();

    void updateCommandData();
    void removeCommand();
    void loadCommandData();
    void writeCommand();
    void printCommand();

    Node<Command>* commandSelect();
    void displayChoices(Profile &playerProfile);
    void newGame();
    void continueGame();
    void runGame();
    
    private:
    ifstream commandInput;
    ofstream commandOutput;
    ifstream profileInput;
    ofstream profileOutput;
    List<Command> commandList;
    List<Profile> profileList;
};