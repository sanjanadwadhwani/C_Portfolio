/*
Sanjana Wadhwani
9/2/2020
CS50AP
Learning Project 3
*/

//Preprocessor Directives
#include <stdio.h>
#include <cs50.h>
#include <string.h>

//Main method
int main(void) {

    char x[8] = "Tiny Tim";
    printf("\"%s\"\n", x);
    printf("There was a little frog.");
    printf("\n\tHis name was %s.", x);
    printf("\nI put him in the bathtub,");
    printf("\n\tto see if he could swim. ");
    printf("\nHe drank up all the water.");
    printf("\n\tHe ate up all the soap,");
    printf("\nand now he is in the bathtub,");
    printf("\n\twith a bubble in his throat.");
    printf("\nBubble, bubble, bubble,");
    printf("\n\tBubble, bubble, pop, ");
    printf("\nI love my little frog");
    printf("\n\twhose name is %s.\n", x);

    return(0);

}

