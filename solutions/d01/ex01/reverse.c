/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuradia <vmuradia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 16:21:34 by vmuradia          #+#    #+#             */
/*   Updated: 2019/03/19 17:50:48 by vmuradia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <unistd.h>
#include <stdio.h>

void printReverse(struct s_node *lst)
{
    if (lst == NULL) // Base case for recusrion
        return ;
    printReverse(lst->next); //print the list after head node
    if(lst->next) //if not first
	    printf(" %s", lst->word);
    else
	    printf("%s", lst->word); // print first word with no space before
}