// LinkedList.h

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// Node class 
class Node {
    string data; 
    Node* next;
   public:
    Node() {}; 
    void SetData(string aData) { data = aData; }; 
    void SetNext(Node* aNext) { next = aNext; }; 
    string Data() { return data; }; 
    Node* Next() { return next; };
};
// List class 
class List { 
    Node *head; 
  public: 
    List() { head = NULL; }; 
    void Print();  
    void Delete(int lineNumber);
    void insert(int n, string data);
    void save();
    int read(int &n, fstream &file);
};
#endif
