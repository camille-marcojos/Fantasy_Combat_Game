/******************
 * Program: character.hpp
 * Author: Camille Marcojos
 * Date: 11/10/19
 * Description: character.hpp is the declaration file for character.cpp.
*******************/
#ifndef CHARACTER_H
#define CHARACTER_H
#include <string> 
#include <vector>
using std::string;
using std::vector;

class Character
{
    protected:
        int armor;
        int strength;
        vector<int> attackDie;
        vector<int> defenseDie;
        string type;
        string desc;
        string name;
    public:
        Character();
        Character(string t, int arm, int str);
        Character* createCharacter(int choice);
        virtual void description() = 0;
        void setAttackDie(int num, int sides);
        void setDefenseDie(int num, int sides);
        vector<int> getAttackDie();
        vector<int> getDefenseDie();
        virtual int attack() = 0;
        virtual void defense(int damage) = 0;
        int getArmor();
        int getStrength();
        void setStrength(int s);
        void setArmor(int a);
        virtual int rollDice(string turn);
        int calcDamage(int roll,int d);
        virtual bool isDead();
        string getType();
        void setName(string n);
        string getName();
        void recover();
        virtual ~Character();

};

#endif