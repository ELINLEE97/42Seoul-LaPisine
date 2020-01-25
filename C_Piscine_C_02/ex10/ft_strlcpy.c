/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 14:15:54 by jko               #+#    #+#             */
/*   Updated: 2020/01/25 14:44:30 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	int index;
	int int_size;

	index = 0;
	int_size = (int)size;
	while (index < int_size - 1 && src[index] != '\0')
	{
		dest[index] = src[index];
		index++;
	}
	if (index == int_size - 1)
	dest[index] = '\0';
	return (index);
}
