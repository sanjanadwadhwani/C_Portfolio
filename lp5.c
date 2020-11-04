/*
Sanjana Wadhwani
9/24/2020
CS50AP
Learning Project 5
*/

//Preprocessor Directives
#include <stdio.h>
#include <cs50.h>
#include <string.h>

//Main method
int main(void) {

    printf("\n");

    //create array
    float dataset[5];
    dataset[0] = get_float("Type 1st number: ");
    dataset[1] = get_float("Type 2nd number: ");
    dataset[2] = get_float("Type 3rd number: ");
    dataset[3] = get_float("Type 4th number: ");
    dataset[4] = get_float("Type 5th number: ");


    //print all the numbers in the array

    int len = sizeof(dataset)/sizeof(dataset[0]);
    printf("\nThe set of numbers you entered is:");
    for(int i=0; i<len; i++){
        printf("[%.1f]", dataset[i]);
    }


    //find the sum of all the numbers
    float x=0;
    for(int i=0; i<len; i++){
        x = x + dataset[i];
    }
    printf("\n\nThe sum of the numbers you entered is %.1f", x);


    //divide sum by 5 to get average of numbers
    x = x/(len+1); //change x/5 to x/(len+1)
    printf("\nThe average of the numbers you entered is %.1f", x);
    printf("\n");


    //order the numbers by comparing each number with index i to the number with index of i+1
    for(int i=0; i<(len-1); i++){
        for(int j=i+1; j<len; j++){
            if (dataset[i]>dataset[j]){
                float y = dataset[i];
                dataset[i]=dataset[j];
                dataset[j] = y;
            }
        }
    }


    //double check the order of the numbers by going through the array backwards
    for(int i=len; i>1; i--){			//change i=4 to i=len
        for(int j=i-1; j>0; j--){
            if (dataset[(i)]<dataset[(j)]){
                float y = dataset[i];
                dataset[i]=dataset[j];
                dataset[j] = y;
            }
        }
    }


    //print ordered dataset
    printf("\nThe set of numbers in order from least to great is:");
    for(int i=0; i<len; i++){
        printf("[%.1f]", dataset[i]);
    }
    
    
    //print ordered dataset from greatest to least (new)
    printf("\nThe set of numbers in order from greatest to least is:");
    for(int i=len; i>0; i--){
        printf("[%.1f]", dataset[i]);
    }
    
    
    //print maximum and minimum
    printf("\nThe maximum is %.1f and the minimum is %.1f\n\n", dataset[len], dataset[0]); //change dataset[4] to dataset[len]

    return(0);

}
