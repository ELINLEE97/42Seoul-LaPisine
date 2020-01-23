/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 20:12:27 by jko               #+#    #+#             */
/*   Updated: 2020/01/23 16:27:12 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print(int n, int nums[])
{
	char	c;
	int		i;

	i = 0;
	while (i < n)
	{
		c = nums[i] + 48;
		write(1, &c, 1);
		i++;
	}
	if (!(nums[0] == 10 - n && nums[n - 1] == 9))
	{
		c = ',';
		write(1, &c, 1);
		c = ' ';
		write(1, &c, 1);
	}
}

void	comb(int n, int m, int check[], int picked[])
{
	int i;

	if (n == m)
	{
		print(n, picked);
	}
	else
	{
		i = m;
		while (i <= 9)
		{
			if (check[i] == 0 && (m == 0 || picked[m - 1] < i))
			{
				picked[m] = i;
				check[i] = 1;
				comb(n, m + 1, check, picked);
				check[i] = 0;
			}
			i++;
		}
	}
}

void	ft_print_combn(int n)
{
	int check[10];
	int picked[10];
	int i;

	i = 0;
	while (i < 10)
	{
		check[i++] = 0;
	}
	comb(n, 0, check, picked);
}
