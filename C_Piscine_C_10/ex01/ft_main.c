/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/07 14:48:42 by jko               #+#    #+#             */
/*   Updated: 2020/02/11 23:23:29 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

void	echo(void)
{
	char c;

	while (1)
	{
		while (read(0, &c, 1))
			write(1, &c, 1);
	}
}

int		main(int argc, char **argv)
{
	int		fd;
	char	buf[100];
	int		n;
	int		i;

	if (argc < 2)
		echo();
	else
	{
		i = 1;
		while (i < argc)
		{
			fd = open(argv[i], O_RDONLY);
			if (fd == 0)
				return (0);
			while ((n = read(fd, buf, 100)))
				write(1, buf, n);
			close(fd);
			i++;
		}
	}
	return (0);
}

Errno 사용하기:
