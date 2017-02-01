/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marahimi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 16:27:13 by marahimi          #+#    #+#             */
/*   Updated: 2017/01/14 16:27:17 by marahimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_copy(char const *s, char c, char **str)
{
	int		i;
	int		j;
	int		k;
	char	*sub;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			if (!(sub = (char *)malloc(ft_count_word(s, c, i) + 1)))
				return (0);
			k = 0;
			while ((s[i] != c) && s[i])
				sub[k++] = s[i++];
			sub[k] = '\0';
			str[j++] = sub;
			i--;
		}
		i++;
	}
	str[j] = 0;
	return (str);
}
