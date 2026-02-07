/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbigourd <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 20:08:00 by hbigourd          #+#    #+#             */
/*   Updated: 2022/11/20 12:47:27 by hbigourd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lsts, t_list *n_lst)
{
	t_list	*t;

	if (!lsts || !n_lst)
		return ;
	if (!*lsts)
	{
		*lsts = n_lst;
		return ;
	}
	t = ft_lstlast(*lsts);
	t->next = n_lst;
}
