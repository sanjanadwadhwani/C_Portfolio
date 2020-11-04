/*
Sanjana Wadhwani
10/8/2020
CS50AP
Learning Project 7
*/
//Preprocessor directives
#include <stdio.h>
#include <stdlib.h>
#include <cs50.h>
#include <string.h>
#include <math.h>

//struct for various information on each book
struct Books{
    //strings are title and author if the book
    string title;
    string author;

    //char is genre
    char genre;

    //ISBN-10 and ISBN-13
    long double ISBN10;
    long double ISBN13;

    //number of pages in book
    int pgs;

    //publication year
    int pubYear;

    //price for hardcover (HC) and paperback (PB)
    double HCprice;
    double PBprice;
};

//struct for the header
struct Header{
    string title;
    string author;
    string genre;
    string ISBN10;
    string ISBN13;
    string pgs;
    string pubYear;
    string HCprice;
    string PBprice;
};

int main(int argc, char *argv[]){

    //creating a file pointer
    FILE *fp;

    //struct version of header struct with titles
    struct Header H = {"TITLE", "AUTHOR", "GENRE (F or N)", "ISBN10", "ISBN13", "PAGES",
        "PUBLICATION YEAR", "HARDCOVER PRICE", "PAPERBACK PRICE"};

    //instantiating 6 versions of Books with various books and their information
    struct Books B1 = {"Glass Castle","Jeannette Walls",'N',
        1439156964,9780743247542,304, 006,30.00,15.50};
    struct Books B2 = {"Catch-22","Joseph Heller",'F',
        1451621175,9781451626650,544,2011,26.99,15.99};
    struct Books B3 = {"To Kill a Mockingbird","Harper Lee",'F',
        0062420704,9780061120084,336,2006,23.99,15.99};
    struct Books B4 = {"Night","Elie Wiesel",'N',
        0374500010,9780374500016,144,2006,19.99,9.99};
    struct Books B5 = {"The Great Gatsby","F. Scott Fitzgerald",'F',
        1839407590,9780743273565,208,2004,22.50,13.99};
    struct Books B6 = {"The Boy in the Striped Pajamas","John Boyne",'F',
        0355751532,9780385751537,224,2007,17.99,8.99};
        
    //opening a file to output the contents of the struct
    fp = fopen("bookListSanjana.text", "w");

    //if there is an error reading the file return(1)
    if(fp==NULL){
        printf("File could not be opened.\n");
        return(1);
    }
    
    //print the header into the file
    fprintf(fp, "%s,%s,%s, %s, %s, %s, %s, %s, %s\n",
        H.title, H.author, H.genre, H.ISBN10, H.ISBN13, H.pgs, H.pubYear, H.HCprice, H.PBprice);

    //print the information for each book into the file
    fprintf(fp, "%s,%s,%c, %.0Lf, %.0Lf, %d, %d, %.4g, %.4g\n",
        B1.title, B1.author, B1.genre, B1.ISBN10, B1.ISBN13, B1.pgs, B1.pubYear, B1.HCprice, B1.PBprice);
    fprintf(fp, "%s,%s,%c, %.0Lf, %.0Lf, %d, %d, %.4g, %.4g\n",
        B2.title, B2.author, B2.genre, B2.ISBN10, B2.ISBN13, B2.pgs, B2.pubYear, B2.HCprice, B2.PBprice);
    fprintf(fp, "%s,%s,%c, %.0Lf, %.0Lf, %d, %d, %.4g, %.4g\n",
        B3.title, B3.author, B3.genre, B3.ISBN10, B3.ISBN13, B3.pgs, B3.pubYear, B3.HCprice, B3.PBprice);
    fprintf(fp, "%s,%s,%c, %.0Lf, %.0Lf, %d, %d, %.4g, %.4g\n",
        B4.title, B4.author, B4.genre, B4.ISBN10, B4.ISBN13, B4.pgs, B4.pubYear, B4.HCprice, B4.PBprice);
    fprintf(fp, "%s,%s,%c, %.0Lf, %.0Lf, %d, %d, %.4g, %.4g\n",
        B5.title, B5.author, B5.genre, B5.ISBN10, B5.ISBN13, B5.pgs, B5.pubYear, B5.HCprice, B5.PBprice);
    fprintf(fp, "%s,%s,%c, %.0Lf, %.0Lf, %d, %d, %.4g, %.4g\n",
        B6.title, B6.author, B6.genre, B6.ISBN10, B6.ISBN13, B6.pgs, B6.pubYear, B6.HCprice, B6.PBprice);

    //Close the file
    fclose(fp);

    return(0);
}