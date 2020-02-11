/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stdin_reader.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/11 17:32:47 by jko               #+#    #+#             */
/*   Updated: 2020/02/11 17:59:41 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STDIN_READER_H
# define STDIN_READER_H

# include "map_reader.h"

char		*read_line_from_stdin(void);
char		**read_map_from_stdin(int size);
t_map_info	*read_map_info_from_stdin(char *void_param);

#endif
