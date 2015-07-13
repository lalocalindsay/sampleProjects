
/////////////// Dustin's Q1 generate() //////////////////

void generate(struct student* students){
/*Generate random ID and scores for ten students, ID being between 1 and 10, scores between 0 and 100*/
int ids[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int scores[10];

int i;
//Now, shuffle its elements
for (i = 0; i < 10; i++) {
    //Grab an element between 0 & 10
    int seed = rand() % 9;
    int temp = ids[seed];
    //Now, swap them to emulate a shuffle
    ids[seed] = ids[i];
    ids[i] = temp;
}

//Populate scores between 0 & 100 for these same students:
for (i = 0; i < 10; i++) {
scores[i] = rand() % 100;
}

for (i = 0; i < 10; i++) {
struct student *st = (students + i);
st->id = ids[i];
st->score = scores[i];
}
}
///////////////Q1 generate() after Dustin's help //////////////////

void generate(struct student* students){

     /*Generate random ID and scores for ten students, ID being between 1 and 10, scores between 0 and 100*/


    int i;             /* loop incrementor for filling w/ rand values */
    int id_temp = 0;   /* stores random id number for comparison, 0 is outside range*/
    int rand;
    srand(time(NULL)); /* rand() seed */

    int ids[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (i = 0; i < 10; i++){
        rand = ( ( (rand() % (9)) +1) +1); /* determines array element to be randomized */
        /* 3 step swap */
        id_temp = students[rand].id;
        students[rand]= students[i].id;
        students [i].id = id_temp;

    }



    /* fill array with random values for score */
    students[i].score=( ( (rand() % (100)) + 1) +0);   /* ENSURE scores are unique */

    /* TESTING */
    printf("//TESTING student id: %i\n",students[i].id);
    printf("//TESTING student score: %i\n",students[i].score);
    }

}
//////////////// Q1 generate() before Dustin's help '//////////////////////
void generate(struct student* students){

     /*Generate random ID and scores for ten students, ID being between 1 and 10, scores between 0 and 100*/

    int h;             /* loop incrementor for filling w/ empty values */
    int i;             /* loop incrementor for filling w/ rand values */
    int j;             /* loop incrementor for checking values */
    int id_temp = 0;   /* stores random id number for comparison, 0 is outside range*/
    srand(time(NULL)); /* rand() seed */

    /* fill array with empty values for id and score */  /*WHY?*/
    for (h = 0; h < 10; h++){
        students[h].id = 0;
        students[h].score = -1;
    }

    /* fill array with random values for id and score */
    /* RANDOM FORMULA: (( (rand()  % (max-min) ) + 1)  +min)  */
    for (i = 0; i < 10; i++){

        id_temp = ( ( (rand() % (9)) +1) +1);
        /*id_temp = ( (rand() % (10) +1));*/

        /* comparison loop to check if id number exists*/
        for(j=0; j< 10; j++){

            /* if that id number exists in loop, generate new rando, restart comparison loop*/

            if (id_temp == students[j].id){
                id_temp = ( ( (rand() % (9)) +1) +1);
                /*id_temp = ( (rand() % (10) +1)); */
                j=0;  /* reset comparison loop */

            }


        }
        /* ENSURE IDs are unique --NOT WORKING */
        students[i].id= id_temp;

        /* ENSURE scores are unique */
        students[i].score=( ( (rand() % (100)) + 1) +0);

        /* TESTING */
        printf("//TESTING student id: %i\n",students[i].id);
        printf("//TESTING student score: %i\n",students[i].score);
    }

}
