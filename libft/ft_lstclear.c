/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbigourd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 20:28:00 by hbigourd          #+#    #+#             */
/*   Updated: 2022/11/20 13:32:16 by hbigourd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lsts, void (*del)(void *))
{
	t_list	*t;
	t_list	*temp;

	if (!lsts || !*lsts || !del)
		return ;
	t = *lsts;
	temp = t;
	while (t)
	{
		temp = t->next;
		ft_lstdelone(t, del);
		t = temp;
	}
	*lsts = NULL;
}
