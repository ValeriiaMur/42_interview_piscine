/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compress.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuradia <vmuradia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 14:30:37 by vmuradia          #+#    #+#             */
/*   Updated: 2019/03/19 14:55:20 by vmuradia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "header.h"

#define PRIME 7

size_t hash(char *input)
{
    size_t len;
    size_t hash;
    size_t i;

    i = 0;
    hash = 0;
    len = strlen(input);
    while (i < len)
    {
        hash += pow(69, len - (i + 1)) * input[i];
        i++;
    }
    return (hash);
}

size_t			rehash(size_t old, int len, unsigned char rm, unsigned char add)
{
	size_t	new;
	new = old - pow(PRIME, len - 1) * rm;
	new = new * PRIME + add;
	return (new);
}

int				howManyJesus(char *bible, char *jesus)
{
	int		bible_len = strlen(bible);
	int		jesus_len = strlen(jesus);
	int		bible_hash = hash(bible);
	int		jesus_hash = hash(jesus);
	int		count = 0;

	for (int i = 0; i < bible_len - jesus_len + 1; i++)
	{
		if (bible_hash == jesus_hash)
			count++;
		bible_hash = rehash(bible_hash, jesus_len, bible[i], bible[i + jesus_len]);
	}
	return (count);
}

struct s_dict *dictInit(int capacity)
//initialize the dictionnary, given as parameter the capacity of the array.
{
    struct s_dict *my_dict;

    if (!(my_dict = (struct s_dict *)malloc(sizeof(struct s_dict))))
		return (NULL);
    my_dict->items = (struct s_item**)malloc(sizeof(struct s_item) * capacity);
    if (!(my_dict->items))
        return (NULL);
    my_dict->capacity = capacity;
    for (int i = 0; i < capacity; i++)
		my_dict->items[i] = NULL;
	return (my_dict);
} 

int	dictInsert(struct s_dict *dict, char *key, int value)
//add one item in the dictionnary, if FAIL return 0, otherwise 1
{

}
int	dictSearch(struct s_dict *dict, char *key)
//find one element in the dictionnary, if not found, return -1
{

}
