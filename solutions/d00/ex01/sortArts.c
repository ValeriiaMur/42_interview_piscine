/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortArts.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuradia <vmuradia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 18:45:12 by vmuradia          #+#    #+#             */
/*   Updated: 2019/03/19 14:20:48 by vmuradia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <string.h>
#include <unistd.h>

size_t  size_of_arr(struct s_art **arts)
{
    size_t i;

    i = 0;
    while (arts[i])
        i++;
    return (i);
} 

int find_partition(struct s_art **arts, int start, int end)
{
    int i;
    int j;
    struct s_art *pivot;
    struct s_art *tmp;

    i = start;
    j = end;
    pivot = arts[start];
    tmp = 0;
    while (1) 
    {
 		while (strcmp(arts[i]->name, pivot->name) < 0)
			i += 1;
		while (strcmp(arts[j]->name, pivot->name) > 0)
			j -= 1;
		if (i < j)
		{
			tmp = arts[i];
			arts[i] = arts[j];
			arts[j] = tmp;
			if (strcmp(arts[i]->name, arts[j]->name) == 0)
				j -= 1;
		}
		else
			break;
    }
    return (j);
}

void    quickSort(struct s_art **arts, int start, int end)
{
    int partition;

    if (start < end)
    {
        partition = find_partition(arts, start, end);
        quickSort(arts, start, partition);
        quickSort(arts, partition +1, end);
    }
}
void    sortArts(struct s_art **arts)
{
    int start = 0;
    int end = size_of_arr(arts) - 1;
    quickSort(arts, start, end);
}