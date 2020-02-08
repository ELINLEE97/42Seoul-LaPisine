/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 14:02:30 by jko               #+#    #+#             */
/*   Updated: 2020/02/08 18:21:41 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

# define DICT_FILE "numbers.dict"
# define BIG_PRIME_NUM 4999
# define TRUE 1
# define FALSE 0

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

typedef struct	s_dict {
	char			*key;
	char			*value;
	struct s_dict	*next;
}				t_dict;

t_dict	*make_dict(char *key, char *value)
{
	t_dict	*new_dict;

	new_dict = (t_dict *)malloc(sizeof(t_dict));
	if (new_dict == 0)
		return (0);
	new_dict->key = key;
	new_dict->value = value;
	new_dict->next = 0;
	return (new_dict);
}

void	free_dict(t_dict *dict)
{
	free(dict->key);
	free(dict->value);
	dict->next = 0;
	free(dict);
}

t_dict	*add_dict_list(t_dict *head, t_dict *new_dict)
{
	t_dict *curr;

	if (head == 0)
		return (new_dict);
	curr = head;
	while (curr->next)
		curr = curr->next;
	curr->next = new_dict;
	return (head);
}

t_dict	*find_dict_in_list(t_dict *head, char *key)
{
	t_dict	*curr;

	if (head == 0)
		return (0);
	if (ft_strcmp(head->key, key) == 0)
		return (head);
	curr = head;
	while (curr->next)
	{
		if (ft_strcmp(curr->key, key) == 0)
			return (curr);
		curr = curr->next;
	}
	return (0);
}

void	free_dict_list(t_dict *head)
{
	t_dict *curr;
	t_dict *temp;

	if (head == 0)
		return ;
	curr = head;
	while (curr->next)
	{
		temp = curr;
		curr = curr->next;
		free_dict(temp);
	}
	free(head);
}

int	get_hash_index(char *str)
{
	int result;
	int i;

	if (!str[0])
		return (-1);
	result = str[0];
	i = 0;
	while (str[i])
	{
		result = (result * 10 % BIG_PRIME_NUM)
			+ ((str[i] - '0') % BIG_PRIME_NUM);
		result %= BIG_PRIME_NUM;
		i++;
	}
	return (result);
}

void	init_hash(t_dict **hash)
{
	int i;

	i = 0;
	while (i < BIG_PRIME_NUM)
	{
		hash[i] = 0;
		i++;
	}
}

t_dict	*put_dict(t_dict **hash, t_dict *new_dict)
{
	int 	hash_index;

	hash_index = get_hash_index(new_dict->key);
	if (hash_index == -1)
		return (0);
	if (hash[hash_index] == 0)
	{
		hash[hash_index] = new_dict;
		return (new_dict);
	}
	return (add_dict_list(hash[hash_index], new_dict));
}

t_dict	*get_dict(t_dict **hash, char *key)
{
	int 	hash_index;
	t_dict	*curr;

	hash_index = get_hash_index(key);
	if (hash_index == -1)
		return (0);
	curr = hash[hash_index];
	return (find_dict_in_list(curr, key));
}

void	free_hash(t_dict **hash)
{
	int i;

	i = 0;
	while (i < BIG_PRIME_NUM)
	{
		free_dict_list(hash[i]);
		i++;
	}
	free(hash);
}

/*
char	**read_dict_file(void)
{
	int		fd;
	char	**strs;
	char	buf[500];
	int		n;
	int		i;

	fd = open(DICT_FILE, O_RDONLY);
	if (fd == 0)
		return (0);

	while ((n = read(fd, buf, 500)))
	{
		i = 0;
		strs = split(buf, "\n");
		while (strs[i])
		{
			add_dict(strs[i]);
			i++;
		}

	close(fd);
	return (result);
}
*/

int		get_len_space_end(char *str, int start)
{
	int len;

	len = 0;
	while (str[start + len] && str[start + len] != ' ' && str[start + len] != '\t')
		len++;
	return (len);
}

int		get_len_newline_end(char *str, int start)
{
	int len;

	len = 0;
	while (str[start + len] && str[start + len] != '\n')
		len++;
	return (len);
}

int		pass_whitespace(char *str, int start)
{
	while (str[start] && (str[start] == ' ' || str[start] == '\t'))
		start++;
	return (start);
}

void	free_strs(char **strs, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

char	*ft_strdup(char *str, int start, int len)
{
	char	*result;
	int		i;

	result = (char *)malloc(sizeof(char) * (len + 1));
	if (result == 0)
		return (0);
	i = 0;
	while (i < len)
	{
		result[i] = str[start + i];
		i++;
	}
	result[i] = 0;
	return (result);
}

int		pass_whitespace_and_colon(char *str, int start)
{
	int i;

	i = pass_whitespace(str, start);
	if (str[i++] != ':')
		return (0);
	i = pass_whitespace(str, i);
	return (i);
}

char	**parse_line(char *str)
{
	char	**result;
	int		i;
	
	result = (char **)malloc(sizeof(char *) * 2);
	if (result == 0)
		return (0);
	i = pass_whitespace(str, 0);
	result[0] = ft_strdup(str, i, get_len_space_end(str, i));
	if (result[0] == 0)
	{
		free(result);
		return (0);
	}
	i += get_len_space_end(str, i);
	if ((i = pass_whitespace_and_colon(str, i)) == 0)
	{
		free_strs(result, 1);
		return (0);
	}
	result[1] = ft_strdup(str, i, get_len_newline_end(str, i));
	if (result[1] != 0)
		return (result);
	free_strs(result, 1);
	return (0);
}


#include <stdio.h>

int		main(int argc, char **argv)
{
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



