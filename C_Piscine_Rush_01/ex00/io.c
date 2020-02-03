/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 16:44:10 by jko               #+#    #+#             */
/*   Updated: 2020/02/02 18:32:32 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		**malloc_arrs(void);
void	free_arrs(int **arrs);

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
			break ;
	}
	if (count == 16)
		return (result);
	free_arrs(result);
	return (0);
}

void	print_error(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(2, &str[i], 1);
		i++;
	}
	write(2, "\n", 1);
}

void	print_answer(int **ints)
{
	int		i;
	int		j;
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
