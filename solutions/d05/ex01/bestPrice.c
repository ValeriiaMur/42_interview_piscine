/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bestPrice.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuradia <vmuradia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 13:04:54 by vmuradia          #+#    #+#             */
/*   Updated: 2019/04/03 13:23:42 by vmuradia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	recursion(int pizzaSize, double *best, double sum, double *prices)
{
	if (pizzaSize <= 0)
		if (sum > *best)
			*best = sum;
	for (int i = 1; i <= pizzaSize; i++)
		recursion(pizzaSize - i, best, sum + prices[i], prices);
}

double bestPrice(int pizzaSize, double *prices)
{
	double bestPrice = 0;
	recursion(pizzaSize, &bestPrice, 0, prices);
	return (bestPrice);
}
