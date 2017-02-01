/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marahimi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 00:13:31 by marahimi          #+#    #+#             */
/*   Updated: 2016/12/12 01:55:23 by marahimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		start;
	int		end;
	int		i;
	char	*str;

	if (!s)
		return (0);
	i = 0;
	start = 0;
	end = ft_strlen(s) - 1;
	while (s[end] == ' ' || s[end] == '\n' || s[end] == '\t')
		end--;
	while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
		start++;
	if (start > end)
		return (ft_strdup(""));
	if (!(str = (char *)malloc(sizeof(char) * (end - start + 2))))
		return (0);
	while (start <= end)
		str[i++] = s[start++];
	str[i] = '\0';
	return (str);
}
