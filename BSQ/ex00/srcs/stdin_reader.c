/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdin_reader.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 12:50:00 by jko               #+#    #+#             */
/*   Updated: 2020/02/11 21:27:41 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_string.h"
#include "map_reader.h"

char		*read_line_from_stdin(void)
{
	char	buf[50];
	char	*result;
	int		len;

	result = 0;
	len = 0;
	while ((len = read(0, buf, 50)))
	{
		result = ft_strdup_and_strcat(result, buf, len);
		if (buf[len - 1] == '\n')
			break ;
	}
	return (result);
}

char		**read_map_from_stdin(int size)
{
	char	**lines;
	char	*line;
	int		i;

	if ((lines = (char **)malloc(sizeof(char *) * (size + 1))) == 0)
		return (0);
	i = 0;
	while (i < size)
	{
		if ((line = read_line_from_stdin()) == 0)
		{
			free_strs(lines, i);
			return (0);
		}
		lines[i] = line;
		i++;
	}
	lines[i] = 0;
	return (lines);
}

t_map_info	*read_map_info_from_stdin(char *void_param)
{
	t_map_info	*map_info;
	char		*line;

	void_param++;
	if ((line = read_line_from_stdin()) == 0)
		return (0);
	if ((map_info = parse_map_info(line)) == 0)
	{
		free(line);
		return (0);
	}
	free(line);
	if ((map_info->map = read_map_from_stdin(map_info->line_num)) == 0)
	{
		free(map_info);
		return (0);
	}
	return (map_info);
}
