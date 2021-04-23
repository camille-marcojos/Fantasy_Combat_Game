/******************
 * Program: menu.hpp
 * Author: Camille Marcojos
 * Date: 11/6/19
 * Description: menu.cpp is the implementation file for menu.hpp and defines the menu character functions.
*******************/
#ifndef MENU_H
#define MENU_H
#include <string>
using std::string;

void mainMenu();
int getMenuChoice();
bool is_int(string choice);
int twoChoiceMenu();
void replayMenu();
void entertoContinue();
int getNum();


#endif