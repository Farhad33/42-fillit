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
}
