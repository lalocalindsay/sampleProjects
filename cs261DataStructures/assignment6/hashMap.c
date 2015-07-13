#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "hashMap.h"



/*the first hashing function you can use*/
int stringHash1(char * str)
{
	int i;
	int r = 0;
	for (i = 0; str[i] != '\0'; i++)
		r += str[i];
	return r;
}

/*the second hashing function you can use*/
int stringHash2(char * str)
{
	int i;
	int r = 0;
	for (i = 0; str[i] != '\0'; i++)
		r += (i+1) * str[i]; /*the difference between stringHash1 and stringHash2 is on this line*/
	return r;
}

/* initialize the supplied hashMap struct*/
void _initMap (struct hashMap * ht, int tableSize)
{
	int index;
	if(ht == NULL)
		return;
	ht->table = (hashLink**)malloc(sizeof(hashLink*) * tableSize);
	ht->tableSize = tableSize;
	//printf("//TESTING: _inti() tableSize = %i\n", ht->tableSize);
	ht->count = 0;
	for(index = 0; index < tableSize; index++)
		ht->table[index] = NULL;
}

/* allocate memory and initialize a hash map*/
hashMap *createMap(int tableSize) {
	assert(tableSize > 0);
	hashMap *ht;
	ht = malloc(sizeof(hashMap));
	assert(ht != 0);
	_initMap(ht, tableSize);
	//printf("//TESTING: createMap() tableSize = %i\n", ht->tableSize);
	return ht;
}

/*
 Free all memory used by the buckets.
 Note: Before freeing up a hashLink, free the memory occupied by key and value
 */
void _freeMap (struct hashMap * ht)
{
	/*write this*/

    //these will iterate down LL to remove hashlinks
    struct hashLink *next;
	struct hashLink *linkerator;

    int i;

	// loop thru the table to free mem in lists
	for (i = 0; i < ht->tableSize; i++)
	{
		linkerator = ht->table[i];

		while (linkerator)  // or while (linkerator != 0)
		{
			next = linkerator->next;
			free(linkerator);
			linkerator = next;
		}
		ht->table[i] = 0;
	}

	// free table
	free(ht->table);

	// reset size and count to 0
	ht->tableSize = 0;
	ht->count = 0;


}

/* Deallocate buckets and the hash map.*/
void deleteMap(hashMap *ht) {
	assert(ht!= 0);
	/* Free all memory used by the buckets */
	_freeMap(ht);
	/* free the hashMap struct */
	free(ht);
}

/*
Resizes the hash table to be the size newTableSize
*/
void _setTableSize(struct hashMap * ht, int newTableSize)
{
	/*write this*/

    struct hashLink **oldTable = ht->table;

    int oldSize = ht->tableSize;
    //printf("////TESTING oldTableSize: %d\n", ht->tableSize);
    //printf("////TESTING newTableSize: %d\n\n", newTableSize);

    _initMap(ht, newTableSize); //resize ht, then transfer everything from oldTable

    //move everything over
    int i;
    ht->count = 0; //reset before rebuilding

    for (i = 0; i < oldSize; i++)
    {
        struct hashLink * linkerator = oldTable[i];
        struct hashLink * prev = 0; //will use this to save linkerators location

        while (linkerator != 0)//if there are any hashlinks at that index, insert
        {
            insertMap(ht, linkerator->key, linkerator->value);
            prev = linkerator->next;
            //free (linkerator);  //not necessary bc no malloc w/ linkerator
            linkerator = prev;

        }
    }
    //printf("////---FINISHED WITH RESIZE----\n\n", newTableSize);
    free(oldTable);


}

/*
 insert the following values into a hashLink, you must create this hashLink but
 only after you confirm that this key does not already exist in the table. For example, you
 cannot have two hashLinks for the word "taco".

 if a hashLink already exists in the table for the key provided you should
 replace that hashLink--this requires freeing up the old memory pointed by hashLink->value
 and then pointing hashLink->value to value v.

 also, you must monitor the load factor and resize when the load factor is greater than
 or equal LOAD_FACTOR_THRESHOLD (defined in hashMap.h).
 */
