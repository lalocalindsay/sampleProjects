//
//  Library.h
//  examples
//
//  Template created by Tim Alcon on 11/25/14.
//

#include <iostream>//added for addBook input

#include "Library.h" //added, per Ashton
#include "Book.h" //added, per Ashton
#include "Patron.h" ///added, per Ashton

#include <vector>
#include <stdio.h>

#include <string> //added
using namespace std; //added


    /*
class Patron;
class Book;

class Library
{
private:
	// If the holdings or members vectors get resized, that can invalidate any pointers to the Books or Patrons contained therein.
	//Please use the vector::reserve function in the Library constructors to increase the capacity of the holdings and members vectors to 100. Piazza 2339
    vector<Book> holdings; //a list of Books the library currently has
    vector<Patron> members; //a list of Patrons the library currently has
    int currentDate; //stores the current date rep. as an integer number of "days" since the Library object was created
public:
    static const double DAILY_FINE = 0.1; //constant that gives the fine per overdue day per Book
    Library(); //1 //CONSTRUCTOR  (initializes the currentDate to zero)
    void addBook(); //2 //prompts the user for book info and uses it to create a Book which is added to holdings
    void addMember();  //3   //prompts the user for patron info and uses it to create a Patron which is added to members
    void checkOutBook(string patronID, string bookID); //4   //MOST COMPLICATED FUNCTION
    void returnBook(string bookID); //5   //MOST COMPLICATED FUNCTION
    void requestBook(string patronID, string bookID); //6
    void incrementCurrentDate(); //7
    void payFine(string patronID, double payment); //8
    void viewPatronInfo(string patronID);  //9
    void viewBookInfo(string bookID);  //10

	//ADDED
	int checkIdMatch(string patronID, string bookID); //11 //added to header  //for return to main if no match and unable to check out book


};
          */


//CONSTRUCTORS
Library::Library() //1
{
		currentDate=0;
}


//Library MEMBER FUNCTIONS
void Library::addBook() //2 //prompts the user for book info and uses it to create a Book which is added to holdings
{
		string idc;
		string t;
		string a;
		cout<<endl;
		cin.ignore(800, '\n');
		cout<< "Enter book info. "<<endl;

		cout<<"ID Code: ";
		getline (cin, idc);
			//cout<< "//TESTING: idc: "<< idc<<endl; //TESTING
		cout<<endl;

		cout<<"Title: ";
		getline (cin, t);
			//cout<< "//TESTING: t: "<< t<<endl; //TESTING
		cout<<endl;

		cout<<"Author : ";
		getline (cin, a);
			//cout<< "//TESTING: a: "<< a<<endl; //TESTING
		cout<<endl;

		//add code and function to check if member already exists
		int k=-1;
		for (int i=0; i< holdings.size(); i++) //check for match in holdings
		{
			if (holdings[i].getIdCode() == idc)
			{
						cout<< "That ID is already in use."<<endl; //TESTING
						k=i;
						break;
			}
			else if (i==holdings.size()-1)
			{
						//cout<< "//TESTING: There is no match for this book in the system (holdings vector)."<<endl;
						k=-2; //no match (-2 is arbitrary)
			}
		}


		if (k<=-1)
		{

				Book book_add (idc, t, a);
				holdings.push_back(book_add);

		}


}

