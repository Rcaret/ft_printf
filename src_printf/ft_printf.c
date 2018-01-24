/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaret <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 18:07:09 by rcaret            #+#    #+#             */
/*   Updated: 2018/01/12 18:07:11 by rcaret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		afficher_elem(const char *str1, int taille1, char *str2, int taille2)
{
	write(1, str1, taille1);
	write(1, str2, taille2);
	free(str2);
	return (taille1 + taille2);
}

int		verif_conversion(t_elem *elem)
{
	if (elem->size == -1 || elem->str == NULL)
	{
		free(elem);
		return (1);
	}
	return (0);
}

void	set_value(int *j, int *i, int *retour, t_elem *elem)
{
	elem->size = 0;
	elem->str = NULL;
	*j = 0;
	*retour = 0;
	*i = 0;
}

int	afficher(const char *str)
{
	int i;

	i = ft_strlen(str);
	write(1, str, i);
	return i;
}

int		ft_printf(const char *restrict format, ...)
{
	va_list	a_list;
	int		i;
	int		j;
	t_elem	*elem;
	int		retour;

	if ((elem = malloc(sizeof(t_elem))) == NULL)
		return (-1);
	set_value(&j, &i, &retour, elem);
	va_start(a_list, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			check_conversion(format + i + 1, &a_list, elem);
			if (verif_conversion(elem))
				return (-1);
			retour += afficher_elem(format + j, i - j, elem->str, elem->size);
			i += elem->saut;
			j = i + 1;
		}
		i++;
	}
	free(elem);
	if (j == 0)
	{
		j = ft_strlen(format);
		write(1, format, ft_strlen(format));
		return (j);
	}
	retour += afficher(format + j);
	return (retour);
}
