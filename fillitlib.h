/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillitlib.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 16:47:42 by imoran            #+#    #+#             */
/*   Updated: 2017/01/24 16:47:46 by imoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLITLIB_H
# define FILLITLIB_H
# define BUF_SIZE 4096

# include <sys/types.h> // for open
# include <sys/stat.h> //for read
# include <fcntl.h> //for open
# include <unistd.h> //for write
# include <stdlib.h> //for malloc & free
# include "libft/libft.h"

typedef struct		s_fillit
{
	char	*line;
	char	**map;
	char	str[1000];
	char	***maps;
	char	**result;
	int		row;
	int		col;
	int		map_num;

}					t_fillit;

int		read_file(char *file, t_fillit *f, int i);
int		check_format_error(t_fillit *f, int i);
int		read_map(t_fillit *f, int i, int j, int k);
int		check_tetro(t_fillit *f, size_t i);
int		check_one_map(char **map, size_t j, int count, int pound);
void	free_map(t_fillit *f, int i, int j);
int		count_maps(t_fillit *f);
int		malloc_result(t_fillit *f);
int		malloc_size(int len);
void	overlap_map(t_fillit *f, int i, int j, int k);
void	print_result(t_fillit *f, int i, int j);


#endif
