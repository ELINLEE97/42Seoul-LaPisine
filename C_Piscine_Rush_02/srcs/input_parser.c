/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_parser.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 22:08:10 by jko               #+#    #+#             */
/*   Updated: 2020/02/08 23:19:10 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dict.h"
#include "hash.h"
#include "ft_string.h"

void	print_dict(t_dict *dict)
{
	int		len;;
	char	*temp;

	temp = dict->value;
	i = 0;
	while (temp[len])
		len++;
	write(1, temp, len);
}

char	find_dict_and_print(t_dict **hash, char *str)
{
	t_dict	*result;

	result = get_dict(hash, str);
	if (result == 0)
		return (0);
	print_dict(result);
	return (1);
}

char	*first_num_and_zeros(char first, int len)
{
	int		i;
	char	*result;

	result = (char *)malloc(sizeof(char) * (len + 1));
	if (result == 0)
		return (0);
	i = 0;
	result[i++] = first;
	while (i < len)
		result[i++] = '0';
	result[i] = 0;
	return (result);
}

void	hundred(char *str, int len, t_dict **hash)
{
	char	*temp;

	while (len > 0)
	{
		temp = ft_strdup(str, 0, len);
		if (!find_dict_and_print(hash, temp))
		{
			free(temp);
			return ;
		}
		free(temp);
		temp = first_num_and_zeros(str, 1);
		result(
		len--;
	}



void	find_dict(char *str, int len, t_dict **hash)
{
	t_dict	*result;
	int		i;
	int		len;

	i = 0;
	while (str[i])
	{
		if (result = get_dict(hash, str))
		{
			result = 
		}
		else
		{

		}

}
