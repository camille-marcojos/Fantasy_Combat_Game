/******************
 * Program: barbarian.cpp
 * Author: Camille Marcojos
 * Date: 11/10/19
 * Description: barbarian.cpp is the implementation file for barbarian.hpp and defines the barbarian character functions.
*******************/
#include "barbarian.hpp"
#include "character.hpp"
#include <iostream>
using std::cout;
using std:: endl;

/*******************
 * constructor
 * Parameters: nothing
 * Return: nothing
 * ****************/
Barbarian::Barbarian() : Character(){

}


/*******************
 * constructor
 * Parameters: string, int, int
 * Description: initializes the type, armor, strength, and attack and defense dice
 * Return: nothing
 * ****************/
Barbarian::Barbarian(string t, int ar, int str) : Character(t, ar, str){
    setAttackDie(2,6);
    setDefenseDie(2,6);
}

/*******************
 * description
 * Parameters: nothing
 * Description: sets description
 * Return: nothing
 * ****************/
void Barbarian::description(){

    cout << type << endl;
    cout << "Description: " << "Think Conan or Hercules from the movies. Big sword, big muscles, bare torso." << endl;
}

/*******************
 * attack
 * Parameters: nothing
 * Description: function used in main to call character attack roll
 * Return: int
 * ****************/
int Barbarian::attack(){

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
void Barbarian::defense(int damage){

    int defenseRoll;
    int newStrength;

    //-1 is returned from Medusa's special ability
    if(damage == -1){
        cout << getName() << " has turned into stone!" << endl;
        setStrength(0);
    } else{
        defenseRoll = rollDice("defense");
        cout << getName() << " generated " << defenseRoll << " defense point(s)!" << endl;
        newStrength = calcDamage(defenseRoll,damage);
        setStrength(newStrength);
    }

}

/*******************
 * destructor
 * Parameters: nothing
 * Return: nothing
 * ****************/       
Barbarian::~Barbarian(){
    
}


