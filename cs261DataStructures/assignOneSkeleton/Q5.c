/* CS261- Assignment 1 - Q.5*/
/*
 * Name: Lindsay Tucker
 * Date: 11April2015
 * Solution description: Assignment 1 Q5.c
*/

#include <stdio.h>
#include <stdlib.h>

int SIZE = 20; /* global cosntant for cstring size */

/*converts ch to upper case, assuming it is in lower case currently*/
char toUpperCase(char ch){
     return ch-'a'+'A';
}

/*converts ch to lower case, assuming it is in upper case currently*/
char toLowerCase(char ch){
     return ch-'A'+'a';
}

/*
*******************************************************************
** Function: void sticky(char* word)
** Description: converts cstring to alternating upper/lower case
** Parameters: * word
** Pre-Conditions: a cstring sent from main
** Post-Conditions: cstring letters are modified
*******************************************************************
*/

void sticky(char* word){
     /*Convert to sticky caps*/

     int i;  /* loop incrementor */
     /*all odds lower */
     /*all evens upper */

     for (i=0; i< SIZE; i++){
        /* if char is null or non-letter */
        if (word[i] == '\0' || word[i]<65 || word[i]>122)
            break;

        /* check if it's upp or low, based on ANSCII */

        /* if lower (check), and it's even (i%2 ==0) --change to upper*/
        if((97 <= word[i]) && (word[i] <= 122) && ( i%2 == 0  )){
            word[i]= toUpperCase(word[i]);
        }
        /* if lower (check), and it's odd(i%2 !=0) --keep lower*/
        if((97 <= word[i]) && (word[i] <= 122) && ( i%2 != 0  )){
            word[i]= word[i];
        }
        /* if upper (check), and it's odd (i%2 !=0) --change to lower*/
        if((65 <= word[i]) && (word[i] <= 90) && ( i%2 != 0  )){
            word[i]= toLowerCase(word[i]);
        }
        /* if upper (check), and it's even (i%2 ==0) --keep upper*/
        if((65 <= word[i]) && (word[i] <= 90) && ( i%2 == 0  )){
            word[i]= word[i];
        }

     }

}

int main(){
    char user_word [SIZE];

    /*Read word from the keyboard using scanf*/
    printf("Enter a word: \n");
    scanf( "%s", user_word);

    /* TESTING */
    /* printf("//TESTING, user_word: %s\n", user_word); */

    /*Call sticky*/
    sticky(user_word);

    /*Print the new word*/
    printf("STICKY CAPS: %s", user_word);

    return 0;
}
