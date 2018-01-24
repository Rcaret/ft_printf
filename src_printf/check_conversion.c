/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaret <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 17:49:10 by rcaret            #+#    #+#             */
/*   Updated: 2018/01/13 17:49:12 by rcaret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	lire_flag(const char *str, char **flags)
{
	size_t	i;
	char	c;

	i = 0;
	*flags = ft_strdup("");
	if (*flags == NULL)
		exit(1);
	while (str[i] == ' ' || str[i] == '+' || str[i] == '#'
	|| (str[i] >= '0' && str[i] <= '9') || str[i] == '-' || str[i] == '.')
	{
		c = str[i];
		if (str[i] == '0')
			if (str[i - 1] < '0' || str[i - 1] > '9')
				c = 'z';
		*flags = ft_strjoin_char(*flags, c);
		i++;
	}
	return (i);
}

void	check_conversion(const char *str, va_list *a_list, t_elem *elem)
{
	char	*flags;

	elem->saut = lire_flag(str, &(flags));
	conversion_in_char1(flags, (char *)str + elem->saut, elem, a_list);
	if (elem->size == -1)
		return ;
	free(flags);
}
