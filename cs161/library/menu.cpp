/****************************************************************************************
Author: Lindsay Tucker
Date created: 1Dec2014
Date last modified: 7Dec2014
Program Filename:  menu.cpp
Description/overview: 
This is a menu with an option for each of the library functions

INPUT: 
string patronID;
string bookID;
double payment;
char choice;           
	
	
OUTPUT: 
the program will output the following:
all output from Library.cpp
		
****************************************************************************************/

#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include<iomanip>
#include<math.h>
#include <stdexcept>  

#include "Book.h"
#include "Patron.h"
#include "Library.h"
  
using namespace std;



int main()
{
	
	/*
	//////////   BOOK  ////////////
	string idc= " "; //Book(string idc, string t, string a); //2 
	string t= " ";
	string a= " ";
	Locale lo; //setLocation(Locale lo); //7
	Patron *p; // void Book::setRequestedBy(Patron* p) //11
	int d; //DateCheckedOut(int d); //13
	//Book book1 (idc, t, a); //TESTING
	
	/////////////////  PATRON  //////////////////////
	string idn= "  "; //a unique identifier for a Patron 
    string n="  "; //cannot  be assumed to be unique
	double amount; //7
    vector<Book*> checkedOutBooks; //a list of Books that Patron currently has checkedOut
    double fineAmount; //how much the Patron owes the Library in late fees
	Book *b; //4 and //5
	Patron patron1 (idn, n); //TESTING
	
	
	////////////////////  LIBRARY ///////////////////////
	vector<Book> holdings; //a list of Books the library currently has
	vector<Patron> members; //a list of Patrons the library currently has
    int currentDate; //stores the current date rep. as an integer number of "days" since the Library object was created
	*/
	
	Library library1; // (creates object and calls constructor that sets date  to 0)
	
	string patronID;
	string bookID;
	double payment;
	
	char choice;           //variable for switch
    //DISPLAY MENU
    cout<<"-------------------------------- Library Menu --------------------------------"<<endl;
    
    do 
	{
        //Display menu and prompt user for choice
        cout<<"\nChoose one of the following options: "<<endl;
		cout<<"1. Add book to library"<<endl;
        cout<<"2. Add member"<<endl;
        cout<<"3. Check out a book"<<endl;
		cout<<"4. Return a book"<<endl;
        cout<<"5. Request a book"<<endl;
        cout<<"6. Pay a fine"<<endl;
        cout<<"7. Increment Current Date (increase Patron's fines)"<<endl;
		cout<<"8. View patron info"<<endl;
		cout<<"9. View book info"<<endl;
        cout<<"Q: Quit "<<endl;
		cout<<"Enter an option (1-9, or Q): ";
        cin>>choice;
        
        //Switch statement for user menu choices
        switch (choice) 
		{
            case '1':
            	//ADD BOOK	
				library1.addBook();
			
                break;
            case '2':
				//ADD MEMBER
				library1.addMember();
				
				break;
            case '3':
				//CHECK OUT BOOK
				
				cout<<endl;
				cin.ignore(800, '\n'); 
				cout<< "Enter book check out info. "<<endl;
			
				cout<<"bookID: ";
				getline (cin, bookID);
					//cout<< "//TESTING: bookID: "<< bookID<<endl; //TESTING
				cout<<endl;
			
				cout<<"patronID: ";
				getline (cin, patronID);
					//cout<< "//TESTING: patronID: "<< patronID<<endl; //TESTING
				cout<<endl;
				
				library1.checkOutBook(patronID, bookID);
		
				break;
            case '4':
                //RETURN BOOK
				cout<<endl;
				cin.ignore(800, '\n'); 
				cout<< "Enter ID for book to return. "<<endl;
			
				cout<<"bookID: ";
				getline (cin, bookID);
					//cout<< "//TESTING: bookID: "<< bookID<<endl; //TESTING
				cout<<endl;
				
				library1.returnBook(bookID);
				
                break;
			case '5':
                //REQUEST A BOOK
				
				cout<<endl;
				cin.ignore(800, '\n'); 
				cout<< "Enter book request info. "<<endl;
			
				cout<<"bookID: ";
				getline (cin, bookID);
					//cout<< "//TESTING: bookID: "<< bookID<<endl; //TESTING
				cout<<endl;
			
				cout<<"patronID: ";
				getline (cin, patronID);
					//cout<< "//TESTING: patronID: "<< patronID<<endl; //TESTING
				cout<<endl;
				
				library1.requestBook(patronID, bookID);
				
                break;	
			case '6':
                //PAY A FINE
				
				cout<<endl;
				cin.ignore(800, '\n'); 
				cout<< "Enter patronID and payment amount (double). "<<endl;
			
				cout<<"patronID: ";
				getline (cin, patronID);
					//cout<< "//TESTING: patronID: "<< patronID<<endl; //TESTING
				cout<<endl;
			
				cout<<"payment: ";
				cin>>payment; //NEED INPUT VALIDATION
					//cout<< "//TESTING: payment: "<< payment<<endl; //TESTING
				cout<<endl;
				
				library1.payFine(patronID, payment);
				
                break;	
			case '7':
                //Increment current date
				cout<<"Incrementing date and adjusting fines. "<<endl;
				
				library1.incrementCurrentDate(); 
				
                break;		
			case '8':
                //VIEW PATRON INFO
				cout<<endl;
				cin.ignore(800, '\n'); 
				cout<< "Enter patron info. "<<endl;
			
				cout<<"patronID: ";
				getline (cin, patronID);
					//cout<< "//TESTING: patronID: "<< patronID<<endl; //TESTING
				cout<<endl;
								
				library1.viewPatronInfo(patronID); 
				
                break;		
			case '9':
                //VIEW BOOK INFO
				cout<<endl;
				cin.ignore(800, '\n'); 
				cout<< "Enter book info. "<<endl;
			
				cout<<"bookID: ";
				getline (cin, bookID);
					//cout<< "//TESTING: bookID: "<< bookID<<endl; //TESTING
				cout<<endl;
								
				library1.viewBookInfo(bookID); 
				
                break;				
			case 'Q':
                //Exit program
                cout<<"Exiting."<<endl;
                break;				
            default:
                break;

		} //end of SWITCH
		
		if (choice =='q' || choice == 'Q')
		{	
				break;
		}
		
	} while ((choice = '1') || (choice = '2') || (choice = '3') || (choice = '4') || (choice = '5') || (choice = '6') || (choice = '7') || (choice = '8') || (choice = '9')); 
	

	return 0;
}