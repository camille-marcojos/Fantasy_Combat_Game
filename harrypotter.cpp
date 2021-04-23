/******************
 * Program: harrypotter.cpp
 * Author: Camille Marcojos
 * Date: 11/10/19
 * Description: harrypotter.cpp is the implementation file for harrypotter.hpp and defines the harrypotter character functions.
*******************/
#include "harrypotter.hpp"
#include "character.hpp"
#include <iostream>
using std::cout;
using std:: endl;

/*******************
 * constructor
 * Parameters: nothing
 * Return: nothing
 * ****************/
HarryPotter::HarryPotter() : Character(){

}

/*******************
 * constructor
 * Parameters: string, int, int
 * Description: initializes the type, armor, strength, Harry's lives, and attack and defense dice
 * Return: nothing
 * ****************/
HarryPotter::HarryPotter(string t, int ar, int str) : Character(t, ar, str){
    setAttackDie(2,6);
    setDefenseDie(2,6);
    lives = 1;
}

/*******************
 * description
 * Parameters: nothing
 * Description: sets description
 * Return: nothing
 * ****************/
void HarryPotter::description(){

    cout << type << endl;
    cout << "Description: " << "Harry Potter is a wizard." << endl;
}

/*******************
 * attack
 * Parameters: nothing
 * Description: function used in main to call character attack roll
 * Return: int
 * ****************/
int HarryPotter::attack(){

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
void HarryPotter::defense(int damage){

    int defenseRoll;
    int newStrength;

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

/*******************
 * isDead
 * Parameters: nothing
 * Description: override function since Harry has an extra life 
 * Return: bool
 * ****************/
bool HarryPotter::isDead(){

    int  s = getStrength();   

    if(s <= 0)
    {
        if(lives <= 0)
        {
            return true;
        } else{
            lives--;
            setStrength(20);
            cout << getName() << " died, but he came back to life! He has " << lives << " lives now and " << getStrength() << " strength points.\n" << endl;
            return false;
        }
    } else
    {
        setStrength(s);
        return false;
    }

}

/*******************
 * destructor
 * Parameters: nothing
 * Return: nothing
 * ****************/
HarryPotter::~HarryPotter(){

}
