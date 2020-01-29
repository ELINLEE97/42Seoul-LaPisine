/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 18:18:15 by jko               #+#    #+#             */
/*   Updated: 2020/01/29 18:26:41 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int i;
	int *result;

	result = (int *)malloc(sizeof(int) * (max - min));
	i = 0;
	while (min < max)
	{
		result[i] = min + i;
		i++;
	}
	return (result);
}
