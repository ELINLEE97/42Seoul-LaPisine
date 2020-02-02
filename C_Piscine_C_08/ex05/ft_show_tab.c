/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/02 15:55:16 by jko               #+#    #+#             */
/*   Updated: 2020/02/02 16:06:32 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void				print_str(char *str)
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

void				recursive_print_int(int n)
{
	char temp;

	temp = n % 10 + '0';
	if (n >= 10)
		recursive_print_int(n / 10);
	write(1, &temp, 1);
}

void				print_int(int n)
{
	recursive_print_int(n);
	write(1, "\n", 1);
}

void				ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str)
	{
		print_str(par[i].str);
		print_int(par[i].size);
		print_str(par[i].copy);
		i++;
	}
}
