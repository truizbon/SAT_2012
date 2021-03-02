#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Students.h"

/* By K&R: getline: read a line into s, return length
 */
int getLine(char s[MAXLINE], int lim)
{
    int c, i;

    //read character, until end of line
    for (i = 0; i < lim - 1 && (c=getchar())!=EOF && c!='\n'; ++i)
        s[i] = c;

    //ignore '\n'
    if (c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';

    return i;
}

/*allocate the memory for a struct data*/
struct data *dataAlloc(struct data inData)
{

    //allocate memory
    struct data* tdata = (struct data *) malloc(sizeof(struct data));

    //copy data field
    strcpy(tdata->schoolName, inData.schoolName);
    strcpy(tdata->dbn, inData.dbn);

    tdata->testTakers = inData.testTakers;
    tdata->rdgAvg = inData.rdgAvg;
    tdata->mathAvg = inData.mathAvg;
    tdata->writeAvg = inData.writeAvg;

    return tdata;
}

/*format line*/
void formatLine(char line[])
{

    //unsigned int i; /*loop control variable*/

    //convert spaces in high school names to non space. ie Hunter High = HunterHigh
    for (unsigned int j = 0; j < 2; j++) {
        for (unsigned int i = 0; i < strlen(line); i++) {
            if (line[i] == ':')
                line[i] = ' ';

            if (line[i] == ' ')
                line[i] = '_';

            if (line[i] == ',' && line[i + 1] == '_')
                line[i] = '_';
        }
    }
    /*convert ',' to ' ' to use in sscanf*/
    for (unsigned int i = 0; i < strlen(line); i++)
    {

        if (line[i] == ',')
            line[i] = ' ';
    }
}

/*print data*/
void printData(struct data *p)
{
    printf("%21s %5s %21d %3d %3d %3d\n", p->dbn,
           p->schoolName, p->testTakers, p->rdgAvg, p->mathAvg, p->writeAvg);
}
