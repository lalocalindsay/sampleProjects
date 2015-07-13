//
//  Book.h
//  examples
//
//  Template created by Tim Alcon on 11/25/14.
//



#include "Book.h"

#include "Library.h"
#include "Patron.h"

#include <string>
using namespace std;
 /*
class Patron;

enum Locale {ON_SHELF, ON_HOLD, CHECKED_OUT};

class Book
{
private:
    string idCode; //unique identifier for the book
    string title; //cannot be assumed to be unique
    string author;
    Locale location; //a book can be: on the shelf, on the hold shelf, or checked out
    Patron* checkedOutBy; //pointer to the Patron who has it checked out (if any)
    Patron* requestedBy; //pointer to the Patron who has requested it (if any); a Book can only be requested by one Patron at a time
    int dateCheckedOut; //when a book is checked out, this will be set to the currentDate of the Library

public:
    static const int CHECK_OUT_LENGTH = 21; //access this value of a constant directly from class  by Book:: CHECK_OUT_LENGTH
    Book(); //1   //CONSTRUCTOR for empty book
    Book(string idc, string t, string a); //2   //CONSTRUCTOR that takes ID code, title and author. checkedOutBy and requestedBy should be initialized to NULL; a new book should be on the shelf
    //int getCheckOutLength();  //removed per Piazza 2339
    string getIdCode(); //3
    string getTitle(); //4
    string getAuthor(); //5
    Locale getLocation(); //6
    void setLocation(Locale lo); //7
    Patron* getCheckedOutBy(); //8
    void setCheckedOutBy(Patron* p); //9
    Patron* getRequestedBy(); //10
    void setRequestedBy(Patron* p); //11
    int getDateCheckedOut(); //12
    void setDateCheckedOut(int d); //13



};
 */

//Book CONSTRUCTORS
//default
Book::Book() ///1 /Piazza 2317
{
   idCode = "";
   title = "";
   author = "";
   location = ON_SHELF;
   checkedOutBy = NULL;
   requestedBy = NULL;
   dateCheckedOut = 0;
}

//non-default
Book:: Book(string idc, string t, string a) //2 //Piazza 2317
{

   idCode = idc;
   title = t;
   author = a;
   location = ON_SHELF;
   checkedOutBy = NULL;
   requestedBy = NULL;
   dateCheckedOut = 0;

}

//Book GET FUNCTIONS
string Book::getIdCode() //3
{
		return idCode;
}
string Book::getTitle() //4
{
		return title;
}
string Book::getAuthor() //5
{
		return author;
}
Locale Book::getLocation() //6
{
		return location;
}

Patron* Book::getCheckedOutBy() //8
{
		return checkedOutBy;
}

Patron* Book::getRequestedBy() //10
{
		return requestedBy;
}

int Book::getDateCheckedOut() //12
{
		return dateCheckedOut;
}

//Book SET FUNCTIONS

void Book::setLocation(Locale lo) //7
{
		location = lo;
}

 void Book::setCheckedOutBy(Patron* p) //9
 {
		checkedOutBy = p;
 }

 void Book::setRequestedBy(Patron* p) //11
 {
		requestedBy=p;
 }

 void Book::setDateCheckedOut(int d) //13
{
		dateCheckedOut=d;
}


