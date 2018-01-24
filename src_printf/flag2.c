/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flag2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaret <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 17:51:00 by rcaret            #+#    #+#             */
/*   Updated: 2018/01/22 17:51:01 by rcaret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*flag_moins(char *str, char *flags, int j)
{
	char	*new;
	int		i;

	flags = ft_strchr_nb(flags);
	i = ft_atoi(flags);
	if (j >= i)
		return (str);
	if ((new = malloc(i + 1)) == NULL)
		exit(1);
	ft_strcpy3(new, str, i);
	free(str);
	i = i - j;
	while (i--)
		new[j++] = ' ';
	new[j] = 0;
	return (new);
}

char	*flag_plus(char *str)
{
	char *tmp;

	if ((tmp = ft_strjoin("+", str)) == NULL)
		return (NULL);
	free(str);
	return (tmp);
}

void	auxiliaire2(char *str, char *c, char *pos_neg)
{
	*pos_neg = 0;
	if ((*str == '-' || *str == '+') && *c == '0')
	{
		*pos_neg = *str;
		*str = '0';
	}
	if ((*(str + 1) == 'x' || *(str + 1) == 'X') && *c == '0')
	{
		*pos_neg = *(str + 1);
		*(str + 1) = '0';
	}
}


void auxiliaire3(char pos_neg, char *new)
{
	if (pos_neg == 'x' || pos_neg == 'X')
	{
		*(new + 1) = pos_neg;
		return ;
	}
	if (pos_neg)
		*new = pos_neg;
}

char	*flag_nb2(char *str, char *flags)
{
	char	*new;
	char	c;
	int		i;
	int		j;
	char	pos_neg;

	c = (ft_strchr(flags, 'z') ? '0' : ' ');
	auxiliaire2(str, &c, &pos_neg);
	flags = ft_strchr_nb(flags);
	i = ft_atoi(flags);
	j = ft_strlen(str);
	if (j >= i)
		return (str);
	if ((new = malloc(i + 1)) == NULL)
		return (NULL);
	i = i - j;
	j = 0;
	while (i--)
		new[j++] = c;
	new[j] = 0;
	ft_strcat(new + j, str);
	auxiliaire3(pos_neg, new);
	free(str);
	return (new);
}
