/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 12:11:05 by jko               #+#    #+#             */
/*   Updated: 2020/02/01 16:07:01 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	free_arrs(int **arrs);
int		**split_inputs(char *inputs);
void	print_str(char *str);
void	print_ints(int **ints);
int		solve(int **inputs);

int		main(int argc, char *argv[])
{
	int **inputs;
	int result;

	if (argc != 2)
	{
		print_str("Error");
		return (0);
	}

	inputs = split_inputs(argv[1]);
	if (inputs == 0)
	{
		print_str("Error");
		return (0);
	}

	result = solve(inputs);
	if (result == 0)
		print_str("Error");
	free_arrs(inputs);
	return (0);
}
