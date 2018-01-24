/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unicode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaret <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 17:19:11 by rcaret            #+#    #+#             */
/*   Updated: 2018/01/16 17:19:12 by rcaret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	traite_wchar_aux(wchar_t data, char *new)
{
	size_t i;

	i = 0;
	new[i++] = 0xf0 | ((data & 0x1c0000) >> 18);
	new[i++] = 0x80 | ((data & 0x3f000) >> 12);
	new[i++] = 0x80 | ((data & 0xfc0) >> 6);
	new[i++] = 0x80 | (data & 0x3f);
	return (i);
}

char	*traite_wchar(wchar_t data)
{
	char	*new;
	size_t	i;

	i = 0;
	if ((new = malloc(sizeof(5))) == NULL)
		return (NULL);
	if (data <= 0x7F)
		new[i++] = (char)data;
	else if (data <= 0x7FF)
	{
		new[i++] = ((data >> 6) + 0xc0);
		new[i++] = ((data & 0x003F) + 0x80);
	}
	else if (data <= 0xFFFF)
	{
		new[i++] = (((data & 0xF000) >> 12) + 0xE0);
		new[i++] = (((data & 0x0Fc0) >> 6) + 0x80);
		new[i++] = ((data & 0x003F) + 0x80);
	}
	else if (data <= 0x1FFFFF)
		i = traite_wchar_aux(data, new);
	new[i] = 0;
	return (i == 0 ? NULL : new);
}
