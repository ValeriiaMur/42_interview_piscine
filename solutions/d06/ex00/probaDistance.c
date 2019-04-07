/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   probaDistance.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuradia <vmuradia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 16:34:26 by vmuradia          #+#    #+#             */
/*   Updated: 2019/04/04 18:34:19 by vmuradia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

double probaDistance(double dist, int *locations, int n)
{
    double possible = 0;
    double total = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = i +1; j < n; j++)
        {
            total++;
            if (locations[i] - locations[j] > dist)
                possible++;
            if (locations[j] - locations[i] > dist)
                possible++;
        }
    }
    return (possible/total);
}
