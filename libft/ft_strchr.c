/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadorlin <sadorlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 06:56:15 by sadorlin          #+#    #+#             */
/*   Updated: 2023/06/16 06:56:16 by sadorlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int				i;
	unsigned char	t;

	t = (unsigned char)c;
	i = -1;
	while (s[++i])
	{
		if (s[i] == t)
			return ((char *)&s[i]);
	}
	if (s[i] == t)
		return ((char *)&s[i]);
	return (NULL);
}
