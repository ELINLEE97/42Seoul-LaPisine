/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 18:19:20 by jko               #+#    #+#             */
/*   Updated: 2020/02/10 21:02:29 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "read_file.h"
#include "map_info.h"
#include "ft_string_h"

t_map_info		*read_map(char *file_name)
{
	t_map_info map_info;
	char **lines;

	if ((lines = read_file(file_name)))
		return (0);
	if ((map_info = parse_map_info(lines[0])))
		return (0);
	if ((map_info->map = get_map(lines + 1)) == 0)
	{
		free_map_info(map_info);
		free_strs(lines, 0);
		return (0);
	}
	free(lines[0]);
	free(lines);
	return (map_info);
}

char		**get_map(char **lines)
{
	char	**map;
	int		i;

	i = 0;
	while (lines[i])
		i++;
	if ((lines = (char **)malloc(sizeof(char *) * (i + 1))) == 0)
		return (0);
	i = 0;
	while (line[i])
	{
		map[i] = lines[i];
		i++;
	}
	return (map);
}

t_map_info	*parse_map_info(char *info)
{
	t_map_info	*map_info;
	int			len;

	len = 0;
	while (info[len])
		len++;
	if (len < 4)
		return (0);
	if ((map_info = (t_map_info *)malloc(sizeof(t_map_info)) == 0))
		return (0);
	map_info->mark = info[--len];
	map_info->obs = info[--len];
	map_info->blank = info[--len];
	info[len] = 0;
	map_info->line_num = ft_atoi(info);
	map_info->map = 0;
	return (map_info);
}

void		free_map_info(t_map_info *map_info)
{
	free_strs(map_info->map, 0);
	free(map_info);
}
