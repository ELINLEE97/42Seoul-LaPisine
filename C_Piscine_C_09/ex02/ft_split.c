/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 17:23:38 by jko               #+#    #+#             */
/*   Updated: 2020/02/03 18:25:46 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*str_cpy(char *str)
{
	char	*copy_str;
	int		len;
	int		i;

	len = 0;
	while (str[len])
		len++;
	copy_str = (char *)malloc(sizeof(char) * (len + 1));
	if (copy_str == 0)
		return (0);
	i = 0;
	while (str[i])
	{
		copy_str[i] = str[i];
		i++;
	}
	copy_str[i] = 0;
	return (copy_str);
}

int		replace_and_count(char *str, char *charset)
{
	int i;
	int j;
	int	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		j = 0;
		while (charset[j])
		{
			if (str[i] == charset[j])
			{
				str[i] = 0;
				if (i > 0 && str[i - 1] != 0)
					count++;
				break ;
			}
			j++;
		}
		i++;
	}
	if (i > 0 && str[i - 1] == 0)
		return (count);
	return (count + 1);
}

char	**make_result(char *str, int size, char **dest)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i] || j < size)
	{
		if ((i == 0 && str[i]) || (str[i] && str[i - 1] == 0))
		{
			dest[j] = str + i;
			j++;
		}
		i++;
	}
	dest[j] = 0;
	return (dest);
}

char	**ft_split(char *str, char *charset)
{
	char	**result;
	char	*copy_str;
	int		size;

	copy_str = str_cpy(str);
	if (copy_str == 0)
		return (0);
	size = replace_and_count(copy_str, charset);
	result = (char **)malloc(sizeof(char *) * (size + 1));
	if (result == 0)
		return (0);
	return (make_result(copy_str, size, result));
}
