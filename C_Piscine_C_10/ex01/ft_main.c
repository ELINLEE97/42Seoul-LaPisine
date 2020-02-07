/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 14:48:42 by jko               #+#    #+#             */
/*   Updated: 2020/02/07 15:52:59 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
	int fd;
	char buf[100];
	int n;

	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	if (fd == 0)
		return (0);
	while ((n = read(fd, buf, 100)))
		write(1, buf, n);
	write(1, "\n", 1);
	close(fd);
	return (0);
}
