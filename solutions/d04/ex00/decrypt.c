/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decrypt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriiamuradian <valeriiamuradian@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/29 20:25:17 by valeriiamur       #+#    #+#             */
/*   Updated: 2019/04/01 12:58:50 by valeriiamur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

//0 + 0 = 0
//0 + 1 = 1
//1 + 0 = 1
//1 + 1 = 10 (which is 0 carry 1)

char *getSum(char *a, char *b)
{
    int add = 0;
	for(int i = 5; i >= 0; i--)
	{
		if (a[i] == '0' && b[i] == '0')
		{
			a[i] = add + '0';
			add = 0;
		}
		else if ((a[i] == '1' & b[i] == '0') || (a[i] == '0' && b[i] == '1'))
		{
			if (add)
			{
				a[i] = '0';
				add = 1;
			}
			else
			{
				a[i] = '1';
				add = 0;
			}

		}
		else
		{
			a[i] = add + '0';
			add = 1;
		}
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
        if (*start ++ == '1')
            total += 1;
    }
    return (total);
}