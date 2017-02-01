/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marahimi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/10 23:58:46 by marahimi          #+#    #+#             */
/*   Updated: 2016/12/10 23:58:49 by marahimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		len;
	int		neg;
	int		temp;
	char	*str;

	len = 1;
	neg = 0;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	else if (n > 2147483647)
		return (ft_strdup("-1"));
	else if (n < -2147483648)
		return (ft_strdup("0"));
	ft_negative(&len, &neg, &n);
	temp = n;
	while ((temp /= 10) > 0)
		len++;
	if (!(str = (char *)malloc(len + 1)))
		return (0);
	ft_copystr(&len, &neg, str, &n);
	return (str);
}
