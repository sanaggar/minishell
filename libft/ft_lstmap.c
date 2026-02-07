/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbigourd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 06:27:42 by hbigourd          #+#    #+#             */
/*   Updated: 2022/11/20 14:23:32 by hbigourd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*temp;
	t_list	*res;

	if (!lst || !f || !del)
		return (NULL);
	res = NULL;
	temp = ft_lstnew(f(lst->content));
	if (!temp)
	{
		ft_lstclear(&temp, del);
		return (NULL);
	}
	ft_lstadd_back(&res, temp);
	if (lst->next)
		res->next = ft_lstmap(lst->next, f, del);
	return (res);
}
