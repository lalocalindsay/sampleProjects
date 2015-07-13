#include "linkedList.h"
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>


/* Double Link*/
struct DLink {
	TYPE value;
	struct DLink * next;
	struct DLink * prev;
};

/* Double Linked List with Head and Tail Sentinels  */

struct linkedList{
	int size;
	struct DLink *firstLink;
	struct DLink *lastLink;
};

/*
	initList
	param lst the linkedList
	pre: lst is not null
	post: lst size is 0
*/

void _initList (struct linkedList *lst) {

  /* FIXME: you must write this */

  /* NTS: firstLink is the same as frontSentinel */
  lst->firstLink = malloc (sizeof(struct DLink));
  assert(lst->firstLink !=0 );

  lst->lastLink = malloc (sizeof(struct DLink));
  assert(lst->lastLink !=0 );

  //point first and lastLinks (sentinels) to eachother
  lst->firstLink->next = lst->lastLink;
  lst->lastLink->prev = lst->firstLink; /* lst->lastLink->next should be null */

  lst->size = 0;

}

/*
 createList
 param: none
 pre: none
 post: firstLink and lastLink reference sentinels
 */

struct linkedList *createLinkedList()
{
	struct linkedList *newList = malloc(sizeof(struct linkedList));
	_initList(newList);
	return(newList);
}

/*
	_addLinkBeforeBefore
	param: lst the linkedList
	param: l the  link to add before
	param: v the value to add
	pre: lst is not null
	pre: l is not null
	post: lst is not empty
*/

/* Adds Before the provided link, l */

void _addLinkBefore(struct linkedList *lst, struct DLink *l, TYPE v)
{
	/* FIXME: you must write this */
	assert (lst != 0);       /* the LL param is not null */
	assert (l!= 0);          /* the DLink l param is not null */

    struct DLink *newLink = malloc(sizeof(struct DLink));
    newLink->value = v;

    newLink->prev = l->prev; /* point the newLink's prev to what the 'before' link was pointing to */
    newLink->next = l;       /* point the newLink's next to the 'before' link */
    l->prev->next = newLink; /* point what is now previous to newLink (referenced via l) to newLink */
    l->prev = newLink ;      /* lastly, point what goes after newLink to newLink*/

    lst->size++;
    assert(!isEmptyList(lst));

}


/*
	addFrontList
	param: lst the linkedList
	param: e the element to be added
	pre: lst is not null
	post: lst is not empty, increased size by 1
*/

void addFrontList(struct linkedList *lst, TYPE e)
{

	/* FIXME: you must write this */
	/* assert (lst != 0); assertion happens in _addLinkBefore */

    _addLinkBefore (lst, lst->firstLink->next, e);
    //struct DLink *newLink = malloc(sizeof(struct DLink));
    //newLink->value = e;

    //newLink->prev = lst->firstLink; /* point the newLink's prev to frontSentinel */
    //newLink->next = lst->firstLink->next; /* point the newLink's next to what frontSentinel was pointing to */
    //lst->firstLink->next = newLink;  /* point frontSentinel to newLink */
    //lst->firstLink->next->prev = newLink ; /* lastly, point what goes after newLink to newLink*/

    //lst->size++;
    //assert(!isEmptyList(lst));

}

/*
	addBackList
	param: lst the linkedList
	param: e the element to be added
	pre: lst is not null
	post: lst is not empty, increased size by 1
*/

void addBackList(struct linkedList *lst, TYPE e) {

	/* FIXME: you must write this */
	/* assert (lst != 0); assertion happens in _addLinkBefore */

	_addLinkBefore (lst, lst->lastLink, e);

}

/*
	frontList
	param: lst the linkedList
	pre: lst is not null
	pre: lst is not empty
	post: none
*/

TYPE frontList (struct linkedList *lst) {

	/* FIXME: you must write this */
	/* temporary return value...you may need to change this */
	/* return(1); */
	assert (lst != 0);

	return lst->firstLink->next->value;

}

/*
	backList
	param: lst the linkedList
	pre: lst is not null
	pre: lst is not empty
	post: lst is not empty
*/

TYPE backList(struct linkedList *lst)
{
	/* FIXME: you must write this */
	/* temporary return value...you may need to change this */
	/* return(1); */
	TYPE temp;

	assert (lst != 0);                  /* the LL param is not null */
	assert(!isEmptyList(lst));

	temp = lst->lastLink->prev->value;
	assert(!isEmptyList(lst));          /* function definition requires checking this again */
	return temp;

}

