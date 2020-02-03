/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puzzle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jko <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/01 13:01:15 by jko               #+#    #+#             */
/*   Updated: 2020/02/02 18:53:38 by jko              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	print_answer(int **ints);
int		**malloc_arrs(void);
void	free_arrs(int **arrs);
char	init_arr(int *arr, int size);
int		is_valid(int **board, int **inputs);
void	dfs(int row, int col, int **board, int **inputs);

char	g_is_end = 0;

int		check_row(int row, int **board)
{
	int used[5];
	int i;

	init_arr(used, 5);
	i = 0;
	while (i < 4)
	{
		if (!board[row][i])
			return (1);
		if (used[board[row][i]])
			return (0);
		used[board[row][i]]++;
		i++;
	}
	return (1);
}

int		check_col(int col, int **board)
{
	int used[5];
	int i;

	init_arr(used, 5);
	i = 0;
	while (i < 4)
	{
		if (!board[i][col])
			return (1);
		if (used[board[i][col]])
			return (0);
		used[board[i][col]]++;
		i++;
	}
	return (1);
}

int		check_return(int row, int col, int **board, int **inputs)
{
	if (g_is_end)
		return (1);
	if (row == 4 && col == 0)
	{
		if (is_valid(board, inputs))
		{
			g_is_end = 1;
			print_answer(board);
		}
		return (1);
	}
	return (0);
}

void	dfs(int row, int col, int **board, int **inputs)
{
	int i;

	if (check_return(row, col, board, inputs))
		return ;
	i = 1;
	while (i <= 4)
	{
		board[row][col] = i;
		if (check_row(row, board) && check_col(col, board))
		{
			if (col == 3)
				dfs(row + 1, 0, board, inputs);
			else
				dfs(row, col + 1, board, inputs);
		}
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
	{
		init_arr(board[i], 4);
		i++;
	}
	dfs(0, 0, board, inputs);
	free_arrs(board);
	return (g_is_end);
}
