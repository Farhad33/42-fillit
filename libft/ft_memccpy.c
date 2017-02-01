/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marahimi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 23:59:14 by marahimi          #+#    #+#             */
/*   Updated: 2016/12/10 23:59:16 by marahimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst1, const void *src1, int c, size_t n)
{
	char	*src;
	char	*dst;

	src = (char *)src1;
	dst = dst1;
	while (n--)
	{
		*dst = *src;
		if ((unsigned char)*src == (unsigned char)c)
		{
			dst++;
			return (dst);
		}
		dst++;
		src++;
	}
	return (0);
}
