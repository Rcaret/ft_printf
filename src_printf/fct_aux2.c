/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fct_aux2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaret <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 19:47:45 by rcaret            #+#    #+#             */
/*   Updated: 2018/01/17 19:47:46 by rcaret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strcpy2(char *dest, char *src, int i)
{
	i = i == 0 ? 0 : ft_strlen(dest);
	while (*src)
		dest[i++] = *(src++);
	dest[i] = 0;
	return (dest);
}

char	*ft_strcpy3(char *dest, char *src, int i)
{
	int j;

	j = 0;
	while (j != i)
		dest[j++] = *(src++);
	dest[j] = 0;
	return (dest);
}
