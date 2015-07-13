/* CS261- Assignment 1 - Q.3*/
/*
 * Name: Lindsay Tucker
 * Date: 11April2015
 * Solution description: Assignment 1 Q3.c
*/
#include <stdlib.h>
#include <stdio.h>
#include <time.h> /* for rand() seed */

/*
*******************************************************************
** Function: void sort(int* number, int n)
** Description: re-sorts based on score
** Parameters: * number, n
** Pre-Conditions: a student dynamically created in main
** Post-Conditions: the array of n students is re-sorted
*******************************************************************
*/

void sort(int* number, int n){
     /*Sort the given array number , of length n*/

    int i;                                   /* loop incrementor */
    int j;                                   /* loop incrementor */
    int temp;                                /* temp storage */

    for (j = 1; j < n; j++){                 /* for n+1 array element compare */
        for (i = 0; i < (n-1); i++){         /* value for current */

            if(number[i] > number[j]){       /* if n+1 [j] is less, swap  */
                temp = number [i];
                number [i] = number[j];
                number [j] = temp;

            }
        }
    }

    /*
    for (i = 0; i < n; i++){
        printf("//TESTING: %i, \n", number[i]);
    }
    */
}

int main(){

    /*Declare an integer n and assign it a value of 20.*/
    int n = 20;                  /* size of array */
    int i;                       /* loop incrementor */
    srand(time(NULL));           /* rand() seed */

    /*Allocate memory for an array of n integers using malloc.*/
    int * ptr_array = malloc (n* sizeof(int));

    /*Fill this array with random numbers, using rand().*/
    for (i = 0; i < n; i++){
        ptr_array [i] = rand();
    }

    /*Print the contents of the array.*/
    /*printf("Unsorted:\n");*/
    for (i = 0; i < n; i++){
        printf(" %i\n", ptr_array [i]);
    }

    /*Pass this array along with n to the sort() function of part a.*/
    sort(&ptr_array[0], n);

    /*Print the contents of the array.*/
    /* printf("\nSorted:\n"); */
    for (i = 0; i < n; i++){
        printf("\n %i \n", ptr_array[i]);
    }

    return 0;
}
