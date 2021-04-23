/******************
 * Program: vampire.hpp
 * Author: Camille Marcojos
 * Date: 11/10/19
 * Description: vampire.hpp is the declaration file for vampire.cpp.
*******************/
#ifndef VAMPIRE_H
#define VAMPIRE_H
#include <string>
#include "character.hpp" 
using std::string;

class Vampire : public Character
{
    private:
    public:
        Vampire();
        Vampire(string t, int ar, int str);
        void description();
        int attack();
        void defense(int damage);
        ~Vampire();

};

#endif