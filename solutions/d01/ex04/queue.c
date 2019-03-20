/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuradia <vmuradia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 12:57:15 by vmuradia          #+#    #+#             */
/*   Updated: 2019/03/20 13:15:14 by vmuradia         ###   ########.fr       */
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

char *dequeue(struct s_queue *queue)
{

}

void enqueue(struct s_queue *queue, char *message)
{

}

char *peek(struct s_queue *queue)
{

}

int isEmpty(struct s_queue *queue)
{
    if ()
}