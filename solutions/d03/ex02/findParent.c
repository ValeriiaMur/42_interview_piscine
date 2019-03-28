/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   findParent.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriiamuradian <valeriiamuradian@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 09:01:27 by valeriiamur       #+#    #+#             */
/*   Updated: 2019/03/28 14:46:57 by valeriiamur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#include <string.h>

struct s_node *findParent(struct s_node *root, char *firstSpecies, char *secondSpecies)
{
    struct s_node *tmp = NULL;
    int count = 0;

    if (!root)
        return NULL;
    if (!strcmp(root->name, secondSpecies) || !strcmp(root->name, secondSpecies)) 
        return (root);
    for (int i = 0;root->children[i]; i++)
    {
        struct s_node *res = findParent(root->children[i], firstSpecies, secondSpecies);
        if (res)
        {
            count++;
            tmp = res;
        } 
    }
    if (count == 2)
        return root;
    return tmp; 
}
