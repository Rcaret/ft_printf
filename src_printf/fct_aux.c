/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_aux.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaret <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 19:06:58 by rcaret            #+#    #+#             */
/*   Updated: 2018/01/13 19:06:59 by rcaret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_strchr_nb(char *s1)
{
	while (*s1 && (*s1 < '0' || *s1 > '9'))
		s1++;
	if (!*s1)
		return (NULL);
	return (s1);
}

char			*ft_strjoin_char(char *s1, char c)
{
	char	*new;
	size_t	len;

	len = 0;
	if (c < '0' || c > '9')
		while (s1[len])
			if (s1[len++] == c)
				return (s1);
	len = ft_strlen(s1);
	new = malloc(len + 2);
	if (!new)
		exit(1);
	ft_strcpy(new, s1);
	free(s1);
	new[len] = c;
	new[len + 1] = 0;
	return (new);
}

static	char	*allocitoa(int n, size_t *j)
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

char			*ft_itoa_uint(unsigned int n)
{
	char			*new;
	size_t			j;

	if (n == 0)
		return (ft_strdup("0"));
	new = allocitoa(n, &j);
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
