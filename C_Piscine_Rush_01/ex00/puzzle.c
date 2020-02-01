/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puzzle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 13:01:15 by jko               #+#    #+#             */
/*   Updated: 2020/02/01 16:06:58 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	print_ints(int **ints);
int		**malloc_arrs(void);
void	free_arrs(int **arrs);
char	init_arr(int *arr, int size);

char	g_is_end = 0;

int		check_row(int row, int **board)
{
	int used[5];
	int j;

	init_arr(used, 5);
	j = 0;
	while (j < 4)
	{
		if (!board[row][j])
			return (1);
		if (used[board[row][j]])
			return (0);
		used[board[row][j]]++;
		j++;
	}
	j = 1;
	while (j < 5)
	{
		if (used[j] != 1 && used[j] != 0)
			return (0);
		j++;
	}
	return (1);
}

int		check_col(int col, int **board)
{
	int used[5];
	int j;

	init_arr(used, 5);
	j = 0;
	while (j < 4)
	{
		if (!board[j][col])
			return (1);
		if (used[board[j][col]])
			return (0);
		used[board[j][col]]++;
		j++;
	}
	j = 1;
	while (j < 5)
	{
		if (used[j] != 1 && used[j] != 0)
			return (0);
		j++;
	}
	return (1);
}

int		is_valid(int **board, int **inputs)
{
	int 	i;
	int 	j;
	int 	count;
	int		temp;
	int		used[5];

	// check col up
	i = 0;
	while (i < 4)
	{
		temp = board[0][i];
		count = 1;
		j = 1;
		while (j < 4)
		{
			if (temp < board[j][i])
			{
				count++;
				temp = board[j][i];
			}
			j++;
		}
		if (count != inputs[0][i])
			return (0);
		i++;
	}

	// check col down
	i = 0;
	while (i < 4)
	{
		temp = board[3][i];
		count = 1;
		j = 2;
		while (j >= 0)
		{
			if (temp < board[j][i])
			{
				count++;
				temp = board[j][i];
			}
			j--;
		}
		if (count != inputs[1][i])
			return (0);
		i++;
	}

	// check row left
	i = 0;
	while (i < 4)
	{
		temp = board[i][0];
		count = 1;
		j = 1;
		while (j < 4)
		{
			if (temp < board[i][j])
			{
				count++;
				temp = board[i][j];
			}
			j++;
		}
		if (count != inputs[2][i])
			return (0);
		i++;
	}

	// check row right
	i = 0;
	while (i < 4)
	{
		temp = board[i][3];
		count = 1;
		j = 2;
		while (j >= 0)
		{
			if (temp < board[i][j])
			{
				count++;
				temp = board[i][j];
			}
			j--;
		}
		if (count != inputs[3][i])
			return (0);
		i++;
	}
	return (1);
}

void	dfs(int row, int col, int **board, int **inputs)
{
	int i;
	int temp_row;
	int temp_col;

	if (g_is_end)
		return ;
	if (row == 4 && col == 0)
	{
		if (is_valid(board, inputs))
		{
			g_is_end = 1;
			print_ints(board);
		}
		return ;
	}
	i = 1;
	while (i <= 4)
	{
		board[row][col] = i;
		if (!check_row(row, board) || !check_col(col, board))
		{
			board[row][col] = 0;
			i++;
			continue;
		}
		temp_row = row;
		temp_col = col + 1;
		if (temp_col >= 4)
		{
			temp_col = 0;
			temp_row++;
		}
		dfs(temp_row, temp_col, board, inputs);
		board[row][col] = 0;
		i++;
	}
}

int		solve(int **inputs)
{
	int **board;
	int	i;

	g_is_end = 0;
	board = malloc_arrs();
	i = 0;
	while (i < 4)
		init_arr(board[i++], 4);
	dfs(0, 0, board, inputs);
	free_arrs(board);
	return (g_is_end);
}
