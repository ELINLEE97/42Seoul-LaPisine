/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puzzle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 13:01:15 by jko               #+#    #+#             */
/*   Updated: 2020/02/01 17:55:57 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	print_ints(int **ints);
int		**malloc_arrs(void);
void	free_arrs(int **arrs);
char	init_arr(int *arr, int size);
int		is_valid(int **board, int **inputs);
void	dfs(int row, int col, int **board, int **inputs);

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
	return (1);
}

void	next_dfs(int row, int col, int **board, int **inputs)
{
	col++;
	if (col >= 4)
	{
		col = 0;
		row++;
	}
	dfs(row, col, board, inputs);
}

void	dfs(int row, int col, int **board, int **inputs)
{
	int i;

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
	i = 0;
	while (++i <= 4)
	{
		board[row][col] = i;
		if (!check_row(row, board) || !check_col(col, board))
		{
			board[row][col] = 0;
			continue;
		}
		next_dfs(row, col, board, inputs);
		board[row][col] = 0;
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
