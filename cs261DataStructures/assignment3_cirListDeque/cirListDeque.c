#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <float.h>
#include "cirListDeque.h"

/* Double Link Struture */
struct DLink {
	TYPE value;/* value of the link */
	struct DLink * next;/* pointer to the next link */
	struct DLink * prev;/* pointer to the previous link */
};

# define TYPE_SENTINEL_VALUE DBL_MAX


/* ************************************************************************
 Deque ADT based on Circularly-Doubly-Linked List WITH Sentinel
 ************************************************************************ */

struct cirListDeque {
	int size;/* number of links in the deque */
	struct DLink *Sentinel;	/* pointer to the sentinel */
};
/* internal functions prototypes */
struct DLink* _createLink (TYPE val);
void _addLinkAfter(struct cirListDeque *q, struct DLink *lnk, TYPE v);
void _removeLink(struct cirListDeque *q, struct DLink *lnk);



/* ************************************************************************
	Deque Functions
************************************************************************ */

/* Initialize deque.

	param: 	q		pointer to the deque
	pre:	q is not null
	post:	q->Sentinel is allocated and q->size equals zero
*/
void _initCirListDeque (struct cirListDeque *q)
{
  	/* FIXME: you must write this */
    assert (q != 0);                    /* q is not null */

  	q->Sentinel = (struct DLink *) malloc (sizeof(struct DLink));
    assert (q->Sentinel != 0);          /* Sentinel is allocated and not null*/
  	q->size = 0;

  	/* Just like in a linear linked list, point first and last (sents) to eachother */
    /* or to itself in this case */
  	q->Sentinel->next = q->Sentinel;
	q->Sentinel->prev = q->Sentinel;


}

/*
 create a new circular list deque

 */

struct cirListDeque *createCirListDeque()
{
	struct cirListDeque *newCL = malloc(sizeof(struct cirListDeque));
	_initCirListDeque(newCL);
	return(newCL);
}


/* Create a link for a value.

	param: 	val		the value to create a link for
	pre:	none
	post:	a link to store the value
*/
struct DLink * _createLink (TYPE val)
{
	/* FIXME: you must write this */
    struct DLink *newLink = (struct DLink *) malloc (sizeof(struct DLink));
    newLink->value = val;
    assert (newLink != 0);      /* q is not null */
	/*temporary return value..you may need to change it*/
	/* return(0); */
	return newLink;

}

/* Adds a link after another link

	param: 	q		pointer to the deque
	param: 	lnk		pointer to the existing link in the deque
	param: 	v		value of the new link to be added after the existing link
	pre:	q is not null
	pre: 	lnk is not null
	pre:	lnk is in the deque
	post:	the new link is added into the deque after the existing link
*/
void _addLinkAfter(struct cirListDeque *q, struct DLink *lnk, TYPE v)
{
	/* FIXME: you must write this */
    assert (q != 0);                    /* q is not null */
    assert (lnk != 0);                  /* lnk is not null */

    /* lnk is in the deque */
    assert (lnk->next != 0);
    assert (lnk->prev != 0);

    /*assign a pointer to iterate through list*/
    struct DLink *newLink = _createLink(v);

    newLink->next = lnk->next; /* pass lnk's next to the newLink */
    newLink->prev = lnk;
    lnk->next->prev = newLink;
    lnk->next = newLink;

    q->size++;

}

/* Adds a link to the back of the deque

	param: 	q		pointer to the deque
	param: 	val		value for the link to be added
	pre:	q is not null
	post:	a link storing val is added to the back of the deque
*/
void addBackCirListDeque (struct cirListDeque *q, TYPE val)
{
	/* FIXME: you must write this */
	/* q is not null is checked in _addLinkAfter*/
    _addLinkAfter(q, q->Sentinel->prev, val);
}

/* Adds a link to the front of the deque

	param: 	q		pointer to the deque
	param: 	val		value for the link to be added
	pre:	q is not null
	post:	a link storing val is added to the front of the deque
*/
void addFrontCirListDeque(struct cirListDeque *q, TYPE val)
{
	/* FIXME: you must write this */
    /* q is not null is checked in _addLinkAfter */
    _addLinkAfter(q, q->Sentinel, val);
}

/* Get the value of the front of the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	none
	ret: 	value of the front of the deque
*/
TYPE frontCirListDeque(struct cirListDeque *q)
{
	/* FIXME: you must write this */
	/* temporary return value..you may need to change it*/
	/* return(1); */
	assert (q != 0);                    /* q is not null */
	assert(!isEmptyCirListDeque(q));    /* q is not empty */

	return q->Sentinel->next->value;

}

