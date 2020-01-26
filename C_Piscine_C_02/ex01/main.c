/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 12:21:46 by jko               #+#    #+#             */
/*   Updated: 2020/01/26 18:42:20 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

char	*ft_strncpy(char *dest, char *src, unsigned int n);

int main(void)
{
	unsigned int n = 6;
	char src[6] = {'a', 'b', 'c', 'd', '\n', '\0'};
	char *dest = (char *) malloc(sizeof(char) * 6);
	char *dest2 = (char *) malloc(sizeof(char) * 6);

	dest2 = ft_strncpy(dest, src, n);
	write(1, dest, n);
	write(1, dest2, n);

	printf("\n");

	dest2 = strncpy(dest, src, n);
	write(1, dest, n);
	write(1, dest2, n);

	return (0);
}
