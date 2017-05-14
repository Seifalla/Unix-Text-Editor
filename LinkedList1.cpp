//LinkedList.cpp

#include "LinkedList.h"
using namespace std;

/** 
* Print the contents of the list
*/ 
void List::Print() {
    // Temp pointer 
    Node *tmp = head; 
    int lineNum = 1;
    // Parse and print the list
    while ( tmp != NULL) {

	 cout<<lineNum<<"> ";
         cout << tmp->Data()<<endl;           
         tmp = tmp->Next();
	 lineNum ++;
    }
}


void List::Delete(int lineNumber) {
    
    int line = 1;
    Node *pre, *ptr;

    pre = NULL;

    ptr = head;


    while (ptr != NULL)
// not finished yet
    {
	if (line == lineNumber)
	         break;

	line ++;
	pre = ptr;
	ptr = ptr -> Next();
    } 

    // not found
    if (pre != NULL)
	pre->SetNext(ptr->Next());

    else
// the first node is to be deleted
	head = ptr->Next();

    delete ptr;
}


void List::insert(int lineNumber, string data){


	Node* cur;

	Node* pre;

	cur = head;

	pre = NULL;

	int curIdx = 1; 

	while (cur != NULL)

// nevigate through the list until
//the line is found

	{

		if (curIdx == lineNumber)

			break;

		curIdx ++;

		pre = cur;		

		cur = cur->Next();
	}

//creat a new node and store the 
//user input in it.
	Node* newnode = new Node();

	newnode->SetData(data);

//If the list is empty insert at the beginning
	if (pre == NULL){

		newnode->SetNext(head);

		head = newnode;

	}


	else

//insert at the specified destination
	{
		newnode->SetNext(cur);

		pre->SetNext(newnode);
	}

}

void List::save(){


    Node *tmp = head;

//remove the existing fiile and create a new one  

    ofstream f2("testfile");

    // Parse and print the list
    while(tmp != NULL){

    	f2 << tmp->Data()<<endl;
	tmp = tmp->Next();
    }

}
int List::read(int &n, fstream &file){


	string data;


	while(file){
		getline( file, data, '\n');


		Node* newNode = new Node();
    		newNode->SetData(data);
    		newNode->SetNext(NULL);
    	// Create a temp pointer
    		Node *tmp = head;

// First node in the list
    		if (!head) {

			head = newNode;
                        n ++;
                }
		else{
        // Nodes already present in the list
        // Parse to end of list
        	while (tmp->Next()) {
            		tmp = tmp->Next();
        	}
        // Point the last node to the new node
        	tmp->SetNext(newNode);

        	n++;
     		}
	}
	return n;
}
