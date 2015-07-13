//
//  Library.h
//  examples
//
//  Template created by Tim Alcon on 11/25/14.
//


#ifndef __examples__Library__
#define __examples__Library__

#include <vector>
#include <stdio.h>

#include "Book.h"
#include "Patron.h"

#include <string>
using namespace std;

class Patron;
class Book;

class Library
{
private:
    vector<Book> holdings;
    vector<Patron> members;
    int currentDate;
public:
    static const double DAILY_FINE = 0.1;
    Library();
    void addBook();
    void addMember();
    void checkOutBook(string patronID, string bookID);
    void returnBook(string bookID);
    void requestBook(string patronID, string bookID);
    void incrementCurrentDate();
    void payFine(string patronID, double payment);
    void viewPatronInfo(string patronID);
    void viewBookInfo(string bookID);

	//ADDED
	int checkIdMatch(string patronID, string bookID);



};

#endif /* defined(__examples__Library__) */
