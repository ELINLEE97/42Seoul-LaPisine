/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 18:37:28 by jko               #+#    #+#             */
/*   Updated: 2020/02/02 11:58:08 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		str_cmp(char *s1, char *s2, int n)
{
	int i;

	i = 0;
	while (s1[n + i] && s2[i] && s1[n + i] == s2[i])
		i++;
	if (s2[i] == 0)
		return (1);
	return (0);
}

int		get_count(char *str, char *charset, int len)
{
	int i;
	int count;

	count = 0;
	i = 0;
	if (!str_cmp(str, charset, i++))
		count++;
	while (str[i])
	{
		if (str_cmp(str, charset, i))
		{
			count++;
			i += len - 1;
		}
		i++;
	}
	return (count);
}

void	str_cpy(int *index, char **result, char *str)
{
	int i;

	result[index[1]] = (char *)malloc(sizeof(char) * (index[3] - index[2] + 1));
	i = 0;
	while (index[2] + i < index[3])
	{
		result[index[1]][i] = str[index[2] + i];
		i++;
	}
	result[index[1]][i] = 0;
	index[1]++;
}

void	init_arr(void *arr, int size, int type)
{
	char	**temp1;
	int		*temp2;
	int		i;

	i = 0;
	if (type == 0)
	{
		temp1 = (char **)arr;
		while (i < size)
			temp1[i++] = 0;
	}
	else
	{
		temp2 = (int *)arr;
		while (i < size)
			temp2[i++] = 0;
	}
}

char	**ft_split(char *str, char *charset)
{
	char	**result;
	int		index[4];

	index[0] = 0;
	while (charset[index[0]])
		index[0]++;
	index[1] = get_count(str, charset, index[0]);
	result = (char **)malloc(sizeof(char *) * (index[1] + 1));
	init_arr(result, index[1] + 1, 0);
	result[index[1]] = 0;
	init_arr(index + 1, 3, 1);
	while (str[index[3]])
		if (str_cmp(str, charset, index[3]))
		{
			if (index[2] < index[3])
				str_cpy(index, result, str);
			index[3] += index[0];
			index[2] = index[3];
		}
		else
			index[3]++;
	if (index[2] != index[3])
		str_cpy(index, result, str);
	return (result);
}
