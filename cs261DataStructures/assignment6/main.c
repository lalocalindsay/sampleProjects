#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "hashMap.h"

/*
 the getWord function takes a FILE pointer and returns you a string which was
 the next word in the in the file. words are defined (by this function) to be
 characters or numbers separated by periods, spaces, or newlines.

 when there are no more words in the input file this function will return NULL.

 this function will malloc some memory for the char* it returns. it is your job
 to free this memory when you no longer need it.
 */
char* getWord(FILE *file);

int main (int argc, const char * argv[]) {
	const char* filename;
	struct hashMap *hashTable;
	int tableSize = 10;
	clock_t timer;
	FILE *fileptr;
    /*
     this part is using command line arguments, you can use them if you wish
     but it is not required. DO NOT remove this code though, we will use it for
     testing your program.

     if you wish not to use command line arguments manually type in your
     filename and path in the else case.
     */
    if(argc == 2)
        filename = argv[1];
    else
        filename = "input1.txt"; /*specify your input text file here*/

    printf("opening file: %s\n", filename);

	timer = clock();

	hashTable = createMap(tableSize);

    /*... concordance code goes here ...*/

	/* the following file i/o code is adapted from recitation_file_operations.ppt  */
	FILE * inputFile;
	if (argc > 1)
    {
        inputFile = fopen (argv[1], "r");    //open the file (r: read from file)
        assert (inputFile != 0);

        if (inputFile != 0)                         //ensure it's open
        {
            char * word = getWord(inputFile);
            while (word)
            {

                    //print word
                    printf("%s \n", word);

                    // if word is not in hashtable, insert once
                    if (containsKey(hashTable, word) == 0)
                    {
                        //printf("//TESTING: INSERTING\n");
                        insertMap(hashTable, word, 1);

                    }
                    else  //otherwise, it's already there so increment and free
                    {
                        //printf("//TESTING: Main: adjusting++ value of this key: %s\n", word);
                        ValueType value = *atMap(hashTable, word); //stores number of occurances of key
                        //printf("//TESTING value: %d\n", value); //should be at least 1
                        //printf("//TESTING: *value++ \n");
                        ++(value);
                        //printf("//TESTING value: %d\n", value);
                        insertMap(hashTable, word, value);
                        //printf("//TESTING: FREEING\n");
                        free(word);

                    }
                    word = 0;
                    word = getWord(inputFile);
            }

        }
        else
        {
            printf( "%s doesn't exist or is protected.\n", argv[1]);
        }
    }

    //print table: keys and their values
    int i;
    struct hashLink * linkerator;


    printf("\n\nPRINTING ALL WORDS IN HASHTABLE:\n\n");
    for (i = 0; i < hashTable->tableSize; i++) //move thru array
    {
        linkerator = hashTable->table[i];
        while (linkerator != 0)//while (linkerator->next != 0)
        {
            printf("%s: %d, index:[%d]\n", linkerator->key, linkerator->value, i);
            //if(linkerator->next != 0)  //this spirals
            linkerator = linkerator->next; //move thru hashlinks
        }
    }

	/*... concordance code ends here ...*/

	printMap(hashTable);
	timer = clock() - timer;
	printf("\nconcordance ran in %f seconds\n", (float)timer / (float)CLOCKS_PER_SEC);
	printf("Table emptyBuckets = %d\n", emptyBuckets(hashTable));
    printf("Table count = %d\n", size(hashTable));
	printf("Table capacity = %d\n", capacity(hashTable));
	printf("Table load = %f\n", tableLoad(hashTable));

	printf("Deleting keys\n");


	removeKey(hashTable, "and");
	removeKey(hashTable, "me");
	removeKey(hashTable, "the");
	printMap(hashTable);

	deleteMap(hashTable);
	printf("\nDeleted the table\n");



	//int fclose(inputFile);
	fclose(inputFile);

	return 0;
}

void printValue(ValueType v) {
	printf("Value:%d",(int *)v);
}

char* getWord(FILE *file)
{
	int length = 0;
	int maxLength = 16;
	char character;

	char* word = malloc(sizeof(char) * maxLength);
	assert(word != NULL);

	while( (character = fgetc(file)) != EOF)
	{
		if((length+1) > maxLength)
		{
			maxLength *= 2;
			word = (char*)realloc(word, maxLength);
		}
		if((character >= '0' && character <= '9') || /*is a number*/
		   (character >= 'A' && character <= 'Z') || /*or an uppercase letter*/
		   (character >= 'a' && character <= 'z') || /*or a lowercase letter*/
		   character == 39) /*or is an apostrophy*/
		{
			word[length] = character;
			length++;
		}
		else if(length > 0)
			break;
	}

	if(length == 0)
	{
		free(word);
		return NULL;
	}
	word[length] = '\0';
	//print word
    //printf("//TESTING getWord(): %s \n", word);
	return word;
}
