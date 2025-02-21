#pragma once

#include <string>
using std::string;

class Command
{
    public:
    Command()
    {
        key = "";
        value = "";
    }

    string getCommand()
    {
        return key;
    }

    string getDescription()
    {
        return value;
    }

    void setCommand(string newCommand)
    {
        key = newCommand;
    }
    
    void setDescription(string newDescription)
    {
        value = newDescription;
    }

    bool operator !=(Command& comparisonCommand)//overloaded comparison so I can compare command names using generic "data" type
    {
        return (key != comparisonCommand.getCommand());
    }

    private:
    string key;
    string value;
};

