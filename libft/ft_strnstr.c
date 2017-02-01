/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marahimi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 00:11:21 by marahimi          #+#    #+#             */
/*   Updated: 2016/12/11 00:11:27 by marahimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t n)
{
	size_t index;
	size_t match;
	size_t length;
	size_t nn;
	size_t i;

	index = 0;
	if ((length = ft_strlen(little)) == 0)
		return ((char *)big);
	while (big[index] && n)
	{
		nn = n;
		i = index;
		match = 0;
		while ((little[match] == big[i]) && nn--)
		{
			if (match == length - 1)
				return ((char *)(big + index));
			if (little[++match] == big[i + 1])
				i++;
		}
		index++;
		n--;
	}
	return (0);
}
