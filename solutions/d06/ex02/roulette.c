/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   roulette.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vmuradia <vmuradia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 18:43:29 by vmuradia          #+#    #+#             */
/*   Updated: 2019/04/04 19:02:37 by vmuradia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

double probabilityWin(double firstDollarsBet, double dollarsWanted, int nbGame)
{
    if (nbGame < 0 || firstDollarsBet == 0)
        return 0;
    if (firstDollarsBet >= dollarsWanted) // if he has enough - stops
        return 1;
   	double red = 18.0 / 37.0 * probabilityWin(2 * firstDollarsBet, dollarsWanted, nbGame - 1);
    //18 red pockets out of 37 total + recursion (if red - > doubles)
	double green = 1.0 / 37.0 * probabilityWin(firstDollarsBet/ 2.0, dollarsWanted, nbGame - 1);
    //1 green pocket out of 37 + recursiion - green cuts in two
	return red + green;
}