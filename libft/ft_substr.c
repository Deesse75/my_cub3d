/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadorlin <sadorlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 06:55:35 by sadorlin          #+#    #+#             */
/*   Updated: 2023/06/16 06:55:36 by sadorlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*dest;

	if (!s)
		return (NULL);
	if (start >= ft_strlen(s))
		len = 0;
	else
		s += start;
	len++;
	if (len > ft_strlen(s))
		len = ft_strlen(s) + 1;
	dest = malloc(len);
	if (dest == NULL)
		return (NULL);
	ft_strlcpy(dest, s, len);
	return (dest);
}
