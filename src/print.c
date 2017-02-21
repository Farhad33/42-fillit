#include "../fillitlib.h"

void	print_result(t_fillit *f, int i, int j)
{
	while (i < f->result_size)
	{
		j = 0;
		while (j < f->result_size)
		{
			ft_putchar(f->result[i][j]);
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}

void	print_cord(t_fillit *f, int i, int j)
{
	while (i < f->map_num)
	{
		j = 0;
		while (j < 4)
		{
			ft_putnbr(f->coords[i][j][0]);
			ft_putchar(' ');
			ft_putnbr(f->coords[i][j][1]);
			ft_putchar('\n');
			j++;
		}
		ft_putchar('\n');
		ft_putchar('\n');
		i++;
	}
}
