/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 18:37:28 by jko               #+#    #+#             */
/*   Updated: 2020/01/30 21:18:12 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		str_cmp(char *s1, char *s2)
{

}

char	**ft_split(char *str, char *charset)
{
	char	**result;
	int		len;
	int		i;

	len = 0;
	while (charset[len])
		len++;
	i = 0;
	while (str[i])
	{
		if (str_cmp(&str[i], charset) == 0)
		{

		}
		i++;
	}

}
