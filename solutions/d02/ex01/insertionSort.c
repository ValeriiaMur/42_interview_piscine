/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insertionSort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuradia <vmuradia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 17:10:11 by vmuradia          #+#    #+#             */
/*   Updated: 2019/03/21 17:42:52 by vmuradia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <unistd.h>

// Algorithm:
// Sort an arr[] of size n
// insertionSort(arr, n)
// Loop from i = 1 to n-1.
// ……a) Pick element arr[i] and insert it into sorted sequence arr[0…i-1]

// Insertion sort is essentially placing unsorted elements into correct spot in sorted.
// Selection is sorting by putting smallest/largest into sorted..
// Bubble is swapping and letting largest/smallest bubble to top, then swapping until no more swaps.

void	insertionSort(struct s_player **players)
{
	int	i = 1; //start at index[1]
    int j = 0;
	struct 		s_player	*player;

	i = 0;
	while (players[++i]) // while we have an array
	{
		player = players[i]; // take a player
		j = i;
		while (--j >= 0 && players[j]->score < player->score) //compare his score w/ previous
        {
			players[j + 1] = players[j]; //while its less than the next one keep moving
		}
		players[j + 1] = player;
	}
}