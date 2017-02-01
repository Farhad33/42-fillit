/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marahimi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 00:12:41 by marahimi          #+#    #+#             */
/*   Updated: 2016/12/11 00:12:44 by marahimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	int		temp;
	char	**str;

	if (!s)
		return (0);
	temp = ft_count_words(s, c);
	if (!(str = (char **)malloc(sizeof(char*) * (temp + 1))))
		return (0);
	if (temp == 0)
	{
		str[0] = NULL;
		return (str);
	}
	return (ft_copy(s, c, str));
}
