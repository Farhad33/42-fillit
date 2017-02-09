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
	int		result_count;
	int		result_size;
	int		row;
	int		col;
	int		map_num;
	int		***coords;
}					t_fillit;

int		read_file(char *file, t_fillit *f, int i);
int		check_format_error(t_fillit *f, int i);
int		read_map(t_fillit *f, int i, int j, int k);
int		check_tetro(t_fillit *f, size_t i);
int		check_one_map(char **map, size_t j, int count, int pound);
void	free_map(t_fillit *f, int i, int j);
int		count_maps(t_fillit *f);
int		malloc_result(t_fillit *f);
void	malloc_size(t_fillit *f);
void	print_result(t_fillit *f, int i, int j);
int		coordinate_init(t_fillit *f);
void	find_coord(t_fillit *f, int i);
void	print_cord(t_fillit *f, int i, int j, int k);
void	reset_coord(t_fillit *f, int i);
void	solve(t_fillit *f, int i, int x, int y);
void	free_result(t_fillit *f);
int		fit_one_peace(t_fillit *f, int i, int x, int y);
int		label_coords(t_fillit *f, int i, int x, int y);
int		add_one_xy(t_fillit *f, int i, int xy, int j);
int		extend_result(t_fillit *f, int i, int y);


#endif
