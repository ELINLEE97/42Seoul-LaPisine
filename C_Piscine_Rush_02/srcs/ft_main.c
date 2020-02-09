/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 14:02:30 by jko               #+#    #+#             */
/*   Updated: 2020/02/08 22:07:12 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

#include "dict.h"
#include "ft_string.h"
#include "dict_parser.h"
#include "dict.h"
#include "hash.h"

# define DICT_FILE "numbers.dict"
# define TRUE 1
# define FALSE 0


#include <stdio.h>

int		main(int argc, char **argv)
{

	argc++;
	printf("%s\n", argv[0]);


	t_dict	**hash;
	hash = (t_dict **)malloc(sizeof(t_dict *) * BIG_PRIME_NUM);
	if (hash == 0)
		return (1);
	init_hash(hash);

	char **parsing_result = parse_line("   50  :  fea  \n");
	if (parsing_result == 0)
	{
		printf("parsing error\n");
		return (0);
	}
	printf("p k = %s\np v = %s\n", parsing_result[0], parsing_result[1]);
	t_dict *new_dict = make_dict(parsing_result[0], parsing_result[1]);
	put_dict(hash, new_dict);
	t_dict *result;

	result = get_dict(hash, parsing_result[0]);
	if (result == 0)
		printf("fail\n");
	else
		printf("success, %s, %s\n", result->key, result->value);

	result = get_dict(hash, "1");
	if (result == 0)
		printf("fail, %s\n", "1");
	else
		printf("success, %s, %s\n", result->key, result->value);


	free_hash(hash);
	return (0);
}
