/****************************************************************************************
Author: Lindsay Tucker
Date created: 9Nov2014
Date last modified: 6Nov2014
Program Filename:  wordShift.cpp
Description/overview: 
This program will ask the user to define a string of characters.
It will then present the user with a menu of options:
-reverse the string
-move it to the left (x) places
-move it to the right (x) places

The user will then be allowed to continue manipulating the  current string
as many times as they like before exiting. More specifically, this means that
once the original string has been modified, it will remain modified until the user
modifies it back to its original display order. The program will  use cstrings, switch,
and three functions.

INPUT: 

		string string_input	// user input which and to be manipulated using cstring_input and cstring_printer
		char choice         // menu choice 1,2,3 or exit
		int x_left			// number of places to move string to the left
		int x_right         // number of places to move string to the right
		
	
OUTPUT: 
the program will output the following:
		
		cstring_printer     // this cstring will be used repeatedly by
                               the rev, Lx, and Rx functions to manipulate
                               and display the user input string
							
****************************************************************************************/

#include <iostream>
#include <string>
#include <cstring>
 
using namespace std;

//global variable
const int SIZE=30;

//Function prototype
void rev(char cstring_input[], char cstring_printer[], int);
void Lx(char cstring_input[], char cstring_printer[], int);
void Rx(char cstring_input[], char cstring_printer[], int);

int main()
{

	
		//DEFINE VARIABLES

		//const int SIZE=30;            //moved to global
		char cstring_input[SIZE],		//input c-string (converted from C++ string)
		cstring_printer [SIZE]; 		//empty c-string to be manipulated
		int length;                     //length of cstring_input
				
		string string_input; 			///// INPUT AS STRING
		
		//VARIABLE FOR SWITCH
		char choice;
		
				
		cout << "Please input a string (all characters are possible):" << endl;
        getline (cin, string_input);                    //INPUT AS STRING //GETLINE TO ACCOUNT FOR SPACES
					//cout <<"(MAIN) string_input: "<< string_input<<endl; //TESTING			
		
		//cout<< endl<< endl;
		
		strcpy(cstring_input, string_input.c_str()); 	//COPY string_input to cstring_input 
					//cout <<"(MAIN) cstring_input: "<< cstring_input<<endl; //TESTING
		
		//cout<< endl<< endl;

		strcpy(cstring_printer, cstring_input);         //COPY cstring_input to cstring_printer
					//cout <<"(MAIN) cstring_printer: "<< cstring_printer<<endl; //TESTING
		
		//cout<< endl<< endl;
		
		length = strlen(cstring_input);                 //determines length (to send to function)
					//cout <<"cstring_input strlen: " <<length<<endl; //TESTING
    
		
///////////////////////////////////     SWITCH START   ///////////////////////////////

	
	
		do
		{
			cout<< "\n\n-------------------MAIN MENU------------------" <<endl;
			cout<< "Options: "<<endl;
			cout<< "  1. (rev)		Reverse the string."<<endl;
			cout<< "  2. (Lx)		Shift the characters in the string LEFT (x) spaces."<<endl;
			cout<< "  3. (Rx)		Shift the characters in the string RIGHT (x) spaces."<<endl<<endl;
			cout<< "  or Exit. "<<endl<<endl<<endl;
			 
			cout<< "Enter a menu option 1, 2, 3, or E (exit): "<<endl;
			cin>> choice;
			cin.clear();                                //input control for >1 character
			cin.ignore(1000000, '\n');	
				
			switch (choice)
			{
					
					//case 'rev':
					//////////////////////////////////////////////////////////////////////
					case '1': cout<< "\n\n\n\n1. Reverse the string."<<endl<<endl;
					
					cout<< endl<< endl;

					rev(cstring_input, cstring_printer, length);
						
					cout<< endl<<endl<<endl<<endl<<endl<<endl;
					//////////////////////////////////////////////////////////////////////
					break; //SWITCH
	
		
					//case 'Lx ':
					//////////////////////////////////////////////////////////////////////
					case '2': cout<< "\n\n\n\n2. Shift the characters in the string LEFT (x) spaces."<<endl<<endl;
					
					cout<< endl<< endl;
		
					Lx(cstring_input, cstring_printer, length); //need to accept integer of spaces to move (loop this many times)
					
					cout<< endl<<endl<<endl<<endl<<endl<<endl;
					//////////////////////////////////////////////////////////////////////
					break;	//SWITCH
					
					
					//case 'Rx ':
					//////////////////////////////////////////////////////////////////////
					case '3': cout<< "\n\n\n\n3. Shift the characters in the string RIGHT (x) spaces."<<endl<<endl;
					
					cout<< endl<< endl;
		
					Rx(cstring_input, cstring_printer, length);
					
					cout<< endl<<endl<<endl<<endl<<endl<<endl;
					//////////////////////////////////////////////////////////////////////
					break;	//SWITCH
					
					
					//exit
					/////////////////////////////////////////////////////////////////////
					case 'E': cout<<"exiting"<<endl;
							return 0;
					case 'e': cout<<"exiting"<<endl;
							return 0;
					default: cout<< "You didn't enter 1) rev, 2) Lx, 3) Rx, or E) exit."<<endl;
								  cout<< "Your string is: "<< cstring_printer<<endl;
							break;
			
			} //end of SWITCH
		
		} while ((choice = '1') || (choice = '2') || (choice = '3')); 		//end of do-while for repetitive menu control



///////////////////////////////////     SWITCH END   ///////////////////////////////

	return 0;
}



