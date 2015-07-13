/* CS261- Assignment 2 - dynamicArray.c*/
/*
 * Name: Lindsay Tucker
 * Date: 19April2015
 * Solution description: Assignment 2 dynamicArray.c
*/



/*	dynamicArray.c: Dynamic Array implementation. */
#include <assert.h>
#include <stdlib.h>
#include <assert.h>
#include "dynamicArray.h"

struct DynArr
{
	TYPE *data;		/* pointer to the data array */
	int size;		/* Number of elements in the array */
	int capacity;	/* capacity ofthe array */
};


/* ************************************************************************
	Dynamic Array Functions
************************************************************************ */

/* Initialize (including allocation of data array) dynamic array.

	param: 	v		pointer to the dynamic array
	param:	cap 	capacity of the dynamic array
	pre:	v is not null
	post:	internal data array can hold cap elements
	post:	v->data is not null
*/
void initDynArr(DynArr *v, int capacity)
{
	assert(capacity > 0);
	assert(v!= 0);
	v->data = (TYPE *) malloc(sizeof(TYPE) * capacity);
	assert(v->data != 0);
	v->size = 0;
	v->capacity = capacity;
}

/* Allocate and initialize dynamic array.

	param:	cap 	desired capacity for the dyn array
	pre:	none
	post:	none
	ret:	a non-null pointer to a dynArr of cap capacity
			and 0 elements in it.
*/
DynArr* createDynArr(int cap)
{
	assert(cap > 0);
	DynArr *r = (DynArr *)malloc(sizeof( DynArr));
	assert(r != 0);
	initDynArr(r,cap);
	return r;
}

/* Deallocate data array in dynamic array.

	param: 	v		pointer to the dynamic array
	pre:	none
	post:	d.data points to null
	post:	size and capacity are 0
	post:	the memory used by v->data is freed
*/
void freeDynArr(DynArr *v)
{
	if(v->data != 0)
	{
		free(v->data); 	/* free the space on the heap */
		v->data = 0;   	/* make it point to null */
	}
	v->size = 0;
	v->capacity = 0;
}

/* Deallocate data array and the dynamic array ure.

	param: 	v		pointer to the dynamic array
	pre:	none
	post:	the memory used by v->data is freed
	post:	the memory used by d is freed
*/
void deleteDynArr(DynArr *v)
{
	freeDynArr(v);
	free(v);
}

/* Resizes the underlying array to be the size cap

	param: 	v		pointer to the dynamic array
	param:	cap		the new desired capacity
	pre:	v is not null
	post:	v has capacity newCap
*/
void _dynArrSetCapacity(DynArr *v, int newCap)
{

	/* FIXME: You will write this function */
    /* REVISED FROM assign 2 submission--corrected w/ assign2 solution code */

    int i;
    assert(v != 0);                           /* confirm v isn't null */
	TYPE * prevData = v->data;                /* pointer to take location of v array */
    int oldSize = v->size;                    /* we'll need this for adjusting size and ending for loop */
    printf("========Resizing========\n");
    initDynArr(v, newCap);                    /* make new array, returns: v->size =0, cap= newCap */

                                              /* transfer everything over to new mem. */
    for(i = 0; i<oldSize; i++)                /* note that we stop at oldSize-- not newCap */
    {
        v->data[i] = prevData[i];
    }

    v->size = oldSize;                        /* since this was _initDA() changed v->size=0, correct here */
    free(prevData);                           /* free! */


}

/* Get the size of the dynamic array

	param: 	v		pointer to the dynamic array
	pre:	v is not null
	post:	none
	ret:	the size of the dynamic array
*/
int sizeDynArr(DynArr *v)
{
	return v->size;
}

/* 	Adds an element to the end of the dynamic array

	param: 	v		pointer to the dynamic array
	param:	val		the value to add to the end of the dynamic array
	pre:	the dynArry is not null
	post:	size increases by 1
	post:	if reached capacity, capacity is doubled
	post:	val is in the last utilized position in the array
*/
void addDynArr(DynArr *v, TYPE val)
{
	int newCap;
	/* FIXME: You will write this function */

	assert(v != 0);                      /* confirm array isn't null */

	if (v->size < v->capacity-1)         /* if room for one more */
    {
        v->data[v->size] = val;          /* edit from: v->size +1 */
        v->size++;
    }
	else                                 /* double capacity and allocate mem*/
    {

        newCap= 2*(v->capacity);
        _dynArrSetCapacity(v, newCap);
        assert (v->size < v->capacity);  /* confirm capacity */
        v->data[v->size] = val;          /* edit from: v->size +1 */
        v->size++;
    }
}

/*	Get an element from the dynamic array from a specified position

	param: 	v		pointer to the dynamic array
	param:	pos		integer index to get the element from
	pre:	v is not null
	pre:	v is not empty
	pre:	pos < size of the dyn array and >= 0
	post:	no changes to the dyn Array
	ret:	value stored at index pos
*/

TYPE getDynArr(DynArr *v, int pos)
{
	/* TYPE rtrnValue; */

	/* FIXME: You will write this function */
	assert(v != 0);          /* confirm array isn't null */
    assert(v->size > 0);     /* confirm array isn't empty */
    assert(pos < v->size);   /* confirm pos is in range */
	assert(pos >= 0);        /* confirm pos is in range */

    /* FIXME: you must change this return value */

    /* rtrnValue = v->data[pos]; */
    /* return rtrnValue; */

    return (v->data[pos]);
}

