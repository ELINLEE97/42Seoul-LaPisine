/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   largest_square_finder.h                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mihykim <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 22:32:31 by mihykim           #+#    #+#             */
/*   Updated: 2020/02/10 23:08:41 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LARGEST_SQUARE_FINDER_H
# define LARGEST_SQUARE_FINDER_H

# include "map_reader.h"

typedef struct	s_answer
{
	int	row;
	int	col;
	int size;
}				t_answer;

int				**prepare_note(t_map_info *info, int len);
int				get_value(int **note, t_map_info *info, int r, int c);
t_answer		*find_answer_point(int **note, t_map_info *info, int len);
t_answer		*find_largest_square(t_map_info *info);

#endif
