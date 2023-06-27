/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadorlin <sadorlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 06:56:08 by sadorlin          #+#    #+#             */
/*   Updated: 2023/06/16 06:56:09 by sadorlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		len_s1;
	int		len_s2;
	char	*dest;

	i = -1;
	j = -1;
	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	dest = malloc(len_s1 + len_s2 + 1);
	if (dest == NULL)
		return (NULL);
	while (++i < len_s1)
		dest[i] = s1[i];
	while (++j < len_s2)
		dest[i + j] = s2[j];
	dest[i + j] = '\0';
	return (dest);
}
