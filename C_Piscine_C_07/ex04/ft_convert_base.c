/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 14:30:33 by jko               #+#    #+#             */
/*   Updated: 2020/02/03 20:29:37 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		get_base_number(char c, char *base);

void	compact(char *arr, int interval);

int		get_length(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		is_valid(char *base, int len)
{
	int i;
	int j;

	if (len < 2)
		return (0);
	i = 0;
	while (i < len)
	{
		if (base[i] == '+' || base[i] == '-'
				|| base[i] == ' ' || (base[i] >= 9 && base[i] <= 13))
			return (0);
		j = i + 1;
		while (j < len)
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

long	base_to_int(char *nbr, char *base)
{
	int		count;
	int		i;
	long	result;

	i = 0;
	while ((nbr[i] >= 9 && nbr[i] <= 13) || nbr[i] == ' ')
		i++;
	count = 0;
	while (nbr[i] == '+' || nbr[i] == '-')
		if (nbr[i++] == '-')
			count++;
	if (get_base_number(nbr[i], base) < 0)
		return (2147483648);
	result = get_base_number(nbr[i++], base);
	while (get_base_number(nbr[i], base) >= 0)
		result = result * 10 + get_base_number(nbr[i++], base);
	if (count % 2 == 0)
		return (result);
	return (result * (-1));
}

char	*int_to_base(long nbr, char *base, int len)
{
	char	*result;
	int		i;

	result = (char *)malloc(sizeof(char) * 34);
	result[33] = '\0';
	if (nbr < 0)
	{
		result[0] = '-';
		nbr = nbr * (-1);
	}
	i = 33;
	while (nbr / len)
	{
		result[i] = base[nbr % len];
		nbr /= len;
		i--;
	}
	result[i] = base[nbr % len];
	compact(result, i);
	return (result);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		len_from;
	int		len_to;
	long	temp;

	len_from = get_length(base_from);
	len_to = get_length(base_to);
	if (!is_valid(base_from, len_from) || !is_valid(base_to, len_to))
		return (0);
	temp = base_to_int(nbr, base_from);
	if (temp > 2147483647 || temp < -2147483648)
		return (0);
	return (int_to_base(temp, base_to, len_to));
}
