/******************
 * Program: bluemen.cpp
 * Author: Camille Marcojos
 * Date: 11/10/19
 * Description: bluemen.cpp is the implementation file for bluemen.hpp and defines the bluemen character functions.
*******************/
#include "bluemen.hpp"
#include "character.hpp"
#include <iostream>
using std::cout;
using std:: endl;


/*******************
 * constructor
 * Parameters: nothing
 * Return: nothing
 * ****************/
BlueMen::BlueMen() : Character(){

}

/*******************
 * constructor
 * Parameters: string, int, int
 * Description: initializes the type, armor, strength, and attack and defense dice
 * Return: nothing
 * ****************/
BlueMen::BlueMen(string t, int ar, int str) : Character(t, ar, str){
    setAttackDie(2,10);
    setDefenseDie(3,6);
}

/*******************
 * description
 * Parameters: nothing
 * Description: sets description
 * Return: nothing
 * ****************/
void BlueMen::description(){

    cout << type << endl;
    cout << "Description: " << "Small, 6 inch tall, but fast and tough.\nThey are hard to hit so they can take some damage.\nThey can also do a LOT of damage when they crawl inside enemies’ armor or clothing." << endl;
}


/*******************
 * attack
 * Parameters: nothing
 * Description: function used in main to call character attack roll
 * Return: int
 * ****************/
int BlueMen::attack(){

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
void BlueMen::defense(int damage){

    int defenseRoll;
    int newStrength;
    int oldStrength = getStrength();

    //-1 is returned from Medusa's special ability
    if(damage == -1){
        cout << getName() << " have turned into stone!" << endl;
        setStrength(0);
    } else{
        //Checking strength and using corresponding defense dice
        if(oldStrength >= 0 && oldStrength <= 4)
        {
            defenseRoll = rollDice("defenseDie1");
            cout << getName() << " generated " << defenseRoll << " defense points!" << endl;
            newStrength = calcDamage(defenseRoll,damage);
            setStrength(newStrength);
        }else if(oldStrength >= 5 && oldStrength <= 8)
        {
            defenseRoll = rollDice("defenseDie2");
            cout << getName() << " generated " << defenseRoll << " defense points!" << endl;
            newStrength = calcDamage(defenseRoll,damage);
            setStrength(newStrength);

        }else if(oldStrength >= 9 && oldStrength <= 12)
        {
            defenseRoll = rollDice("defenseDie3");
            cout << getName() << " generated " << defenseRoll << " defense points!" << endl;
            newStrength = calcDamage(defenseRoll,damage);
            setStrength(newStrength);
        }
    }
}

/*******************
 * setDefenseDie
 * Parameters: int,int
 * Description: override function for bluemen since # of defense dice varies according to strength
 * Return: nothing
 * ****************/
void BlueMen::setDefenseDie(int num, int sides){

    for(int i = 0; i < num; i++)
    {
        defenseDie3.push_back(sides);
    }

    //Creating 3 sets of defense dice that varies in # of dice to correspond with blue men strength
    defenseDie2 = defenseDie3;
    defenseDie2.pop_back();
    defenseDie1 = defenseDie2;
    defenseDie1.pop_back();

    //Tests
    /*cout << "DEFENSE DIE 3 - NUMBER: " << defenseDie3.size() << " SIDES: " << defenseDie3[0];
    cout << endl;

    cout << "DEFENSE DIE 2 - NUMBER: " << defenseDie2.size() << " SIDES: " << defenseDie2[0];
    cout << endl;

    cout << "DEFENSE DIE 1 - NUMBER: " << defenseDie1.size() << " SIDES: " << defenseDie1[0];
    cout << endl;

    for(unsigned int i = 0; i < defenseDie1.size(); i++)
    {
            cout << defenseDie1[i] << " ";
    }
    for(unsigned int i = 0; i < defenseDie2.size(); i++)
    {
            cout << defenseDie2[i] << " ";
    }
    for(unsigned int i = 0; i < defenseDie3.size(); i++)
    {
            cout << defenseDie3[i] << " ";
    }*/
}

/*******************
 * rollDice
 * Parameters: string
 * Description: override function for bluemen since # of defense dice varies according to strength
 * Return: nothing
 * ****************/
int BlueMen::rollDice(string die){

    int roll = 0;
    int total = 0;
    int dice;
    int sides;

    if(die == "attack")
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
            //cout << " Total: " << total << endl;
        }
    }

    if(die == "defenseDie1")
    {
        //cout << "Defense Die 1!" << endl;
        dice = defenseDie1.size();
        sides = defenseDie1[0];

        for(int i = 0; i < dice; i++)
        {
            //int j = i;
            //cout << "Roll " << ++j << ": ";
            roll = rand() % sides + 1;
            //cout << roll;
            total += roll;
            //cout << " Total: " << total << endl;
        }
    }

    if(die == "defenseDie2")
    {
        //cout << "Defense Die 2!" << endl;
        dice = defenseDie2.size();
        sides = defenseDie2[0];

        for(int i = 0; i < dice; i++)
        {
            //int j = i;
            //cout << "Roll " << ++j << ": ";
            roll = rand() % sides + 1;
            //cout << roll;
            total += roll;
            //cout << " Total: " << total << endl;
        }
    }

    if(die == "defenseDie3")
    {
        //cout << "Defense Die 3!" << endl;
        dice = defenseDie3.size();
        sides = defenseDie3[0];

        for(int i = 0; i < dice; i++)
        {
            //int j = i;
            //cout << "Roll " << ++j << ": ";
            roll = rand() % sides + 1;
            //cout << roll;
            total += roll;
            //cout << " Total: " << total << endl;
        }
    }

return total;
}

/*******************
 * destructor
 * Parameters: nothing
 * Return: nothing
 * ****************/
BlueMen::~BlueMen(){

}
