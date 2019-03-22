/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quickSort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuradia <vmuradia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 17:43:49 by vmuradia          #+#    #+#             */
/*   Updated: 2019/03/21 18:37:10 by vmuradia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

//sorts in ascending, fix this bitch 

void	ft_swap(struct s_player **players, int a, int b)
{
	struct s_player *tmp;

	tmp =  players[a];
	players[a] = players[b];
	players[b] = tmp;
}

int partition(struct s_player **players, int low, int high)
{
	struct s_player *pivot;
	int 	i = low - 1;
	pivot = players[high];

	for (int j = low; j <= high - 1; j++)
	{
		if (players[j]->score <= pivot->score)
		{
			i++;
			ft_swap(players, i, j);
		}
	}
	ft_swap(players, i + 1, high);
	return (i + 1);
}

void sorting(struct s_player **players, int low, int high)
{
	int part;

	if (low < high)
	{
		part = partition(players, low, high); //divide
		sorting(players, low, part-1); //sort before deviding point
		sorting(players, part, high); //..and after
	}
}

void quickSort(struct s_player **players)
{
    int low = 0;
    int i = 0;
    while(players[i])
        i++;
    int high = i - 1;
    sorting(players, low, high);
}

