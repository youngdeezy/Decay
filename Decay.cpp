/*****************************************
 ** File:    Decay.cpp
 ** Project: CMSC 202 Project 3, Fall 2019
 ** Author:  Diego Burgos
 ** Date:    10/29/2019
 ** Section: 30
 ** E-mail:  dburgos2@umbc.edu
 **
 **   This file contains the Decay program for project 3.
 ** This program can read a file to generate a linked list
 ** or be used to simulate a linked list. It also has the main
 ** menu for the program.
 **
 **
 ***********************************************/


#include <stdio.h>
#include <cstdlib>
#include "Decay.h"

// Constructor
// Preconditions: None
// Postconditions: None
Decay::Decay(){
    
}

// Destructor - Deletes all lists in m_list
// Preconditions: m_list is populated
// Postconditions: All lists are deleted and there are no memory leaks
Decay::~Decay(){
    //while(!m_list.empty()) delete m_list.back(), m_list.pop_back();
    for(unsigned int i = 0; i < m_list.size(); i++){
        m_list.at(i)->~DecayList();
    }
}

// EmptyLists() - Empties all lists in m_list
// Preconditions: m_list is populated
// Postconditions: All lists are deleated and there are no memory leaks
void Decay::EmptyLists(){
    
    
    m_list.clear();
}


// LoadFile - Requests a file and loads all linked lists in a file (separated by ;)
// Preconditions: Valid input file exists (preferably with three lines of data)
// Postconditions: m_list is initialized

void Decay::LoadFile(){
    
    int counter = 0;
    ifstream myFile ("test1.txt");
    
    
    //values set for the foundables
    string line;
    DecayList a1 = DecayList();
    //Node t1 = Node();
    //int element;
    //bool value;
    char zero = '0';
    char one = '1';
    
    cout << "Hello" << endl;
    
    //cout << "Hello" << endl;
    
    
    //goes across each line and sets the values for the foundable that is set apa\
    rt by commas
    while(getline(myFile, line, ';')){
        
        DecayList* a1 = new DecayList();
        int counter = 0;
        // cout << line << endl;
        // line = line.c_str();
        
        // cout << line.size();
        int length = line.length();
        
        
        for(int i = 0; i < length; i++){
            // cout << length << endl;
            Node t1;
            char c = line[i];
            if (c == zero){
                t1 = Node(false);
                a1->InsertEnd(&t1);
            }
            
            if (c == one){
                t1 = Node(true);
                a1->InsertEnd(&t1);
            }
            // counter++;
            //a1.InsertEnd(&t1);
            
            
        }
        m_list.push_back(a1);
        //a1.~DecayList();
        
        
        //cout << line << endl;
    }
    //m_list.push_back(&a1);
    //m_list[0]->PrintDecayList();
    
    
    for(auto i : m_list){
        
    }
    
    myFile.close();
    return;
}




// ChooseList - After a file is loaded, allows user to choose a list to simulate
// Preconditions: User has chosen to start simulation
// Postconditions: Simulation is started on list chosen by user
void Decay::ChooseList(){
    
    int choice;
    cout << "Which decay scenario would you like to experience?" << endl;
    for (unsigned int i = 0; i < m_list[i]->GetSize(); i++){
        cout << "List " << i+1 << m_list[i] << "(" << m_list[i] << " nodes)";
    }
    cin >> choice;
    
    cout << "The sequence has been initiated" << endl;
    m_list[choice]->PrintDecayList();
    RunSimulation(choice);
    //for(int i = 0; i < m_list.size(); i++){
    
    // }
}

// CreateRandomList - Creates list of a specific size (1-10000) times 3 nodes each
// Preconditions: m_list is empty
// Postconditions: m_list.at(0) has a list loaded into it
void Decay::CreateRandomList(){
    
    int num;
    //int counter = 0;
    // int randBool;
    srand(time(0));
    DecayList tempList = DecayList();
    
    cout << "How large a list would you like?" << endl;
    cin >> num;
    
    int size = num*3;
    for(int i = 0; i < size; i++){
        
        int randBool = rand() % 2;
        Node tempNode;
        if(randBool == 0){
            tempNode = Node(false);
            // Node tempNode = Node(false);
        } else{
            tempNode =  Node(true);
            //tempNode = Node(true);
        }
        tempList.InsertEnd(&tempNode);
    }
    //tempList.PrintDecayList();
    m_list.push_back(&tempList);
    m_list.at(0)->PrintDecayList();
    RunSimulation(0);
}


// RunSimulation - Simulate one of the loaded lists
// Preconditions: A DecayList is available
// Postconditions: Simulation is run
void Decay::RunSimulation(int index){
    
    int num = 0;
    bool allNodes = false;
    
    while(allNodes == false){
        cout << "Which node to change?" << endl;
        
        /*
         for(int i = 0; i < (m_list[i]->GetSize()); i++){
         cout << "   " << i+1;
         }  */
        cin >> num;
        
        m_list[index]->InvertValue(num);
        m_list[index]->TraverseList(1);
        m_list[index]->PrintDecayList();
        if(m_list[index]->CheckEmpty() == true){
            allNodes = true;
            cout << "All nodes removed" << endl;
        }
        
    }
    
}

// Start - Starts sim. Can load file, choose list, or create random list
// Preconditions: A DecayList is available
// Postconditions: Empties all lists after one is simulated.
void Decay::Start(){
    
    bool resume = true;
    do{
        string fileName;
        bool fileIn = false;
        int num = 0;
        int simNum = 0;
        cout << "Welcome to decay, where you code a frustrating system instead of doing your physics homework." << endl;
        cout << "What would you like to do?" << endl;
        cout << "1. Load file " << endl;
        cout << "2. Simulate Loaded file" << endl;
        cout << "3. Simulate Random list " << endl;
        cout << "4. Quit" << endl;
        cin >> num;
        
        
        switch (num){
                
            case 1:
                
                cout << "What is the name of the file?" << endl;
                cin >> m_file;
                fileIn = true;
                LoadFile();
                break;
                
            case 2:
                
                    cout << "Which decay scenario would you like to experience?" << endl;
                    cin >> simNum;
                    if(fileIn == false){
                        cout << "File has not been loaded" << endl;
                        break;
                    }
                
                RunSimulation(simNum);
                break;
                
            case 3:
                EmptyLists();
                CreateRandomList();
                //RunSimulation(0);
                break;
                
            case 4:
                cout << "Quitting game" << endl;
                resume = false;
                
                
        }
    }
    while (resume == true);
    
    
}

