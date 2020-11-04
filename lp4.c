/*
Sanjana Wadhwani
8/20/2020
CS50AP
Learning Project 4
*/

//Preprocessor Directives
#include <stdio.h>
#include <cs50.h>
#include <string.h>

//Main method
int main(void)
{ 
    //get input and store as c
    float c = get_float("\nC: ");

    //convert celsius to fahrenheit
    float f = ((c * 9) / 5) + 32;

    //print result
    printf("F: %.1f \n\n", f);

    return (0);
} 