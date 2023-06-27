/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadorlin <sadorlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 06:55:52 by sadorlin          #+#    #+#             */
/*   Updated: 2023/06/16 06:55:53 by sadorlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	int		a;

	i = 0;
	if (little[0] == '\0')
		return ((char *)big);
	while (i < len && big[i])
	{
		a = 0;
		while (big[i + a] == little[a] && (a + i) < len && little[a])
			a++;
		if (little[a] == '\0')
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
