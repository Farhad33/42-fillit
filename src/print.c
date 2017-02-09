#include "../fillitlib.h"

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

void	print_cord(t_fillit *f, int i, int j, int k)
{
	while (i < f->map_num)
	{
		j = 0;
		while (j < 4)
		{
			k = 0;
			while (k < 2)
			{
				ft_putnbr(f->coords[i][j][k]);
				ft_putchar(' ');
				k++;
			}
			ft_putchar('\n');
			j++;
		}
		ft_putchar('\n');
		ft_putchar('\n');
		i++;
	}
}
