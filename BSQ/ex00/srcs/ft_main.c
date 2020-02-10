/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 12:11:13 by jko               #+#    #+#             */
/*   Updated: 2020/02/10 21:07:53 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "map.h"
#include "answer.h"

int	main(int argc, char **argv)
{
	int			i;
	t_map_info	*map_info;

	if (argc < 2)
	{
		write(1, "Life is 42!\n", 12);
		return (0);
	}
	i = 1;
	while (i < argc)
	{
		if ((map_info = read_map(argv[i])) == 0)
			return (-1);
		if (!is_valid_map(map_info))
		{
			write(1, "Map Error!\n", 12);
			free_map_info(map_info);
			i++;
			continue ;
		}


	}
	return (0);
}
