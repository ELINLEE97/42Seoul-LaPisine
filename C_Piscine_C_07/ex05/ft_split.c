/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 18:37:28 by jko               #+#    #+#             */
/*   Updated: 2020/01/31 15:07:35 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		str_cmp(char *s1, char *s2)
{

}

char	**ft_split(char *str, char *charset)
{
	char	**result;
	int		len;
	int		i;
	int		j;
	int		count;
	char	*copy_str;

	len = 0;
	while (str[len])
		len++;
	i = 0;
	copy_str = (char *)malloc(sizeof(char) * (len + 2));
	while (str[i])
		copy_str[i++] = str[i];
	copy_str[i++] = 0;
	copy_str[i] = -1;

	len = 0;
	while (charset[len])
		len++;
	i = 0;
	while (copy_str[i] > 0)
	{
		if (str_cmp(&copy_str[i], charset) == 0)
		{
			count++;
			j = i + len - 1;
			while (i < j)
				copy_str[i++] = 0;
		}
		i++;
	}

	result = (char **)malloc(sizeof(char *) * (len + 1));
	result[len] = 0;
	i = 0;

	for(int k = 0; copy_str[k] > 0; k++)
	{
		if (copy_str[k])
			printf("%c", copy_str[k]);
		else
			printf("\n", copy_str[k]);
	}

	return (0);
}
