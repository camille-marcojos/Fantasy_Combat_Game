/******************
 * Program: menu.cpp
 * Author: Camille Marcojos
 * Date: 11/6/19
 * Description: This is the menu and input validation functions for menu.hpp
*******************/
#include <iostream>
#include <string>
#include  <cstdlib>
#include "menu.hpp"
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::getline;
using std::isdigit;
using std::stol;

/*******************
 * getNum
 * This function is the input validation for when the user needs to input values for the array in recursive 
 * function #2 and the integer for recursive function #3. Users must input a number greater than or equal to 1.
 * Parameters: nothing
 * Return: int
 * ****************/

int getNum()
{
    int number;
    string input;    
    bool invalid = true;

    do
    {
        getline(cin,input);
        cout << endl;
        
        if(!input.empty())
        {
            if(is_int(input))
            {
                number = stol(input);
                if(number >= 0)
                    invalid = false;
                else
                {
                    cout << "Not a valid input. Try again." << endl;
                    cout << "Your input: ";
                    invalid = true; 
                }           
            }else
            {
                cout << "Not a valid input. Try again." << endl;
                cout << "Your input: ";
                invalid = true;      
            }
        }else{
            
            cout << "You did not enter anything. Try again." << endl;
            cout << "Your input: ";
            invalid = true;
        }
    }while(invalid);

    return number;
}

void entertoContinue()
{
    cout << "Press enter to continue.";
    //cin.ignore();
    string temp;
    getline(cin, temp);
    cout << endl;
}


void mainMenu(){

    cout << "Choose a character type to play:" << endl;
    cout << "1. Vampire" << endl;
    cout << "2. Barbarian" << endl;
    cout << "3. Blue Men" << endl;
    cout << "4. Medusa" << endl;
    cout << "5. Harry Potter" << endl;
    cout << "Your input: ";

}

void replayMenu(){

    cout << "\n1. Play again?" << endl;
    cout << "2. Exit the game" << endl;
    cout << "Your input: ";

}
/*******************
 * getMenuChoice
 * This function is the users input validation for the main mainMenu
 * Parameters: nothing
 * Return: int
 * ****************/
int getMenuChoice()
{
    int choice;
    string input;    
    bool invalid = true;

    do
    {
        getline(cin,input);
        cout << endl;
        
        if(!input.empty())
        {
            if(is_int(input))
            {
                choice = stol(input);
                if(choice >=1 && choice <= 5)
                    invalid = false;
                else
                {
                    cout << "Not a valid choice." << endl;
                    mainMenu();
                    invalid = true; 
                }           
            }else
            {
                cout << "Not a valid choice." << endl;
                mainMenu();
                invalid = true;      
            }
        }else{
            
            cout << "You did not enter anything." << endl;
            mainMenu();
            invalid = true;
        }
    }while(invalid);

    return choice;
}

/*******************
 * 
 * This function is the input validation for when the user only has 2 choices (1 or 2).
 * Parameters: nothing
 * Return: int
 * ****************/
int twoChoiceMenu()
{
    int number;
    string input;    
    bool invalid = true;

    do
    {
        getline(cin,input);
        cout << endl;
        
        if(!input.empty())
        {
            if(is_int(input))
            {
                number = stol(input);
                if(number >=1 && number <= 2)
                    invalid = false;
                else
                {
                    cout << "Not a valid input." << endl;
                    invalid = true; 
                }           
            }else
            {
                cout << "Not a valid input." << endl;
                invalid = true;      
            }
        }else{
            
            cout << "You did not enter anything." << endl;
            invalid = true;
        }
    }while(invalid);

    return number;
}

/*******************
 * is_int
 * This function checks that the user inputs is a digit and therefore a valid candidate 
 * to be converted by atol into an integer value by the getChoice and getNum functions.
 * Parameters: string for users input
 * Return: bool
 * ****************/
bool is_int(string choice)
{
    for(unsigned int i = 0; i < choice.size(); i++)
    {
        if(!isdigit(choice[i]))
            return false;
    }
    return true;
}
