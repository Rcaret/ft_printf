/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_alloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaret <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 17:42:46 by rcaret            #+#    #+#             */
/*   Updated: 2018/01/18 17:42:48 by rcaret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*allocitoa_oct(unsigned long long n, size_t *j)
{
	char	*new;
	size_t	i;

	i = 0;
	while (n != 0)
	{
		n = n / 8;
		i++;
	}
	*j = i;
	new = malloc(i + 1);
	return (new);
}

char	*allocitoa_dec(long long n, size_t *j)
{
	char	*new;
	size_t	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	*j = i;
	new = malloc(i + 1);
	return (new);
}

char	*allocitoa_hex(unsigned long long n, size_t *j)
{
	char	*new;
	size_t	i;

	i = 0;
	while (n != 0)
	{
		n = n / 16;
		i++;
	}
	*j = i;
	new = malloc(i + 1);
	return (new);
}

char	*allocitoa_udec(unsigned long long n, size_t *j)
{
	char	*new;
	size_t	i;

	i = 0;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	*j = i;
	new = malloc(i + 1);
	return (new);
}

char	*allocitoa_hex_pointeur(unsigned long long n, size_t *j)
{
	char	*new;
	size_t	i;

	i = 0;
	while (n != 0)
	{
		n = n / 16;
		i++;
	}
	*j = i + 2;
	new = malloc(i + 3);
	return (new);
}