void Library::addMember() //3   //prompts the user for patron info and uses it to create a Patron which is added to members
{
		string idn;
		string n;
		cout<<endl;
		cin.ignore(800, '\n');
		cout<< "Enter member info. "<<endl;

		cout<<"ID#: ";
		getline (cin, idn);
			//cout<< "//TESTING: idn: "<< idn<<endl; //TESTING
		cout<<endl;

		cout<<"Name : ";
		getline (cin, n);
			//cout<< "//TESTING: n: "<< n<<endl; //TESTING
		cout<<endl;

		//add code and function to check if member already exists
		int k=-1;
		for (int i=0; i< members.size(); i++) //check for match in mem
		{
			if (members[i].getIdNum() == idn)
			{
						cout<< "That ID is already in use."<<endl; //TESTING
						k=i;
						break;
			}
			else if (i==members.size()-1)
			{
						//cout<< "//TESTING: There is no match for this patron in the system (members vector)."<<endl;
						k=-2; //no match (-2 is arbitrary)
			}
		}


		if (k<=-1)
		{
				Patron member_add (idn, n);
				members.push_back(member_add);
		}


}


 void Library::checkOutBook(string patronID, string bookID) //4   //MOST COMPLICATED FUNCTION
{

		int match=checkIdMatch(patronID, bookID);		//match = location of book in holdings or -2 (no match)
		if (match >=0)  // match  and  nested ifs        //else return to menu;
		{

						//cout<<"//TESTING: match >=0, match exists, holding vector location returned"<<endl;//TESTING

				if (holdings[match].getLocation()== CHECKED_OUT)
				{
						cout<<"Book is already CHECKED_OUT"<<endl;//TESTING
				}

				//string idn= holdings[match].getRequestedBy()->getIdNum(); 	//chaining not working
				string idn;
				Patron* p;//=holdings[match].getRequestedBy();
				if (holdings[match].getRequestedBy()!=NULL) //if book is on hold, get pointer to that idNum to compare to patron ID
				{
						p=holdings[match].getRequestedBy();  //moved this to inside if so that pointer only assigned to non-NULL location
						idn = p->getIdNum(); //dereferenced pointer to idNUm
				}

				if ((holdings[match].getLocation()== ON_HOLD) && (idn != patronID))
				{
						cout<<"Book is ON_HOLD by another patron"<<endl;
				}

				else if(       (holdings[match].getLocation()== ON_SHELF) ||  ((holdings[match].getLocation()== ON_HOLD) &&  (idn == patronID))           ) //adding catch in case patron checking out had on hold
				{
						//cout<<"//TESTING: ON_SHELF!"<<endl; //TESTING

						//////////////////  UPDATE CHECKED OUT BY ////////////////////////
						int k=-1; //accepts i value in for loop to be used in assigning vector location address to ptrToPatronCheckingOut         //-1 indicates no match, but we already know there is a match if we got this far.
						//get patronID location in members
						for (int i=0; i< members.size(); i++) //check for match in members to establish pointer location to update checkedOut By
						{
								if (members[i].getIdNum()== patronID)
								{
										//cout<< "//TESTING: members vector [location] that checkedOutBy will point to: "<<i<<endl; //TESTING
										k=i;
										break;
								}

						}

						Patron *ptrToPatronCheckingOut;
						ptrToPatronCheckingOut=&members[k];
						holdings[match].setCheckedOutBy(ptrToPatronCheckingOut);


						///////////////////////////// UPDATE DATE OUT  ///////////////////////////////

						holdings[match].setDateCheckedOut(currentDate);
						//cout<< "//TESTING:DateCheckedOut UPDATED to: "<<holdings[match].getDateCheckedOut() <<endl; //TESTING
						///////////////////////////// UPDATE LOCATION //////////////////////////////
						holdings[match].setLocation(CHECKED_OUT); ///may cause problems to change location inside else if statement
						//cout<< "//TESTING: Location UPDATED to: "<< holdings[match].getLocation()<<endl; //TESTING

						//////////////////////////  UPDATE REQUESTED BY /////////////////////  //may need to re-address this function. might need to move update location to after and include (idn==patronID && getLocation==ON_HOLD)
						if (idn == patronID)  //if idn (string that came from dereferenced pointer to requestedBy.getIdNum or could be NULL) is == to patronID (was on hold for the patron)
						{
								holdings[match].setRequestedBy(ptrToPatronCheckingOut);	//update pointer  in requestedBy to current patron's location in members
								//cout<< "TEST THIS: RequestedBy UPDATED to (pointer location): "<<holdings[match].getRequestedBy() <<endl; //TESTING
						}
						else
						{
								//cout<< "TEST THIS: RequestedBy not needing to be UPDATED bc idn (possibly NULL):" <<idn<< " != "<< patronID<<" (patronID). "<<endl; //TESTING
						}
						///////////////////////////// UPDATE PATRON'S LIST /////////////////////////////
						//members[k].addBook(Book* b)
						Book * bookPtr;
						bookPtr=&holdings[match]; //address of book in holdings
						members[k].addBook(bookPtr); //adds book pointer to patron's vector of checkedOutBooks
						//cout<< "//TESTING: Patron's list (members.checkedOutBooks) UPDATED!"<<endl; //TESTING

						//////////////////////////////////////  PRINT BOOK CHECKED OUT & PATRON'S NAME ///////////////////////////////////
						cout<<"Title: " <<holdings[match].getTitle();
						cout<< " has been check out to: ";
						cout<< members[k].getName()<<endl;
				}

		}

		else //TESTING
		{
				//cout<<"//TESTING: no match found, returned -2 from checkIdMatch. return to menu."<<endl; //TESTING
		}


}

