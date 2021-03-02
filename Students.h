#ifndef __BABY_H
#define __BABY_H

#define MAXLINE 1000 // maximum input line length
#define MAXDATA_FIELD_LEN 200   // maximum length of field

/*data of node*/
struct data
{
    char schoolName[MAXDATA_FIELD_LEN];
    char dbn[MAXDATA_FIELD_LEN];
    unsigned int testTakers;
    unsigned int rdgAvg;
    unsigned int mathAvg;
    unsigned int writeAvg;
};

/*node of binary tree*/
struct tnode
{
    struct data *person;
    struct tnode *right;
    struct tnode *left;
};

/*check condition before add to tree*/
int checkCondition(struct data);

/*read a line*/
int getLine(char line[], int maxline);

/*format line*/
void formatLine(char line[]);

//
int rightFormat(char line[]);

/*allocate the memory for a struct data then copy data*/
struct data *dataAlloc(struct data);

/*print data*/
void printData(struct data*);

#endif
