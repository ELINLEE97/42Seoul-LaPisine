/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 14:02:30 by jko               #+#    #+#             */
/*   Updated: 2020/02/09 16:11:03 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "dict.h"
#include "hash.h"
#include "file_to_hash.h"

# define DICT_FILE "numbers.dict"

#include <stdio.h>
#include "hash.h"

int		main(int argc, char **argv)
{
	char *key;
	char *file_name;
	
	if (argc > 3 || argc < 2)
		return (0);
	file_name = DICT_FILE;
	key = argv[1];
	if (argc == 3)
	{
		file_name = argv[1];
		key = argv[2];
	}
	t_dict **hash = read_file_and_make_hash(file_name);

	t_dict *result;
	result = get_dict(hash, "100");
	if (result == 0)
		printf("fail\n");
	else
		printf("success, %s, %s\n", result->key, result->value);

	free_hash(hash);
	return (0);
}
