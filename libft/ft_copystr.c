/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_copystr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marahimi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/14 16:18:05 by marahimi          #+#    #+#             */
/*   Updated: 2017/01/14 16:18:06 by marahimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_copystr(int *len, int *neg, char *str, int *n)
{
	str[*len] = '\0';
	while (*len >= 0)
	{
		*len = *len - 1;
		if (*len == 0 && *neg)
			str[*len] = '-';
		else
			str[*len] = (*n % 10) + '0';
		*n /= 10;
	}
}
