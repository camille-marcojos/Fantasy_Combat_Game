/******************
 * Program: queue.hpp
 * Author: Camille Marcojos
 * Date: 11/6/19
 * Description: This is the header file for the queue implementation file
*******************/
#ifndef QUEUE_H
#define QUEUE_H
#include "character.hpp"

//Citation: Starting Out With C++ Early Objects 9th Ed. Gaddis et al pg. 1078
class Queue
{
    protected:
        struct QueueNode{
            Character* player;
            QueueNode* next;
            QueueNode* prev;
            QueueNode(Character* ch, QueueNode* next1 = nullptr, QueueNode* prev1 = nullptr)
            {
                player = ch;
                next = next1;
                prev = prev1;
            }
        };
        QueueNode* head;
    public:
        Queue() { head = nullptr; };
        ~Queue();
        void addBack(Character* ch);
        void printBackwardsQueue() const;
        Character* getFront();
        void removeFront();
        void printQueue() const;
        bool isEmpty() const;
};


#endif