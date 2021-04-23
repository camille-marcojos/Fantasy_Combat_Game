/******************
 * Program: barbarian.hpp
 * Author: Camille Marcojos
 * Date: 11/10/19
 * Description: barbarian.hpp is the declaration file for barbarian.cpp.
*******************/
#ifndef BARBARIAN_H
#define BARBARIAN_H
#include <string>
#include "character.hpp" 
using std::string;

class Barbarian : public Character
{
    private:
    public:
        Barbarian();
        Barbarian(string t, int ar, int str);
        void description();
        int attack();
        void defense(int damage);
        void setDefense3(int damage);
        void setDefense2(int damage);
        void setDefense1(int damage);
        ~Barbarian();

};

#endif