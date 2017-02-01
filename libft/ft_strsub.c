/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marahimi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 00:13:13 by marahimi          #+#    #+#             */
/*   Updated: 2016/12/12 01:54:05 by marahimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*str;

	if (!s)
		return (0);
	str = (char *)malloc(len + 1);
	i = 0;
	if (!str)
		return (0);
	while (len--)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}
