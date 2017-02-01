/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marahimi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 00:12:19 by marahimi          #+#    #+#             */
/*   Updated: 2016/12/11 00:12:25 by marahimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*s2;
	int		len;

	len = 1;
	s2 = (char *)s;
	while (*s2)
	{
		len++;
		s2++;
	}
	while (len--)
	{
		if (*s2 == c)
			return (s2);
		s2--;
	}
	return (0);
}
