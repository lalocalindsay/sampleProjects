//
//  Book.h
//  examples
//
//  Template created by Tim Alcon on 11/25/14.
//


#ifndef examples_Book_h
#define examples_Book_h

#include "Patron.h"
#include "Library.h"

#include <string>
using namespace std;

class Patron;

enum Locale {ON_SHELF, ON_HOLD, CHECKED_OUT};

class Book
{
private:
    string idCode;
    string title;
    string author;
    Locale location;
    Patron* checkedOutBy;
    Patron* requestedBy;
    int dateCheckedOut;
public:
    static const int CHECK_OUT_LENGTH = 21;
    Book();
    Book(string idc, string t, string a);
    //int getCheckOutLength(); //removed per Piazza 2339
    string getIdCode();
    string getTitle();
    string getAuthor();
    Locale getLocation();
    void setLocation(Locale lo);
    Patron* getCheckedOutBy();
    void setCheckedOutBy(Patron* p);
    Patron* getRequestedBy();
    void setRequestedBy(Patron* p);
    int getDateCheckedOut();
    void setDateCheckedOut(int d);

};

#endif