void Library::returnBook(string bookID) //5
{
		int j=-3; //if -2 , no match   /////if >=0 in library location is value of i    //-3 is arbitrary
		int loc; // loc values: 0= ON_SHELF, 1= ON_HOLD, 2= CHECKED_OUT


		for (int i=0; i< holdings.size(); i++) //check for match in holdings
		{
			if (holdings[i].getIdCode() == bookID)
			{
					//cout<< "//TESTING: Match found, book in the system (holdings vector) @: "<<i<<endl; //TESTING
					j=i;
					break;
			}
			else if (i==holdings.size()-1)
			{
					cout<< "There is no match for this bookID in the system (holdings vector)."<<endl;
					j=-2; //no match (-2 is arbitrary) //return to main
			}
		}

		if (j>=0) //if  book in holdings and if location shows it's NOT checked out, print message and return to main.
		{
				loc=holdings[j].getLocation(); // loc values: 0= ON_SHELF, 1= ON_HOLD, 2= CHECKED_OUT
				if (loc != 2)
				{
						cout<<"Book ID: "<< bookID<< " is not CHECKED_OUT. Did you steal it?" <<endl;
				}

		}




		if (  (j>=0) && (loc==2) ) //if book in holdings and is Checked out... update patron's list, update book's location (ON_SHELF),
		{


				//look for book ID in holdings (use j)

				//get idNum for patron who has it checked out
				string idn; //will be the member's idNum
				Patron* p;


				p=holdings[j].getCheckedOutBy();  //pointer to book in holdings that contains a location to a patron in members (that's who checked it out)
				idn = p->getIdNum(); //dereferenced pointer to idNUm of patron in members


				///////////////////////////// UPDATE PATRON'S LIST /////////////////////////////


				//look for idn (idNum) of Patron in members vector to get location.
				int k=-1; //accepts i value in for loop to be used in establishing  patron's vector location in members       //-1 indicates no match
				//get patronID location in members
				for (int i=0; i< members.size(); i++) //check for match in members to establish pointer location to update checkedOut By
				{
						if (members[i].getIdNum()== idn)
						{
								//cout<< "//TESTING: members vector [location] that checkedOutBy will point to: "<<i<<endl; //TESTING
								k=i;
								break;
						}

				}

				Book * bookPtr;
				bookPtr=&holdings[j]; //address of book in holdings
				members[k].removeBook(bookPtr); //removes book pointer from patron's checkedOutBooks vector.  	//members[k].removeBook(Book* b)

				 //TESTING
				int sizeOfCOB= members[k].getCheckedOutBooks().size();
				//cout<<"//TESTING: print list of checked out books."<<endl;
				for (int i=0; i<sizeOfCOB; i++)
				{
						//cout<< "//TESTING: Title: ";
						//cout<<members[k].getCheckedOutBooks()[i]->getTitle()<<endl;
						//cout<< "//TESTING: Location: ";
						//cout<<members[k].getCheckedOutBooks()[i]->getLocation()<<endl;
				}
				//cout<< "//TESTING: Patron's list (members.checkedOutBooks) UPDATED!"<<endl; //TESTING


				///////////////////////////// UPDATE BOOK's LOCATION /////////////////////////////
				holdings[j].setLocation(ON_SHELF);
				//cout<< "//TESTING: Location UPDATED to: "<< holdings[j].getLocation()<<endl; //TESTING

				///////////////////////////// Print CONFIRMATION /////////////////////////////
				cout<< "Book title: "<<holdings[j].getTitle()<< ", has been returned. Thank you." <<endl;
				//cout<<"//TESTING: Book ID: "<< bookID<< " has been returned. " <<endl;
				//cout<<"//TESTING: Thank you Patron (ID: "<< idn<< ")." <<endl;


		}



}


