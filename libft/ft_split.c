/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadorlin <sadorlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 06:56:18 by sadorlin          #+#    #+#             */
/*   Updated: 2023/06/16 06:56:19 by sadorlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nb_strs(char *s, char c)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	if (s[0] == '\0')
		return (0);
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
			nb++;
		while (s[i] != c && s[i])
			i++;
	}
	return (nb);
}

static char	**len_strs(char *s, char c, char **strs, int nb)
{
	int	len;
	int	i;
	int	a;

	i = 0;
	a = -1;
	while (++a < nb)
	{
		len = 0;
		while (s[i] == c && s[i])
			i++;
		while (s[i] != c && s[i])
		{
			len++;
			i++;
		}
		strs[a] = (char *)malloc(sizeof(char) * (len + 1));
		if (strs[a] == NULL)
			return (NULL);
	}
	return (strs);
}

static char	**write_strs(char *s, char c, char **strs, int nb)
{
	int	i;
	int	j;
	int	e;

	i = -1;
	e = 0;
	while (++i < nb)
	{
		j = -1;
		while (s[e] == c && s[e])
			e++;
		while (s[e] != c && s[e])
		{
			strs[i][++j] = s[e];
			e++;
		}
		strs[i][++j] = '\0';
	}
	strs[i] = NULL;
	return (strs);
}

char	**ft_split(char const *s, char c)
{
	int		nb;
	char	*s1;
	char	**strs;

	if (!s)
		return (NULL);
	s1 = (char *)s;
	nb = nb_strs(s1, c);
	strs = (char **)malloc(sizeof(char *) * (nb + 1));
	if (strs == NULL)
		return (NULL);
	strs = len_strs(s1, c, strs, nb);
	strs = write_strs(s1, c, strs, nb);
	return (strs);
}
