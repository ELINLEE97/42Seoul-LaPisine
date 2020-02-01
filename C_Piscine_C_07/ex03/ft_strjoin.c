/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 12:42:35 by jko               #+#    #+#             */
/*   Updated: 2020/02/01 21:56:16 by jko              ###   ########.fr       */
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
		return (0);
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
