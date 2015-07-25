/****************************************************************************************
Author: Lindsay Tucker
Date created: 31Oct2014
Date last modified: 31Oct2014
Program Filename:  recFun.cpp
Description/overview: 
This program will accept integer input  (n) that is sent to a (recursive) function to 
determine the nth number in the Fibonacci sequence.

INPUT: 
	int input		//user input	
			
OUTPUT: 
the program will output the following:
	int fib(input)	//an integer which originates from the parameter sent to the recursive function
****************************************************************************************/


#include <iostream>


using namespace std;

//Function prototype
int fib(int input);

int main () 
{
		
		//define variables
		int input; //user input

		
		cout<< "Which number in the Fibonacci sequence would you like me to display? "<<endl;
		cout<< "(enter an integer): "<<endl;
		cin>> input;
		cout<< "This program will display the "<< input<<"th Fibonacci number." <<endl;
		
		cout<<fib(input-1)<<endl; //simplified version of next 2 lines
			//fib(input);
			//cout<< fib(input-1)<< endl; //Input-1 displays the accurate input's number in the sequence, sequence starts at F sub 0
		
		return 0;
}

/**********************************************************************************
	This function accepts an integer parameter (n) and computes the nth
	number in the Fibonacci sequence.
**********************************************************************************/

int fib(int input) 
{
			if (input<=0) //BASE CASE
				return 0;
			else if (input==1) //BASE CASE
				return 1;
			else 
				return fib(input-1) + fib(input-2);
}
