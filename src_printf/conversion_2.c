/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaret <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 17:04:21 by rcaret            #+#    #+#             */
/*   Updated: 2018/01/22 17:04:23 by rcaret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	s_into_ulong_long(unsigned long long elem, char *flags, t_elem *l_elem)
{
	char *new;

	new = ft_itoa_long_long(elem);
	if (ft_strchr(flags, '-'))
		new = flag_moins(new, flags, ft_strlen(new));
	else if (ft_strchr_nb(flags))
		new = flag_nb(new, flags, ft_strlen(new));
	l_elem->size = ft_strlen(new);
	l_elem->saut += 3;
	l_elem->str = new;
}

void	s_into_ulong_oct(unsigned long long elem, char *flags,
	t_elem *l_elem, size_t saut)
{
	char *new;

	new = ft_itoa_octale(elem);
	if (ft_strchr(flags, '#'))
		new = flag_dieze(new, "0", flags);
	if (ft_strchr(flags, '-'))
		new = flag_moins(new, flags, ft_strlen(new));
	else if (ft_strchr_nb(flags))
		new = flag_nb(new, flags, ft_strlen(new));
	l_elem->size = ft_strlen(new);
	l_elem->saut += saut;
	l_elem->str = new;
}

void	s_into_ulong_hex_min(unsigned long long elem, char *flags,
	t_elem *l_elem, size_t saut)
{
	char *new;

	new = ft_itoa_hexa_min(elem);
	if (ft_strchr(flags, '#') && elem != 0)
		new = flag_dieze(new, "0x", flags);
	if (ft_strchr(flags, '-'))
		new = flag_moins(new, flags, ft_strlen(new));
	else if (ft_strchr_nb(flags))
		new = flag_nb2(new, flags);
	l_elem->size = ft_strlen(new);
	l_elem->saut += saut;
	l_elem->str = new;
}

void	s_into_ulong_hex_maj(unsigned long long elem, char *flags,
	t_elem *l_elem, size_t saut)
{
	char *new;

	new = ft_itoa_hexa_maj(elem);
	if (ft_strchr(flags, '#') && elem != 0)
		new = flag_dieze(new, "0X", flags);
	if (ft_strchr(flags, '-'))
		new = flag_moins(new, flags, ft_strlen(new));
	else if (ft_strchr_nb(flags))
		new = flag_nb2(new, flags);
	l_elem->size = ft_strlen(new);
	l_elem->saut += saut;
	l_elem->str = new;
}

void	s_into_pointeur(void *elem, char *flags, t_elem *l_elem)
{
	char *new;

	new = ft_itoa_pointeur((unsigned long long)elem);
	if (ft_strchr(flags, '-'))
		new = flag_moins(new, flags, ft_strlen(new));
	else if (ft_strchr_nb(flags))
		new = flag_nb(new, flags, ft_strlen(new));
	l_elem->size = ft_strlen(new);
	l_elem->saut += 1;
	l_elem->str = new;
}
