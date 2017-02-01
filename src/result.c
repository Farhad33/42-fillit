#include "../fillitlib.h"

int		count_maps(t_fillit *f)
{
	int len;

	len = 0;
	while (f->maps[len])
		len++;
	return (len);
}

int		malloc_result(t_fillit *f)
{
	int		size;
	int		i;
	char	*line;

	size = malloc_size(count_maps(f));
	if (!(f->result = ft_memalloc(sizeof(char *) * (size + 1))))
		return (1);
	i = 0;
	while (i < size)
	{
		if (!(line = ft_memalloc(sizeof(char) * (size + 1))))
			return (1);
		f->result[i] = line;
		i++;
	}
	return (0);
}

int		malloc_size(int len)
{
	int i;

	i = 4;
	while (i <= 11)
	{
		if ((i * i) >= (len * 4))
			return (i);
		i++;
	}
	return (0);
}
