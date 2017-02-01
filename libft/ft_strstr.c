/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marahimi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 00:12:56 by marahimi          #+#    #+#             */
/*   Updated: 2016/12/11 00:12:59 by marahimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int index;
	int match;
	int length;

	index = 0;
	match = 0;
	length = 0;
	length = ft_strlen(little);
	if (length == 0)
		return ((char *)big);
	while (big[index])
	{
		while (little[match] == big[index + match])
		{
			if (match == length - 1)
				return ((char *)(big + index));
			match++;
		}
		match = 0;
		index++;
	}
	return (0);
}
