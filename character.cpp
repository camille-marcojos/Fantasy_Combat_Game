/******************
 * Program: character.cpp
 * Author: Camille Marcojos
 * Date: 11/10/19
 * Description: character.cpp is the implementation file for character.hpp and defines the character character functions.
*******************/
#include "character.hpp"
#include "barbarian.hpp"
#include "medusa.hpp"
#include "vampire.hpp"
#include "harrypotter.hpp"
#include "bluemen.hpp"
#include <iostream>
#include <string>
using std::cout;
using std::string;
using std::endl;


/*******************
 * constructor
 * Parameters: nothing
 * Return: nothing
 * ****************/
Character::Character(){
        armor = strength = 0;
        type = " ";
        desc = " ";
        name = " ";
}

/*******************
 * constructor
 * Parameters: string, int, int
 * Description: initializes the type, armor, strength
 * Return: nothing
 * ****************/
Character::Character(string t, int ar, int str){

        type = t;
        armor = ar;
        strength =str;
}

/*******************
 * setAttackDie
 * Parameters: int, int
 * Description: initializes attack die
 * Return: nothing
 * ****************/
void Character::setAttackDie(int num, int sides){

        for(int i = 0; i < num; i++)
        {
                attackDie.push_back(sides);
        }

        /*for(int i = 0; i < num; i++)
        {
                cout << attackDie[i] << " ";
        }*/
        //cout << "ATTACK DIE - NUMBER: " << attackDie.size() << " SIDES: " << attackDie[0];
        cout << endl;

}

/*******************
 * setDefenseDie
 * Parameters: int, int
 * Description: initializes defense die
 * Return: nothing
 * ****************/
void Character::setDefenseDie(int num, int sides){

        for(int i = 0; i < num; i++)
        {
                defenseDie.push_back(sides);
        }

        /*for(int i = 0; i < num; i++)
        {
                cout << defenseDie[i] << " ";
        }*/
        //cout << "DEFENSE DIE - NUMBER: " << defenseDie.size() << " SIDES: " << defenseDie[0];
        cout << endl;

}


/*******************
 * getAttackDie
 * Parameters: nothing
 * Description: returns attack die
 * Return: vector of ints
 * ****************/
vector<int> Character::getAttackDie(){
        return attackDie;
}

/*******************
 * getDefenseDie
 * Parameters: nothing
 * Description: returns defense die
 * Return: vector of ints
 * ****************/
vector<int> Character::getDefenseDie(){
        return defenseDie;
}

/*******************
 * getArmor
 * Parameters: nothing
 * Description: returns armor
 * Return: int
 * ****************/
int Character::getArmor(){
        return armor;
}

/*******************
 * getStrength
 * Parameters: nothing
 * Description: returns strength
 * Return: int
 * ****************/
int Character::getStrength(){
        return strength;        
}

/*******************
 * rollDice
 * Parameters: string
 * Description: rolls dice based on parameter (either attack die or defense die)
 * Return: int
 * ****************/
int Character::rollDice(string turn){

        int roll = 0;
        int total = 0;
        int dice;
        int sides;

        if(turn == "attack")
        {
                //cout << "Attack!" << endl;
                dice = attackDie.size();
                sides = attackDie[0];

                for(int i = 0; i < dice; i++)
                {
                        //int j = i;
                        //cout << "Roll " << ++j << ": ";
                        roll = rand() % sides + 1;
                        //cout << roll;
                        total += roll;
                        //cout << "Attack rolled: " << total << endl;
                }
        }

        if(turn == "defense")
        {
                //cout << "Defense!" << endl;
                dice = defenseDie.size();
                sides = defenseDie[0];

                for(int i = 0; i < dice; i++)
                {
                        //int j = i;
                        //cout << "Roll " << ++j << ": ";
                        roll = rand() % sides + 1;
                        //cout << roll;
                        total += roll;
                        //cout << " Defense rolled: " << total << endl;
                }
        }

        return total;

}

/*******************
 * setStrength
 * Parameters: int
 * Description: sets strength
 * Return: nothing
 * ****************/
void Character::setStrength(int s){
        strength = s;
}

/*******************
 * setArmor
 * Parameters: int
 * Description: sets armor
 * Return: nothing
 * ****************/
void Character::setArmor(int a){
        armor = a;
}

/*******************
 * calcDamage
 * Parameters: int,int
 * Description: calculates damage inflicted and subtracts attacker roll, defense roll, armor to find new strength
 * Return: int
 * ****************/
int Character::calcDamage(int roll, int damage){
        int newStrength;
        int finalDamage; 
        int armor = getArmor();

        finalDamage = damage - roll - armor;

        if(finalDamage < 0)
        {
                finalDamage = 0;
                cout << "Damage inflicted: " << finalDamage << " damage point(s)" << endl;
                newStrength = getStrength();
                newStrength -= finalDamage;
                return newStrength;
        } else{
                cout << "Damage inflicted: " << finalDamage << " damage point(s)" << endl;
                newStrength = getStrength();
                newStrength -= finalDamage;
                return newStrength;
        }
}

/*******************
 * isDead
 * Parameters: nothing
 * Description: checks strength value if its <= 0, if <= 0 character is dead
 * Return: bool
 * ****************/
bool Character::isDead(){

        int  s = getStrength();
        
        if(s <= 0)
        {
                return true;
        } else
        {
                setStrength(s);
                return false;
        }

}

/*******************
 * getType
 * Parameters: nothing
 * Description: returns character type
 * Return: string
 * ****************/
string Character::getType(){
        return type;
}

/*******************
 * createCharacter
 * Parameters: int
 * Description:  creates character type based on input from user from choices given in menu
 * Return: Character*
 * ****************/
Character* Character::createCharacter(int choice){

Character* ch = nullptr;

switch (choice)
        {
        case 1:
            cout << "You chose Vampire!";
            ch = new Vampire("Vampire",1, 18);
            return ch;
            break;
        case 2:
            cout << "You chose Barbarian!";
            ch = new Barbarian("Barbarian",0, 12);
            return ch;
            break;
        case 3:
            cout << "You chose Blue Men!\n";
            ch = new BlueMen("Blue Men",3, 12);
            return ch;
            break;
        case 4:
            cout << "You chose Medusa!";
            ch = new Medusa("Medusa",3, 8);
            return ch;
            break;
        case 5:
            cout << "You chose Harry Potter!";
            ch = new HarryPotter("Harry Potter",0, 10);
            return ch;
            break;
        default:
            break;
        };
        
        return ch;
}

void Character::setName(string n){
        name = n;
}

string Character::getName(){
        return name;
}

void Character::recover(){
        int roll;
        int oldStr = getStrength();
        int newStr;
        int recovery;

        roll = rand() % 6 + 1;
        //cout << "Recover roll: " << roll << endl;

        if(roll == 5)
        {
                recovery = oldStr * .5;
                cout << getName() << " recovered " << recovery << " strength points." << endl;
                newStr = oldStr + recovery;
                setStrength(newStr);
        }
}


Character::~Character(){

}


