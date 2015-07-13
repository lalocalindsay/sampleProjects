
//  
//  Task.cpp
//  An implementation file for Task definition
//  Created by Lindsay Tucker on 03/03/15.
//  Updated on 03/07/15
//  Copyright (c) 2015 Lindsay Tucker. All rights reserved.
//

#include "Task.h"
#include <cstring>
using namespace std; 


//DEFAULT CONSTRUCTOR
Task::Task()
{
		// initializes members w/ empty fields
		course_name = new char[strlen(" ")+1]; 
		assign_desc = new char[strlen(" ")+1];
		due_date = new char[strlen(" ")+1];
		
		//add placeholders  "    "
		strcpy (course_name," ");
		strcpy (assign_desc, " ");
		strcpy (due_date, " ");
		
}

//CONSTRUCTOR
Task::Task (const char input_course_name [], const char input_assign_desc[], const char input_due_date [])
{
		
		//cout << "//TESTING: " << strlen(input_course_name)+1 << endl;   ///  cs162 = 6
		course_name = new char[strlen(input_course_name)+1];
			
		//cout << "//TESTING: " << strlen(input_assign_desc)+1 << endl;  
		assign_desc = new char[strlen(input_assign_desc)+1];
			
		//cout << "//TESTING: " << strlen(input_due_date)+1 << endl;  
		due_date = new char[strlen(input_due_date)+1];
		
		strcpy (course_name, input_course_name);
		strcpy (assign_desc, input_assign_desc);
		strcpy (due_date, input_due_date);
}

//DESTRUCTOR
Task::~Task()
{

		if (course_name !=NULL)
			delete course_name;
		if (assign_desc !=NULL)
			delete  assign_desc;
		if (due_date !=NULL)
			delete due_date;

}


//ACCESSOR FUNCTIONS //adapted from Li Liang AddressEntry.cpp  
void Task::getCourseName(char input_course_name[]) const
{
		strcpy(input_course_name, course_name);
}
void Task::getAssignDesc(char input_assign_desc[])  const
{
		strcpy(input_assign_desc, assign_desc);
}
void Task::getDueDate(char input_due_date []) const
{
		strcpy (input_due_date, due_date);
}


//MUTATOR FUNCTIONS  //adapted from Li Liang AddressEntry.cpp
void Task::setCourseName(const char input_course_name [])
{
		if(course_name != NULL)
				delete [] course_name;
		course_name = new char[strlen(input_course_name)+1];
		strcpy (course_name, input_course_name);
}
void Task::setAssignDesc(const char input_assign_desc []) 
{
		if(assign_desc != NULL)
				delete [] assign_desc;
		assign_desc = new char[strlen(input_assign_desc)+1];
		strcpy (assign_desc, input_assign_desc);
}
void Task::setDueDate(const char input_due_date []) 
{
		if(due_date  != NULL)
				delete [] due_date ;
		due_date  = new char[strlen(input_due_date)+1];
		strcpy (due_date, input_due_date);
}
