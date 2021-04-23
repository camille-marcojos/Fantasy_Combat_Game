/******************
 * Program: bluemen.hpp
 * Author: Camille Marcojos
 * Date: 11/10/19
 * Description: bluemen.hpp is the declaration file for bluemen.cpp.
*******************/
#ifndef BLUEMEN_H
#define BLUEMEN_H
#include <string>
#include "character.hpp" 
using std::string;

class BlueMen : public Character
{
    private:
        vector<int> defenseDie1;
        vector<int> defenseDie2;
        vector<int> defenseDie3;
    public:
        BlueMen();
        BlueMen(string t, int ar, int str);
        void description();
        int attack();
        void defense(int damage);
        void setDefenseDie(int num, int sides);
        int rollDice(string die);
        ~BlueMen();


};

#endif