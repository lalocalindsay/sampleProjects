/****************************************************************************************
Author: Lindsay Tucker
Date created: 14Nov2014
Date last modified: 14Nov2014
Program Filename:  symArrays.cpp
Description/overview: 
This program will use CL arguments to specify the size
of 3 arrays that they with fill w/ integers. The arrays will be dynamically allocated.
Symmetry values will be printed for each array. 0 not symmetric. 

INPUT: 
 command line: specify size of 3 1D arrays
./symArrays size1  size2  size3 

array int contents entered in a single line w/ spaces
		
	
OUTPUT: 
the program will output the following:
		
		symmetry for each array

							
****************************************************************************************/

#include <iostream>
#include <string>
 #include <cstring>
 #include <stdlib.h>
 
using namespace std;


//Function prototype
bool symArray(int array_1[], int length_1);
bool symArray(int array_2[], int length_2);
bool symArray(int array_3[], int length_3);

int main(int argc, char *argv[]) //command line: user enter 3 ints
{
	
	if (argc <= 3) 
    {
        cout << "NOT ENOUGH ARGUMENTS ENTERED." << endl;
        exit(1);
    }
	
	else
	{
			cout<<"The arguments you entered are:"<<endl;
			for(int i=1;i<argc;i++)
				cout<<argv[i]<<endl;
	}
	
	int length_1 = atoi (argv[1]); //convert  c-string values from argv to int
	//cout<< length_1; //TESTING
	
	int length_2 = atoi (argv[2]); //convert  c-string values from argv to int
	//cout<< length_2; //TESTING
	
	int length_3 = atoi (argv[3]); //convert  c-string values from argv to int
	//cout<< length_3; //TESTING
	
	
	//variable definitions
	int * array_1;
	int * array_2;
	int * array_3;
	
	
	array_1= new int [length_1];
	array_2= new int [length_2];
	array_3= new int [length_3];
	
	
	
	//////////////////////// FILL ARRAY 1  ///////////////////////////////
	cout<< "\nARRAY 1" <<endl;
	cout<<"\nEnter " << length_1 << " integers, separated by spaces:" <<endl;
	for (int i = 0; i< length_1; i++)
	{			
			cin>> array_1[i];
			while (!cin) 	//don't count whitespace
			{	
					i+1;
			}
					//cin.ignore(1000000, '\n');  //cin ignore here or below
	}		
	for (int m=0; m< length_1; m++) //TESTING
	{
			cout<< array_1 [m]; //TESTING
	}	
	//////////////////////// FILL ARRAY 1  ///////////////////////////////
	
	
	
	//////////////////////// FILL ARRAY 2  ///////////////////////////////
	cout<< "\nARRAY 2" <<endl;
	cout<<"\nEnter " << length_2 << " integers, separated by spaces:" <<endl;
	for (int i = 0; i< length_2; i++)
	{			
			cin>> array_2[i];
			while (!cin) 	//don't count whitespace
			{	
					i+1;
			}
					//cin.ignore(1000000, '\n');  //cin ignore here or below
	}		
	for (int m=0; m< length_2; m++) //TESTING
	{
			cout<< array_2 [m]; //TESTING
	}	
	//////////////////////// FILL ARRAY 2  ///////////////////////////////
	
	
	//////////////////////// FILL ARRAY 3  ///////////////////////////////
	cout<< "\nARRAY 3" <<endl;
	cout<<"\nEnter " << length_3 << " integers, separated by spaces:" <<endl;
	for (int i = 0; i< length_3; i++)
	{			
			cin>> array_3[i];
			while (!cin) 	//don't count whitespace
			{	
					i+1;
			}
					//cin.ignore(1000000, '\n');  //cin ignore here or below
	}		
	for (int m=0; m< length_3; m++) //TESTING
	{
			cout<< array_3 [m]; //TESTING
	}	
	//////////////////////// FILL ARRAY 3  ///////////////////////////////
	
	
	cout<< "-------------------------------------------------"<<endl;
	cout<< "\n 0=not symmetric, 1=symmetric" <<endl;
	cout<< "-------------------------------------------------"<<endl;
	
	//call functions
	cout<<"\n ARRAY 1: "<<endl;
	symArray(array_1, length_1);
	cout<< endl<<endl;
	
	cout<<"\n ARRAY 2: "<<endl;
	symArray(array_2, length_2);
	cout<< endl<<endl;
	
	cout<<"\n ARRAY 3: "<<endl;
	symArray(array_3, length_3);
	cout<< endl<<endl;
	
	delete [] array_1;
	delete [] array_2;
	delete [] array_3;
	
	return 0;

}

/**********************************************************************************
							This function increments thru arrays
 **********************************************************************************/

bool symArray(int array [], int length)
 {
	bool symm = 0; //not symmetrical 
	
	int i;
	int j;
	
	//array (length is odd)
	if (length %2 !=0)
	{
			//int length_decre= length;
			int oddmid=  length/2;
					//cout<< "oddmid:"<<oddmid<<endl;  //TESTING
			for (int i=0; i<oddmid; i++)
			{
					for (int j=length; j>oddmid ; j--)
					{
						if(array[i] != array[j])
						{
							symm = 0; //not equal
							//cout<< "\n1-1) odd length, NOT symmetrical" <<endl; //TESTING
						}
						else if (array[i] == array[j])
						{
							symm = 1; //the two values on  opposite sides of the array are equal
							//cout<< "\n1-2) odd length, symmetrical" <<endl; //TESTING
						}
					
					}
			}
	}
	
	
	//array (length is even)
	if (length%2 ==0)
	{
			
			int evenmid=  length/2;
					//cout<< "evenmid:"<<evenmid<<endl;  //TESTING
			for (int i=0; i<evenmid; i++)
			{
					for (int j=length; j>evenmid-1 ; j--)
					{
						if(array[i] != array[j])
						{
							symm = 0; //not equal
							//cout<< "\n2-1) even length, NOT symmetrical" <<endl; //TESTING
						}
						else if (array[i] == array[j])
						{
							symm = 1; //the two values on  opposite sides of the array are equal
							//cout<< "\n2-2) even length, symmetrical" <<endl; //TESTING
						}
					
					}
			}
	}
	
	
	
	cout<< endl<< "symmetry: " <<symm<<endl;
	return symm;
 }

 
 
 