/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadorlin <sadorlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 06:56:11 by sadorlin          #+#    #+#             */
/*   Updated: 2023/06/16 06:56:12 by sadorlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*nptr;
	int		i;
	int		len;

	i = -1;
	len = (int)ft_strlen(s);
	nptr = malloc(len + 1);
	if (nptr == NULL)
		return (NULL);
	while (s[++i])
		nptr[i] = s[i];
	nptr[i] = s[i];
	return (nptr);
}
