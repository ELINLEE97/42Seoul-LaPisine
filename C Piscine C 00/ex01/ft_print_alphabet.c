/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testmain.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 15:14:43 by jko               #+#    #+#             */
/*   Updated: 2020/01/22 15:36:53 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);
void	ft_print_alphabet(void);

void	ft_print_alphabet(void)
{
	char c;

	c = 'a';
	while (c != 'z')
	{
		ft_print(c);
		c++;
	}
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
