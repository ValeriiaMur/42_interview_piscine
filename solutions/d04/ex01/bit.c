/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriiamuradian <valeriiamuradian@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 13:41:56 by valeriiamur       #+#    #+#             */
/*   Updated: 2019/04/01 14:13:51 by valeriiamur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

// This sign '~' invert bits so we check for that 

char *getNeg(char *a)
{
    for (int i = 0; i < 4; i++)
    {
        if (a[i] == '1')
            a[i] = '0';
        else
            a[i] = '1';
    }
    return (a);
}

//The result of AND is 1 only if both bits are 1. If either is 0, it's 0

char *getAnd(char *a,char *b)
{
	a = (a[0] == '~') ? getNeg(a+1) : a;
	b = (b[0] == '~') ? getNeg(b+1) : b;
	for (int i = 0; i < 4; i++)
		a[i] = (a[i] == '0'|| b[i] == '0') ? '0': a[i];
	return a;
}

//The result of OR is 1 any of the two bits is 1. 

char *getOr(char *a,char *b)
{
	a = (a[0] == '~') ? getNeg(a + 1) : a;
	b = (b[0] == '~') ? getNeg(b + 1) : b;
	for (int i = 0; i < 4; i++)
		a[i] = (a[i] == '1'|| b[i] == '1') ? '1': a[i];
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