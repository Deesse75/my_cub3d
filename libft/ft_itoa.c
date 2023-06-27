/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sadorlin <sadorlin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 06:56:24 by sadorlin          #+#    #+#             */
/*   Updated: 2023/06/16 06:56:25 by sadorlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_nb(long int nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (1);
	if (nb < 0)
	{
		i++;
		nb *= -1;
	}
	while (nb > 0)
	{
		i++;
		nb /= 10;
	}
	return (i);
}

static void	write_str(char *str, long int n, int len)
{
	if (n < 0)
	{
		str[0] = '-';
		n = -n;
	}
	while (--len >= 0 && n > 0)
	{
		str[len] = (n % 10) + 48;
		n /= 10;
	}
}

char	*ft_itoa(int n)
{
	char		*str;
	int			len;

	len = len_nb(n);
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	if (n == 0)
	{
		str[0] = 48;
		return (str);
	}
	write_str(str, n, len);
	return (str);
}
