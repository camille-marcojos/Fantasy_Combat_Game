/******************
 * Program: medusa.hpp
 * Author: Camille Marcojos
 * Date: 11/10/19
 * Description: medusa.hpp is the declaration file for medusa.cpp.
*******************/
#ifndef MEDUSA_H
#define MEDUSA_H
#include <string>
#include "character.hpp"
using std::string;

class Medusa : public Character
{
    private:
    public:
        Medusa();
        Medusa(string t, int ar, int str);
        void description();
        int attack();
        void defense(int damage);
        ~Medusa();
};

#endif