#ifndef __BST_H
#define __BST_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Students.h"

/*allocate the memory for a struct tnode*/
struct tnode *talloc(void);

/*add a node to tree*/
struct tnode *addtree(struct tnode *, struct data *);

/*print tree from root*/
void treeprint(struct tnode *);

/*clear tree from root*/
void treepclear(struct tnode *);

#endif
