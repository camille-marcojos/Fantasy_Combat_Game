/******************
 * Program: harrypotter.hpp
 * Author: Camille Marcojos
 * Date: 11/10/19
 * Description: harrypotter.hpp is the declaration file for harrypotter.cpp.
*******************/
#ifndef HARRYPOTTER_H
#define HARRYPOTTER_H
#include <string>
#include "character.hpp" 
using std::string;

class HarryPotter : public Character
{
    private:
        int lives;
    public:
        HarryPotter();
        HarryPotter(string t, int ar, int str);
        void setLives(int l);
        void setName(string n);
        void description();
        int attack();
        void defense(int damage);
        bool isDead();
        ~HarryPotter();

};

#endif