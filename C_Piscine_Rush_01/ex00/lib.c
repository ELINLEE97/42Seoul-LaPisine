/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 12:13:22 by jko               #+#    #+#             */
/*   Updated: 2020/02/01 17:08:56 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	init_arr(int *arr, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		arr[i] = 0;
		i++;
	}
}

int		**malloc_arrs(void)
{
	int		i;
	int		**result;

	result = (int **)malloc(sizeof(int *) * 4);
	i = 0;
	while (i < 4)
		result[i++] = (int *)malloc(sizeof(int) * 4);
	return (result);
}

void	free_arrs(int **arrs)
{
	int i;

	i = 0;
	while (i < 4)
	{
		free(arrs[i]);
		i++;
	}
	free(arrs);
}
