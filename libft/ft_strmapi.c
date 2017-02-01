/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marahimi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 00:09:20 by marahimi          #+#    #+#             */
/*   Updated: 2016/12/11 00:09:23 by marahimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	int		len;
	char	*s1;
	char	*str;

	if (!s)
		return (0);
	i = -1;
	s1 = (char *)s;
	len = ft_strlen(s1) + 1;
	str = (char *)malloc(len);
	if (s1[i + 1] && str)
	{
		while (s1[++i])
			str[i] = f((unsigned int)i, s1[i]);
		str[i] = '\0';
	}
	return (str);
}
