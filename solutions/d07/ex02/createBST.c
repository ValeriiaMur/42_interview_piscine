/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createBST.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuradia <vmuradia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 13:52:58 by vmuradia          #+#    #+#             */
/*   Updated: 2019/04/05 19:31:00 by vmuradia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "header.h"

struct s_node *createNew(int n)
{
    struct s_node *new = malloc(sizeof(struct s_node));
   
    new->value = n;
    new->left = NULL;
    new->right = NULL;
    
    return (new);
}

struct s_node *recursive(int *arr, int start, int end)
{
    int mid = start + (end - start) / 2;

    if (start > end)
        return NULL;
    struct s_node *new = createNew(arr[mid]);
    new->left = recursive(arr, start, mid - 1);
    new->right = recursive(arr, mid + 1, end);
    return (new);
}

struct s_node *createBST(int *arr, int n)
{
    if (n < 1 || !arr)
        return NULL;
    return recursive(arr, 0, n -1);
}