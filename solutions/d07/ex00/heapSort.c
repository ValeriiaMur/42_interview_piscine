/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heapSort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuradia <vmuradia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 13:12:37 by vmuradia          #+#    #+#             */
/*   Updated: 2019/04/05 13:31:04 by vmuradia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <string.h>

void swap(struct s_art *a, struct s_art *b)
{
    struct s_art tmp = *a;
    *a = *b;
    *b = tmp;
}

//The heapify procedure calls itself recursively to build heap in top down manner.

void heapify(struct s_art **masterpiece, int n, int i)
{
    int largest = i; //init largest to compare
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    //if left is larger than largest
    if (left < n && strcmp(masterpiece[left]->name, masterpiece[largest]->name) > 0)
        largest = left;
    //if right is larger that the largest we have
    if (right < n && strcmp(masterpiece[right]->name, masterpiece[largest]->name) > 0)
        largest = right;
    //if largest not what we have (i), then swap!
    if (largest != i)
    {
        swap(masterpiece[i], masterpiece[largest]);
        //recursively keep heapifying the rest
        heapify(masterpiece, n, largest);
    }
}

void heapSort(struct s_art **masterpiece, int n)
{
    //rearrange array (building heap)
    for (int i = n/ 2 -1; i >= 0; i --)
        heapify(masterpiece, n, i);
    //Now, extract elements from heap one by one starting at the end
    for (int i = n-1; i >= 0; i--)
    {
        //move current value to the 0 pos
        swap(masterpiece[0], masterpiece[i]);
        //heapify the reduced heap 
        heapify(masterpiece, i, 0);
    }
}