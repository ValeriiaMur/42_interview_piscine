/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverseV2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuradia <vmuradia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 18:42:29 by vmuradia          #+#    #+#             */
/*   Updated: 2019/03/19 19:20:47 by vmuradia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

//creating stack, init at 0
struct s_stack *stackInit(void)
{
    struct s_stack *new_stack = (struct s_stack*)malloc(sizeof(struct s_stack));
    if (!(new_stack))
        return NULL;
    new_stack->item = NULL;
    return (new_stack);
}

//remove the top item from stack and return t
void *pop(struct s_stack *stack)
{
	if (!(stack))
		return NULL;
	if (!(stack->item))
		return NULL;
	struct s_item *tmp = stack->item; //save the item in tmp to use the contents
	char *content;
	stack->item = stack->item->next;
	content = tmp->word;
	free(tmp);
	return (content);
}

// Function to add an item to the top of the stack
void push(struct s_stack *stack, char *word)
{
    struct s_item *new = (struct s_item*)malloc(sizeof(struct s_item));
    if (!(new))
        return ;
    new->word = word;
    if (!stack->item) // if stack is empty, push the new item, set to null
    {
        new->next = NULL;
		stack->item = new;
		return;
	}
	new->next = stack->item; //if not, put on top
	stack->item = new;
}

void printReverseV2(struct s_node *lst)
{
    struct s_stack *stack = stackInit();

	while (lst)
	{
		push(stack, lst->word);
		lst = lst->next;
	}
	while(stack->item)
		printf("%s ", pop(stack));
	printf("\n");
}