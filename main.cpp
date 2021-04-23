/******************
 * Program: Project 3 - Fantasy Combat Game
 * Author: Camille Marcojos
 * Date: 11/10/19
 * Description: This is a Fantasy Combat Game where the user chooses two characters to fight each other. 
 * The user has 5 different character choices. A round consists of each characters attacking once and 
 * the game plays until a character dies. After a character dies, the user can choose to replay or quit.
*******************/
#include "character.hpp"
#include "barbarian.hpp"
#include "medusa.hpp"
#include "vampire.hpp"
#include "harrypotter.hpp"
#include "bluemen.hpp"
#include "menu.hpp"
#include "queue.hpp"
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main(){

    //Setting up seed for random dice rolls
    unsigned seed;
    seed = time(0);
    srand(seed);

    int play, choice, size;

    //For each character created by user
    Character* fighter;
    //Holds all characters created by user
    vector <Character*> allfighters;
    //Holds the two teams and losers
    Queue teamOne;
    Queue teamTwo;
    Queue losers;

    cout << "\n=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=" << endl;
    cout << "=+=+=+=+=+=+=+= FANTASY COMBAT GAME =+=+=+=+=+=+=+=" << endl;
    cout << "=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=+=\n" << endl;

    cout << "Please choose one of the following: " << endl;
    cout << "1. Play Game" << endl;
    cout << "2. Quit" << endl;
    cout << "Your input: ";
    play = twoChoiceMenu();

do{

    cout << "This is a one-user-two-player game. You will create two teams and select fighters for each team." << endl;
    cout << "\nHow many fighters do you want on each team?" << endl;
    cout << "Your input: ";
    size = getNum();
    cout << "\nEach team will have " << size << " fighter(s)." << endl;

    entertoContinue();

    //Create the two teams. Loop through fighters for each team
    for(unsigned int i = 1; i < 3; i++){

        cout << "============ CREATE TEAM " << i << " ============" << endl;
        int team = i;
        int fighterNum = 0;
        cout << "\nChoose the fighters for Team " << team << "." << endl;

        //create the fighters in each team
        for(int j = 0; j < size; j++){
            string name;
            fighterNum++;
            cout << "\nTEAM " << team << " - " << "FIGHTER " << fighterNum << ": ";
            mainMenu();
            choice = getMenuChoice();
            fighter = fighter->createCharacter(choice);
            fighter->description();

            //ask user to name fighter
            cout << "\nName your fighter. " << endl;
            cout << "Name: ";
            getline(cin,name);
            fighter->setName(name);

            //holding all dynamically allocated characters so program can call delete at the end of tournament
            allfighters.push_back(fighter);
            
            //add fighter to container
            if(team == 1){
                teamOne.addBack(fighter);
            }else{
                teamTwo.addBack(fighter);
            }
            cout << endl;
        }

        team++;
    }

    cout << "================= LINE-UP =================" << endl;

    cout << "\nTeam 1: ";
    teamOne.printQueue();
    cout << "Team 2: ";
    teamTwo.printQueue();

    entertoContinue();


    //int i = 0;
    int playerNum = 1;
    int round = 1;
    int teamOneScore = 0, teamTwoScore = 0;
    int attack;
    bool tournamentDone = false;
    Character *P1, *P2;
    cout << "============ TOURNAMENT BEGINS ============\n" << endl;


    //Loop for game flow, do while the user choosers to play game and re-play game
    do
    {  
        
        P1 = teamOne.getFront();
        P2 = teamTwo.getFront();
        cout << "+-+-+-+-+-+-+- ROUND " << round << " -+-+--+-+-+-+-+\n" << endl;

        cout << "[Team 1 - Fighter " << playerNum << " - Type " << P1->getType() << "] ";
        cout << " vs. [Team 2 - Fighter " << playerNum << " - Type " << P2->getType() << "]" << endl;
        cout << P1->getName() << " vs. " << P2->getName(); 
        cout << endl;

        //Team 1 attacks and Team 2 defends
        cout << endl;
        cout << "Team 1 " << P1->getName() << " attacks!" << endl;
        attack = P1->attack();
        cout << endl;

        cout << "Team 2 " << P2->getName() << " defends!" << endl;
        cout << "Defense Stats - Armor: " << P2->getArmor() << " Strength: " << P2->getStrength() << endl;
        P2->defense(attack);  
        cout << "Updated defense stats - ";
        cout << "Armor: " << P2->getArmor() << " Strength: " << P2->getStrength() << endl;
        round++;
        cout << endl;
        entertoContinue();

        //Check if Team 2 fighter is dead, if so end battle
        if(P2->isDead())
        {
            cout << "+-+-+-+-+-+-+- BATTLE ENDED -+-+--+-+-+-+-+\n" << endl;
            cout << "[Team 1 - Fighter " << playerNum << " - Type " << P1->getType() << "] ";
            cout << " vs. [Team 2 - Fighter " << playerNum << " - Type " << P2->getType() << "]" << endl;

            cout << "Team 2 - Fighter " << playerNum << ": " << P2->getName() << " died! " << endl;
            cout << "Team 1 - Fighter " << playerNum << ": " << P1->getName() << " wins!" << endl;

            teamTwoScore--;
            losers.addBack(P2);
            teamTwo.removeFront();

            teamOneScore++;
            P1->recover();
            teamOne.addBack(P1);
            teamOne.removeFront();

            //Check if Team 2 is empty, if so end tournament
            if(teamTwo.isEmpty())
                tournamentDone = true;
            else{

                playerNum++;
                round = 1;

                cout << "\n============ NEXT FIGHTER ============\n" << endl;

            }

            entertoContinue();

        } else
        {
            cout << "+-+-+-+-+-+-+- ROUND " << round << " -+-+--+-+-+-+-+\n" << endl;
            cout << "[Team 1 - Fighter " << playerNum << " - Type " << P1->getType() << "] ";
            cout << " vs. [Team 2 - Fighter " << playerNum << " - Type " << P2->getType() << "]" << endl;
            cout << P1->getName() << " vs. " << P2->getName(); 
            cout << endl;

            //Team 2 attacks and Team 1 defends
            cout << endl;
            cout << "Team 2 " << P2->getName() << " attacks!" << endl;
            attack = P2->attack();
            cout << endl;

            cout << "Team 1 " << P1->getName() << " defends!" << endl;
            cout << "Defense Stats - Armor: " << P1->getArmor() << " Strength: " << P1->getStrength() << endl;
            P1->defense(attack);  
            cout << "Updated defense stats - ";
            cout << "Armor: " << P1->getArmor() << " Strength: " << P1->getStrength() << endl;
            cout << endl;
            round++;
            entertoContinue();
            
            //Check if Team 1 Fighter is dead. If so, end battle
            if(P1->isDead())
            {
                cout << "+-+-+-+-+-+-+- BATTLE ENDED -+-+--+-+-+-+-+\n" << endl;
                cout << "[Team 1 - Fighter " << playerNum << " - Type " << P1->getType() << "] ";
                cout << " vs. [Team 2 - Fighter " << playerNum << " - Type " << P2->getType() << "]" << endl;

                cout << "Team 1 - Fighter " << playerNum << ": " << P1->getName() << " died! " << endl;
                cout << "Team 2 - Fighter " << playerNum << ": " << P2->getName() << " wins!" << endl;

                teamOneScore--;
                losers.addBack(P1);
                teamOne.removeFront();

                teamTwoScore++;
                P2->recover();
                teamTwo.addBack(P2);
                teamTwo.removeFront();

                //Check if Team 1 is empty, if so end tournament
                if(teamOne.isEmpty())
                    tournamentDone = true;
                else{

                    //i++;
                    playerNum++;
                    round = 1;

                    cout << "\n============ NEXT FIGHTER ============\n" << endl;
                }

                entertoContinue();
            }

       }
    
    }while(!tournamentDone);


    cout << "============ TOURNAMENT ENDED ============\n" << endl;
    cout << "Team 1 Final Score: " << teamOneScore << endl;
    cout << "Team 2 Final Score: " << teamTwoScore << endl;

    //compare team scores and output winner or tie
    if(teamOneScore == teamTwoScore)
        cout << "It's a tie!" << endl;
    else if (teamOneScore > teamTwoScore)
        cout << "Team 1 wins!" << endl;
    else
        cout << "Team 2 wins!" << endl;

    //ask user if they want to display loser pile
    cout << "Do you want to display the loser pile?" << endl;
    cout << "1. Yes" << endl;
    cout << "2. No" << endl;
    cout << "Your input: ";
    choice = twoChoiceMenu();

    if(choice == 1)
    {
        cout << "Loser pile: ";
        losers.printBackwardsQueue();   
    }

    //freeing the memory allocated for the battling fighters
    delete P1;
    delete P2;

    //freeing all memory allocated for the creation of characters
    for ( int i = 0; i < allfighters.size(); i++ )    
        delete allfighters[i];    
    allfighters.clear();

    //freeing all the memory allocated from creation of nodes
    teamOne.~Queue();
    teamTwo.~Queue();
    losers.~Queue();

    replayMenu();
    play = twoChoiceMenu();

}while(play == 1);

    cout << "Game is quitting. Good-bye!\n" << endl;

    return 0;
}