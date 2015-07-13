//
//  Patron.h
//  examples
//
//  Template created by Tim Alcon on 11/25/14.
//


#ifndef __examples__Patron__
#define __examples__Patron__

#include <stdio.h>
#include <vector>

#include "Book.h"
#include "Library.h"

#include <string>
using namespace std;

class Book;

class Patron
{
private:
    string idNum;
    string name;
    vector<Book*> checkedOutBooks;
    double fineAmount;
public:
    Patron();
    Patron(string idn, string n);
    string getIdNum();
    string getName();
    vector<Book*> getCheckedOutBooks();
    void addBook(Book* b);
    void removeBook(Book* b);
    double getFineAmount();
    void amendFine(double amount);
	//OTHER GET FUNCTIONS
	//OTHER SET FUNCTIONS
	//OTHER METHODS
	int sizeOfCheckedOutBooks ();  //added


};

#endif /* defined(__examples__Patron__) */
