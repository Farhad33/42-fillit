#include "../fillitlib.h"

int		control(t_fillit *f)
{
	malloc_result(f);
	if ((f->result = solve(f, result, 0)))
		print_result(f, 0, 0);
	else
	{
		f->result_size++;
		control(f);
	}
	return (0);
}

int		solve(t_fillit *f, int i)
{
	while (i < f->map_num)
	{
		if (move_one_peace(f, i, 0, 0))
			return (1);
		i++;
	}
	return (0);
}

int		recursive(t_fillit *f, int i, int x, int y)
{
	while (1)
	{
		if (check_boundries(f, i, y))
			return (0);
		if (label_coords(f, i, x, y))
			return (1);
		else if (add_one_xy(f, i, x, 0))
		{
			x++;
			ft_putstr(" x++ ");
		}
		else if (add_one_xy(f, i, y, 1))
		{
			ft_putstr(" y++ ");
			y++;
			x = 0;
		}
	}
	return (0);
}

int		move_one_peace(t_fillit *f, int i, int x, int y)
{
	while (check_boundries(f, i, y))
	{
		if (label_coords(f, i, x, y))
			return (1);
		else if (add_one_xy(f, i, x, 0))
			x++;
		else if (add_one_xy(f, i, y, 1))
		{
			y++;
			x = 0;
		}
	}
	return (0);
}

int		label_coords(t_fillit *f, int i, int x, int y)
{
	if (f->result[f->coords[i][0][0] + y][f->coords[i][0][1] + x] == '.' &&
		f->result[f->coords[i][1][0] + y][f->coords[i][1][1] + x] == '.' &&
		f->result[f->coords[i][2][0] + y][f->coords[i][2][1] + x] == '.' &&
		f->result[f->coords[i][3][0] + y][f->coords[i][3][1] + x] == '.')
	{
		f->result[f->coords[i][0][0] + y][f->coords[i][0][1] + x] = ('A' + i);
		f->result[f->coords[i][1][0] + y][f->coords[i][1][1] + x] = ('A' + i);
		f->result[f->coords[i][2][0] + y][f->coords[i][2][1] + x] = ('A' + i);
		f->result[f->coords[i][3][0] + y][f->coords[i][3][1] + x] = ('A' + i);
		return (1);
	}
	return (0);
}

int		add_one_xy(t_fillit *f, int i, int xy, int j)
{
	if (j)
		j--;
	else
		j++;
	if (f->coords[i][0][j] + xy < (f->result_size - j) &&
		f->coords[i][1][j] + xy < (f->result_size - j) &&
		f->coords[i][2][j] + xy < (f->result_size - j) &&
		f->coords[i][3][j] + xy < (f->result_size - j))
		{
			return (1);
		}
	return (0);
}

int		extend_result(t_fillit *f, int i, int y)
{
	if (f->coords[i][0][0] + y >= (f->result_size) ||
		f->coords[i][1][0] + y >= (f->result_size) ||
		f->coords[i][2][0] + y >= (f->result_size) ||
		f->coords[i][3][0] + y >= (f->result_size))
	{
		ft_putstr(" extend_result ");
		free_result(f);
		f->result_size++;
		malloc_result(f);
		solve(f, 0, 0, 0);
		return (1);
	}
	return (0);
}

int		check_boundries(t_fillit *f, int i, int y)
{
	if (f->coords[i][0][0] + y >= (f->result_size) ||
		f->coords[i][1][0] + y >= (f->result_size) ||
		f->coords[i][2][0] + y >= (f->result_size) ||
		f->coords[i][3][0] + y >= (f->result_size))
	{
		ft_putstr(" check_boundries ");
		return (0);
	}
	return (1);
}

void	find_coord(t_fillit *f, int i)
{
	int j;
	int k;
	int x;
	ft_putstr("\n");
	ft_putstr("find_coord");
	ft_putstr("\n");
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
					f->coords[i][x][0] = j;
					f->coords[i][x][1] = k;
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
	ft_putstr("\n");
	ft_putstr("reset_coord");
	ft_putstr("\n");
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
