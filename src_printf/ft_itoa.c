/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaret <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 18:33:51 by rcaret            #+#    #+#             */
/*   Updated: 2017/12/17 17:37:38 by rcaret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	char	*allocitoa(int n, size_t *j)
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

char			*ft_itoa(int n)
{
	char			*new;
	unsigned int	nb;
	size_t			j;

	if (n == 0)
		return (ft_strdup("0"));
	new = allocitoa(n, &j);
	if (!new)
		return (NULL);
	nb = (n < 0 ? -n : n);
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
