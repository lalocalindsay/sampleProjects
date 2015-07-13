/* CS261- Assignment 1 - Q.4*/
/*
 * Name: Lindsay Tucker
 * Date: 11April2015
 * Solution description: Assignment 1 Q4.c
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h> /* for rand() seed */

struct student{
	int id;
	int score;
};

/*
*******************************************************************
** Function: void sort(struct student* students, int n)
** Description: sorts based on score
** Parameters: * student, n
** Pre-Conditions: a student dynamically created in main
** Post-Conditions: the array of n students is sorted
*******************************************************************
*/

void sort(struct student* students, int n){
     /*Sort the n students based on their score*/
    int i;                                   /* loop incrementor */
    int j;                                   /* loop incrementor */
    int temp_score;                          /* temp storage for score */
    int temp_id;                             /* temp storage for id */

    for (j = 1; j < n; j++){                 /* for n+1 array element compare */
        for (i = 0; i < (n-1); i++){         /* value for current */

            if(students[i].score > students[j].score){       /* if n+1 [j] is less, swap  */
                /* 3 step swap, for boht score and id */
                temp_score = students[i].score;
                temp_id = students[i].id;


                students[i].score = students[j].score;
                students[i].id = students[j].id;


                students[j].score = temp_score;
                students[j].id = temp_id;
            }
        }
    }

    /*
    printf("//TESTING: \n");
    for (i = 0; i < n; i++){
        printf("ID: %i, \n", students[i].id);
        printf("  Sorted SCORE: %i, \n", students[i].score);
    }
    */



}

int main(){

    int i;             /* loop incrementor for filling w/ rand values */
    /* int j; */
    int random;
    srand(time(NULL)); /* rand() seed */

    /*Declare an integer n and assign it a value.*/
    int n = 10;

    /*Allocate memory for n students using malloc.*/
    struct student *studptr= malloc(n* sizeof(struct student));

    /*Generate random IDs and scores for the n students, using rand().*/
    /* populate students w/ random values for id and score*/
    for (i = 0; i < n; i++){

        random = rand() % n;
        studptr[i].id = random;
        studptr[i].score= rand() % 100;

        /* DYSFUNCTIONAL CODE ATTEMPTING TO PREVENT REPEAT IDs
        for(j=0; j< n; j++){
            //if that id number exists in loop, generate new rando, restart comparison loop
            if (random == studptr[j].id){
                random = rand() % n;
                j=0;  //reset comparison loop
            }
        }
        */
    }

    /*Print the contents of the array of n students.*/
    for (i = 0; i < n; i++){
        printf("id: %i\n", studptr[i].id);
        printf("  score: %i\n", studptr[i].score);
    }

    /*Pass this array along with n to the sort() function*/
    sort(&studptr[0], n);

    /*Print the contents of the array of n students.*/
    /* printf("SORTED BY SCORES: \n"); */
    for (i = 0; i < n; i++){
        printf("ID: %i \n", studptr[i].id);
        printf("  Sorted SCORE: %i \n", studptr[i].score);
    }

    return 0;
}
