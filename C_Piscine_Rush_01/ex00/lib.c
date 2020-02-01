/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 12:13:22 by jko               #+#    #+#             */
/*   Updated: 2020/02/01 16:07:00 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

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

int		**split_inputs(char *inputs)
{
	int		**result;
	int		i;
	int		count;

	result = malloc_arrs();
	i = 0;
	count = 0;
	while (inputs[i])
	{
		if (inputs[i] >= '1' && inputs[i] <= '4')
		{
			result[count / 4][count % 4] = inputs[i] - '0';
			i++;
			count++;
		}
		else if (inputs[i] == ' ')
			i++;
		else
		{
			free_arrs(result);
			return (0);
		}
	}
	if (count != 16)
	{
		free_arrs(result);
		return (0);
	}
	return (result);
}

void	print_str(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

void	print_ints(int **ints)
{
	int 	i;
	int 	j;
	char	temp[2];

	temp[0] = ' ';
	i = 0;
	while (i < 4)
	{
		temp[1] = ints[i][0] + '0';
		write(1, &temp[1], 1);
		j = 1;
		while (j < 4)
		{
			temp[1] = ints[i][j] + '0';
			write(1, &temp, 2);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
