#ifndef HEADER_H
# define HEADER_H

/*--------------------------------
  !! required structure
  --------------------------------*/
struct s_node {
	int value;
	struct s_node *right;
	struct s_node *left;
};


/*--------------------------------
  :) function you must implement
  --------------------------------*/
struct s_node *createBST(int *arr, int n);


/*--------------------------------
  ?? test function used in main 
  --------------------------------*/
void printBinaryTree(struct s_node * t); //print a binary tree


/*--------------------------------
  &  your own other function
  --------------------------------*/

struct s_node *makingBST(int *arr, int start, int end);
struct s_node *createNew(int data);

#endif
