/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchPriceV3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuradia <vmuradia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 19:11:28 by vmuradia          #+#    #+#             */
/*   Updated: 2019/03/19 14:50:00 by vmuradia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

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
        hash += pow(69, len - (i + 1)) * input[i]; //The pow() function computes the power of a number.
        i++;
    }
    return (hash);
}

struct s_dict		*dictInit(int capacity) // malloc space for all the items
{
	struct s_dict	*ret;

	ret = (struct s_dict*)malloc(sizeof(struct s_item*));
	ret->items = (struct s_item**)malloc(sizeof(struct s_item*) * capacity);
	ret->capacity = capacity;
	for (int i = 0; i < capacity; i += 1)
		ret->items[i] = NULL;
	return (ret);
}

int					dictInsert(struct s_dict *dict, char *key, 
								struct s_art *value)
{
	struct s_item	*curr;

	if (dict->items[hash(key) % dict->capacity] != NULL)
	{
		curr = dict->items[hash(key) % dict->capacity];
		while (curr->next != NULL)
		{
			if (strcmp(curr->key, key) == 0)
			{
				curr->value = value;
				return (1);
			}
		curr = curr->next;
		}
	curr->next = (struct s_item*)malloc(sizeof(struct s_item));
	curr = curr->next;
	}
	else
	{
		dict->items[hash(key) % dict->capacity] = malloc(sizeof(struct s_item));
		curr = dict->items[hash(key) % dict->capacity];
	}
	if (curr == NULL)
		return (0);
	curr->value = value;
	curr->key = strdup(key);
	curr->next = NULL;
	return (1);
}

struct s_art		*dictSearch(struct s_dict *dict, char *key)
{
	struct s_item	*current;

	if (dict != NULL && key != NULL)
	{
		current = dict->items[hash(key) % dict->capacity];
		while (current)
		{
			if (!strcmp(current->key, key))
				return (current->value);
			current = current->next;
		}
	}
	return (NULL);
}

int					searchPrice(struct s_dict *dict, char *name)
{
	struct s_art	*search;

	search = dictSearch(dict, name);
    if (search != NULL)
        return (search->price);
    else
        return (-1);
}