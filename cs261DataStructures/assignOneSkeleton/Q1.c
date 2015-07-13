/* CS261- Assignment 1 - Q. 1*/
/*
 * Name: Lindsay Tucker
 * Date: 8April2015
 * Solution description: Assignment 1 Q1.c
*/


#include <stdio.h>
#include<stdlib.h>
/*#include<math.h>*/
#include <time.h> /* for rand() seed */

struct student{
    int id;
	int score;
};

struct student* allocate(){

     /*Allocate memory for ten students*/
    struct student *studptr= malloc(10* sizeof(struct student));

     /*return the pointer*/
    return studptr;
}

/*
*******************************************************************
** Function: void generate(struct student* students)
** Description: generates random scores and randomizes array of IDs
** Parameters: * students
** Pre-Conditions: dynamically allocated student *10
** Post-Conditions: N/A
*******************************************************************
*/

void generate(struct student* students){  /* with help from Dustin Castor */


    /*Generate random ID and scores for ten students, ID being between 1 and 10, scores between 0 and 100*/

    int ids[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};   /* array of IDs, to be randomized */
    int i;                                           /* loop incrementor */
    int id_temp = 0;                                 /* stores random id number for swapping*/
    int random;                                      /* holds random number ot be used as index */
    srand(time(NULL));                               /* rand() seed */

    /* randomize existing IDs  */
    for (i = 0; i < 10; i++){

        random = rand() % 9;                         /* determines array element to be randomized */

        /* 3 step swap to randomize id array */
        id_temp = ids[random];
        ids[random]= ids[i];
        ids[i] = id_temp;

    }

    /* populate students */
    for (i = 0; i < 10; i++){

        students[i].id = ids[i];

        /* fill array with random values for score */
        students[i].score= rand() % 100;

        /* TESTING */
        /*
        printf("//TESTING student id: %i\n",students[i].id);
        printf("//TESTING student score: %i\n",students[i].score);
        */
    }


}

void output(struct student* students){
     /*Output information about the ten students in the format:
              ID1 Score1
              ID2 score2
              ID3 score3
              ...
              ID10 score10*/

    int i;
    for (i=0; i< 10; i++){
        printf(" %i  ",students[i].id);
        printf(" %i\n",students[i].score);

    }

}

/*
*******************************************************************
** Function: void summary(struct student* students)
** Description: generates min, max, and avg
** Parameters: * students
** Pre-Conditions: dynamically allocated student *10 w/ scores
** Post-Conditions: N/A
*******************************************************************
*/

void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the ten students*/
    int i;
    int min= 101; /* this is not a valid score, this is the comparison for < */
    int max= -1;  /* this is not a valid score, this is the comparison for > */
    int avg = -1; /* init only, this is not a valid avg */
    int sum = 0;  /* init only, this is not a valid sum */

    /*  MIN  */
    for (i=0; i< 10; i++){
        if (students[i].score < min ){
            min = students[i].score;
        }
    }

    /*  MAX  */
    for (i=0; i< 10; i++){
        if (students[i].score > max ){
            max = students[i].score;
        }
    }

    /*  AVG  */
    for (i=0; i< 10; i++){
        sum = sum+ students[i].score;
    }
    avg = sum / 10;


    printf(" min: %i\n",min);
    printf(" max: %i\n",max);
    printf(" avg: %i\n",avg);
}

void deallocate(struct student* stud){
     /*Deallocate memory from stud*/

     if (stud != NULL)
        free(stud);

}

int main(){
    struct student* stud = NULL;

    /*call allocate*/
    stud = allocate();

    /*call generate*/
    generate(&stud[0]);

    /*call output*/
    output(&stud[0]);

    /*call summary*/
    summary(&stud[0]);

    /*call deallocate*/
    deallocate(&stud[0]);

    return 0;
}
