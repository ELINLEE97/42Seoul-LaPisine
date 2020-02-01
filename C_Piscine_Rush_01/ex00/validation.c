/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 17:17:45 by jko               #+#    #+#             */
/*   Updated: 2020/02/01 17:43:21 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		check_col_up(int col, int **board, int **inputs)
{
	int		j;
	int		count;
	int		temp;

	temp = board[0][col];
	count = 1;
	j = 1;
	while (j < 4)
	{
		if (temp < board[j][col])
		{
			count++;
			temp = board[j][col];
		}
		j++;
	}
	if (count != inputs[0][col])
		return (0);
	return (1);
}

int		check_col_down(int col, int **board, int **inputs)
{
	int		j;
	int		count;
	int		temp;

	temp = board[3][col];
	count = 1;
	j = 2;
	while (j >= 0)
	{
		if (temp < board[j][col])
		{
			count++;
			temp = board[j][col];
		}
		j--;
	}
	if (count != inputs[1][col])
		return (0);
	return (1);
}

int		check_row_left(int row, int **board, int **inputs)
{
	int		j;
	int		count;
	int		temp;

	temp = board[row][0];
	count = 1;
	j = 1;
	while (j < 4)
	{
		if (temp < board[row][j])
		{
			count++;
			temp = board[row][j];
		}
		j++;
	}
	if (count != inputs[2][row])
		return (0);
	return (1);
}

int		check_row_right(int row, int **board, int **inputs)
{
	int		j;
	int		count;
	int		temp;

	temp = board[row][3];
	count = 1;
	j = 2;
	while (j >= 0)
	{
		if (temp < board[row][j])
		{
			count++;
			temp = board[row][j];
		}
		j--;
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
		if (!check_col_up(i, board, inputs))
			return (0);
		if (!check_col_down(i, board, inputs))
			return (0);
		if (!check_row_left(i, board, inputs))
			return (0);
		if (!check_row_right(i, board, inputs))
			return (0);
		i++;
	}
	return (1);
}
