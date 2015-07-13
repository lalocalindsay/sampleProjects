/* CS261- Assignment 2 - calc.c*/
/*
 * Name: Lindsay Tucker
 * Date: 19April2015
 * Solution description: Assignment 2 calc.c
*/


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

#include "dynamicArray.h"


/* param: s the string
   param: num a pointer to double
   returns: true (1) if s is a number else 0 or false.
   postcondition: if it is a number, num will hold
   the value of the number
*/
int isNumber(char *s, double *num)
{
	char *end;
	double returnNum;

	if(strcmp(s, "0") == 0)            /* LT: if s is "0" */
	{
		*num = 0;                      /* this is the # part of the string we want to keep */
		return 1;
	}
	else
	{
		returnNum = strtod(s, &end);   /* LT: conv. string pointed to by s to a float # (type double)  */
		/* LT: http://www.tutorialspoint.com/c_standard_library/c_function_strtod.htm */
		/* If end !=0, a pointer to the char after the last char used in the conv. is stored in the location referenced by end. */
		/* If there's anythin in end, it's bad */
		if((returnNum != 0.0) && (strcmp(end, "") == 0))
		{
			*num = returnNum;          /* this is the # part of the string we want to keep */
			return 1;
		}
	}
	return 0;  //if got here, it was not a number
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and
	their sum is pushed back onto the stack.
*/
void add (struct DynArr *stack)
{
    /* FIXME: You will write this function */

    /* check for correct # of operands, return if <2 */
    if(sizeDynArr(stack) < 2)
    {
        printf("Error! Incorrect number of operands for add().\n");
        return;
    }


	double operand1, operand2;


    if(sizeDynArr(stack) >= 2) /* assert(sizeDynArr(stack) >= 2); */
    {
        operand1 = topDynArr(stack);
        popDynArr(stack);

        operand2 = topDynArr(stack);
        popDynArr(stack);

        pushDynArr(stack, (operand1 + operand2));
    }
    /* TESTING: print size
    printf("TESTING (add) Stack size: %i\n", sizeDynArr(stack)); */

}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and
	their difference is pushed back onto the stack.
*/
void subtract(struct DynArr *stack)
{
	/* FIXME: You will write this function */

    /* check for correct # of operands, return if <2 */
    if(sizeDynArr(stack) < 2)
    {
        printf("Error! Incorrect number of operands for subtract().\n");
        return;
    }

	double operand1, operand2;

    if(sizeDynArr(stack) >= 2) /* assert(sizeDynArr(stack) >= 2); */
    {
        operand1 = topDynArr(stack);
        popDynArr(stack);

        operand2 = topDynArr(stack);
        popDynArr(stack);

        pushDynArr(stack, (operand2 - operand1));
    }
    /* TESTING: print size
    printf("TESTING (subtract) Stack size: %i\n", sizeDynArr(stack)); */

}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and
	their quotient is pushed back onto the stack.
*/
void divide(struct DynArr *stack)
{
	/* FIXME: You will write this function */

	/* check for correct # of operands, return if <2 */
    if(sizeDynArr(stack) < 2)
    {
        printf("Error! Incorrect number of operands for divide().\n");
        return;
    }

	double operand1, operand2;

    if (topDynArr(stack) == 0) /* return if divisor == 0 */
    {
        printf("Error! Divisor can't = 0.\n");
        return;
    }

    if(sizeDynArr(stack) >= 2)  /* assert(sizeDynArr(stack) >= 2); */
    {
        operand1 = topDynArr(stack);
        popDynArr(stack); /* cant be 0 */

        operand2 = topDynArr(stack);
        popDynArr(stack);

        pushDynArr(stack, (operand2/operand1));
    }



    /* TESTING: print size
    printf("TESTING (divide) Stack size: %i\n", sizeDynArr(stack)); */

}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and
	their product is pushed back onto the stack.
*/
void multiply(struct DynArr *stack)
{
	/* FIXME: You will write this function */

	/* check for correct # of operands, return if <2 */
    if(sizeDynArr(stack) < 2)
    {
        printf("Error! Incorrect number of operands for multiply().\n");
        return;
    }

	double operand1, operand2;

    if(sizeDynArr(stack) >= 2) /* assert(sizeDynArr(stack) >= 2); */
    {
        operand1 = topDynArr(stack);
        popDynArr(stack);

        operand2 = topDynArr(stack);
        popDynArr(stack);

        pushDynArr(stack, (operand2 * operand1));
    }
    /* TESTING: print size
    printf("TESTING (multiply) Stack size: %i\n", sizeDynArr(stack)); */

}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and
	the power product is pushed back onto the stack.
*/
void power (struct DynArr *stack)
{
	/* FIXME: You will write this function */

	/* check for correct # of operands, return if <2 */
    if(sizeDynArr(stack) < 2)
    {
        printf("Error! Incorrect number of operands for power().\n");
        return;
    }

	double operand1, operand2;

    if(sizeDynArr(stack) >= 2) /* assert(sizeDynArr(stack) >= 2); */
    {
        operand1 = topDynArr(stack);
        popDynArr(stack);

        operand2 = topDynArr(stack);
        popDynArr(stack);

        pushDynArr(stack, pow(operand2, operand1));
    }
    /* TESTING: print size
    printf("TESTING (power) Stack size: %i\n", sizeDynArr(stack)); */

}

/*	param: stack the stack being manipulated
	pre: the stack contains at least 1 element
	post: the top element is popped and
	the squared product is pushed back onto the stack.
*/
void square (struct DynArr *stack)
{
	/* FIXME: You will write this function */

	/* check for correct # of operands, return if <1 */
    if(sizeDynArr(stack) < 1)
    {
        printf("Error! Incorrect number of operands for square().\n");
        return;
    }

	double operand1;

    if(sizeDynArr(stack) >= 1) /* assert(sizeDynArr(stack) >= 2); */
    {
        operand1 = topDynArr(stack);
        popDynArr(stack);

        pushDynArr(stack, pow(operand1, 2));
    }
    /* TESTING: print size
    printf("TESTING (square) Stack size: %i\n", sizeDynArr(stack)); */

}

/*	param: stack the stack being manipulated
	pre: the stack contains at least 1 element
	post: the top element is popped and
	the cubed product is pushed back onto the stack.
*/
void cube (struct DynArr *stack)
{
	/* FIXME: You will write this function */

	/* check for correct # of operands, return if <1 */
    if(sizeDynArr(stack) < 1)
    {
        printf("Error! Incorrect number of operands for cube().\n");
        return;
    }

	double operand1;

    if(sizeDynArr(stack) >= 1) /* assert(sizeDynArr(stack) >= 2); */
    {
        operand1 = topDynArr(stack);
        popDynArr(stack);

        pushDynArr(stack, pow(operand1, 3));
    }
    /* TESTING: print size
    printf("TESTING (cube) Stack size: %i\n", sizeDynArr(stack)); */

}

/*	param: stack the stack being manipulated
	pre: the stack contains at least 1 element
	post: the top element is popped and
	the absolute value is pushed back onto the stack.
*/
void absolute (struct DynArr *stack)
{
	/* FIXME: You will write this function */

	/* check for correct # of operands, return if <1 */
    if(sizeDynArr(stack) < 1)
    {
        printf("Error! Incorrect number of operands for absolute().\n");
        return;
    }

	double operand1;

    if(sizeDynArr(stack) >= 1) /* assert(sizeDynArr(stack) >= 2); */
    {
        operand1 = topDynArr(stack);
        popDynArr(stack);

        pushDynArr(stack, abs(operand1));
    }
    /* TESTING: print size
    printf("TESTING (absolute) Stack size: %i\n", sizeDynArr(stack)); */

}

/*	param: stack the stack being manipulated
	pre: the stack contains at least 1 element
	post: the top element is popped and
	the square root is pushed back onto the stack.
*/
void squareroot (struct DynArr *stack)
{
	/* FIXME: You will write this function */

	/* check for correct # of operands, return if <1 */
    if(sizeDynArr(stack) < 1)
    {
        printf("Error! Incorrect number of operands for squareroot().\n");
        return;
    }

	double operand1;

    if(sizeDynArr(stack) >= 1) /* assert(sizeDynArr(stack) >= 2); */
    {
        operand1 = topDynArr(stack);
        popDynArr(stack);

        pushDynArr(stack, sqrt(operand1));
    }
    /* TESTING: print size
    printf("TESTING (square root) Stack size: %i\n", sizeDynArr(stack)); */

}

/*	param: stack the stack being manipulated
	pre: the stack contains at least 1 element
	post: the top element is popped and
	the base e exp function is pushed back onto the stack.
*/
void exponential (struct DynArr *stack)
{
	/* FIXME: You will write this function */

	/* check for correct # of operands, return if <1 */
    if(sizeDynArr(stack) < 1)
    {
        printf("Error! Incorrect number of operands for exponential().\n");
        return;
    }

	double operand1;

    if(sizeDynArr(stack) >= 1) /* assert(sizeDynArr(stack) >= 2); */
    {
        operand1 = topDynArr(stack);
        popDynArr(stack);

        pushDynArr(stack, exp(operand1));
    }
    /* TESTING: print size
    printf("TESTING (exponential) Stack size: %i\n", sizeDynArr(stack)); */

}

/*	param: stack the stack being manipulated
	pre: the stack contains at least 1 element
	post: the top element is popped and
	the natural log (base e) is pushed back onto the stack.
*/
void naturallog (struct DynArr *stack)
{
	/* FIXME: You will write this function */

	/* check for correct # of operands, return if <1 */
    if(sizeDynArr(stack) < 1)
    {
        printf("Error! Incorrect number of operands for naturallog().\n");
        return;
    }

	double operand1;

    if(sizeDynArr(stack) >= 1) /* assert(sizeDynArr(stack) >= 2); */
    {
        operand1 = topDynArr(stack);
        popDynArr(stack);

        pushDynArr(stack, log(operand1));
    }
    /* TESTING: print size
    printf("TESTING (naturallog) Stack size: %i\n", sizeDynArr(stack)); */

}

/*	param: stack the stack being manipulated
	pre: the stack contains at least 1 element
	post: the top element is popped and
	the log (base 10) is pushed back onto the stack.
*/
void logten (struct DynArr *stack)
{
	/* FIXME: You will write this function */

	/* check for correct # of operands, return if <1 */
    if(sizeDynArr(stack) < 1)
    {
        printf("Error! Incorrect number of operands for logten().\n");
        return;
    }

	double operand1;

    if(sizeDynArr(stack) >= 1) /* assert(sizeDynArr(stack) >= 2); */
    {
        operand1 = topDynArr(stack);
        popDynArr(stack);

        pushDynArr(stack, log10(operand1));
    }
    /* TESTING: print size
    printf("TESTING (logten) Stack size: %i\n", sizeDynArr(stack)); */

}
double calculate(int numInputTokens, char **inputString)
{
	int i;
	double result = 0.0;
	char *s;
	struct DynArr *stack;
	//set up the stack
	stack = createDynArr(20);

    double e = 2.7182818;
    double pi = 3.14159265;

	// start at 1 to skip the name of the calculator calc
	for(i=1;i < numInputTokens;i++)
	{
		s = inputString[i];

                /* TESTING: PRINT ARGUMENTS
                printf("TESTING: Arguments[%i]: %s\n", i,inputString[i] ); */
                /* TESTING: print size
                printf("TESTING (calculate) Stack size: %i\n", sizeDynArr(stack)); */
		// Hint: General algorithm:
		// (1) Check if the string s is in the list of operators.
		//   (1a) If it is, perform corresponding operations.
		//   (1b) Otherwise, check if s is a number.
		//     (1b - I) If s is not a number, produce an error.
		//     (1b - II) If s is a number, push it onto the stack

		if(strcmp(s, "+") == 0)
        {
            add(stack);
        }
		else if(strcmp(s,"-") == 0)
        {
            subtract(stack);
        }
		else if(strcmp(s, "/") == 0)
		{
		    divide(stack);
		}
		else if(strcmp(s, "x") == 0)
		{
			/* FIXME: replace printf with your own function */
            multiply(stack);
		}
		else if(strcmp(s, "^") == 0)
		{
			/* FIXME: replace printf with your own function */
			power(stack);
		}
		else if(strcmp(s, "^2") == 0)
		{
			/* FIXME: replace printf with your own function */
			square(stack);
        }
		else if(strcmp(s, "^3") == 0)
		{
		    /* FIXME: replace printf with your own function */
			cube(stack);
		}
		else if(strcmp(s, "abs") == 0)
		{
			/* FIXME: replace printf with your own function */
			absolute(stack);
		}
		else if(strcmp(s, "sqrt") == 0)
		{
            /* FIXME: replace printf with your own function */
			squareroot(stack);
        }
		else if(strcmp(s, "exp") == 0)
		{
			/* FIXME: replace printf with your own function */
			exponential(stack);
		}
		else if(strcmp(s, "ln") == 0)
		{
			/* FIXME: replace printf with your own function */
			naturallog(stack);
		}
		else if(strcmp(s, "log") == 0)
		{
            /* FIXME: replace printf with your own function */
			logten (stack);
        }
		else
		{
			// FIXME: You need to develop the code here (when s is not an operator)
			// Remember to deal with special values ("pi" and "e")

            if (strcmp(s,"e") == 0)
            {
                /* push e to stack */
                pushDynArr(stack, e);
                /* printf("TESTING: Stack size: %i\n", sizeDynArr(stack)); */
            }
            else if (strcmp(s,"pi") == 0)
            {
                /* push pi to stack */
                pushDynArr(stack, pi);
                /* printf("TESTING: Stack size: %i\n", sizeDynArr(stack)); */
            }
            else if (isNumber (s, &result)) /* if s is a number, give it the value result now points to */
            {
                /* push result to stack */
                pushDynArr(stack, result);
            }
            else if ( (isNumber(s, &result)) == 0 )
            {
                /* print: "invalid operator" */
                printf("Error! offending argument string: %s\n", inputString[i]);
                break;
            }

		}
	}	//end for

	 /* FIXME: You will write this part of the function (2 steps below)
	 * (1) Check if everything looks OK and produce an error if needed.
	 * (2) Store the final value in result and print it out.
	 */
    if (sizeDynArr(stack) == 1)
    {
        result = topDynArr(stack);
        printf("RESULT: %f\n", result);
        return result;
        /* print here */
    }
    else
    {
        printf("Error! Incorrect number of arguments.\n");
        return 0;
    }


}

int main(int argc , char** argv)
{

	// assume each argument is contained in the argv array
	// argc-1 determines the number of operands + operators
	if (argc == 1)  /* if (argc-1 == 1), this doesn't print a result */
		return 0;

	calculate(argc,argv);
	return 0;
}
