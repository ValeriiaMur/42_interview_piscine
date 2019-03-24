/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   countSort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriiamuradian <valeriiamuradian@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 20:38:18 by valeriiamur       #+#    #+#             */
/*   Updated: 2019/03/23 21:21:31 by valeriiamur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <string.h>
#include <stdlib.h>
#define RANGE 16

void countSort(unsigned char *utensils, int n)
{
    unsigned char *res = malloc(n); //the sorted char array 
    int count[RANGE] = {0}; //init the array to store the num of unique chars
    int i = 0;

    for (i = 0; i < n; i++)
	       count[utensils[i] - 1]++;
    //store count of each char
    for (i = 1; i <= RANGE; i++) 
        count[i] += count[i-1]; 
    //build the final output array
    for (i = 0; i < n; i++) 
    { 
        res[count[utensils[i]-1]] = utensils[i]; 
        count[utensils[i] - 1]--; 
    } 
    for (i = 0; i < n; ++i) 
        utensils[i] = res[i]; 
    free(res);
}