void insertMap (struct hashMap * ht, KeyType k, ValueType v)
{
	/*write this*/
    printf("//TESTING: here! insertMap()\n");
    printf("//TESTING: tableSize = %i\n", ht->tableSize);

	//check if table needs to be resized
	if (tableLoad(ht) >= LOAD_FACTOR_THRESHOLD)
    {
        //printf("\n////TESTING: SETTING TABLE SIZE \n\n");
        int newTableSize = 2 * (ht->tableSize);
        _setTableSize(ht, newTableSize);
    }
    int hashIdx = 0;
    //printf("//TESTING: tableSize = %i\n", ht->tableSize);

    //determine index w/ hash fx (starting point)
    hashIdx = stringHash2(k) % (ht->tableSize);
    //printf("//TESTING: hashIdx = %i\n", hashIdx);

    if (hashIdx < 0)
    {
        //printf("//TESTING: hashIndex < 0 \n");
        hashIdx = hashIdx + ht->tableSize;
        //printf("//TESTING: adj hashIdx = %i\n", hashIdx);
    }

    struct hashLink * newLink = malloc(sizeof(struct hashLink)); //could move malloc, leaving here for readability
    //struct hashLink * temp = malloc(sizeof(struct hashLink)); //not necessary?

    //assign newLink's values, it will be pointing to null (bc only link or at end of hashlink list)
    newLink->next = 0;
    newLink->key = k;
    //printf("//////TESTING: key = %s\n", newLink->key);
    newLink->value = v;
    //printf("//TESTING: value = %d\n", newLink->value);

    //does key exist in table? if so, increase value
    /* SEE ABOVE: "replace that hashLink--this requires freeing up the old memory pointed by hashLink->value and then pointing hashLink->value to value v." */
	if (containsKey(ht, k))
	{
		//printf("//TESTING: contains = T\n");

		struct hashLink * linkerator = ht->table[hashIdx];
		while (linkerator != 0) // move along until match is found or at end
        {
            if (strcmp(linkerator->key, k) == 0)  //if/where keys match, update value
            {
                //printf("//TESTING: adj value in insert()\n");
                linkerator->value = v; //found it, adjust value
                //printf("//TESTING: adjusted value in insert() is: %d\n", linkerator->value );
                return;
            }
            else  //move along
            {
                //printf("//TESTING: linkerating in insert() to adj++ key's value\n");
                if (linkerator->next != 0)
                {
                    linkerator = linkerator->next;
                }
            }
        }
        //printf("//TESTING: didn't find key's match to adj++ key's value\n");
		return;

		//removeKey(ht, k);  //overwrite if duplicate found. rather, VALUE++
	}

    //if hashlinks don't exist at this hash index, insert newlink
    if (!ht->table [hashIdx]) //there's no hashlink at this table location
    {
        //printf("//TESTING: no hashlinks at this index, inserting newLink\n\n");
        //malloc and assign could go here for newLink, kept it above for readability/testing

        ht->table[hashIdx] = newLink;
        //newLink = ht->table[hashIdx];  //THIS IS INCORRECT!
        //printf("//TESTING: ht->table[hashIdx]:%p, newLink: %p\n", ht->table[hashIdx], newLink);

    }
    else //linkerate to the end and add
    {
        struct hashLink * linkerator = ht->table[hashIdx];

        while (linkerator->next != 0) // or while (linkerator || next link is not zero)
        {
            linkerator = linkerator->next;
        }
        //printf("//TESTING: adding newLink at end of hashlink list\n");
        //malloc and assign could go here for newLink, kept it above for readability/testing
        linkerator->next = newLink;
    }
    ++ht->count; //increases # of hashlinks in table


}

/*
 this returns the value (which is void*) stored in a hashLink specified by the key k.

 if the user supplies the key "taco" you should find taco in the hashTable, then
 return the value member of the hashLink that represents taco.

 if the supplied key is not in the hashtable return NULL.
 */
ValueType* atMap (struct hashMap * ht, KeyType k)
{
	/*write this*/
	/*help for this function from solution code provided by instructor */

    int hashIdx = stringHash2(k) % (ht->tableSize); //determine index w/ hash fx (starting point)
    if (hashIdx < 0)
    {
        //printf("//TESTING: hashIndex < 0 \n");
        hashIdx = hashIdx + ht->tableSize;
    }
    //printf("//TESTING: hashIdx: %d \n", hashIdx);

    struct hashLink * linkerator = ht->table[hashIdx];

    if (ht->table[hashIdx] == 0)
    {
        //printf("//TESTING: atMap(): no hashlinks at this index\n");
        return 0; //no hashlinks at that hashIdx

    }

    while (linkerator != 0) // move along until match is found or at end
    {

        if (strcmp(linkerator->key, k) == 0)
        {
            return &linkerator->value; //found it, return value (int)
        }
        else
        {
            //printf("//TESTING: linkerating in atMap()\n");
            if (linkerator->next != 0)
            {
                linkerator = linkerator->next;
            }
        }
    }

    //printf("//TESTING: atMap() didn't find key \n");
	return 0; //didnt find it
}

/*
 a simple yes/no if the key is in the hashtable.
 0 is no, all other values are yes.
 */
int containsKey (struct hashMap * ht, KeyType k)
{
	/*write this*/

    int hashIdx = stringHash2(k) % (ht->tableSize); //determine index w/ hash fx (starting point)
    if (hashIdx < 0)
    {
        hashIdx = hashIdx + ht->tableSize;
    }

    //create hashlink iterator to look for key at specified index in table
    struct hashLink * linkerator = ht->table[hashIdx];

    while (linkerator)                             // or while (linkerator != 0)
    {
        if(strcmp(linkerator->key, k) == 0)
        {
            return 1;                              //found!
        }
        linkerator = linkerator->next;             //move along
    }
    return 0;                                      //not found
}

