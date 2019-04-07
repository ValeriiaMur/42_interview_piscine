/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maxSW.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuradia <vmuradia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 19:32:43 by vmuradia          #+#    #+#             */
/*   Updated: 2019/04/05 19:34:32 by vmuradia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>
#include <limits.h>

struct s_deque *dequeInit(void)
{
	struct s_deque *que = malloc(sizeof(struct s_deque));
	if (!que)
		return (NULL);
	que->first = NULL;
	que->last = NULL;
	return (que);
}

void pushFront(struct s_deque *deque, int value)
{
	if (!deque)
		return ;
	struct s_dequeNode *tmp = malloc(sizeof(struct s_dequeNode));

	tmp->value = value;
	if (!deque->first)
	{
		tmp->next = NULL;
		tmp->prev = NULL;
		deque->first = tmp;
		deque->last = tmp;
	}
	else
	{
		tmp->next = deque->first;
		tmp->prev = NULL;
		deque->first->prev = tmp;
		deque->first = tmp;
	}

}
void pushBack(struct s_deque *deque, int value)
{
	if (!deque)
		return ;

	struct s_dequeNode *tmp = malloc(sizeof(struct s_dequeNode));
	tmp->value = value;
	if (!deque->last)
	{
		tmp->next = NULL;
		tmp->prev = NULL;
		deque->first = tmp;
		deque->last = tmp;
	}
	else
	{
		tmp->prev = deque->last;
		tmp->next = NULL;
		deque->last->next = tmp;
		deque->last = tmp;
	}
}
int popFront(struct s_deque *deque)
{
	if (!deque || !deque->first)
		return (INT_MIN);
	struct s_dequeNode *tmp;
	int fr = deque->first->value;
	tmp = deque->first;
	deque->first = deque->first->next;

	if (!deque->first)
		deque->last = NULL;
	else
		deque->first->prev = NULL;
	free(tmp);
	return fr;
}

int popBack(struct s_deque *deque)
{
	if (!deque || !deque->last)
		return (INT_MIN);
	struct s_dequeNode *tmp;
	int back =  deque->last->value;
	tmp = deque->last;
	deque->last = deque->last->prev;
	if(!deque->last)
		deque->last = NULL;
	else
		deque->last->next = NULL;
	free(tmp);
	return back;
}

int peekBack(struct s_deque *deque)
{
	if (!deque || !deque->last)
		return INT_MIN;
	return deque->last->value;
}

int peekFront(struct s_deque *deque)
{
	if (!deque || !deque->first)
		return INT_MIN;
	return deque->first->value;
}

struct s_max *maxSlidingWindow(int *arr, int n, int k)
{
	if (k > n || k < 0 || !arr)
		return NULL;
	int i = 0;
	struct s_deque *que = dequeInit();
	struct s_max *window = malloc(sizeof(struct s_max));
	window->length = n - k + 1;
	window->max = malloc(sizeof(int) * window->length);
	for (i = 0; i < k; i++)
	{
		while (que->last && peekBack(que) != INT_MIN && arr[i] >= arr[peekBack(que)])
			popBack(que);
		pushBack(que, i);
	}

	for (i = k; i < n; i++)
	{
		window->max[i - k] = arr[peekFront(que)];
		while (que->first && peekFront(que) != INT_MIN && peekFront(que) <= i - k)
			popFront(que);
		while (que->last && peekBack(que) != INT_MIN && arr[i] >= arr[peekBack(que)])
			popBack(que);
		pushBack(que, i);
	}
	window->max[i - k] = arr[peekFront(que)];

	return window;
}
