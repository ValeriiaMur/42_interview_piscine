/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   saveTheSequoia.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriiamuradian <valeriiamuradian@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 19:09:53 by valeriiamur       #+#    #+#             */
/*   Updated: 2019/03/29 20:05:05 by valeriiamur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <unistd.h>

void pop(struct s_node **parent, struct s_node **child)
{
	struct s_node *temp = *parent;
	struct s_node *childLeft = (*child)->left;
	struct s_node *childRight = (*child)->right;
	*parent = *child;
	if (temp->left == *child)
	{
		(*child)->left = temp;
		(*child)->right = temp->right;
	}
	else
	{
		(*child)->right = temp;
		(*child)->left = temp->left;
	}
	//*child = temp;
	temp->left = childLeft;
	temp->right = childRight;
}

int heap(struct s_node **node)
{
	if (!*node)
		return 0;

	int num = 1;

	if ((*node)->right && (*node)->value < (*node)->right->value)
		pop(node, &(*node)->right);
	if ((*node)->left && (*node)->value < (*node)->left->value)
		pop(node, &(*node)->left);
	num += heap(&(*node)->right);
	num += heap(&(*node)->left);

	return num;
}


void saveTheSequoia(struct s_node **root)
{
	if (!root)
		return;

	int n = heap(root);
	for (int i=0;i<n-1;i++) {
		heap(root);
	}
}