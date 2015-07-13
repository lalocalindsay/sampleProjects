/* CS261- Assignment 1 - Q.2*/
/*
 * Name: Lindsay Tucker
 * Date: 11April2015
 * Solution description: Assignment 1 Q2.c
*/

#include <stdio.h>
#include <stdlib.h>

/*
*******************************************************************
** Function: int foo(int* a, int* b, int c)
** Description: prints values
** Parameters: int* a, int* b, int c
** Pre-Conditions: 3 int variables initialized w/ values in main
** Post-Conditions: N/A
*******************************************************************
*/

int foo(int* a, int* b, int c){

    /*Set a to double its original value*/
    *a = 2* (*a);
    /* printf("//TESTING *a = %i\n", *a); */

    /*Set b to half its original value*/
    *b = (*b)/2;
   /* printf("//TESTING *b = %i\n", *b); */

    /*Assign a+b to c*/
    c = (*a) + (*b);
    /* printf("//TESTING c = %i\n", c); */

    /*Return c*/
    return c;
}

int main(){

    /*Declare three integers x,y and z and initialize them to 5, 6, 7 respectively*/
    int x = 5;
    int y = 6;
    int z = 7;
    int foo_return = 0;

    /*Print the values of x, y and z*/
    printf(" X: %i, Y: %i, Z: %i \n", x, y, z);

    /*Call foo() appropriately, passing x,y,z as parameters*/
    foo_return = foo(&x, &y, z);

    /*Print the value returned by foo*/
    printf(" foo_return = %i\n", foo_return);

    /*Print the values of x, y and z again*/
    printf(" X: %i, Y: %i, Z: %i \n", x, y, z);

    /*Is the return value different than the value of z?  Why?*/

    /* The return value of foo() is 13 and the value of z is 7. They are different
    because unlike x and y which are passed by reference, z is passed to foo by value.
    Once the program has moved outside of the scope of the foo() function,
    the value of z reverts to the original value in main.
    */

    return 0;
}


