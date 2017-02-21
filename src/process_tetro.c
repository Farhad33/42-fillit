#include "../fillitlib.h"

int		control(t_fillit *f)
{
	malloc_result(f);
	if (solve(f, 0) == 0)
	{
		f->result_size++;
		xy_zero(f, 0);
		free_result(f);
		control(f);
	}
	return (0);
}

int		solve(t_fillit *f, int i)
{
	if (i >= (f->map_num))
	{
		print_result(f, 0, 0);
		exit(0);
	}
	if (move_one_peace(f, i))
		solve(f, i + 1);
	else
	{
		i--;
		if (i < 0)
			return (0);
		remove_one_result(f, i, 0, 0);
		f->xy[i][0]++;
		xy_zero(f, i + 1);
		solve(f, i);
	}
	return (0);
}

void	remove_one_result(t_fillit *f, int i, int x, int y)
{
	if (f->result[f->coords[i][0][1] + y][f->coords[i][0][0] + x] == ('A' + i) &&
		f->result[f->coords[i][1][1] + y][f->coords[i][1][0] + x] == ('A' + i) &&
		f->result[f->coords[i][2][1] + y][f->coords[i][2][0] + x] == ('A' + i) &&
		f->result[f->coords[i][3][1] + y][f->coords[i][3][0] + x] == ('A' + i))
	{
		(f->result[f->coords[i][0][1] + y][f->coords[i][0][0] + x] = '.');
		(f->result[f->coords[i][1][1] + y][f->coords[i][1][0] + x] = '.');
		(f->result[f->coords[i][2][1] + y][f->coords[i][2][0] + x] = '.');
		(f->result[f->coords[i][3][1] + y][f->coords[i][3][0] + x] = '.');
		return ;
	}
	if (add_one_x(f, i, x))
		x++;
	else if (add_one_y(f, i, y))
	{
		y++;
		x = 0;
	}
	remove_one_result(f, i, x, y);
}


int		move_one_peace(t_fillit *f, int i)
{
	while (check_boundries(f, i, f->xy[i][1]))
	{
		if (label_coords(f, i, f->xy[i][0], f->xy[i][1]))
			return (1);
		else if (add_one_x(f, i, f->xy[i][0]))
			f->xy[i][0]++;
		else if (add_one_y(f, i, f->xy[i][1]))
		{
			f->xy[i][1]++;
			f->xy[i][0] = 0;
		}
	}
	return (0);
}

int		label_coords(t_fillit *f, int i, int x, int y)
{
	if (f->result[f->coords[i][0][1] + y][f->coords[i][0][0] + x] == '.' &&
		f->result[f->coords[i][1][1] + y][f->coords[i][1][0] + x] == '.' &&
		f->result[f->coords[i][2][1] + y][f->coords[i][2][0] + x] == '.' &&
		f->result[f->coords[i][3][1] + y][f->coords[i][3][0] + x] == '.')
	{
		f->result[f->coords[i][0][1] + y][f->coords[i][0][0] + x] = ('A' + i);
		f->result[f->coords[i][1][1] + y][f->coords[i][1][0] + x] = ('A' + i);
		f->result[f->coords[i][2][1] + y][f->coords[i][2][0] + x] = ('A' + i);
		f->result[f->coords[i][3][1] + y][f->coords[i][3][0] + x] = ('A' + i);
		return (1);
	}
	return (0);
}

int		add_one_y(t_fillit *f, int i, int y)
{
	if ((f->coords[i][0][1] + y) <= (f->result_size - 1) &&
		(f->coords[i][1][1] + y) <= (f->result_size - 1) &&
		(f->coords[i][2][1] + y) <= (f->result_size - 1) &&
		(f->coords[i][3][1] + y) <= (f->result_size - 1))
		{
			return (1);
		}
	return (0);
}

int		add_one_x(t_fillit *f, int i, int x)
{
	if ((f->coords[i][0][0] + x) < (f->result_size - 1) &&
		(f->coords[i][1][0] + x) < (f->result_size - 1) &&
		(f->coords[i][2][0] + x) < (f->result_size - 1) &&
		(f->coords[i][3][0] + x) < (f->result_size - 1))
		{
			return (1);
		}
	return (0);
}

int		check_boundries(t_fillit *f, int i, int y)
{
	if ((f->coords[i][0][1] + y) >= (f->result_size) ||
		(f->coords[i][1][1] + y) >= (f->result_size) ||
		(f->coords[i][2][1] + y) >= (f->result_size) ||
		(f->coords[i][3][1] + y) >= (f->result_size))
	{
		return (0);
	}
	return (1);
}

void	find_coord(t_fillit *f, int i)
{
	int j;
	int k;
	int x;

	while (f->maps[i])
	{
		j = 0;
		x = 0;
		while (f->maps[i][j])
		{
			k = 0;
			while (f->maps[i][j][k])
			{
				if (f->maps[i][j][k] == '#')
				{
					f->coords[i][x][0] = k;
					f->coords[i][x][1] = j;
					x++;
				}
				k++;
			}
			j++;
		}
		i++;
	}
}

void 	reset_coord(t_fillit *f, int i)
{
	while (i < f->map_num)
	{
		while (f->coords[i][0][0] > 0 && f->coords[i][1][0] > 0 &&
			   f->coords[i][2][0] > 0 && f->coords[i][3][0] > 0)
		{
			f->coords[i][0][0]--;
			f->coords[i][1][0]--;
			f->coords[i][2][0]--;
			f->coords[i][3][0]--;
		}
		while (f->coords[i][0][1] > 0 && f->coords[i][1][1] > 0 &&
			   f->coords[i][2][1] > 0 && f->coords[i][3][1] > 0)
		{
			f->coords[i][0][1]--;
			f->coords[i][1][1]--;
			f->coords[i][2][1]--;
			f->coords[i][3][1]--;
		}
		i++;
	}
}
