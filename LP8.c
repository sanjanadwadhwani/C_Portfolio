/*
Sanjana Wadhwani
10/22/2020
CS50AP
Learning Project 8
*/

//Preprocessor directives
#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

//contact struct
struct contactName{
    string name;
    string email;
    string number;
    float birthday;
    int age;

};

int main(int argc, char *argv[]){
    FILE *fp;

    //intialize variables
    string name, email, number, readName;
    float birthday;
    int age, quit, again, loopVarInd, lineNum, found, rowNum;
    char choice, singleLine[150], line[150], file;

    //choose what to do
    printf("[1] Add a new contact \n[2] Search for contact \n[3] Print all contacts \n[0] Exit");
    choice = get_char("\nChoose one: ");

    //switch based on choice from main menu
    switch(choice){
        //exit
        case '0':
            return 0;


        //add a contact
        case '1':
            //loop to add contacts. As long as loop variable index is 1, add contacts
            loopVarInd = 1;
            while (loopVarInd == 1){
                //get all info on contact
                name = get_string("\nName: ");
                email = get_string("Email: ");
                number = get_string("Phone Number: ");
                birthday = get_float("Birthday (MM.DD): ");
                age = get_int("Age: ");

                //open file
                fp = fopen("Contact List.txt", "a");
                //if there is an error reading the file return(1)
                if(fp==NULL){
                    printf("File could not be opened.\n");
                    return(1);
                    }

                //put contact info into struct and print into file
                struct contactName contact = {name, email, number, birthday, age};
                fprintf(fp, "\n%s, %s, %s, %.2f, %d", 
                	contact.name, contact.email, contact.number, contact.birthday, contact.age);

                //close file
                fclose(fp);

                //choose to break out of loop or keep adding contacts
                loopVarInd = get_int("\nChoose an option \n[1] Add another contact \n[0] Exit \nChoose one: ");
            }
            //exit
            break;


        //search for contact
        case '2':
            //loop to add contacts. As long as loop variable index is 1, search contacts
            loopVarInd = 1;
            while (loopVarInd == 1){
                //ask for person's name
                name = get_string("\nWhat is the person's name? ");

                found = 0; //true and false variable for if name is found
                rowNum = 0; //lines searched counter

                //open file
                fp = fopen("Contact List.txt", "r");
                //if there is an error reading the file return(1)
                if(fp==NULL){
                    printf("File could not be opened.\n");
                    return(1);
                    }

                //while not the end of the file to print line with that name
                while(!feof(fp)){
                    fgets(singleLine,100,fp);
                    strcpy(line, singleLine); //copy singleLine into variable line
                    //make readName characters from start of the line to the first comma
                    readName = strtok (singleLine,",");

                    //compare readName and name and if they are the same, print the entire line
                    if (strcmp(readName, name) == 0){
                        //order of contact information
                        printf("\nName, Email, Number, Birthday (MM.DD), Age");
                        printf("\n%s", line);
                        found = 1;
                        break; }
                    rowNum++; //count number of lines searched
                }

                //close file
                fclose(fp);

                //if the found variable was never changed to 1, name was not found
                if (found == 0){
                    printf("Name not found. Searched %i lines.", rowNum);
                }

                //choose to break out of loop or keep searching contacts
                loopVarInd = get_int("\n\nChoose an option \n[1] Search for another contact \n[0] Exit \nChoose one: ");
            }
            //exit
            break;


        //print all contacts
        case '3':
            //print line break
            printf("\n");
            //open file
            fp = fopen("Contact List.txt", "r");
            //if there is an error reading the file return(1)
            if(fp==NULL){
                printf("File could not be opened.\n");
                return(1);
            }

            //print all contents of file
            file = fgetc(fp);
            while (file != EOF) {
                printf ("%c", file);
                file = fgetc(fp);
            }

            //close file and print line break
            fclose(fp);
            printf("\n\n");
            break;

        //check if the user entered an option that could work
        default:
            printf("Error! You must choose 1, 2, 3, or 0.\n");
            return 1;
    }
}
s