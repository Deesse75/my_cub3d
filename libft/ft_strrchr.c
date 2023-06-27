/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadorlin <sadorlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 06:55:49 by sadorlin          #+#    #+#             */
/*   Updated: 2023/06/16 06:55:50 by sadorlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int				i;
	unsigned char	t;
	char			*str;

	str = (char *)s;
	t = (unsigned char)c;
	i = (int)ft_strlen(str);
	while (i >= 0)
	{
		if (str[i] == t)
			return (&str[i]);
		i--;
	}
	return (NULL);
}
