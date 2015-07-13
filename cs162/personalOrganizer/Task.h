
//  
//  Task.h
//  A header file for Task definition
//  Created by Lindsay Tucker on 03/03/15.
//  Updated on 03/07/15
//  Copyright (c) 2015 Lindsay Tucker. All rights reserved.
//

#ifndef TASK_H
#define TASK_H

const int SIZE = 101;  //GLOBALLY DEFINED HERE IN Task.h ONLY

class Task
{

	private:
	char *course_name; 
    char *assign_desc; 
    char *due_date; 
	
	public:
	//constructors
	Task();
	Task(const char input_course_name [], const char input_assign_desc[], const char input_due_date []);  // DYNAMIC
	// destructor
	~Task();  //DESTROY DYNAMIC
	
	//ACCESSOR FUNCTIONS
	void getCourseName(char input_course_name[]) const;
	void getAssignDesc(char input_assign_desc[]) const;
	void getDueDate(char input_due_date []) const;
	
	//MUTATOR FUNCTIONS
	void setCourseName(const char input_course_name []);
	void setAssignDesc(const char input_assign_desc []);
	void setDueDate(const char input_due_date []);

}; 

#endif