/******************************************************************************
			This function reverses the string using a temp cstring.
 ******************************************************************************/
 
void rev(char cstring_input[], char cstring_printer[], int length)
{
		
		cout<< "(rev FUNCTION): ";
		cout<< endl;
		
		char temp [SIZE];
		strcpy (temp, cstring_printer);
		
		int j =0;
		for (int i=length-1; i>=0; i--) 
		{
				
				cstring_printer[j]=temp[i];
				j++;
		}
		
		cout<<cstring_printer;
}

/**********************************************************************************
		This function does Lx: shifts string left (x) number of spaces and
		appends the truncated items to the end of the string.
 **********************************************************************************/

void Lx(char cstring_input[], char cstring_printer[], int length)
{
		int x_left;                                                         //prompt for input
		
		cout<<"How many spaces would you like to shift LEFT? "<<endl;
		cout<<"(enter an integer): ";
		cin>>x_left;
		
		while (!cin)                                                        //int input validation
		{	
				cout<<"(enter an integer): ";
				cin.clear();
				cin.ignore(1000000, '\n');
				cin>>x_left;
		}
		
		if (x_left>0) 
		{
				do
				{
						int temp= cstring_printer[0];                       //holds first char in temp
						for (int i=0; i< (length-1); i++)
						{
								cstring_printer[i] = cstring_printer[i+1];  //what was at 1, now at 2, 2>3, 3>4...
						}
						cstring_printer[length -1] =temp;                   //puts former first char at the end
		
						x_left--;                                           //decrements the shift variable
		
				} while (x_left>0);
		}
		cout<< "(Lx FUNCTION): ";		//TESTING
		cout<< endl;
		cout<<cstring_printer; 
		
		
}

/****************************************************************************************
		This function does Rx: shifts string right (x) number of spaces and
		appends the truncated items to the front of the string.
 ****************************************************************************************/
 void Rx(char cstring_input[], char cstring_printer[], int length)
 {
		
		int x_right;                                                        //prompt for input
		cout<<"How many spaces would you like to shift RIGHT? "<<endl;
		cout<<"(enter an integer): ";
		cin>>x_right;
		
		while (!cin)                                                        //int input validation
		{	
				cout<<"(enter an integer): "; 
				cin.clear();
				cin.ignore(1000000, '\n');
				cin>>x_right;
		}
		
		
		if (x_right>0)
		{
				do
				{
						int temp= cstring_printer[length-1];                //holds last char in temp
						for (int i=(length-1); i>0; i--)
						{
								cstring_printer[i] = cstring_printer[i-1]; 
						}
						cstring_printer[0] =temp;                           //puts former last char at the beginning
		
						x_right--;                                          //decrements the shift variable
		
				} while (x_right>0);
		}
		cout<< "(Rx FUNCTION): ";		//TESTING
		cout<< endl;
		cout<<cstring_printer; 
		
 }
 
 
 
