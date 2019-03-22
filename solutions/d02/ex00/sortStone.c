/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sortStone.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuradia <vmuradia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 17:25:19 by vmuradia          #+#    #+#             */
/*   Updated: 2019/03/21 16:06:19 by vmuradia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <stdlib.h>

void	ft_swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
//Optimized Implementation:
//Bubble sort always runs O(n^2) time even if the array is sorted. 
//It can be optimized by stopping the algorithm if inner loop didn’t 
//cause any swap. Now its O(n*n)

void sortStones(struct s_stone **stone)
{
    int i;
    int j;
    struct s_stone *ptr;
    struct s_stone *moving;
    int swapped = 0;
    int sorted;
    while (!sorted)
    {
        sorted = 1;
        swapped = 0;
        ptr = *stone;
        while( ptr!= NULL && ptr->next != NULL)
        {
            moving = ptr;
            ptr = ptr->next;
            if (moving->size > ptr->size)
            {
                ft_swap(&moving->size, &ptr->size);
                swapped = 1;
                sorted = 0;
            }
        }
         // IF no two elements were swapped by inner loop, then break 
        if (swapped == 0) 
            break; 
    }

}