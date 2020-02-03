/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 17:17:45 by jko               #+#    #+#             */
/*   Updated: 2020/02/02 18:31:12 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		is_valid_up(int col, int **board, int **inputs)
{
	int		i;
	int		count;
	int		temp;

	temp = board[0][col];
	count = 1;
	i = 1;
	while (i < 4)
	{
		if (temp < board[i][col])
		{
			count++;
			temp = board[i][col];
		}
		i++;
	}
	if (count != inputs[0][col])
		return (0);
	return (1);
}

int		is_valid_down(int col, int **board, int **inputs)
{
	int		i;
	int		count;
	int		temp;

	temp = board[3][col];
	count = 1;
	i = 2;
	while (i >= 0)
	{
		if (temp < board[i][col])
		{
			count++;
			temp = board[i][col];
		}
		i--;
	}
	if (count != inputs[1][col])
		return (0);
	return (1);
}

int		is_valid_left(int row, int **board, int **inputs)
{
	int		i;
	int		count;
	int		temp;

	temp = board[row][0];
	count = 1;
	i = 1;
	while (i < 4)
	{
		if (temp < board[row][i])
		{
			count++;
			temp = board[row][i];
		}
		i++;
	}
	if (count != inputs[2][row])
		return (0);
	return (1);
}

int		is_valid_right(int row, int **board, int **inputs)
{
	int		i;
	int		count;
	int		temp;

	temp = board[row][3];
	count = 1;
	i = 2;
	while (i >= 0)
	{
		if (temp < board[row][i])
		{
			count++;
			temp = board[row][i];
		}
		i--;
	}
	if (count != inputs[3][row])
		return (0);
	return (1);
}

int		is_valid(int **board, int **inputs)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (!is_valid_up(i, board, inputs)
				|| !is_valid_down(i, board, inputs)
				|| !is_valid_left(i, board, inputs)
				|| !is_valid_right(i, board, inputs))
			return (0);
		i++;
	}
	return (1);
}
