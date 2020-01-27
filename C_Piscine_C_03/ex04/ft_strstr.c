/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 13:09:16 by jko               #+#    #+#             */
/*   Updated: 2020/01/27 14:18:29 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	int		i;
	int		j;
	int		check;

	i = 0;
	while (str[i] != '\0')
	{
		j = 0;
		check = 1;
		while (str[i + j] != '\0' && to_find[j] != '\0')
		{
			if (str[i + j] != to_find[j])
			{
				check = 0;
				break ;
			}
			j++;
		}
		if (check == 1)
			return (str + i);
		i++;
	}
	return (0);
}
