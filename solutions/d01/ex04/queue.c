/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuradia <vmuradia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 12:57:15 by vmuradia          #+#    #+#             */
/*   Updated: 2019/03/20 17:20:03 by vmuradia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


struct s_queue *queueInit(void)
{
    struct s_queue *queue = (struct s_queue*)malloc(sizeof(struct s_queue));

    if (!queue)
        return NULL;
    queue->first = NULL;
    queue->last = NULL;
    return (queue);
}

char *dequeue(struct s_queue *queue) // remove the first item and return it (from the first queue)
{
	char *msg = NULL;
	struct s_node *tmp;

	if (!queue)
		return NULL;
	if (!queue->first)
		return NULL;
	msg = queue->first->message;
	tmp = queue->first;
	queue->first = queue->first->next;
	if (!queue->first)
		queue->last = NULL;
	free(tmp);
	return msg;
}


void enqueue(struct s_queue *queue, char *message) // add a message to the end of queue
{
	if (!queue)
		return;

	struct s_node *new = malloc(sizeof(struct s_node));
	if (!new)
		return;

	new->message = message;
	new->next = NULL;

	if (!queue->last)
	{
		queue->last = new;
		queue->first = new;
		return;
	}
	queue->last->next = new;
	queue->last = new;
}

char *peek(struct s_queue *queue) // return the first item of the queue
{
	if (!queue)
		return NULL;
	if (!queue->first)
		return NULL;
	return (queue->first->message);
}

int isEmpty(struct s_queue *queue)
{
    if (!queue)
        return 1;
    if (!(queue->first) || !(queue->last))
        return 1;
    return 0;
}