void Library::requestBook(string patronID, string bookID) //6
{

		int match=checkIdMatch(patronID, bookID);		//match = location of book in holdings or -2 (no match)
		if (match >=0)  // match  and  nested ifs        //else return to menu;
		{
				string idn; //to hold dereferenced pointer string= idNum of requestedBy
				Patron* p;//

				if (holdings[match].getRequestedBy()!=NULL) //if book is on hold, get pointer to that idNum to compare to patron ID, otherwise if value is null
				{
						p=holdings[match].getRequestedBy();  //moved this to inside 'if ' so that pointer only assigned to non-NULL location
						idn = p->getIdNum(); //dereferenced pointer to requested by idNUm
				}

							//TESTING
							if (holdings[match].getRequestedBy()==NULL) //if requestedBy is NULL (nobody requested)
							{
									//cout<<"//TESTING: getRequestedBy() is NULL."<<endl;
							}


				if (  (holdings[match].getLocation() == ON_HOLD ) && (idn != patronID)  ) //if book is on hold and idn (requested by patron'sID isn't = to patron requesting, then say book is already on hold
				{
						cout<<"Book is already ON_HOLD by another patron"<<endl;
				}


			//////////////////////////  UPDATE REQUESTED BY /////////////////////  //may need to re-address this function in previous application (chechOutBook)

				//cout<< "TEST THIS: (before update) RequestedBy (pointer location): "<<holdings[match].getRequestedBy() <<endl; //TESTING

				int k=-1; //accepts i value in for loop to be used in assigning vector location address to ptrToPatronRequesting        //-1 indicates no match, but we already know there is a match if we got this far.
						//get patronID location in members
				for (int i=0; i< members.size(); i++) //check for match in members to establish pointer location to update checkedOut By
				{
						if (members[i].getIdNum()== patronID)
						{
								//cout<< "//TESTING: members vector [location] that RequestedBy will point to: "<<i<<endl; //TESTING
								k=i;
								break;
						}

				}

				Patron *ptrToPatronRequesting;
				ptrToPatronRequesting=&members[k];

				holdings[match].setRequestedBy(ptrToPatronRequesting);	//update pointer  in requestedBy to current patron's location in members
				//cout<< "TEST THIS: RequestedBy UPDATED to (pointer location): "<<holdings[match].getRequestedBy() <<endl; //TESTING

				//////////////////////////// UPDATE LOCATION IF ON_SHELF to ON_HOLD /////////////////////////////
				if (holdings[match].getLocation()==ON_SHELF)
				{

						//cout<< "//TESTING: Location before request update to (0= on shelf): "<< holdings[match].getLocation()<<endl; //TESTING
						holdings[match].setLocation(ON_HOLD);
						//cout<< "//TESTING: Location UPDATED to (1= on hold): "<< holdings[match].getLocation()<<endl; //TESTING

				}

				///////////////////////////// PRINT MESSAGE /////////////////////////////
				cout<<" Book: "<< holdings[match].getTitle()<<", is on request for: "<<members[k].getName()<<endl;
		}

}


