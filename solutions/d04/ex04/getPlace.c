/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getPlace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriiamuradian <valeriiamuradian@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 09:52:10 by valeriiamur       #+#    #+#             */
/*   Updated: 2019/04/02 10:16:15 by valeriiamur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int getPlace(unsigned int parkingRow, int pos)
{
    return (parkingRow >> pos) & 1;
}

// First, shift to get the needed pos at the end. Doing (num & 1) 
// checks if the last bit (least significant bit) of the number is set.
// If it is set, the number is odd, and if it is not set, it is even.