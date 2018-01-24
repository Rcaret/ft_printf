/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaret <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 17:07:05 by rcaret            #+#    #+#             */
/*   Updated: 2018/01/18 17:07:06 by rcaret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_itoa_octale(unsigned long long n)
{
	char			*new;
	size_t			j;

	if (n == 0)
		return (ft_strdup("0"));
	new = allocitoa_oct(n, &j);
	if (!new)
		return (NULL);
	new[j--] = 0;
	while (n != 0)
	{
		new[j--] = n % 8 + '0';
		n = n / 8;
	}
	return (new);
}

char	*ft_itoa_hexa_min(unsigned long long n)
{
	char			base[16];
	char			*new;
	size_t			j;

	*base = 0;
	ft_strcpy(base, "0123456789abcdef");
	if (n == 0)
		return (ft_strdup("0"));
	new = allocitoa_hex(n, &j);
	if (!new)
		return (NULL);
	new[j--] = 0;
	while (n != 0)
	{
		new[j--] = base[n % 16];
		n = n / 16;
	}
	return (new);
}

char	*ft_itoa_hexa_maj(unsigned long long n)
{
	char			base[16];
	char			*new;
	size_t			j;

	*base = 0;
	ft_strcpy(base, "0123456789ABCDEF");
	if (n == 0)
		return (ft_strdup("0"));
	new = allocitoa_hex(n, &j);
	if (!new)
		return (NULL);
	new[j--] = 0;
	while (n != 0)
	{
		new[j--] = base[n % 16];
		n = n / 16;
	}
	return (new);
}

char	*ft_itoa_pointeur(unsigned long long n)
{
	char			base[16];
	char			*new;
	size_t			j;

	*base = 0;
	ft_strcpy(base, "0123456789abcdef");
	if (n == 0)
		return (ft_strdup("0x0"));
	new = allocitoa_hex_pointeur(n, &j);
	if (!new)
		return (NULL);
	new[j--] = 0;
	new[0] = '0';
	new[1] = 'x';
	while (n != 0)
	{
		new[j--] = base[n % 16];
		n = n / 16;
	}
	return (new);
}
