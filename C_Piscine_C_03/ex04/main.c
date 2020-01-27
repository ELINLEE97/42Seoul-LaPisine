/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 13:08:23 by jko               #+#    #+#             */
/*   Updated: 2020/01/27 18:26:24 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

char	*ft_strstr(char *str, char *to_find);

int		main(void)
{
	char str[30] = "";
	char to_find[10] = "a";

	printf("%s\n%s\n", ft_strstr(str, to_find), strstr(str, to_find));

	return (0);
}
