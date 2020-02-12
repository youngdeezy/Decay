/*****************************************
 ** File:    driver.cpp
 ** Project: CMSC 202 Project 3, Fall 2019
 ** Author:  Diego Burgos
 ** Date:    10/29/2019
 ** Section: 30
 ** E-mail:  dburgos2@umbc.edu
 **
 **   This file contains the main driver program for Project 3.
 ** This program initizlies the Decay class to start the program
 ** 
 **
 **
 **
 ***********************************************/

#include "Decay.h"
#include "Node.h"
#include "DecayList.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


int main(){
    
    srand(time(nullptr));
    
    Decay simulation;
    
    /*
    //simulation.CreateRandomList();
    
    Node a1 = Node(true);
    Node a2 = Node(false);
    Node a3 = Node(true);
    
    cout << "To the same" << endl;
    DecayList l1 = DecayList();
    l1.InsertEnd(&a1);
    l1.InsertEnd(&a2);
    l1.InsertEnd(&a3);
    l1.PrintDecayList();  */
    
    simulation.Start();
    
}

