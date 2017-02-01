/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marahimi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 19:45:03 by marahimi          #+#    #+#             */
/*   Updated: 2017/01/09 19:45:05 by marahimi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *element;
	t_list *last_elem;

	if (lst == NULL || f == NULL)
		return (NULL);
	element = (t_list *)malloc(sizeof(t_list));
	if (!element)
		return (NULL);
	last_elem = f(lst);
	element = last_elem;
	while (lst->next)
	{
		lst = lst->next;
		last_elem->next = f(lst);
		if (last_elem->next == NULL)
			return (NULL);
		last_elem = last_elem->next;
	}
	return (element);
}
