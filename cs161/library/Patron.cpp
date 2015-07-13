//
//  Patron.h
//  examples
//
//  Template created by Tim Alcon on 11/25/14.
//


#include <iostream> //added for TESTING

#include "Library.h"
#include "Book.h"
#include "Patron.h"

#include <stdio.h>
#include <vector>

#include <string>
using namespace std;

        /*
class Book;

class Patron
{
private:
    string idNum; //a unique identifier for a Patron
    string name; //cannot  be assumed to be unique
    vector<Book*> checkedOutBooks; //a list of Books that Patron currently has checkedOut
    double fineAmount; //how much the Patron owes the Library in late fees
public:
    Patron(); //CONSTRUCTOR (EMPTY)
    Patron(string idn, string n); //CONSTRUCTOR takes an idNum and name
    string getIdNum(); //1
    string getName(); //2
    vector<Book*> getCheckedOutBooks(); //3
    void addBook(Book* b); //4  //adds the specified Book to checkedOutBooks
    void removeBook(Book* b); //5     //removes the specified Book from checkedOutBooks
    double getFineAmount(); //6
    void amendFine(double amount);  //7 //a positive argument increases, a negative decreases


	//Patron METHODS
	int sizeOfCheckedOutBooks (); //8  //added to .h file


};

        */

//Patron CONSTRUCTORS
//default
Patron::Patron()
{
		string idNum ="";
		string name="";
		//vector<Book*> checkedOutBooks= NULL;
		 fineAmount= 0;
		checkedOutBooks.reserve(100); //piazza 2311 (Tim), to correct for resized vectors of pointers pointing incorrect memory
}


//non-default
Patron::Patron(string idn, string n) //Piazza 2268
{
		idNum = idn;
		name=n;
		//vector<Book*> checkedOutBooks= NULL;
		fineAmount= 0;
		checkedOutBooks.reserve(100); //piazza 2311 (Tim), to correct for resized vectors of pointers pointing incorrect memory
}

//Patron GET FUNCTIONS
string Patron::getIdNum() //1
{
		return idNum;
}
 string Patron::getName() //2
{
		return name;
}
 vector<Book*> Patron:: getCheckedOutBooks() //3
{
		return checkedOutBooks;
}
double Patron:: getFineAmount() //6
{
		return fineAmount;
}



//Patron METHODS

void Patron::addBook(Book* b) //4  //adds the specified Book to checkedOutBooks
{
		checkedOutBooks.push_back(b);

}

void Patron::removeBook(Book* b) //5     //removes the specified Book from checkedOutBooks    //assumes correct sizeOfCOB
{

		int sizeOfCOB=sizeOfCheckedOutBooks();

		for (int i=0; i< sizeOfCOB; i++)
		{

				if((checkedOutBooks[i]->getIdCode()) == (b->getIdCode()))
				{
						checkedOutBooks.erase(checkedOutBooks.begin()+i); //remove Book at that location //stackoverflow: http://stackoverflow.com/questions/3385229/c-erase-vector-element-by-value-rather-than-by-position
				}
		}
}

void Patron::amendFine(double amount)  //7 //a positive argument increases, a negative decreases
{
		fineAmount+=amount;
}

int Patron::sizeOfCheckedOutBooks() //8  //add to .h file
{

		int sizeOfCOB = checkedOutBooks.size();
		return sizeOfCOB;
}

