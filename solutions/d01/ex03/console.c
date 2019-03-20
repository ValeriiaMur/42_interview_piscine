/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   console.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuradia <vmuradia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 11:19:56 by vmuradia          #+#    #+#             */
/*   Updated: 2019/03/20 12:44:54 by vmuradia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

struct s_stack *initStack()
{
    struct s_stack *my_stack = (struct s_stack*)malloc(sizeof(struct s_stack));
    if (!(my_stack))
        return NULL;
    my_stack->item = NULL;
	return (my_stack); 
}

void push(struct s_stack *stack, int idx)
{
	struct s_item *item = (struct s_item*)malloc(sizeof(struct s_item));
	if (!(item))
		return ;
	item->idx = idx;
	if (!(stack->item))
	{
		item->next = NULL;
		stack->item = item;
		return ;
	}
	item->next = stack->item;
	stack->item = item;
}

int pop(struct s_stack *stack)
{
	int index;

	if (!stack)
		return 0;
	if (!stack->item)
		return 0;
	struct s_item *tmp = stack->item;
	stack->item = stack->item->next;
	index = tmp->idx;
	free(tmp);
	return (index);
}

char *console(void)
{
	char *msg = calloc(1, 256); //Allocate and zero-initialize array
	struct s_stack *stack = initStack();
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	int i = 0;
	int idx;

	while (1)
	{
		printf("console:> ");
	 	read = getline(&line, &len, stdin);
	 	if (!strncmp("UNDO", line, 4))
	 	{
	 		idx = pop(stack);
	 		memset(msg + idx, '\0', 256 - idx); //Fill block of memory
	 		i = idx;
	 	}
	 	else if (!strncmp("SEND", line, 4))
	 	{
	 		free(line);
	 		while (stack->item)
				pop(stack);
			free(stack);
			if (i > 0)
				msg[i - 1] = '\0';
			return msg;
	 	}
	 	else
	 	{
	 		push(stack, i);
	 		strncat(msg, line, read - 1); //Append characters from string
	 		strncat(msg, " ", 1);
	 		i += read;
	 	}
	 	printf("%s\n\n", msg);
	}
	return NULL;
}