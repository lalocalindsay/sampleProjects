/* CS261- Assignment 1 - Q. 1*/
/*
 * Name: Lindsay Tucker
 * Date: 8April2015
 * Solution description: Assignment 1 Q1.c
*/


#include <stdio.h>
#include<stdlib.h>
#include<math.h>

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

void generate(struct student* students){

     /*Generate random ID and scores for ten students, ID being between 1 and 10, scores between 0 and 100*/
    /* struct student *studentArray = malloc (10*(sizeof(struct student)));  */

    int h;
    int i;
    int j;
    int id_temp=0;

    /* fill array with empty values for id and score */
    for (h=0; h< 10; h++){
            students[h].id = 0;
            students[h].score = -1;
    }

    for (i=0; i< 10; i++){
            /*  (( (rand()  % (max-min) ) + 1)  +min)  */
            id_temp=( ( (rand() % (9)) + 1) +1);

            /* check array for that number */
            for(j=0; j< 10; j++){

                    if (id_temp==students[j].id){
                            id_temp=( ( (rand() % (9)) + 1) +1);
                            j=0;
                    }

            }
            /* ENSURE IDs are unique */
            students[i].id= id_temp;

            /* ENSURE scores are unique */
            students[i].score=( ( (rand() % (100)) + 1) +0);

            /* TESTING */
            printf("a student id: %i\n",students[i].id);
            printf("a student score: %i\n",students[i].score);
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

void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the ten students*/
    /*  MIN  */

    /*  MAX  */

    /*  AVG  */



}

void deallocate(struct student* stud){
     /*Deallocate memory from stud*/
     free(stud);
}

int main(){
    struct student* stud = NULL;

    /*call allocate*/
    stud = allocate();

    /*call generate*/
    generate(&stud[0]);

    /*call output*/
    output(&stud[0]);  /*  OUTPUT DOESN'T MATCH generate() */

    /*call summary*/


    /*call deallocate*/
    deallocate(&stud[0]);
    return 0;
}
