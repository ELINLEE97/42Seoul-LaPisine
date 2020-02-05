/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 12:16:36 by jko               #+#    #+#             */
/*   Updated: 2020/02/05 14:24:17 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

# define NO_ARG_MSG "File name missing.\n"
# define NO_ARG_MSG_SIZE 20

# define TOO_MANY_ARG_MSG "Too many arguments.\n"
# define TOO_MANY_ARG_MSG_SIZE 21

# define CANNOT_READ_MSG "Cannot read file.\n"
# define CANNOT_READ_MSG 19

int	main(int argc, char **argv)
{
	int fd;

	if (argc == 1)
		write(2, NO_ARG_MSG, NO_ARG_MSG_SIZE);
	else if (argc > 2)
		write(2, TOO_MANY_ARG_MSG, TOO_MANY_ARG_MSG_SIZE);
	fd = open(argv[1], 
