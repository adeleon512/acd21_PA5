//
// Created by Adam on 2/26/2017.
//

#ifndef ACD21_PA5_NLL_H
#define ACD21_PA5_NLL_H

/*
 * nLL.h
 *
 *  Created on: Mar 24, 2014
 *      Author: Adam C. De Leon
 *      Class: CS2308
 *      Section: 1
 *      Roster: 6
 *      Program: 5
 */

#include <cstddef>

using namespace std;

class NumberList {
private:
    //Stucture for original list
    struct ListNode {
        int value;
        struct ListNode *next;
    };
    ListNode *head;

    //Structure for first secondary list
    struct ListNode2 {
        int value2;
        struct ListNode2 *next2;
    };
    ListNode2 *head2;

    //structure for second secondary list
    struct ListNode3 {
        int value3;
        struct ListNode3 *next3;
    };
    ListNode3 *head3;

public:
    NumberList();            //default constructor
    ~NumberList();            //destructer to prevent memory leak.

    void appendNode(int);        //function declarations
    void displayList();

    void displayList2();

    void displayList3();

    void displayListBackward();

    void removeListNode(int);

    void rotateList();

    void divideListAT(int);

};

#endif //ACD21_PA5_NLL_H
