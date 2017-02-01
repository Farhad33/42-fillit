/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marahimi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 23:59:56 by marahimi          #+#    #+#             */
/*   Updated: 2016/12/10 23:59:58 by marahimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char *d;
	char *s;

	d = dst;
	s = (char *)src;
	if ((s == d) || !n)
		return (dst);
	while (n--)
		*d++ = *s++;
	return (dst);
}
