/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   searchPrice.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuradia <vmuradia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 09:43:04 by vmuradia          #+#    #+#             */
/*   Updated: 2019/03/19 14:16:56 by vmuradia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "header.h"
# include <string.h>

int	searchPrice(struct s_art **arts, char *name)
{
	int i = 0;
	while(arts[i])
	{
		if (strcmp(arts[i]->name, name) == 0)
			return (arts[i]->price);
		arts++;
	}
	return (-1);
}