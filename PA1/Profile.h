#pragma once

#include <string>
#include <iostream>

using std::string;
using std::endl;


class Profile
{
    public:
    Profile()
    {
        name = "";
        rounds = 0;
        score = 0;
    }

    string getName()
    {
        return name;
    }

    int getRounds()
    {
        return rounds;
    }

    int getScore()
    {
        return score;
    }

    void setName(string newName)
    {
        name = newName;
    }

    void setRounds(int newRound)
    {
        rounds = newRound;
    }

    void setScore(int newScore)
    {
        score = newScore;
    }

    bool operator !=(Profile& comparisonProfile)//overloaded comparison so I am able to compare the "name" attribute using generic "data" type
    {
        return (name != comparisonProfile.getName());
    }


    private:
    string name;
    int rounds;
    int score;
};

