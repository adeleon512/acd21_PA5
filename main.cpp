/*
 * nLLDriver.cpp
 *
 *  Created on: Mar 24, 2014
 *      Author: Adam C. De Leon
 *      Class: CS2308
 *      Section: 1
 *      Roster: 6
 *      Program: 5
 *      Program description: This program uses a random number generator to
 *      create a list then it appends those values to a linked list. It then
 *      displays those values. Then it displays them in reverse. Then removes
 *      the fifth node from the list and displays the remaining list. Then
 *      rotates the list, and finally it divides the list into two secondary
 *      lists and displays each of those secondary lists.
 */
#include<iostream>
#include<cstdlib>
#include "nLL.h"			//created library

using namespace std;

int main() {
    NumberList list;   //instance of NumberList
    int temp;            //value for temporary values generated.

    cout << "This program was written by Adam C. De Leon." << endl;
    cout << endl;
    //display the list
    cout << "First displaying the list after definition." << endl;
    list.displayList();
    cout << endl;

    //random number generator.
    for (int i = 0; i < 20; i++) {
        temp = rand() % 100 + 1;
        list.appendNode(temp);    //append to list
    }

    //display the list second time
    cout << "Display the list after random number generator." << endl;
    list.displayList();
    cout << endl;
    cout << endl;

    cout << "Display the list in reverse order." << endl;
    list.displayListBackward();  //display list in reverse
    cout << endl;
    cout << endl;

    cout << "Display the list with the fifth node deleted." << endl;
    list.removeListNode(4);     //remove the fifth node
    list.displayList();            //display after modification
    cout << endl;
    cout << endl;

    cout << "Display list after rotate." << endl;
    list.rotateList();            //rotate the list
    list.displayList();            //display the list after modification
    cout << endl;
    cout << endl;

    cout << "Display list after divide." << endl;
    list.divideListAT(10);        //divide the list and display both sublists.

    return 0;
}

