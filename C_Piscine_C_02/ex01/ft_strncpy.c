/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 11:24:53 by jko               #+#    #+#             */
/*   Updated: 2020/01/26 16:45:02 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	int nn;
	int check;

	check = 0;
	nn = (int)n;
	while (--nn >= 0)
	{
		if (check == 1 || src[nn] == '\0')
		{
			dest[nn] = '\0';
			check = 1;
		}
		else
			*(dest + nn) = *(src + nn);
	}
	return (dest);
}
