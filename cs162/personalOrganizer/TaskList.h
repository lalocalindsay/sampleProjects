
//
//  TaskList.h
//  A header file for TaskList definition
//  Created by Lindsay Tucker on 03/03/15.
//  Updated on 03/07/15
//  Copyright (c) 2015 Lindsay Tucker. All rights reserved.
//



#ifndef TASK_LIST_H
#define TASK_LIST_H

#include "Task.h"
#include <cstring>
using namespace std;

class TaskList   //adapted from Li Liang AddressBook E: EntryList.cpp
{
	private:

	struct Node
	{
		Task	taskData;
		Node * next;

		Node(const Task& aTaskData)
		{
			char	course_name[SIZE];
			char assign_desc[SIZE];
			char due_date[SIZE];

			aTaskData.getCourseName (course_name);
			aTaskData.getAssignDesc (assign_desc);
			aTaskData.getDueDate (due_date);

			taskData.setCourseName (course_name);
			taskData.setAssignDesc(assign_desc);
			taskData.setDueDate (due_date);
			next = NULL;
		}
	};

	Node *	head;
	int taskData_size;



	public:
	//constructors
	TaskList(); //default   ///    DYNAMIC

	//destructor
	~TaskList();   ////   DESTROY DYNAMIC

	//ACCESSOR FUNCTIONS
	int getTaskDataSize() const; //returns size of taskArray
	bool getTaskObject( int index, Task &taskObject) const;
	void printTaskData ();
	bool findTask (int& num_of_matches,  const char search_key[], Task &matchingTask) const;

	//MUTATOR FUNCTIONS
	//void setTaskDataBeginning(const Task &taskObject);
	void setTaskDataAppend(const Task &taskObject);
	void setTaskDataSort (const Task &taskObject);
	void writeFile(const char external_file[]) const;

};
#endif