void Library::incrementCurrentDate()  //7
{

		//0.1 * total_days_overdue

		//cout<<"//TESTING: currentDate= "<<currentDate<<endl; //TESTING
		int old_date=currentDate;
		currentDate+=1;
		//cout<<"//TESTING: new_date= "<<currentDate<<endl; //TESTING

		int total_days_since_co;
		int factor;
		int diff;
		double add_amount;
		double sub_total;
		for (int i=0; i< members.size(); i++) //cycle thru members
		{
				int sizeOfCOB=members[i].sizeOfCheckedOutBooks(); //determine number of books for this patron

				add_amount=0;
				diff= currentDate - old_date; //usually 1 day

				for (int j=0; j< sizeOfCOB; j++) //cycle thru CheckedOutBooks   //M
				{
						total_days_since_co= currentDate - (members[i].getCheckedOutBooks()[ j]->getDateCheckedOut());   //number of days since check out of book
						//add_amount=0;

								if ( total_days_since_co >(Book::CHECK_OUT_LENGTH)) //if book is overdue
								{

												//cout<<"//TESTING:  (before add) members[" << i<<"].getFineAmount(): "<<members[i].getFineAmount()<<endl;

												add_amount= DAILY_FINE * diff; //usually 0.1 * 1
												members[i].amendFine(add_amount); //old total + add_amount

												//cout<<"//TESTING: (after add) members[" << i<<"].getFineAmount(): "<<members[i].getFineAmount()<<endl;
								}
				}


		}


}




 void Library::payFine(string patronID, double payment) //8
{
		int k=-4; //patron location //default value arbitrary
		for (int i=0; i< members.size(); i++) //check for match in members
		{
				if (members[i].getIdNum() == patronID)
				{
						//cout<< "//TESTING: Match found, patron in the system (members vector) @: "<<i<<endl; //TESTING
						k=i;
						break;
				}
				else if (i==members.size()-1)
				{
						cout<< "There is no match for this patronID in the system (members vector)."<<endl;
						k=-2; //no match (-2 is arbitrary)
				}
		}

		if (k>=0)
		{

				double fines=members[k].getFineAmount();
				//cout<<"//TESTING: before amending fines, amount: $"<<fines<<endl; //TESTING
				if (fines!=0)
				{
						members[k].amendFine(fines);
						//cout<<"//TESTING: existing value for fines, so amended accordingly."<<endl; //TESTING
				}
				cout<<"Patron: "<< members[k].getName()<<", has fines amounting to: $ "<<members[k].getFineAmount()<<endl;
		}

}


 void Library::viewPatronInfo(string patronID)  //9
 {
		int j=-3; //if -2 , no match   /////if >=0 in library location is value of J

		for (int i=0; i< members.size(); i++) //check for match in members
		{
				if (members[i].getIdNum() == patronID)
				{
						//cout<< "//TESTING: Match found, patron in the system (members vector) @: "<<i<<endl; //TESTING
						j=i;
						break;
				}
				else if (i==members.size()-1)
				{
						cout<< "There is no match for this patronID in the system (members vector)."<<endl;
						j=-2; //no match (-2 is arbitrary) //return to main
				}
		}

		if (j >=0) //if  member in holdings, J is location
		{
				cout<<"Patron ID: "<< members[ j].getIdNum()<<endl;
				cout<<"Name: "<< members[ j].getName()<<endl;
				cout<<"Books checked out: "<<endl;


				int sizeOfCOB=members[ j].sizeOfCheckedOutBooks();


				for (int i=0; i< sizeOfCOB; i++)
				{
						if (members[ j].getCheckedOutBooks()[ i]->getLocation()== CHECKED_OUT)
						{
								cout<<"--Book ID: "<< members[ j].getCheckedOutBooks()[ i]->getIdCode()<<endl;
						}
				}

				cout<<endl<<endl;
				cout<<"Total fines: $"<< members[ j].getFineAmount()<<endl;

		}



 }


 void Library::viewBookInfo(string bookID)  //10
{
		int j; //if -2 , no match   /////if >=0 in library location is value of J
		int loc; // loc values: 0= ON_SHELF, 1= ON_HOLD, 2= CHECKED_OUT
		for (int i=0; i< holdings.size(); i++) //check for match in holdings
		{
				if (holdings[i].getIdCode() == bookID)
				{
						//cout<< "//TESTING: Match found, book in the system (holdings vector) @: "<<i<<endl; //TESTING
						j=i;
						break;
				}
				else if (i==holdings.size()-1)
				{
						cout<< "There is no match for this bookID in the system (holdings vector)."<<endl;
						j=-2; //no match (-2 is arbitrary) //return to main
				}
		}

		if (j >=0) //if  book in holdings, J is location
		{
				cout<<"Book ID: "<< holdings[ j].getIdCode()<<endl;
				cout<<"Title: "<< holdings[ j].getTitle()<<endl;
				cout<<"Author: "<< holdings[ j].getAuthor()<<endl;

				//cout<<"Location: "<< holdings[ j].getLocation()<<endl;
				loc=holdings[ j].getLocation();
				if (loc == 0)
				{
						cout<<"Location: ON_SHELF"<<endl;
				}

				if (loc == 1)
				{
						cout<<"Location: ON_HOLD"<<endl;
				}

				if (loc == 2)
				{
						cout<<"Location: CHECKED_OUT"<<endl;
				}

				if (holdings[ j].getLocation() == ON_HOLD)
				{
						cout<< "On request by patron#: " ;
						//cout<<holdings[j].getCheckedOutBy()->getIdNum()<<endl;

						//         /*
						if (holdings[j].getCheckedOutBy()==NULL)
						{
								cout<<holdings[j].getRequestedBy()->getIdNum()<<endl;
						}
						else
						{
							cout<<holdings[j].getCheckedOutBy()->getIdNum()<<endl;
						}
						//          */


				}

				if (holdings[ j].getLocation() == CHECKED_OUT)
				{
						cout<< "Checked out by patron#: "<<endl;
						cout<<holdings[j].getCheckedOutBy()->getIdNum()<<endl;


						int days_since_co=currentDate- holdings[j].getDateCheckedOut(); //determines of overdue


						int due_date= holdings[j].getDateCheckedOut() + Book::CHECK_OUT_LENGTH;
						int more_days=due_date - currentDate;  //negative if overdue

						cout<< "Due by day #: "<<endl;
						cout<<due_date<<endl;
						cout<<"("<<more_days<<" days.) "<<endl;

						if (days_since_co>(Book::CHECK_OUT_LENGTH))
						{
								cout<< "Book is overdue. "<<endl;
						}

				}


		}
}





