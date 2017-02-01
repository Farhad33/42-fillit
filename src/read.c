#include "../fillitlib.h"

int		read_file(char *file, t_fillit *f, int i)
{
	int		fd;
	char	buf[1];
	// int		j;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (1);
	while (read(fd, buf, 1))
		f->str[i++] = buf[0];
	f->str[i] = '\0';
	if (close(fd) == -1)
		return (1);
	if (check_format_error(f, 0))
		return (1);
	if (read_map(f, 0, 0, 0))
		return (1);
	if (check_tetro(f, 0))
	{
		free_map(f, 0, 0);
		return (1);
	}
	if (malloc_result(f))
		return (1);
	// j = 0;
	// while (f->maps[j])
	// {
	// 	i = 0;
	// 	while (f->maps[j][i])
	// 	{
	// 		ft_putstr(f->maps[j][i++]);
	// 		ft_putstr("\n");
	// 	}
	// 	ft_putstr("\n");
	// 	j++;
	// }
	return (0);
}

int		check_tetro(t_fillit *f, size_t i)
{
	while (f->maps[i])
	{
		f->map = f->maps[i];
		if (check_one_map(f->map, 0, 0, 1))
			return (1);
		i++;
	}
	return (0);
}

int		check_one_map(char **map, size_t j, int count, int pound)
{
	size_t k;

	while (map[j])
	{
		k = 0;
		while (map[j][k])
		{
			if (map[j][k] == '#')
			{
				if (pound++ && k < 3 && map[j][k + 1] == '#')
					count++;
				if (k > 0 && map[j][k - 1] == '#')
					count++;
				if (j > 0 && map[j - 1][k] == '#')
					count++;
				if (j < 3 && map[j + 1][k] == '#')
					count++;
			}
			k++;
		}
		j++;
	}
	if (!(count >= 6 && count <= 8) || pound != 5)
		return (1);
	return (0);
}

int		read_map(t_fillit *f, int i, int j, int k)
{
	if (!(f->maps = ft_memalloc(sizeof(char **) * (f->map_num + 1))))
		return (1);
	while (f->str[i])
	{
		if (!(f->map = ft_memalloc(sizeof(char *) * 5)))
			return (1);
		k = 0;
		f->col = 4;
		while (f->col--)
		{
			if (!(f->line = ft_memalloc(sizeof(char) * 5)))
				return (1);
			f->row = 0;
			while (f->row < 4)
				f->line[f->row++] = f->str[i++];
			if (f->str[i] == '\n')
				i++;
			f->map[k++] = f->line;
		}
		f->maps[j++] = f->map;
		if (f->str[i] == '\n')
			i++;
	}
	return (0);
}

int		check_format_error(t_fillit *f, int i)
{
	f->map_num = 0;
	i = 0;
	while (f->str[i])
	{
		f->col = 4;
		while (f->col-- && f->str[i])
		{
			f->row = 4;
			while (f->row-- && f->str[i])
			{
				if (f->str[i] != '#' && f->str[i] != '.' && f->str[i])
					return (1);
				i++;
			}
			if (f->str[i] != '\n' && f->str[i])
				return (1);
			i++;
		}
		if (f->str[i] == '\n')
			i++;
		f->map_num++;
	}
	return (0);
}
