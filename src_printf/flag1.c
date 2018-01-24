/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaret <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 21:09:30 by rcaret            #+#    #+#             */
/*   Updated: 2018/01/14 21:09:31 by rcaret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*flag_dieze(char *str, char *ajout, char *flags)
{
	char *tmp;
	int i;

	flags = ft_strchr_nb(flags);
	if (flags != NULL)
		i = ft_atoi(flags);
	else
		i = 0;
	if ((tmp = ft_strjoin(ajout, str)) == NULL)
		return (NULL);
	free(str);
	return (tmp);
}

char	*flag_espace(char *str)
{
	char *tmp;

	if ((tmp = ft_strjoin(" ", str)) == NULL)
		return (NULL);
	free(str);
	return (tmp);
}

char	*flag_nb_unicode(char *str, char *flags, int taille)
{
	char	*new;
	int		i;
	int		j;

	flags = ft_strchr_nb(flags);
	i = ft_atoi(flags);
	j = taille;
	if (j >= i)
		return (str);
	if ((new = malloc(i + 1)) == NULL)
		return (NULL);
	i = i - j;
	j = 0;
	while (i--)
		new[j++] = ' ';
	new[j] = 0;
	ft_strcat(new + j, str);
	free(str);
	return (new);
}

void	auxiliaire(char *str, char *c, char *pos_neg)
{
	if ((*str == '-' || *str == '+') && *c == '0')
	{
		*pos_neg = *str;
		*str = *c;
	}
}

char	*flag_nb(char *str, char *flags, int j)
{
	char	*new;
	char	c;
	int		i;
	char	pos_neg;

	c = (ft_strchr(flags, 'z') ? '0' : ' ');
	flags = ft_strchr_nb(flags);
	i = ft_atoi(flags);
	if ((pos_neg = 0) || j >= i)
		return (str);
	auxiliaire(str, &c, &pos_neg);
	if ((new = malloc(i + 1)) == NULL)
		return (NULL);
	i = i - j;
	j = 0;
	while (i--)
		new[j++] = c;
	new[j] = 0;
	ft_strcat(new + j, str);
	if (pos_neg)
		*new = pos_neg;
	free(str);
	return (new);
}
