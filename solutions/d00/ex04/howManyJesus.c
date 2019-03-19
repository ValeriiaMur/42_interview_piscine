/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   howManyJesus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuradia <vmuradia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 15:29:07 by vmuradia          #+#    #+#             */
/*   Updated: 2019/03/19 14:41:55 by vmuradia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <string.h>

int hash(char *string, int start, int end)
{
	int i = start;
	int total = 0;

	while (i <= end)
	{
		total += string[i];
		i++;
	}
	return (total);
}

int howManyJesus(char *bible, char *jesus)
{
	int totalJesus = 0;
	int jesus_len = strlen(jesus);
	int jesus_hash = hash(jesus, 0, jesus_len - 1);
	int curr_hash = 0;
	int l = 0;
	int r = 0;

	while(*(bible + r) && r < jesus_len) // Calculate the hash of window of text
	{
		curr_hash += bible[r];
		r++;
	}
	r--;
	while (*(bible + r)) // while in this wibdow
	{
		if (jesus_hash == curr_hash) // if hash match
		{
			if (strncmp(jesus, bible + l, jesus_len) == 0) // we found jesus!
				totalJesus++;
			l++;
			r++;
		}
		else // no jesus here :( move window in bible by one char
		{
			l++;
			r++;
			curr_hash -= bible[l - 1];
			curr_hash += bible[r];
		}
	}
	return (totalJesus);
}
