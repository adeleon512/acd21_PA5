//
// Created by Adam on 2/26/2017.
//

/*
 * nLLImp.cpp
 *
 *  Created on: Mar 24, 2014
 *      Author: Adam C. De Leon
 *      Class: cs2308
 *      Section: 1
 *      Roster: 6
 *      Program: 5
 */
#include <iostream>
#include <iostream>
#include "nLL.h"

NumberList::NumberList() {
    head = NULL;
    head2 = NULL;
    head3 = NULL;
}

NumberList::~NumberList() {
    ListNode *nodePtr;  //traversal ptr
    ListNode *nextNode; //saves the next node
    ListNode2 *nodePtr2;
    ListNode2 *nextNode2;
    ListNode3 *nodePtr3;
    ListNode3 *nextNode3;

    nodePtr = head;    //start at head of list
    while (nodePtr) {
        nextNode = nodePtr->next;  //save the next
        delete nodePtr;         //delete current
        nodePtr = nextNode;     //advance pointer
    }

    nodePtr2 = head2;        //start at head for secondary list
    while (nodePtr2) {
        nextNode2 = nodePtr2->next2;    //save the next
        delete nodePtr2;                //delete current
        nodePtr2 = nextNode2;        //advance pointer
    }

    nodePtr3 = head3;        //start at head for second secondary list
    while (nodePtr3) {
        nextNode3 = nodePtr3->next3;    //save the next
        delete nodePtr3;                //delete current
        nodePtr3 = nextNode3;        //advance pointer
    }
}

void NumberList::appendNode(int num) {
    ListNode *newNode; //to point to a new node
    ListNode *nodePtr;  //to move through the list

    //Allocate a new node and store the num there
    newNode = new ListNode;
    newNode->value = num;
    newNode->next = NULL;

    //if there are no nodes in the list
    //make newNodethe first node
    if (!head) {
        head = newNode;
    } else {
        //Otherwise, insert newNode at end.
        //Initialize nodePtr to head at end
        nodePtr = head;

        //Find the last node in the list
        while (nodePtr->next)
            nodePtr = nodePtr->next;

        //insert newNode as last node
        nodePtr->next = newNode;
    }
}

void NumberList::displayList() {
    ListNode *nodePtr; //To move through the list

    //Position nodePtr at the head of the list
    nodePtr = head;

    //while nodePtr points to a node, traverse the list.
    while (nodePtr) {
        //Display the value in this node
        cout << nodePtr->value << " ";

        //move to the next node.
        nodePtr = nodePtr->next;
    }
}

void NumberList::displayList2() {
    ListNode2 *nodePtr2;        //to move through list
    nodePtr2 = head2;    //position nodePtr at head of list

    cout << "List 1 = ";
    //traverse list while nodePtr points to node
    while (nodePtr2) {
        cout << nodePtr2->value2 << " "; //display the value
        nodePtr2 = nodePtr2->next2;        //move to next node
    }
}

void NumberList::displayList3() {
    ListNode3 *nodePtr3;    //to move through list
    nodePtr3 = head3;        //position nodePtr at head of list

    cout << "List 2 = ";
    //traverse list while nodePtr points to node
    while (nodePtr3) {
        cout << nodePtr3->value3 << " ";    //display the value
        nodePtr3 = nodePtr3->next3;            //move to next node
    }
}

void NumberList::displayListBackward() {
    ListNode *last = NULL; //for last node

    //While nodePtr point to a node, traverse list
    while (last != head) {
        ListNode *currentPtr = head;
        while (currentPtr->next != last) {
            currentPtr = currentPtr->next;
        }
        cout << currentPtr->value << " ";
        last = currentPtr;
    }
}

void NumberList::removeListNode(int num) {
    ListNode *nodePtr;
    ListNode *previous;
    //number passed to specify removal node
    for (int i = 0; i < num; i++) {
        previous = nodePtr;
        nodePtr = nodePtr->next;        //traverse list until you hit number
    }
    previous->next = nodePtr->next;    //Previous now points to same as nodePtr
    delete nodePtr;                //delete node
}

void NumberList::rotateList() {
    ListNode *newNode; //to point to a new node
    ListNode *nodePtr;  //to move through the list

    //Allocate a new node and store the num there
    newNode = new ListNode;
    newNode->next = NULL;

    //if there are no nodes in the list
    //make newNodethe first node
    if (!head)
        cout << "The list is empty.";
        //Otherwise, insert newNode at end.
    else {
        //Initialize nodePtr to head at end
        nodePtr = head;
        newNode->value = nodePtr->value;


        //Find the last node in the list
        while (nodePtr->next) {
            nodePtr = nodePtr->next; //Make it point to next.
        }
        //insert newNode as last node
        nodePtr->next = newNode;
        nodePtr = head;
        head = nodePtr->next;
    }
}

void NumberList::divideListAT(int index) {
    ListNode *nodePtr;            //current index pointer
    ListNode2 *temp2;            //temp carrier for new first list
    ListNode2 *newNode2;
    ListNode3 *temp3;            //temp carrier for new second list
    ListNode3 *newNode3;

    //assign each list to a head
    nodePtr = head;
    temp2 = head2;
    temp3 = head3;

    //index passed from main
    for (int i = 0; i < index; i++) {
        newNode2 = new ListNode2; //allocate new node
        newNode2->value2 = nodePtr->value;  //assign values to new node
        nodePtr = nodePtr->next;        //traverse list
        newNode2->next2 = NULL;            //Set the new node pointer to null

        //If at first position
        if (i == 0) {
            head2 = newNode2;
            temp2 = newNode2;
        } else if (i >= 0) {
            //Other than first position
            temp2->next2 = newNode2;
            temp2 = newNode2;
        }
    }

    //Display the new first list
    displayList2();
    cout << endl;

    //start the new list at this position
    //traverse the list until NULL
    for (int i = index; i < 19; i++) {
        newNode3 = new ListNode3; //create new node
        newNode3->value3 = nodePtr->value;
        nodePtr = nodePtr->next;
        newNode3->next3 = NULL;

        //enter values from 10th position
        if (i == index) {
            head3 = newNode3;  //first value of list
            temp3 = newNode3;
        } else if (i >= index) {
            //all other values
            temp3->next3 = newNode3;
            temp3 = newNode3;
        }
    }

    //display the new second list
    displayList3();
}







