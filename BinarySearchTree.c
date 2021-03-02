#include "BinarySearchTree.h"

/*allocate the memory for a struct tnode*/
struct tnode *talloc(void)
{
    return (struct tnode *) malloc(sizeof(struct tnode));
}

/*
 add new node to tree
 */
struct tnode *addtree(struct tnode *p, struct data* n)
{
    //empty tree?
    if (p == NULL)
    {
        //create a new node
        p = talloc();
        p->person = n;
        p->left = p->right = NULL;

    } else if (p->person->mathAvg < n->mathAvg)
    { //add to right subtree
        p->right = addtree(p->right, n);
    } else
    {//add to left subtree
        p -> left = addtree(p->left, n);
    }

    return p;
}

/*
 * print tree
 * preorder
 */
void treeprint(struct tnode *p)
{
    if (p != NULL)
    {
        treeprint(p->left);

        if ((p->person->mathAvg) > 700)
            printData(p->person);

        treeprint(p->right);
    }
}

/*clear tree from root*/
void treepclear(struct tnode *p)
{
    if (p != NULL)
    {
        //clear left, right subtrees
        treepclear(p->left);
        treepclear(p->right);

        free (p->person);
        free (p);
    }
}
