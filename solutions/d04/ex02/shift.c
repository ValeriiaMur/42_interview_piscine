/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shift.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: valeriiamuradian <valeriiamuradian@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 14:24:12 by valeriiamur       #+#    #+#             */
/*   Updated: 2019/04/02 09:31:17 by valeriiamur      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char *rightShift(char *bin, int k)
{
    for (int i = 5; i - k >= 0; i--)
			bin[i] = bin[i-k];
	for (int i = 0; i < k && i < 6; i++)
		bin[i] = '1';
	return bin;
}
char *leftShift(char *bin, int k)
{
    for (int i = 0; i < 6; i++)
		bin[i] = bin[i + k];
	for (int i = 5; i >= 0 && k > 0; i--,k--)
		bin[i] = '0';
	return bin;
}

int toInt(char *bits)
{
	int result = 0;
	int shift = 1;
	int neg = (bits[0] == '1') ? 1 : 0;

	for (int i = 5;i >= 1; i--)
	{
		result = result + shift * ((bits[i] == '1') ^ neg);
		shift = shift << 1;
	}
	return (neg) ? -result -1 : result;
}