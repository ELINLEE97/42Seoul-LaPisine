/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 15:33:07 by jko               #+#    #+#             */
/*   Updated: 2020/02/03 20:29:41 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		get_base_number(char c, char *base)
{
	int i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

void	compact(char *arr, int interval)
{
	int i;

	i = 0;
	if (arr[0] == '-')
	{
		i++;
		interval--;
	}
	while (i + interval < 34)
	{
		arr[i] = arr[i + interval];
		i++;
	}
	arr[i] = '\0';
}
