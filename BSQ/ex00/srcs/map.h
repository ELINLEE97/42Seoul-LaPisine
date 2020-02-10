/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 18:56:52 by jko               #+#    #+#             */
/*   Updated: 2020/02/10 21:02:40 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

typedef struct	s_map_info
{
	int		line_num;
	char	blank;
	char	obs;
	char	mark;
	char	**map;
}				t_map_info;

t_map_info		*read_map(char *file_name);
t_map_info		*parse_map_info(char *info);
char			**get_map(char **lines);
void			free_map_info(t_map_info *map_info);

#endif