/*
	_removeLink
	param: lst the linkedList
	param: l the linke to be removed
	pre: lst is not null
	pre: l is not null
	post: lst size is reduced by 1
*/

void _removeLink(struct linkedList *lst, struct DLink *l)
{

	/* FIXME: you must write this */
    assert (lst != 0);       /* the LL param is not null */
	assert (l!= 0);          /* the DLink l param is not null */

    l->prev->next = l->next; /* set left equal to right */
    l->next->prev = l->prev; /* set right equal to left */

    free (l);
    lst->size--;


}

/*
	removeFrontList
	param: lst the linkedList
	pre:lst is not null
	pre: lst is not empty
	post: size is reduced by 1
*/

void removeFrontList(struct linkedList *lst) {
   	/* FIXME: you must write this */
   	/* lst is not null or empty assertions happen in _removeLink */
   	_removeLink (lst, lst->firstLink->next);

}

/*
	removeBackList
	param: lst the linkedList
	pre: lst is not null
	pre:lst is not empty
	post: size reduced by 1
*/

void removeBackList(struct linkedList *lst)
{
	/* FIXME: you must write this */
    /* lst is not null or empty assertions happen in _removeLink */
   	_removeLink (lst, lst->lastLink->prev);
}

/*
	isEmptyList
	param: lst the linkedList
	pre: lst is not null
	post: none
*/

int isEmptyList(struct linkedList *lst) {
 	/* FIXME: you must write this */

	/*temporary return value...you may need to change this */

    return lst->size == 0;
    /* alternatively, return lst->firstLink == lst->lastLink; */

}


/* Function to print list
 Pre: lst is not null
 */
void _printList(struct linkedList* lst)
{
	/* FIXME: you must write this */

	assert (lst != 0); /* the LL param is not null */
	/*assign a pointer to iterate through list*/
    struct DLink *thisLink = lst-> firstLink->next;

    while(thisLink != lst->lastLink)
    {
        printf(" %i\n", thisLink->value);
        thisLink = thisLink->next;
    }

}

/*
	Add an item to the bag
	param: 	lst		pointer to the bag
	param: 	v		value to be added
	pre:	lst is not null
	post:	a link storing val is added to the bag
 */
void addList(struct linkedList *lst, TYPE v)
{
	/* FIXME: you must write this */
    /* lst is not null assertion happens in _addLinkBefore */

    _addLinkBefore (lst, lst->lastLink, v);
}

/*	Returns boolean (encoded as an int) demonstrating whether or not
	the specified value is in the collection
	true = 1
	false = 0

	param:	lst		pointer to the bag
	param:	e		the value to look for in the bag
	pre:	lst is not null
	pre:	lst is not empty
	post:	no changes to the bag
*/
int containsList (struct linkedList *lst, TYPE e) {
	/* FIXME: you must write this */
	/* temporary return value...you may need to change this */
	/* return(1); */
    assert (lst != 0);          /* the LL param is not null */
	assert(!isEmptyList(lst));  /* list is not empty */

	/*assign a pointer to iterate through list*/
    struct DLink *thisLink = lst-> firstLink->next;

    /*iterate through list*/
    while(thisLink != lst->lastLink)
    {
        /*compare values*/
        if(thisLink->value == e)
        {
            return 1;                    /* return T if found */
        }
        thisLink = thisLink->next;       /* increment */
    }
    return 0;                            /* not found, return F */

}

/*	Removes the first occurrence of the specified value from the collection
	if it occurs

	param:	lst		pointer to the bag
	param:	e		the value to be removed from the bag
	pre:	lst is not null
	pre:	lst is not empty
	post:	e has been removed
	post:	size of the bag is reduced by 1
*/
void removeList (struct linkedList *lst, TYPE e) {
	/* FIXME: you must write this */

	assert (lst != 0);          /* the LL param is not null */
	assert(!isEmptyList(lst));  /* list is not empty */

	/*assign a pointer to iterate through list*/
    struct DLink *thisLink = lst->firstLink->next;

    /*iterate through list*/
    while(thisLink != lst->lastLink)
    {
        /*compare values*/
        if(thisLink->value == e)
        {
            _removeLink(lst, thisLink);
            return;                      /* stop here if removal takes place*/
        }
        thisLink = thisLink->next;       /* increment */
    }

}
