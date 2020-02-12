/*****************************************
 ** File:    DecayList.cpp
 ** Project: CMSC 202 Project 3, Fall 2019
 ** Author:  Diego Burgos
 ** Date:    10/29/2019
 ** Section: 30
 ** E-mail:  dburgos2@umbc.edu
 **
 ** The file contains the cpp for DecayList, a
 ** linked list of Nodes that goes across each Node
 ** in the list
 ***********************************************/

#include <stdio.h>
#include "DecayList.h"

DecayList::DecayList(){
    m_head = NULL;
    m_size = 0;
}

DecayList::~DecayList(){
    /*
    Node* current = m_head;
    
    while(current != NULL ){
        
        Node* next = current->GetNext();
        delete current;
        current = next;
        m_size--;
        
    }
    m_head = NULL; */
    delete m_head;
}

int DecayList:: GetSize(){
    return m_size;
}

void DecayList::InvertValue(int index){
    
    Node* current = m_head;
    
    
    int count = 0;
    while(current != nullptr){
        
        if(count == index){
            current->ReplaceValue();
        }
        count++;
        current = current->GetNext();
        
    }
    
}

bool DecayList::PrintDecayList(){
    
    Node* current;
    current = m_head;
    //current->GetNext()
    
    
    if(m_size == 0){
        return false;
    }
    else
    {
        
        
        
        int count = 0;
        cout << "This is the list" << endl;
        while(current != NULL && current != nullptr){
            cout << "|" << current->GetValue() << "|->";
            //cout << count << ":" <<  current->GetValue() << endl;
            current = current->GetNext();
            count++;
        }
        cout << "END" << endl;
        cout << "Total size is: " << m_size << endl;
        
        return true;
    }
    return true;
}

// CheckEmpty - Called to see if the list is empty
// Preconditions: Nodes were removed from list
// Postconditions: If empty, returns true and round ends
bool DecayList::CheckEmpty(){
    
    if(m_head == NULL){
        return true;
    }
    return false;
}

// InsertEnd - Inserts new Node into end of DecayList
// Preconditions: DecayList exists - may not create m_tail
// Postconditions: Inserts passed node to end of list
void DecayList::InsertEnd(Node* path){
    
    
    Node* tempNode = new Node(path->GetValue());
    if(m_head == NULL)
    {
        m_head = tempNode;
        m_size++;
    }
    else
    {
        Node* current = m_head;
        while(current->GetNext() != NULL){
            current = current->GetNext();
        }
        
        
        //    Node temp = new Node(path->GetValue());
        
        current->SetNext(tempNode);
        m_size++;
        //current = current.GetNext();
    }
}

// TraverseList - Loops list to see if any sequences of 3 or more nodes with a value of 1
// Preconditions: DecayList has Nodes. Passed value to be checked (true by default)
// Postconditions: Removes all sequences of nodess with 3 or more cards with a value of 1; returns \
number of cards removed
int DecayList::TraverseList(bool check){
    
    int counter = 0;
    int num = 0;
    Node* current = m_head;
    //Node* currentNode = m_head;
    Node* nextNode = current->GetNext();
    Node* lastNode = current->GetNext()->GetNext();
    
    
    while( current != nullptr && nextNode != nullptr && lastNode != nullptr) {
        
        //Node* currentOne;
        //Node* currentTwo;
        
        if(current->GetValue() == check && nextNode->GetValue() == check && lastNode->GetValue() == check){
            num += 3;
            counter++;
            RemoveNodes(counter, 3);
            break;
        }
        
        current = current->GetNext();
        nextNode = nextNode->GetNext();
        lastNode = lastNode->GetNext();
        
        /*
         if(current->GetNext() != nullptr){
         current = current->GetNext();
         }
         if(nextNode->GetNext() != nullptr){
         nextNode = nextNode->GetNext();
         }
         if(lastNode->GetNext() != nullptr){
         lastNode = lastNode->GetNext();
         }
         */
    }
    //if(
    
    // if(){
    //     RemoveNodes
    // }
    
    return num;
}

// RemoveNodes - Called when 3 or more 1's in a row. Nodes are removed left to right.
// Preconditions: A DecayList has a minimum of 3 nodes
// Postconditions: The nodes are removed, which resizes DecayList; Returns number removed.


int DecayList::RemoveNodes(int index , int numNodes){
    
    /*
        Node* tempNode = m_head;
        Node* start;
        Node* end;*/
    Node* previousNode = m_head;
    Node* currentNode = m_head;
    Node* nextNode = new Node();
    Node* lastNode = new Node();
    
    
    int count = 0;
    int endIndex = GetSize();
    
    cout << "Match has been found" << endl;
    
    
    
    
    if (endIndex == index)
        return 0; // if they are equal we aren't deleting anything;
    
    if(currentNode != nullptr && nextNode != nullptr & nextNode != nullptr){
        previousNode->SetNext(nullptr);
        delete currentNode;
        delete nextNode;
        delete lastNode;
        
    }
    while(currentNode != nullptr && nextNode != nullptr & lastNode != nullptr){
        
        if(count == index){
            previousNode->SetNext(lastNode->GetNext());
            delete currentNode;
            delete nextNode;
            delete lastNode;
            cout << numNodes << " nodes removed!" << endl;
            return numNodes;
        }
        count++;
        previousNode = currentNode;
        currentNode = currentNode->GetNext();
        nextNode = currentNode->GetNext();
        lastNode = nextNode->GetNext();
     
    
    
    /*
    //int endIndex = GetSize();
    
    if(CheckEmpty() == true){
        return 0;
    }
    if( index < 1 || index > GetSize() )
            return 0;
        
        if( index > GetSize() )
            return 0;
        
        if (GetSize() < index){
            int placeholder = index;
            index = endIndex;
            endIndex = placeholder;   //changes so that the endIndex is now the placeholder
        }
        
        if (endIndex == index)
            return 0; // if they are equal we aren't deleting anything;
        
        
        while( currentNode != nullptr){
            if (count == index)
                nextNode = currentNode;
            
            if (count == GetSize())
                lastNode = currentNode;
            
            currentNode = currentNode->GetNext();
            count++;
        }
        
        if (nextNode != NULL && lastNode != NULL){
            previousNode = currentNode;
            delete currentNode;
            delete nextNode;
            delete lastNode;
            cout << "Removing " << numNodes << " Nodes" << endl;
            m_size -= 3;
            
            
        }
        

   
        /*
    //m_head = m_head->GetNext();
    int indexCount = 0;
    int nodeCount = 0;
    
    Node* previousNode = m_head;
    Node* currentNode = m_head;
    //Node* nextNode = currentNode->GetNext();
    //Node* lastNode = currentNode->GetNext()->GetNext();
    Node* nextNode = nullptr;
    Node* lastNode = nullptr;
    cout << "Match has been found" << endl;
    
    
    int count = 0;
    
    
    
    
    while(currentNode != nullptr && nextNode != nullptr & lastNode != nullptr){
        
        if(count == index){
            previousNode->SetNext(nullptr);
            delete &currentNode;
            delete &nextNode;
            delete &lastNode;
            cout << numNodes << " nodes removed!" << endl;
            return numNodes;
        }
        count++;
        previousNode = currentNode;
        currentNode = currentNode->GetNext();
        nextNode = currentNode->GetNext();
        lastNode = nextNode->GetNext();
        
    } 
    return numNodes;*/
    
return numNodes;
}




