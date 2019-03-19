/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchPriceV2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuradia <vmuradia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 18:46:26 by vmuradia          #+#    #+#             */
/*   Updated: 2019/03/19 14:22:00 by vmuradia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <string.h>


int searchPrice(struct s_art **arts, int n, char *name)
{
    int low = 0;
    int mid;
    char *guess;
    int high = n -1;

    while(low <= high)
    {
        mid = (low+high) / 2;
        guess = arts[mid]->name;
        if (strcmp(name, guess) == 0)
            return(arts[mid]->price);
        if (strcmp(name, guess) > 0)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return (-1);
}