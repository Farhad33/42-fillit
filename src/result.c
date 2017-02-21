#include "../fillitlib.h"

int		malloc_result(t_fillit *f)
{
	int		i;
	char	*line;

	// printf(" malloc_result \n" );
	if (!(f->result = malloc(sizeof(f->result) * (f->result_size + 1))))
		return (1);
	i = 0;
	while (i < f->result_size)
	{
		if (!(line = malloc(sizeof(line) * (f->result_size + 1))))
			return (1);
		ft_memset(line, '.', (f->result_size));
		line[f->result_size] = '\0';
		f->result[i] = line;
		i++;
	}
	f->result[i] = 0;
	return (0);
}

int		coordinate_init(t_fillit *f)
{
	int i;
	int j;
	int *one_coord;
	int **tetro;

	if (!(f->coords = malloc(sizeof(int **) * (f->map_num))))
		return (1);
	i = 0;
	while (i < f->map_num)
	{

		if (!(tetro = malloc(sizeof(int *) * (5))))
			return (1);
		j = 0;
		while (j < 4)
		{
			if (!(one_coord = malloc(sizeof(int) * (3))))
				return (1);
			tetro[j] = one_coord;
			j++;
		}
		tetro[j] = 0;
		f->coords[i] = tetro;
		i++;
	}
	return (0);
}

int		init_xy(t_fillit *f)
{
	int i;
	int *each;

	if (!(f->xy = malloc(sizeof(f->xy) * (f->map_num))))
		return (1);
	i = 0;
	while (i < f->map_num)
	{
		if (!(each = malloc(sizeof(int) * (2))))
			return (1);
		f->xy[i] = each;
		i++;
	}
	xy_zero(f, 0);
	return (0);
}

void	xy_zero(t_fillit *f, int i)
{
	while (i < f->map_num)
	{
		f->xy[i][0] = 0;
		f->xy[i][1] = 0;
		i++;
	}
}

void	malloc_size(t_fillit *f)
{
	int i;

	i = 2;
	while (i <= 11)
	{
		if ((i * i) >= (f->result_size * 4))
		{
			f->result_size = i;
			return ;
		}
		i++;
	}
}
