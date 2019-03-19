/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precious.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuradia <vmuradia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 15:29:42 by vmuradia          #+#    #+#             */
/*   Updated: 2019/03/19 16:11:56 by vmuradia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "header.h"
# include <stdlib.h>

void insert(struct s_node **head, char value)
{
    //if the head is empty, start with a single head node
    if (*head == NULL)
    {
        struct s_node *node = (struct s_node*)malloc(sizeof(struct s_node));
        node->c = value;
        node->next = node->prev = node;
        *head = node;
        return ;
	}
    //if the list is not empty 
    //Find last node first
    struct s_node *last = (*head)->prev;
    //create a new node
    struct s_node *node = (struct s_node*)malloc(sizeof(struct s_node));
    node->c = value;
    node->next = *head; // the head is going to be next of new_node
    (*head)->prev = node; //The new node is prevous of start
    node->prev = last; //Make last preivous of new node 
	last->next = node; //Make new node next of old last 
}

char *precious(int *text, int size)
{
    char *str = (char*)malloc(sizeof(char)* (size + 1));
    struct s_node *list = NULL;
    int move = 0;
    if (size < 0)
        return NULL;
    for (int i = 0; CS[i] != '\0'; i++)
        insert(&list, CS[i]);
    for(int i = 0; i < size; i++)
    {
        move = text[i];
        if ( move >= 0)
            while (move--)
                list = list->next;
        else
            while(move++)
                list = list->prev;
        str[i] = list->c;
    }
    return (str);
}