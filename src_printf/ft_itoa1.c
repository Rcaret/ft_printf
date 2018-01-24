/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaret <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 16:51:07 by rcaret            #+#    #+#             */
/*   Updated: 2018/01/18 16:51:08 by rcaret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_itoa_ulong(unsigned long n)
{
	char			*new;
	size_t			j;

	if (n == 0)
		return (ft_strdup("0"));
	new = allocitoa_dec(n, &j);
	if (!new)
		return (NULL);
	new[j--] = 0;
	while (n != 0)
	{
		new[j--] = n % 10 + '0';
		n = n / 10;
	}
	return (new);
}

char			*ft_itoa_long(long n)
{
	char			*new;
	size_t			j;

	if (n == 0)
		return (ft_strdup("0"));
	new = allocitoa_dec(n, &j);
	if (!new)
		return (NULL);
	if (n < 0)
		new[0] = '-';
	n = (n < 0 ? -n : n);
	new[j--] = 0;
	while (n != 0)
	{
		new[j--] = n % 10 + '0';
		n = n / 10;
	}
	return (new);
}

char			*ft_itoa_long_long(long long n)
{
	unsigned long long nb;
	char			*new;
	size_t			j;

	if (n == 0)
		return (ft_strdup("0"));
	new = allocitoa_dec(n, &j);
	if (!new)
		return (NULL);
	nb = n < 0 ? -n : n;
	if (n < 0)
		new[0] = '-';
	new[j--] = 0;
	while (nb != 0)
	{
		new[j--] = nb % 10 + '0';
		nb = nb / 10;
	}
	return (new);
}

char			*ft_itoa_ulong_long(unsigned long long n)
{
	char			*new;
	size_t			j;

	if (n == 0)
		return (ft_strdup("0"));
	new = allocitoa_udec(n, &j);
	if (!new)
		return (NULL);
	new[j--] = 0;
	while (n != 0)
	{
		new[j--] = n % 10 + '0';
		n = n / 10;
	}
	return (new);
}
