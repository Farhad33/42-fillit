/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: imoran <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/24 16:58:32 by imoran            #+#    #+#             */
/*   Updated: 2017/01/24 16:58:34 by imoran           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fillitlib.h"

int		main(int argc, char **argv)
{
	t_fillit f;

	if (argc != 2)
	{
		write(2, "usage: ", 7);
		write(2, argv[0], ft_strlen(argv[0]));
		write(2, " tetriminos_file", 16);
		ft_putchar('\n');
		return (0);
	}
	if (read_file(argv[1], &f, 0))
	{
		write(2, "error", 5);
		ft_putchar('\n');
	}
	overlap_map(&f, 0, 0, 0);
	return (0);
}
