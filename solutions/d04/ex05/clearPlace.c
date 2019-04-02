/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clearPlace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriiamuradian <valeriiamuradian@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 10:21:22 by valeriiamur       #+#    #+#             */
/*   Updated: 2019/04/02 10:23:51 by valeriiamur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int clearPlace(unsigned int parkingRow, int pos)
{
    return (parkingRow &= ~(1 << pos));
}