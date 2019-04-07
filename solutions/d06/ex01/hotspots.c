/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hotspots.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuradia <vmuradia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 17:50:50 by vmuradia          #+#    #+#             */
/*   Updated: 2019/04/04 18:33:03 by vmuradia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int selectHotspots(struct s_hotspot **hotspots)
{
	if (!hotspots)
		return 0;
	int count = 1;
	int prev = 0;
	for (int i = 1; hotspots[i]; i++)
	{
        //compare two hotspots, begin with 1 and 0
		if (hotspots[i]->pos + hotspots[i]->radius < hotspots[prev]->pos + hotspots[prev]->radius)
			prev = i; //if less, just update previous
		else if (hotspots[i]->pos - hotspots[i]->radius >= hotspots[prev]->pos + hotspots[prev]->radius)
		{ 
            //if pos - rad more or equals, count and update
			count++;
			prev = i;
		}
        //if none, just keep comparing the next one with the old prev
	}
	return count;
}