/* Get the value of the back of the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	none
	ret: 	value of the back of the deque
*/
TYPE backCirListDeque(struct cirListDeque *q)
{
	/* FIXME: you must write this */
	/* temporary return value..you may need to change it*/
	/* return(1);*/
	assert (q != 0);                    /* q is not null */
	assert(!isEmptyCirListDeque(q));    /* q is not empty */

	return q->Sentinel->prev->value;

}

/* Remove a link from the deque

	param: 	q		pointer to the deque
	param: 	lnk		pointer to the link to be removed
	pre:	q is not null and q is not empty
	post:	the link is removed from the deque
*/
void _removeLink(struct cirListDeque *q, struct DLink *lnk)
{
	/* FIXME: you must write this */
	assert (q != 0);                    /* q is not null */
	assert(!isEmptyCirListDeque(q));    /* q is not empty */

    /* make sure lnk is a thing that exists (not null and size !=0) */
    assert (lnk != 0);
    assert (q->size != 0);

	/* connect lnk's neighbors before freeing lnk */
	lnk->prev->next = lnk->next;
	lnk->next->prev = lnk->prev;

	free(lnk);                          /* free at last! */

	q->size--;

}

/* Remove the front of the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	the front is removed from the deque
*/
void removeFrontCirListDeque (struct cirListDeque *q) {
	/* FIXME: you must write this */

    /* q is not null and q is not empty is asserted in _removeLink */
    /* send what comes AFTER the sentinel */
    _removeLink(q, q->Sentinel->next);
}


/* Remove the back of the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post:	the back is removed from the deque
*/
void removeBackCirListDeque(struct cirListDeque *q)
{
  	/* FIXME: you must write this */
  	/*q is not null and q is not empty is asserted in _removeLink */
  	/* send what comes BEFORE the sentinel */
    _removeLink(q, q->Sentinel->prev);
}

/* De-allocate all links of the deque

	param: 	q		pointer to the deque
	pre:	none
	post:	All links (including Sentinel) are de-allocated
*/
void freeCirListDeque(struct cirListDeque *q)
{
	/* FIXME: you must write this */
	/* first, make sure some things are true: */
    assert (q != 0);                   /* q is not null */
    assert(!isEmptyCirListDeque(q));   /* q isn't empty, yet */
    assert(q->size != 0);              /* q isn't empty, yet */

    while (q->size > 0)
    {
        removeFrontCirListDeque(q); /* could also removeBack... */
        /* q->size is decremented in _removeLink() */
    }
    assert(q->size == 0);              /* q should be empty now */
    free (q->Sentinel);                /* we are freeing Sent, not q (the deque) */
    q->Sentinel = 0;                   /* just to be safe */

}

/* Check whether the deque is empty

	param: 	q		pointer to the deque
	pre:	q is not null
	ret: 	1 if the deque is empty. Otherwise, 0.
*/
int isEmptyCirListDeque(struct cirListDeque *q) {
  	/* FIXME: you must write this */
	/*temporary return value..you may need to change it*/
	assert(q != 0);
	return(q->size == 0);
	/* alternatively, we could return if q->Sentinel->next = q->Sentinel->prev */
}

/* Print the links in the deque from front to back

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post: 	the links in the deque are printed from front to back
*/
void printCirListDeque(struct cirListDeque *q)
{
	/* FIXME: you must write this */
	assert (q != 0);                   /* q is not null */
    assert(!isEmptyCirListDeque(q));   /* q isn't empty */

    struct DLink *tmp = q->Sentinel->next; /* iterator for moving thru links */

    int i;
    for (i = 0; i < (q->size); i++)
    {
        printf(" %f\n", tmp->value);
        tmp = tmp->next;
    }
    printf("\n");
}

/* Reverse the deque

	param: 	q		pointer to the deque
	pre:	q is not null and q is not empty
	post: 	the deque is reversed
*/
void reverseCirListDeque(struct cirListDeque *q)
{
	/* FIXME: you must write this */
    assert (q != 0);                   /* q is not null */
    assert(!isEmptyCirListDeque(q));   /* q isn't empty */

    struct DLink *index = q->Sentinel;
    struct DLink *temp;


    /* adapted from cprogramming.com post 101462 */
    do
    {
        temp = index->next;
        index->next = index->prev;
        index->prev = temp;
        index = temp;
    } while(index != q->Sentinel );


}
