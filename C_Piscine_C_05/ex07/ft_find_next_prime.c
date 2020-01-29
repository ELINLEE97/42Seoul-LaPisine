/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/29 12:47:56 by jko               #+#    #+#             */
/*   Updated: 2020/01/29 12:52:54 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_prime(int n)
{
	int i;
	int temp;

	if (n < 2)
		return (0);
	i = 2;
	temp = n / 2;
	while (i <= temp)
	{
		if (n % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	while (is_prime(nb) == 0)
		nb++;
	return (nb);
}
