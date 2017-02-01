/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marahimi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 00:00:50 by marahimi          #+#    #+#             */
/*   Updated: 2016/12/11 00:00:54 by marahimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	int				i;
	char			*s;
	unsigned char	ch;

	ch = (unsigned char)c;
	s = b;
	i = 0;
	while (len)
	{
		s[i] = ch;
		len--;
		i++;
	}
	return (b);
}
