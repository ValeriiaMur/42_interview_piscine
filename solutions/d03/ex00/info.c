/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriiamuradian <valeriiamuradian@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 15:40:21 by valeriiamur       #+#    #+#             */
/*   Updated: 2019/03/26 09:00:53 by valeriiamur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <limits.h>
#include <stdlib.h>

struct s_info   getInfo(struct s_node *root)
{
    struct s_info info;
    int height = 0;

    info.min = findMin(root);
    info.max = findMax(root);
    info.elements = countNodes(root);
    info.height = findDepth(root);
    info.isBST = isBst(root, INT_MIN, INT_MAX);
    info.isBalanced = isBalanced(root, &height);
    return (info);
}

// Return true if difference between heights is not more than 1
int isBalanced(struct s_node *node, int *h)
{	 
  int lh = 0, rh = 0;   
  
  /* l will be true if left subtree is balanced  
    and r will be true if right subtree is balanced */ 
  int l = 0, r = 0;

  if (node == NULL) 
  { 
    *h = 0; 
    return (1); 
  } 
  
  /* Get the heights of left and right subtrees in lh and rh  
    And store the returned values in l and r */    
  l = isBalanced(node->left, &lh); 
  r = isBalanced(node->right,&rh);
  *h = (lh > rh? lh: rh) + 1; 
  if ((lh - rh >= 2) || (rh - lh >= 2))
	return (0);
  else 
	return (l && r); 
}

int isBst(struct s_node *root, int min, int max)
{
    if (root == NULL) //an empty tree is bst
        return 1;
    if (root->value < min || root->value > max)
        return 0;
    return isBst(root->left, min, root->value - 1) 
    && isBst(root->right, root->value + 1, max);
}

int findMin(struct s_node *root)
{
    if (root == NULL) //base case
        return INT_MAX;
    int res = root->value; 
    int lres = findMin(root->left); 
    int rres = findMin(root->right); 
    if (lres < res) 
      res = lres; 
    if (rres < res) 
      res = rres; 
    return res; 
}

int findMax(struct s_node *root)
{
    if (root == NULL)
        return INT_MIN;
    int res = root->value;
    int lres = findMax(root->left);
    int rres = findMax(root->right);
    if (lres > res)
        res = lres;
    if (rres > res)
        res = rres;
    return (res);
}

int countNodes(struct s_node *root)
{
    int count = 1;

    if (root == NULL)
        return 0;
    else
    {
        count += countNodes(root->left);
        count += countNodes(root->right);
        return(count);
    }
}

int findDepth(struct s_node *root)
{
    int left_d = 1;
    int right_d = 1;
    if (root == NULL)
        return 0;
    else
    {
        left_d += findDepth(root->left);
        right_d += findDepth(root->right);
    }
    if (left_d > right_d)
        return left_d;
    else
        return right_d;
}