#include "../fillitlib.h"

void	overlap_map(t_fillit *f, int i, int j, int k)
{
	while (f->maps[i])
	{
		j = 0;
		while (f->maps[i][j])
		{
			k = 0;
			while (f->maps[i][j][k])
			{
				if (f->maps[i][j][k] == '#')
					f->result[j][k] = 'A';
				else if (f->result[j][k] != 'A')
					f->result[j][k] = '.';
				k++;
			}
			j++;
		}
		i++;
	}
	print_result(f, 0, 0);
}

void	print_result(t_fillit *f, int i, int j)
{
	while (f->result[i])
	{
		j = 0;
		while (f->result[i][j])
		{
			ft_putchar(f->result[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
