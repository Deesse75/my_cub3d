/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadorlin <sadorlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 06:55:46 by sadorlin          #+#    #+#             */
/*   Updated: 2023/06/16 06:55:47 by sadorlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char c, char const *set)
{
	int	i;

	i = -1;
	if (!set)
		return (-1);
	while (set[++i])
		if (c == set[i])
			return (0);
	return (-1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	char	*dest;
	int		start;
	int		len;

	i = 0;
	if (!s1)
		return (NULL);
	while (s1[i] && is_set(s1[i], set) == 0)
		i++;
	start = i;
	if (s1[i] == '\0')
		len = 0;
	else
	{
		i = ft_strlen(s1) - 1;
		while (i >= 0 && is_set(s1[i], set) == 0)
			i--;
	len = i + 1 - start;
	}
	dest = ft_substr(s1, start, len);
	return (dest);
}
