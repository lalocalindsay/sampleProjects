
//  
//  TaskList.cpp
//  A header file for TaskList definition
//  Created by Lindsay Tucker on 03/03/15.
//  Updated on 03/07/15
//  Copyright (c) 2015 Lindsay Tucker. All rights reserved.
//


#include "TaskList.h" 
#include "Task.h" 
#include <cstring>
#include <iostream>
#include <stdlib.h>
#include <fstream>
using namespace std; 


//DEFAULT CONSTRUCTOR   //adapted from Li Liang AddressBook E: EntryList.cpp
TaskList::TaskList()
{
		taskData_size = 0;
		head =NULL;

}

//DESTRUCTOR   //adapted from Li Liang AddressBook E: EntryList.cpp
TaskList::~TaskList()
{
		Node * curr = head;
		while(head != NULL)
		{
				curr = head->next;

				//delete node that head points to 
				//destructor for Task invoked automatically
				delete head;	

				head = curr;
		}

}

//ACCESSOR FUNCTIONS

int TaskList :: getTaskDataSize() const
{
		return taskData_size;
}

bool TaskList :: getTaskObject(int index, Task &taskObject)  const
{
		// local cstrings for transfer from get to set
		char object_course_name [SIZE]; 
		char object_assign_desc [SIZE];
		char object_due_date [SIZE];	
		
		if(index < 0 || index >= taskData_size)
		{
				return false;
		}
		//traverse to position
		int j;
		Node *	curr = head;
		for( j =0; j <index; j++)
		{	
				curr = curr->next;
		}

		curr->taskData.getCourseName (object_course_name);
		curr->taskData.getAssignDesc (object_assign_desc);
		curr->taskData.getDueDate (object_due_date);
		
		
		taskObject.setCourseName (object_course_name);
		taskObject.setAssignDesc (object_assign_desc);
		taskObject.setDueDate (object_due_date);
		return true;
}


/* 
	Prints taskData
	in:  N/A
	out:  N/A
*/
void TaskList :: printTaskData ()     
{
		Node *	curr;
		// local variables used for printing
		char print_course_name[SIZE];
		char print_assign_desc[SIZE];
		char print_due_date[SIZE];
		
		cout << "ALL TASKS: " << endl;
	
		for(curr=head; curr; curr=curr->next)
		{
				curr->taskData.getCourseName(print_course_name);
				curr->taskData.getAssignDesc (print_assign_desc);
				curr->taskData.getDueDate(print_due_date);
				
				cout << print_course_name << ";" << print_assign_desc << ";" <<print_due_date << endl;
				
		}

}


/* 
	Finds task in list based on search key and prints matches w/ cout
	in:  num_of_matches, search_key[], matchingTask
	out:  num_of_matches
*/
bool TaskList :: findTask (int& num_of_matches,  const char search_key[], Task &matchingTask) const
{
		Node *	curr;
		
		// local variables used for finding
		char find_course_name[SIZE];
		char find_assign_desc[SIZE];
		char find_due_date[SIZE];
		
		cout<< endl << "Matches: " << endl;
		for(curr=head; curr!=NULL; curr = curr->next)
		{
				curr->taskData.getCourseName (find_course_name);
				curr->taskData.getAssignDesc (find_assign_desc);
				curr->taskData.getDueDate (find_due_date);
				if(strcmp(search_key, find_course_name) == 0)  //they match,
				{
						matchingTask.setCourseName (find_course_name);
						matchingTask.setAssignDesc (find_assign_desc);
						matchingTask.setDueDate (find_due_date);
						
						cout << find_course_name << ";" << find_assign_desc << ";" << find_due_date <<endl;
						num_of_matches ++; //this number is displayed in main 
						//break;
				}
		}
		if (!curr)
		{
				return false;
		}
		else
		{
				return true;
		}
		
}



//MUTATOR FUNCTIONS

/* Adds the passed in taskObject at the beginning of the list
   in: taskObject
   out: N/A
*/
/*
void TaskList::setTaskDataBeginning(const Task &taskObject) //adapted from Li Liang AddressBook E EntryList.cpp
{
		//create a new node to hold the data
		Node * newNode = new Node(taskObject);

		//insert the node at the beginning of the list
		newNode->next = head;
		head = newNode;

		// increment size
		taskData_size++;
}
*/



/* Append the passed taskObject to the end of the list
   in: taskObject
   out: N/A
*/

void TaskList :: setTaskDataAppend(const Task &taskObject)  //adapted from Li Liang AddressBook E EntryList.cpp
{
		//create a new node to hold the data
		Node * newNode = new Node(taskObject);

		//empty list?	
		if(!head)
		{
				head = newNode;
		}
		else
		{
				Node * curr = head;

				//traverse to the last node 
				while(curr->next)  //note this is not while(curr)
				{
						curr = curr->next;
				}

				//link the newNode to the last node
				curr->next = newNode;
		}
	
		// increment size
		taskData_size++;
}




/* 
	Add object to linked list downstream alphabetically 
	in: TaskObject
	out: NA
*/
void TaskList::setTaskDataSort (const Task &taskObject)  //adapted from Li Liang AddressBook E EntryList.cpp
{
		// local cstrings for accepting object variables
		char set_course_name[SIZE];
		char curr_course_name[SIZE]; //existing  course_name in taskData list
		
		//retrieve course_name from  passed object
		taskObject.getCourseName(set_course_name);
	
		//new node to hold taskObject data
		Node * newNode = new Node(taskObject);
		
		Node * prev = NULL;
		Node * curr = head;
		
		//traverse list to locate insertion point
		while(curr)
		{
				curr->taskData.getCourseName(curr_course_name);
				if(strcmp(set_course_name, curr_course_name) < 0) //set_course_name (from passed object) is < curr_course_name
				{
						if (( taskData_size == 1) && (strcmp(set_course_name, curr_course_name) > 0) )  //if only 1 object in list and it's less than set_course_name, append 
						{																																	// ex)  list entries   cs162 and you want to add   or am101
								setTaskDataAppend(taskObject);
								return; // ex) add cs162 and you want to add  cs271
						}
						break;
				}
				prev = curr;
				curr = curr->next;
		}
		
		//insert  newNode
		newNode->next = curr;
		
		//insert at the beginning
		if(!prev)
		{
				head = newNode;
		}
		else
		{
				prev->next = newNode;
		}
		// increment size
		taskData_size++;

}

void TaskList :: writeFile(const char external_file[]) const  //adapted from Li Liang AddressBook E EntryList.cpp
{
		
		Node * curr;
		
		ofstream task_out; 
		char output_course_name [SIZE]; 
		char output_assign_desc [SIZE];
		char output_due_date [SIZE];	
		
		task_out.open (external_file); //opens output file
		if(!task_out) //error message if failure to open, then exit
		{
				task_out.clear(); 
				cerr << endl << "Failure when opening file: " << external_file << endl; //output stream for errors
				exit(1);
		}
						
						
		for(curr = head; curr; curr = curr->next)
		{
				curr->taskData.getCourseName(output_course_name);
				curr->taskData.getAssignDesc(output_assign_desc);
				curr->taskData.getDueDate(output_due_date);
								
				task_out << output_course_name << ';' << output_assign_desc << ';' << output_due_date << endl;
		}
						

		task_out.close();


}