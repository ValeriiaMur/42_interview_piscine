/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findShifted.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuradia <vmuradia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/24 17:38:38 by vmuradia          #+#    #+#             */
/*   Updated: 2019/03/24 18:29:54 by vmuradia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	search(int *rocks, int left, int right, int value)
{
	int mid = left + (right - left) / 2; // find middle p

	if (left > right)
		return -1;
	if (rocks[mid] == value) // if there, return it
		return mid;
	if (rocks[left] <= rocks[mid]) //if this half is sorted
	{
		if (rocks[left] <= value && value <= rocks[mid]) // if the value is here, search here
			return search(rocks, left, mid - 1, value);
		else // or here
			return search(rocks, mid + 1, right, value);
	}
	else //(arr[mid+1..r] must be sorted
	{
		if (rocks[mid] <= value && value <= rocks[right])
			return search(rocks, mid + 1, right, value);
		else
			return search(rocks, left, mid - 1, value);
	}
}

int searchShifted(int *rocks, int length, int value)
{
	int start = search(rocks, 0, length - 1, value);
	if (start == -1)
		return -1;
	while (start >= 0 && rocks[start] == value)
		start--;
	return start + 1;
}