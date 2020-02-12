/*****************************************
 ** File:    Node.cpp
 ** Project: CMSC 202 Project 3, Fall 2019
 ** Author:  Diego Burgos
 ** Date:    10/29/2019
 ** Section: 30
 ** E-mail:  dburgos2@umbc.edu
 **
 **The file contains the class file for Node where
 **the values for node are initialized
 **
 ***********************************************/

#include "Node.h"

Node::Node(){
    m_next = NULL;
    //m_value = true;
}

//more than that
Node::~Node(){
    
    /*
    while(m_next){
        Node* temp = m_next->GetNext();
        m_next->SetNext(nullptr);
        delete m_next;
        m_next->SetNext(temp);
    } */
    
    delete m_next;
    m_next = nullptr;
    //cout << "deleting node" << endl;
    //delete m_value;
}

Node::Node(bool value){
    m_value = value;
    m_next = NULL;
}

void Node::ReplaceValue(){
    m_value = !m_value;
}

void Node::SetNext(Node* next){
    m_next = next;
}

Node*Node:: GetNext(){
    return m_next;
}

bool Node:: GetValue(){
    return m_value;
}

#include "Node.h"