/*
 find the hashlink for the supplied key and remove it, also freeing the memory
 for that hashlink. it is not an error to be unable to find the hashlink, if it
 cannot be found do nothing (or print a message) but do not use an assert which
 will end your program.
 */
void removeKey (struct hashMap * ht, KeyType k)
{

	/*write this*/
	/* this code is modeled after instructor's solution code -- the seg faulty version of my code is commented out below */
	int hashIdx = stringHash2(k) % (ht->tableSize);
	if (hashIdx < 0)
    {
        hashIdx = hashIdx + ht->tableSize;
    }

	//create hashlink for head that iterates
    struct hashLink * linkerator = ht->table[hashIdx];
    //lagging iterator
	struct hashLink *prev = linkerator;

	if (ht->table[hashIdx] == 0) //no hashlinks
    {
        return;
    }
	else
    {
        while (linkerator != 0)
        {
            if (containsKey(ht, k) == 0)
            {
                if(linkerator == ht->table[hashIdx])
                {
                    ht->table[hashIdx] = linkerator->next;
                }
                else
                {
                    prev->next = linkerator->next;
                }
                free (linkerator);
                ht->count--;
                return;
            }
            else
            {
                prev = linkerator;
                linkerator = linkerator->next;
            }
        }
    }


	/*

    if (containsKey(ht, k))
    {
         //determine index w/ hash fx (starting point)
        int hashIdx = stringHash2(k) % (ht->tableSize);
        if (hashIdx < 0)
        {
            hashIdx = hashIdx + ht->tableSize;
        }

        //create hashlink for head that iterates
        struct hashLink * linkerator = ht->table[hashIdx];

        //will create pointers to prev and next to use in remove
        //struct hasLink *next = linkerator->next;
        //struct hasLink *prev = linkerator; and linkerator = linkerator->next;

        //REMOVE:

        //if match at the head
        if (strcmp(linkerator->key, k) == 0)
        {
            struct hashLink *next = linkerator->next;
            printf("//TESTING: removeKey() match at head\n");
            free (linkerator);
            ht->table[hashIdx] = next; //the head is now at new location
        }

        //else match is in middle or at the tail
        else
        {
            struct hashLink *prev = linkerator; //head is initial prev value
            linkerator = linkerator->next;   //move linkerator (downstream of prev)
            struct hashLink *next = linkerator->next; //next is now downstream of linkerator

            //move thru LL until key match
            while (strcmp(linkerator->key, k) != 0)  // REVISION?: || next->next == 0
            {
                prev = linkerator; //move everything down
                linkerator = next;
                next = next->next;
            }

            //then delete   //REVISION: re: head= prev, what about everything before prev? (in case we're deleting in middle)
            free(linkerator);
            prev->next = next; //introduce neighbors
            ht->table[hashIdx]= prev;  //the head is now downstream from free'd link  //REVISON: is this line necessary?
        }
        --ht->count;
    }
    else
        printf( "CANNOT BE FOUND.\n");
        */

}

/*
 returns the number of hashLinks in the table
 */
int size (struct hashMap *ht)
{
	/*write this*/
    return ht->count;

}

/*
 returns the number of buckets in the table
 */
int capacity(struct hashMap *ht)
{
	/*write this*/
    return ht->tableSize;
}

/*
 returns the number of empty buckets in the table, these are buckets which have
 no hashlinks hanging off of them.
 */
int emptyBuckets(struct hashMap *ht)
{
	/*write this*/

    int empties = 0;
    int i;

    //loop thru table up to size
    for (i = 0; i < (ht->tableSize); i++)
    {
        if ((ht->table[i]) == 0) //count ++ for nulls
        {
            empties++;
        }
    }
	return empties;
}

/*
 returns the ratio of: (number of hashlinks) / (number of buckets)

 this value can range anywhere from zero (an empty table) to more then 1, which
 would mean that there are more hashlinks than buckets (but remember hashlinks
 are like linked list nodes so they can hang from each other)
 */
float tableLoad(struct hashMap *ht)
{
	/* write this */

    float loadFact;
    loadFact = (float) ht->count / ht->tableSize;
    return loadFact;

    //return (float)size(ht)/ capacity(ht); (alternatively)


}

void printMap (struct hashMap * ht)
{
	int i;
	struct hashLink *temp;
	for(i = 0;i < capacity(ht); i++){
		temp = ht->table[i];
		if(temp != 0) {
			printf("\nBucket Index %d -> ", i);
		}
		while(temp != 0){
			printf("Key:%s | ", temp->key);
			printValue(temp->value);
			printf(" -> ");
			temp=temp->next;
		}
	}
}


