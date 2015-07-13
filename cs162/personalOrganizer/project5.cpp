//
//
//  personalOrganizer4.cpp
//
//  Created by Lindsay Tucker on 03/03/15.
//  Updated on 03/07/15
//  Copyright (c) 2015 Lindsay Tucker. All rights reserved.
//
//   Notes: all objects, object containers, and functions follow this: namingFormat, other variables named like_this


//      AUTHOR NOTES TO SELF:
//      WHEN SEPARATING   .h and .cpp files, move:
//      const int SIZE = 101;  //(GLOBALLY DEFINED  IN Task.h ONLY)
//       un-comment #include Task.h and Tasklist.h
//      update header and implementation files
//       delete project5.exe


//DEBUGGING
//#define _CRTDBG_MAP_ALLOC
//#include <stdlib.h>
//#include <crtdbg.h>

#include "Task.h"
#include "TaskList.h"

#include <iostream>
#include <cstring>
#include <fstream> // definitions for ifstream and ofstream
#include <stdlib.h>  // exit
#include <cctype> //char handling functions
#include <iomanip> //setprecision ,etc

using namespace std;

// GLOBAL FUNCTIONS
void displayMenu ();  //displays menu

int main()
{


		//temp input storage (ifstream and user input)
		char input_course_name [SIZE];
		char input_assign_desc [SIZE];
		char input_due_date [SIZE];

		Task taskObject;  //default constructor, other constructor called w/ file input
		TaskList taskData; //default constructor

		// filestream
		ifstream task_in;
		//ofstream in TaskList member function
		char external_file[] = "tasks.txt";

		// variables for search function
		char search_key [SIZE]; //holds search terms (user-entry)
		int num_of_matches = 0;

		//switch menu
		char choice;

		//OPEN FILE
		task_in.open (external_file); //opens file
		if(!task_in) //error message if failure to open, then exit
		{
				task_in.clear();
				cerr << endl << "Failure when opening file: " << external_file << endl; //output stream for errors
				exit(1);
		}


		//READ IN CONTENTS TO OBJECT>LINKED LIST, CLOSE (adapted from Lecture: "Address Book - File Input/Output ")
		task_in.get(input_course_name, SIZE, ';'); //grab all characters before " ; " or until SIZE is reached
		while (!task_in.eof()) //until end of file / while not at the end of file
		{

				task_in.get(); //removes delimiter
				task_in.get(input_assign_desc, SIZE, ';');

				task_in.get();	//removes delimiter
				task_in.get(input_due_date, SIZE, '\n');
				task_in.ignore(100, '\n');				//removes '\n'

				//input to object
				Task taskObject (input_course_name, input_assign_desc, input_due_date); //constructor

				//object to array
				taskData.setTaskDataSort(taskObject);

				task_in.get(input_course_name, SIZE, ';'); //next line: grabs all characters before " ; " or until SIZE is reached

		}

		task_in.close(); //close file



		//  do: switch menu , while: 'choice'
		do
		{
				//Display menu and prompt user for 'choice'
				displayMenu ();
				cin >> choice;
				cin.ignore(100, '\n'); //throw away rest of the line

				//Switch statement for user menu choices
				switch (choice)
				{
						case '1': //////////// ENTER NEW TASK //////////////////////
						// 1) enter task (add to object and then to list)
						cout << "Input course name: " << endl;
						cin.get (input_course_name, SIZE, '\n');
						cin.ignore (100, '\n'); //removes newline character if cin.get stops before newline character causing \n to be stuck in buffer

						cout << "Input assignment description: " << endl;
						cin.get (input_assign_desc, SIZE, '\n');
						cin.ignore (100, '\n');

						cout << "Input due date in the following format (MM/DD/YYYY): " << endl;
						cin.get (input_due_date, SIZE, '\n');
						cin.ignore (100, '\n');

						//input to object
						taskObject.setCourseName(input_course_name);
						taskObject.setAssignDesc(input_assign_desc);
						taskObject.setDueDate(input_due_date);

						//object to list
						taskData.setTaskDataSort (taskObject);

						cout << " ----------------------------" << endl;
						break;

						case '2': ////////////////////// LIST ALL TASKS ///////////////////////////
						// 2) display all of tasks in list
						taskData.printTaskData();
						cout << " ----------------------------" << endl;
						break;

						case '3': ////////////////////  SEARCH BY COURSE ///////////////////
						// 3) find task by course
						cout << "Enter the complete course name for which you'd like to display tasks" << endl;
						cout << "(case-sensitive): " << endl;
						cin.get (search_key, SIZE, '\n');
						cin.ignore (100, '\n'); //removes newline character if cin.get stops before newline character causing \n to be stuck in buffer

						taskData.findTask (num_of_matches, search_key, taskObject);
						cout << "Total tasks found for that course: " << num_of_matches << endl;
						num_of_matches = 0;

						cout << " ----------------------------" << endl;
						break;

						case '4':  ///////////////  SAVE AND EXIT  /////////////////////////////////
						// 4) quit
						//OPEN FILE, SAVE, CLOSE (when quitting)
						taskData.writeFile(external_file);

						cout << "Exiting." << endl;
						break;

						default:
						break;

				} //end of SWITCH

				if (choice == '4')
				{
						break;
				}

		} while ((choice = '1') || (choice = '2') || (choice = '3'));


		return 0;
}


///////////////////////////////////////////////////////////////////////////////

				//  FUNCTIONS  //

/////////////////////////////////////////////////////////////////////////////////


/*
	DISPLAY MENU
*/
void displayMenu ()
{

		//Display menu
		cout << " ----------------------------" << endl;
		cout << "  ~ YOUR PERSONAL ORGANIZER ~" << endl;
		cout << " ----------------------------" << endl << endl;
        cout << "Choose one of the following options: " << endl;
        cout << "1. Enter a task or assignment" << endl;
        cout << "2. Display all tasks" << endl;
        cout << "3. Find a task by 'course' " << endl;
        cout << "4. Quit" << endl;
		cout << "Enter an option (1-4): ";
}