/*	Put an item into the dynamic array at the specified location,
	overwriting the element that was there

	param: 	v		pointer to the dynamic array
	param:	pos		the index to put the value into
	param:	val		the value to insert
	pre:	v is not null
	pre:	v is not empty
	pre:	pos >= 0 and pos < size of the array
	post:	index pos contains new value, val
*/
void putDynArr(DynArr *v, int pos, TYPE val)
{
	/* FIXME: You will write this function */
	assert(v != 0);          /* confirm array isn't null */
	assert(v->size > 0);     /* confirm array isn't empty */
	assert(pos < v->size);   /* confirm pos is in range */
	assert(pos >= 0);        /* confirm pos is in range */

	v->data[pos] = val;
}

/*	Swap two specified elements in the dynamic array

	param: 	v		pointer to the dynamic array
	param:	i,j		the elements to be swapped
	pre:	v is not null
	pre:	v is not empty
	pre:	i, j >= 0 and i,j < size of the dynamic array
	post:	index i now holds the value at j and index j now holds the value at i
*/
void swapDynArr(DynArr *v, int i, int  j)
{
	int temp;

	/* FIXME: You will write this function */
	assert(v != 0);          /* confirm array isn't null */
	assert(v->size > 0);     /* confirm array isn't empty */
	assert(i < v->size);     /* confirm i is in range */
	assert(j < v->size);     /* confirm j is in range */
	assert(i >= 0);          /* confirm i is in range */
	assert(j >= 0);          /* confirm j is in range */

	temp = v->data [i];
	v->data[i] = v->data[j];
	v->data[j] = temp;
}

/*	Remove the element at the specified location from the array,
	shifts other elements back one to fill the gap

	param: 	v		pointer to the dynamic array
	param:	idx		location of element to remove
	pre:	v is not null
	pre:	v is not empty
	pre:	idx < size and idx >= 0
	post:	the element at idx is removed
	post:	the elements past idx are moved back one
*/
void removeAtDynArr(DynArr *v, int idx)
{
	int i;

	/* FIXME: You will write this function */
	assert(v != 0);                      /* confirm array isn't null */
	assert(v->size > 0);                 /* confirm array isn't empty */
	assert(idx < v->size);               /* confirm idx is in range */
	assert(idx >= 0);                    /* confirm idx is in range */


    for (i = idx; i < (v->size-1); i++)  /* move everything left, stop before null */
    {
        v->data[i] = v->data[i+1];
    }

    v->size--;                           /* decrease size */
}



/* ************************************************************************
	Stack Interface Functions
************************************************************************ */

/*	Returns boolean (encoded in an int) demonstrating whether or not the
	dynamic array stack has an item on it.

	param:	v		pointer to the dynamic array
	pre:	the dynArr is not null
	post:	none
	ret:	1 if empty, otherwise 0
*/
int isEmptyDynArr(DynArr *v)
{
	/* FIXME: You will write this function */
    assert(v != 0);            /* confirm array isn't null */

	/* FIXME:  You will change this return value*/
	return (v->size == 0);
}

/* 	Push an element onto the top of the stack

	param:	v		pointer to the dynamic array
	param:	val		the value to push onto the stack
	pre:	v is not null
	post:	size increases by 1
			if reached capacity, capacity is doubled
			val is on the top of the stack
*/
void pushDynArr(DynArr *v, TYPE val)
{
	/* FIXME: You will write this function */

	/* confirmation of array != null takes place in addDynArr function*/
	addDynArr(v, val);

}

/*	Returns the element at the top of the stack

	param:	v		pointer to the dynamic array
	pre:	v is not null
	pre:	v is not empty
	post:	no changes to the stack
*/
TYPE topDynArr(DynArr *v)
{
	TYPE rtrnVal;

	/* FIXME: You will write this function */

    /* confirmation of array != null takes place in getDynArr function*/
    /* confirmation of array != empty takes place in getDynArr function*/
	rtrnVal = getDynArr(v, (v->size-1));

	/* FIXME: You will change this return value*/
	return rtrnVal;
}

/* Removes the element on top of the stack

	param:	v		pointer to the dynamic array
	pre:	v is not null
	pre:	v is not empty
	post:	size is decremented by 1
			the top has been removed
*/
void popDynArr(DynArr *v)
{
	/* FIXME: You will write this function */

	/* confirmation of array != null takes place in removeAtDynArr function*/
    /* confirmation of array != empty takes place in removeAtDynArr function*/
	removeAtDynArr(v, (v->size-1));

}

/* ************************************************************************
	Bag Interface Functions
************************************************************************ */

/*	Returns boolean (encoded as an int) demonstrating whether or not
	the specified value is in the collection
	true = 1
	false = 0

	param:	v		pointer to the dynamic array
	param:	val		the value to look for in the bag
	pre:	v is not null
	pre:	v is not empty
	post:	no changes to the bag
*/
int containsDynArr(DynArr *v, TYPE val)
{
	int i;

	/* FIXME: You will write this function */
    assert(v != 0);                      /* confirm array isn't null */
	assert(v->size > 0);                 /* confirm array isn't empty */

	for (i=0; i < (v->size); i++)
    {
        if(v->data[i] == val)
        {
            return 1;
        }
    }
	/* FIXME:  You will change this return value */
	return 0;

}

/*	Removes the first occurrence of the specified value from the collection
	if it occurs

	param:	v		pointer to the dynamic array
	param:	val		the value to remove from the array
	pre:	v is not null
	pre:	v is not empty
	post:	val has been removed
	post:	size of the bag is reduced by 1
*/
void removeDynArr(DynArr *v, TYPE val)
{
	int i;
	int pos;

	/* FIXME: You will write this function */
	assert(v != 0);                      /* confirm array isn't null */
	assert(v->size > 0);                 /* confirm array isn't empty */

	for (i=0; i < (v->size); i++)
    {
        if(v->data[i] == val)
        {
            pos = i;
            break;
        }
    }
    removeAtDynArr(v, pos);
}
