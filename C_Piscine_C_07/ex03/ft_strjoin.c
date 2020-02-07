/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 12:42:35 by jko               #+#    #+#             */
/*   Updated: 2020/02/05 15:55:06 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		get_length(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		str_cat(char *dest, int index, char *src)
{
	int i;

	i = 0;
	while (src[i])
	{
		dest[index + i] = src[i];
		i++;
	}
	return (index + i);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		j;
	int		length;
	char	*result;

	if (size == 0)
	{
		result = (char *)malloc(sizeof(char) * 1);
		result[0] = 0;
		return (result);
	}
	length = get_length(sep) * (size - 1);
	i = 0;
	while (i < size)
		length += get_length(strs[i++]);
	result = (char *)malloc(sizeof(char) * (length + 1));
	i = 0;
	j = 0;
	while (i < size)
	{
		j = str_cat(result, j, strs[i]);
		if (i < size - 1)
			j = str_cat(result, j, sep);
		i++;
	}
	result[j] = '\0';
	return (result);
}
