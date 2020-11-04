/*
Sanjana Wadhwani
8/20/2020
CS50AP
Learning Project 6
*/

//Preprocessor Directives
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>

//Main method
int main(int argc, char* argv[]){

    //check to make sure there is only the 2 numbers and 1 operater present
    if (argc != 4){
        printf("Error! Type in the format of A x B where A and B are the numbers and x is the operator.\n");
        return 1;
    }

    //set n1 to the first number entered and n2 to the second number entered after the operator
    double n1 = atof(argv[1]);
    double n2 = atof(argv[3]);

    //set variable oper to whatever operator they entered
    char oper = *argv[2];

    //switch based on what the operator is
    float result;
    int z;

    switch(oper){
        //operation is addition
        case '+':
            result = n1 + n2;
            printf("%.6f\n", result);
            break;
        //operation is multiplication
        case 'x':
            result = n1*n2;
            printf("%.6f\n", result);
            break;
        //operation is subtraction
        case '-':
            result = n1-n2;
            printf("%.6f\n", result);
            break;
        //operation is division
        case '/':
            if (n2 == 0){ //if divided by 0 then DNE
                printf("Does not exist");
                return 0;
            }
            result = n1/n2;
            printf("%.6f\n", result);
            break;
        //operation is finding the remainder
        case '%':
            z = (n1/n2);
            result = n1 - (n2 * z);
            printf("%.6f\n", result);
            break;
        //check to make sure that the operator entered is valid
        default:
            printf("Error! The operator must be x, +, -, /, or %%.\n");
            return 1;
    }


}
