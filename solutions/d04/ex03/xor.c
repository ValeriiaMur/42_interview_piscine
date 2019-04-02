/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xor.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriiamuradian <valeriiamuradian@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 09:33:26 by valeriiamur       #+#    #+#             */
/*   Updated: 2019/04/02 09:45:26 by valeriiamur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

//exclusive OR gives one only if 2 bits are opposite

char *getXor(char *a, char *b)
{
    for (int i = 0; i < 6; i++)
	{
        if (a[i] == b[i])
            a[i] = '0';
        else
            a[i] = '1';
    }
	return a;
}

int toInt(char *bits)
{
    char *start = &bits[0];
    int total = 0;
    while (*start)
    {
        total *= 2;
        if (*start++ == '1')
            total += 1;
    }
    return (total);
}