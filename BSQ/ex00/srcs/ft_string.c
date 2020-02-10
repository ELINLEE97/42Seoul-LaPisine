/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 19:00:01 by jko               #+#    #+#             */
/*   Updated: 2020/02/10 21:12:06 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	free_strs(char **strs, int size)
{
	int i;

	i = 0;
	if (size <= 0)
	{
		while (strs[i])
			free(strs[i++]);
	}
	else
	{
		while (i < size)
			free(strs[i++]);
	}
	free(strs);
}

int		ft_strlen(char *str)
{
	int len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}
