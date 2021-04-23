/******************
 * Program: medusa.cpp
 * Author: Camille Marcojos
 * Date: 11/10/19
 * Description: medusa.cpp is the implementation file for medusa.hpp and defines the medusa character functions.
*******************/
#include "medusa.hpp"
#include "character.hpp"
#include <iostream>
using std::cout;
using std:: endl;

/*******************
 * constructor
 * Parameters: nothing
 * Return: nothing
 * ****************/
Medusa::Medusa() : Character(){

}

/*******************
 * constructor
 * Parameters: string, int, int
 * Description: initializes the type, armor, strength, and attack and defense dice
 * Return: nothing
 * ****************/
Medusa::Medusa(string t, int ar, int str) : Character(t, ar, str){
    setAttackDie(2,6);
    setDefenseDie(1,6);
}

/*******************
 * description
 * Parameters: nothing
 * Description: sets description
 * Return: nothing
 * ****************/
void Medusa::description(){

    cout << type << endl;
    cout << "Description: " << "Scrawny lady with snakes for hair which helps her during combat. Just don’t look at her!" << endl;
}

/*******************
 * attack
 * Parameters: nothing
 * Description: function used in main to call character attack roll
 * Return: int
 * ****************/
int Medusa::attack(){

        int roll = rollDice("attack");

        //Special ability: glare
        if(roll == 12)
        {
            cout << getName() << " used glare on her opponent!" << endl;
            return -1;
        } else
        {
            cout << getName() << " generated " << roll << " attack point(s)!" << endl;
            return roll;
        }
}

/*******************
 * defense
 * Parameters: int
 * Description: function used in main to call character defense roll
 * Return: nothing
 * ****************/
void Medusa::defense(int damage){

    int defenseRoll;
    int newStrength;

    if(damage == -1){
        cout << getName() << " has turned into stone!" << endl;
        setStrength(0);
    } else
    {
        defenseRoll = rollDice("defense");
        cout << getName() << " generated " << defenseRoll << " defense points!" << endl;
        newStrength = calcDamage(defenseRoll,damage);
        setStrength(newStrength);
    }
    
}

/*******************
 * destructor
 * Parameters: nothing
 * Return: nothing
 * ****************/ 
Medusa::~Medusa(){
    
}
