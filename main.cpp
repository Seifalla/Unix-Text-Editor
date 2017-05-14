#include <iostream>
#include "LinkedList.h"
//Name: Seifalla Moustafa
//CS216
//Programming Assignment 2
//This program is a text editor that will let 
//the user type in some text lines and store them
// in a linked list structure. The user can also 
//insert and delete lines.

using namespace std;

//passing file name as a command 
//line argument
int main(int argc,char *argv[]){

//defining the file object	
	fstream f;
//opening the file
	f.open(argv[1], ios::in | ios::out);

//checking for file open errors
	if(!f){

		cout<<"File cannot be opened"<<endl;

		return 0;
	}

//creating the linked list	
	List l;

//variable to store user input
	string line;

//variable to store the user choice
	char ch;

//line number variable
	int n;

//total number of lines
	int numLines = 0;

//reading the lines from the file to the
//linked list
        l.read(numLines,f);

//displaying the list
	l.Print();

//displaying the prompt
	cout<<"> ";

//reading the user choice
	cin.get(ch);	

//keep accepting user input until
//'Q' is entered 
	while(ch != 'Q'){

//If the user typed in I accept the line
//number and insert the input at that
//line and move the text that was in that line
//to the next line.	
	if(ch == 'I'){

		cin >> n;

//if user entered a number that's more
//than the total number of lines insert some extra
//lines at the end of the file.
		if(n >= numLines)

			for(int i = 0; i <= 5; i++)

				 l.insert(numLines,"\n");

		cin.ignore();

		getline(cin,line);		

		l.insert(n,line);
	}

//If the user typed in D accept the line
//number and delete the text at that
//line.
	if(ch == 'D'){

                cin >> n;

//Display an error message if 
//an invalid line number is entered

		if(n >= numLines || n < 0)

			cout<<"Sorry. Unable to delete a nonexistent line."<<endl;
		else

                	l.Delete(n);
        }

//Display the list if L is entered
	if(ch == 'L')

		l.Print();

	cout<<"> ";

	cin.get(ch);
	
	}

	remove(argv[1]);
	
//Save the changes into the file
	l.save();
		
	return 0;
}

	

	

	

		
