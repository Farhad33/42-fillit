#include "../fillitlib.h"

void	free_map(t_fillit *f, int i, int j)
{
	while (f->maps[i])
	{
		while (f->maps[i][j])
		{
			free(f->maps[i][j]);
			j++;
		}
		free(f->maps[i]);
		i++;
	}
	free(f->maps);
	f->maps = 0;
}

void	free_result(t_fillit *f)
{
	int i;

	i = 0;
	while (i < f->result_size)
	{
		free(f->result[i]);
		i++;
	}
	free(f->result);
	f->result = 0;
}
