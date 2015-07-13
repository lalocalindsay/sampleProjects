If ten tasks are added to the priority queue all with the same priority,
they will be removed in LIFO. In order to produce a more
appropriate result when duplicate tasks are added, it will be necessary to
maintain insertion order (this object has been added to the Task struct in type.h)
and the functions in dynamicArray.c have been modified accordingly.
createTask in toDoList.c is also modified (see below) in order to adjust (increment) insertion order when
a new task is created.


Task* createTask (int priority, char *desc, int order)
{
    /* FIXME */

    struct Task *newTask;
	newTask = malloc(sizeof(struct Task));

	assert(newTask != 0);

	newTask->priority = priority;
	newTask->orderAdded = order;
	strcpy(newTask->description, desc);

	return newTask;

}
