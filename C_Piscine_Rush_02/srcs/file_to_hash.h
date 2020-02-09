/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_hash.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 15:56:45 by jko               #+#    #+#             */
/*   Updated: 2020/02/09 16:03:44 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_TO_HASH_H
# define FILE_TO_HASH_H

int		parse_and_put_dict(t_dict **hash, char **lines);
t_dict	**read_file_and_make_hash(char *file_name);
t_dict	**change_dict_file(char *file_name, t_dict **hash);

#endif
