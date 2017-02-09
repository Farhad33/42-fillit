#include "../fillitlib.h"

void	malloc_result(t_fillit *f)
{
	int		i;
	char	*line;

	if (!(f->result = malloc(sizeof(result) * (f->result_size + 1))))
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
