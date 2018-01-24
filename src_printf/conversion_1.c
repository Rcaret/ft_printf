/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaret <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 19:06:23 by rcaret            #+#    #+#             */
/*   Updated: 2018/01/14 19:06:24 by rcaret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	s_into_string(char *elem, char *flags, t_elem *l_elem)
{
	char *new;

	if (!elem || (int)elem == 0x100)
		new = ft_strdup("(null)");
	else
		new = ft_strdup(elem);
	if (ft_strchr(flags, '-'))
		new = flag_moins(new, flags, ft_strlen(new));
	else if (ft_strchr_nb(flags))
		new = flag_nb(new, flags, ft_strlen(new));
	l_elem->size = ft_strlen(new);
	l_elem->saut += 1;
	l_elem->str = new;
}

void	s_into_int(int elem, char *flags, t_elem *l_elem, char c)
{
	char *new;

	new = (c == 'h' ? ft_itoa((int)((char)elem)) : ft_itoa(elem));
	if (ft_strchr(flags, '+') && *new != '-')
		new = flag_plus(new);
	else if (ft_strchr(flags, ' ') && elem >= 0)
		new = flag_espace(new);
	if (ft_strchr(flags, '-'))
		new = flag_moins(new, flags, ft_strlen(new));
	else if (ft_strchr_nb(flags))
		new = flag_nb(new, flags, ft_strlen(new));
	l_elem->size = ft_strlen(new);
	l_elem->saut += (c == 'h' ? 3 : 1);
	l_elem->str = new;
}

void	s_into_char(char elem, char *flags, t_elem *l_elem)
{
	char *new;

	new = ft_strdup(" ");
	new[0] = elem;
	if (ft_strchr(flags, '-'))
		new = flag_moins(new, flags, 1);
	else if (ft_strchr_nb(flags))
		new = flag_nb(new, flags, 1);
	l_elem->size = elem == 0 ? ft_strlen(new) + 1 : ft_strlen(new);
	l_elem->saut += 1;
	l_elem->str = new;
}

void	s_into_unicode(wchar_t *elem, char *flags, t_elem *l_elem)
{
	char	*new;
	char	*tmp;
	size_t	i;

	if (!(l_elem->size = -1) || !elem)
		new = ft_strdup("(null)");
	else
	{
		i = 0;
		if ((new = malloc(ft_strlen((char *)elem) * 4)) == NULL)
			return ;
		while (elem[i])
		{
			if ((tmp = traite_wchar(elem[i++])) == NULL)
				return ;
			ft_strcpy2(new, tmp, i == 1 ? 0 : 1);
			free(tmp);
		}
	}
	if (!(l_elem->saut += 1) || ft_strchr(flags, '-'))
		new = flag_moins(new, flags, ft_strlen(new));
	else if (ft_strchr_nb(flags))
		new = flag_nb_unicode(new, flags, i);
	l_elem->size = ft_strlen(new);
	l_elem->str = new;
}

void	s_into_long_long(long long elem, char *flags,
	t_elem *l_elem, size_t saut)
{
	char *new;

	new = ft_itoa_long_long(elem);
	if (ft_strchr(flags, '-'))
		new = flag_moins(new, flags, ft_strlen(new));
	else if (ft_strchr_nb(flags))
		new = flag_nb(new, flags, ft_strlen(new));
	l_elem->size = ft_strlen(new);
	l_elem->saut += saut;
	l_elem->str = new;
}
