/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marahimi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 00:00:26 by marahimi          #+#    #+#             */
/*   Updated: 2016/12/11 00:00:32 by marahimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t c)
{
	char *s;
	char *d;

	s = (char *)src;
	d = dst;
	if ((s == d) || !c)
		return (dst);
	if (d < s)
	{
		while (c--)
			*d++ = *s++;
		return (dst);
	}
	s += c;
	d += c;
	while (c--)
		*--d = *--s;
	return (dst);
}
