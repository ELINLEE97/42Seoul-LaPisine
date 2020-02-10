/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 12:11:13 by jko               #+#    #+#             */
/*   Updated: 2020/02/10 23:30:16 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "map_reader.h"
#include "map_validation.h"
#include "largest_square_finder.h"
#include "answer_printer.h"

char	solve(t_map_info *map_info)
{
	t_answer	*answer;

	if (!is_valid_map(map_info))
	{
		write(1, "Map Error!\n", 12);
		return (0);
	}
	if ((answer = find_largest_square(map_info)) == 0)
		return (-1);
	mark_largest_square(map_info, answer);
	print_answer(map_info);
	free(answer);
	write(1, "\n", 1);
	return (0);
}

int		main(int argc, char **argv)
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
		if (solve(map_info) != 0)
		{
			free_map_info(map_info);
			return (-1);
		}
		free_map_info(map_info);
		i++;
	}
	return (0);
}
