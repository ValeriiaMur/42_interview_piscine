/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   possibleSlices.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuradia <vmuradia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 11:33:03 by vmuradia          #+#    #+#             */
/*   Updated: 2019/04/03 12:05:56 by vmuradia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void    solve_recursively(struct s_array *res, int slice)
{
    struct s_array *tmp;
    if (slice == 0)
        arrayPrint(res);
    for (int i = slice; i > 0; i--)
    {
        tmp = arrayClone(res);
        arrayAppend(tmp, i);
        solve_recursively(tmp, slice - i);
    }
}


void printPossibleSlices(int pizzaSize)
{
    struct s_array *res = arrayInit();
    solve_recursively(res, pizzaSize);
}



