/* program for boundary traversal of a binary tree */
#include "stub.h"
#include <stdio.h>
#include <stdlib.h>
// 
/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct cl_node
{
    int data;
    struct cl_node *left, *right;
};
typedef struct cl_node CLNODE;
 


// A simple function to print leaf nodes of a binary tree
void printLeaves(CLNODE* root)
{
    if ( root )
    {
        printLeaves(root->left);
 
        // Print it if it is a leaf node
        if ( !(root->left)  &&  !(root->right) )
            printf("%d ", root->data);
 
        printLeaves(root->right);
    }
}
 
// A function to print all left boundry nodes, except a leaf node.
// Print the nodes in TOP DOWN manner
void printBoundaryLeft(CLNODE* root)
{
    if (root)
    {
        if (root->left)
        {
            // to ensure top down order, print the node
            // before calling itself for left subtree
            printf("%d ", root->data);
            printBoundaryLeft(root->left);
        }
        else if( root->right )
        {
            printf("%d ", root->data);
            printBoundaryLeft(root->right);
        }
        // do nothing if it is a leaf node, this way we avoid
        // duplicates in output
    }
}
 
// A function to print all right boundry nodes, except a leaf node
// Print the nodes in BOTTOM UP manner
void printBoundaryRight(CLNODE* root)
{
    if (root)
    {
        if ( root->right )
        {
            // to ensure bottom up order, first call for right
            //  subtree, then print this node
            printBoundaryRight(root->right);
            printf("%d ", root->data);
        }
        else if ( root->left )
        {
            printBoundaryRight(root->left);
            printf("%d ", root->data);
        }
       // do nothing if it is a leaf node, this way we avoid
       // duplicates in output
    }
}
 
 
// A function to do boundary traversal of a given binary tree
void printBoundary (CLNODE* root)
{
    if (root)
    {
        printf("%d ",root->data);
 
        // Print the left boundary in top-down manner.
        printBoundaryLeft(root->left);
 
        // Print all leaf nodes
        printLeaves(root->left);
        printLeaves(root->right);
 
        // Print the right boundary in bottom-up manner
        printBoundaryRight(root->right);
    }
}
 
// A utility function to create a node
CLNODE* newNode( int data )
{
    CLNODE* temp = (CLNODE*) malloc( sizeof(CLNODE) );
 
    temp->data = data;
    temp->left = temp->right = NULL;
 
    return temp;
}
 
// Driver program to test above functions
int eeferer()
{
    // Let us construct the tree given in the above diagram
    CLNODE *root         = newNode(1);
    root->left                = newNode(2);
    //root->left->left          = newNode(4);
    root->left->right         = newNode(4);
  //  root->left->right->left   = newNode(10);
   // root->left->right->right  = newNode(14);
    root->right               = newNode(3);
    root->right->right        = newNode(25);
 
    printBoundary( root );
 
    return 0;
}