/* CS261- Assignment 1 - Q. 0*/
/*
 * Name: Lindsay Tucker
 * Date: 8April2015
 * Solution description: Assignment 1 Q0.c
*/


#include <stdio.h>
#include <stdlib.h>


/*
*******************************************************************
** Function: void fooA(int* iptr)
** Description: prints value, pointing location and actual location
** Parameters: * iptr
** Pre-Conditions: an int variable is declared in main
** Post-Conditions: N/A
*******************************************************************
*/


void fooA(int* iptr){
     /*Print the value pointed to by iptr*/
    printf("(fooA) value of iptr: %i\n", *iptr);

     /*Print the address pointed to by iptr*/
    printf("(fooA) address iptr points to: %p\n", iptr);

     /*Print the address of iptr itself*/
    printf("(fooA) address of iptr itself: %p\n", &iptr);

}

int main(){

    /*declare an integer x*/
    int x=2;

    /*print the address of x*/
    printf("(Main) address of x: %p\n", &x);

    /*Call fooA() with the address of x*/
    fooA(&x);

    /*print the value of x*/
    printf("(Main) value of x: %i\n", x);

    return 0;

}
