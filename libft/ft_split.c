/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sannagar <sannagar@student.42nice.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 15:01:34 by hbigourd          #+#    #+#             */
/*   Updated: 2023/11/30 01:40:49 by sannagar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ss_tab(char *s, char c)
{
	t_split_info	v;

	v.i = 0;
	v.j = 0;
	while (s[v.i] && s[v.i] == c)
		v.i++;
	while (s[v.i] && s[v.i] != c)
	{
		v.j++;
		v.i++;
	}
	v.ss_tab = malloc(sizeof(char) * (v.j + 1));
	if (!v.ss_tab)
	{
		free(v.ss_tab);
		return (NULL);
	}
	v.i -= v.j;
	v.j = 0;
	while (s[v.i] && s[v.i] != c)
		v.ss_tab[v.j++] = s[v.i++];
	v.ss_tab[v.j] = '\0';
	return (v.ss_tab);
}

char	**fill_tab(char **tab, size_t nb_list, char *s1, char c)
{
	t_split_info	v;

	v.i = 0;
	v.j = 0;
	while (v.j < nb_list)
	{
		tab[v.j] = ft_ss_tab(s1 + v.i, c);
		if (!tab[v.j])
			return (NULL);
		while (s1[v.i] && s1[v.i] == c)
			v.i++;
		v.i += ft_strlen(tab[v.j]);
		v.j++;
	}
	tab[v.j] = NULL;
	return (tab);
}

size_t	ft_nb_c_in_list(char const *s, char c)
{
	t_split_info	v;

	v.i = 0;
	v.j = 0;
	while (s[v.i])
	{
		if (v.i == 0 && s[v.i] == c)
		{
			while (s[v.i] == c)
				v.i++;
		}
		if (c == s[v.i] && c != s[v.i + 1] && s[v.i + 1] != '\0')
			v.j++;
		v.i++;
	}
	if (v.i > 0 && s[v.i - 1] == c)
		v.j--;
	return (v.j);
}

char	**ft_split(char const *s, char c)
{
	t_split_info	v;
	char			**tab;

	if (!s)
		return (NULL);
	v.tmp_set[0] = c;
	v.tmp_set[1] = '\0';
	v.s1 = ft_strtrim(s, v.tmp_set);
	if (!v.s1 || *v.s1 == '\0')
	{
		free(v.s1);
		tab = malloc(sizeof(char *));
		if (!tab)
			return (NULL);
		tab[0] = NULL;
		return (tab);
	}
	v.nb_list = ft_nb_c_in_list(v.s1, c) + 1;
	tab = malloc(sizeof(char *) * (v.nb_list + 1));
	if (!tab)
		return (NULL);
	tab = fill_tab(tab, v.nb_list, v.s1, c);
	free(v.s1);
	return (tab);
}
