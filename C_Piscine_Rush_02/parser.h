/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 20:13:47 by jko               #+#    #+#             */
/*   Updated: 2020/02/08 20:18:01 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

int		get_len_space_end(char *str, int start);
int		get_len_newline_end(char *str, int start);
int		pass_whitespace(char *str, int start);
int		pass_whitespace_and_colon(char *str, int start);
char	**parse_line(char *str);

#endif