int Library::checkIdMatch(string patronID, string bookID) //11  //added to header  //maybe not necessary
{
		int j; //holding location
		int k; //patron location

		if (holdings.size() ==0) //in case holdings is empty
		{
				j=-2;
				cout<< "There is no match for this bookID in the system (holdings vector)."<<endl;
		}


		for (int i=0; i< holdings.size(); i++) //check for match in holdings
		{
			if (holdings[i].getIdCode() == bookID)
			{
						//cout<< "//TESTING: Match found, book in the system (holdings vector) @: "<<i<<endl; //TESTING
					j=i;
					break;
			}
			else if (i==holdings.size()-1)
			{
					cout<< "There is no match for this bookID in the system (holdings vector)."<<endl;
					j=-2; //no match (-2 is arbitrary)
			}
		}

		if (members.size() ==0) //in case members is empty
		{
				k=-2;
				cout<< "There is no match for this patronID in the system (members vector)."<<endl;
		}

		for (int i=0; i< members.size(); i++) //check for match in members
		{
			if (members[i].getIdNum()== patronID)
			{
						//cout<< "//TESTING: Match found, member in the system (members vector) @: "<<i<<endl; //TESTING
					k=i;
					break;
			}
			else if (i==members.size()-1)
			{
					cout<< "There is no match for this patronID in the system (members vector)."<<endl;
					k=-2; //no match in members (-2 is arbitrary)
					break;
			}
		}

		//what to return: location of book in holdings, or -2 indicating no matches
		if ((k>-2) && (j>-2)) //match in both
		{
					//cout<<"//TESTING: j value (location in holdings) should be >=0 if match: "<<j<<endl; //TESTING
				return j; //match location in holdings
		}
		else
		{
				return -2; //no matches in either
		}
}



