/******************
 * Program: queue.cpp
 * Author: Camille Marcojos
 * Date: 11/6/19
 * Description: These are the queue functions for a circular linked list that adds a node
 * to the back, removes the front node, prints the queue, and displays the value the head
 * is pointing to.
*******************/
#include "queue.hpp"
#include <iostream>
#include <fstream>
using std::cout;
using std::endl;


/*******************
 * addBack
 * This function adds a value to the back of the list
 * Parameters: double
 * Return: nothing
 * ****************/
void Queue::addBack(Character* ch) {

    if(head == nullptr){
        head = new QueueNode(ch);
        head->next = head;
        head->prev = head;

    } else
    {
        QueueNode* prevNodePtr = head;
        QueueNode* nodePtr = head->next;
        
        while(nodePtr != head)
        {
            prevNodePtr = nodePtr; 
            nodePtr = nodePtr->next;
        }   
        prevNodePtr->next = new QueueNode(ch,head,prevNodePtr);
        head->prev = prevNodePtr->next;
    }

    //printQueue();

}

/*******************
 * removeFront
 * This function removes a value at the front of the list
 * Parameters: nothing
 * Return: nothing
 * ****************/
void Queue::removeFront() {
    if(isEmpty())
    {
        cout << "Removal error. This list is empty." << endl;
        return;
    }else if( head == head->next)
    {
        delete head;
        head = nullptr;
    }else
    {
        QueueNode* nodePtr = head;
        head = head->next;
        head->prev = nodePtr->prev;
        head->prev->next = head;
        delete nodePtr;
    }
    
    //printQueue();

}


/*******************
 * printQueue
 * This function displays list in normal order
 * Parameters: nothing
 * Return: nothing
 * ****************/
void Queue::printQueue() const {

    if(isEmpty())
    {
        cout << "Display error. The list is empty." << endl;
        return;
    }else{
        QueueNode *nodePtr = head;

        do
        {
            cout << nodePtr->player->getName() << " ";
            nodePtr = nodePtr->next;
        }while(nodePtr != head);

    }

    cout << endl;
}

/*******************
 * printBackwardsQueue
 * This function displays list in normal order
 * Parameters: nothing
 * Return: nothing
 * ****************/
void Queue::printBackwardsQueue() const {

    if(isEmpty())
    {
        cout << "Display error. The list is empty." << endl;
        return;
    }else{
        QueueNode *nodePtr = head->prev;

        while(nodePtr != head)
        {
            cout << nodePtr->player->getName() << " ";
            nodePtr = nodePtr->prev;
        }

        cout << head->player->getName();
    }
    cout << endl;
}


/*******************
 * getFront
 * This function displays what the first node value
 * Parameters: nothing
 * Return: nothing
 * ****************/
Character* Queue::getFront(){

    if(isEmpty())
    {
        cout << "Error! The list is empty." << endl;
        return nullptr;
    }

    return head->player;
    //cout << "The head value is:  " << head->player << endl;

}

/*******************
 * isEmpty()
 * This function checks if the list is empty
 * Parameters: nothing
 * Return: bool
 * ****************/
bool Queue::isEmpty() const{

    if(head == nullptr)
    {
        return true;
    } else
    {
        return false;
    }
    
}

/*******************
 * deconstructor
 * This function frees all the allocated memory
 * Parameters: nothing
 * Return: nothing
 * ****************/
Queue::~Queue(){

    while(!isEmpty())
    {
        removeFront();
    }; 
}



