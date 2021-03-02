#include "Students.h"
#include "BinarySearchTree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Note: check the checkCondition function in the Students.c to know which line is used to analyzed

*/
int main()
{
    int len;        // current line length
    char input[MAXLINE]; // current input line

    /*a data created from a line*/
    struct data dataLine;

    /*root of tree*/
    struct tnode* root = NULL;

    /*statistics*/
    //rows of data were analyzed, how many were ignored, and how many were badly-formed
    int analyzedRows = 0;
    int ignoredRows = 0;
    int badlyFormedRows = 0;


    /*ignore the header line of csv file*/
    getLine(input, MAXLINE);

    /*read line by line until end of file*/
    while ((len = getLine(input, MAXLINE)) > 0)
    {
        /*replace ',' by ' '*/
        formatLine(input);

        /*parse a line*/
            if (sscanf(input, "%s %s %d %d %d %d \n", dataLine.dbn, dataLine.schoolName,
                       &dataLine.testTakers, &dataLine.rdgAvg, &dataLine.mathAvg, &dataLine.writeAvg) == 6) {
                root = addtree(root, dataAlloc(dataLine));

                analyzedRows = analyzedRows + 1;
            } else {
                badlyFormedRows = badlyFormedRows + 1;
            }

    }
    printf("SAT Math scores > 700\n");
    treeprint(root);


    /*print statistics*/
    printf("----------- Statistics ---------- \n");
    printf("Number of rows of data were analyzed: %d\n", analyzedRows);
    printf("Number of rows of data were badly-formed: %d\n", badlyFormedRows);

    /*free resource*/
    treepclear(root);

    return 0;
}
