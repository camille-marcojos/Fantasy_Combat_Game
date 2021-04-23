/******************
 * Program: vampire.cpp
 * Author: Camille Marcojos
 * Date: 11/10/19
 * Description: vampire.cpp is the implementation file for vampire.hpp and defines the vampire character functions.
*******************/
#include "vampire.hpp"
#include "character.hpp"
#include <iostream>
using std::cout;
using std:: endl;

/*******************
 * constructor
 * Parameters: nothing
 * Return: nothing
 * ****************/
Vampire::Vampire() : Character(){

}

/*******************
 * constructor
 * Parameters: string, int, int
 * Description: initializes the type, armor, strength, and attack and defense dice
 * Return: nothing
 * ****************/
Vampire::Vampire(string t, int ar, int str) : Character(t, ar, str){
    setAttackDie(1,12);
    setDefenseDie(1,6);
}

/*******************
 * description
 * Parameters: nothing
 * Description: sets description
 * Return: nothing
 * ****************/
void Vampire::description(){

    cout << type << endl;
    cout << "Description: " << "Suave, debonair, but vicious and surprisingly resilient." << endl;
}

/*******************
 * attack
 * Parameters: nothing
 * Description: function used in main to call character attack roll
 * Return: int
 * ****************/
int Vampire::attack(){

    int roll = rollDice("attack");
    cout << getName() << " generated " << roll << " attack point(s)!" << endl;
    return roll;
}

/*******************
 * defense
 * Parameters: int
 * Description: function used in main to call character defense roll
 * Return: nothing
 * ****************/
void Vampire::defense(int damage){

    int defenseRoll;
    int newStrength;

    //Special ability: charm
    int charm = rand() % 2 + 1;
    //cout << "Charm: " << charm << endl;

    if(charm == 1)
    {
        cout << getName() << " charmed his attacker! No damage was inflicted." << endl;
    } else
    {
        //-1 is returned from Medusa's special ability
        if(damage == -1){
            cout << getName() << " has turned into stone!" << endl;
            setStrength(0);
        } else{
            defenseRoll = rollDice("defense");
            cout << getName() << " generated " << defenseRoll << " defense points!" << endl;
            newStrength = calcDamage(defenseRoll,damage);
            setStrength(newStrength);
        }
    }

}

/*******************
 * destructor
 * Parameters: nothing
 * Return: nothing
 * ****************/   
Vampire::~Vampire(){
    
}