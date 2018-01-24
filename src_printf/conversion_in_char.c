/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_in_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaret <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 19:01:49 by rcaret            #+#    #+#             */
/*   Updated: 2018/01/14 19:01:50 by rcaret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	conversion_in_char1(char *flags, char *str,
	t_elem *elem, va_list *a_list)
{
	if (*str == 's')
		return (s_into_string(va_arg(*a_list, char *), flags, elem));
	if (*str == 'd' || *str == 'i' || *str == 'D' ||
	!ft_strncmp(str, "hhd", 3) || !ft_strncmp(str, "hhi", 3))
		return (s_into_int(va_arg(*a_list, int), flags, elem, *str));
	if (*str == 'c')
		return (s_into_char(va_arg(*a_list, int), flags, elem));
	if (*str == 'u' || *str == 'U')
		return (s_into_long_long(va_arg(*a_list, unsigned int),
		flags, elem, 1));
		if (*str == 'S')
		return (s_into_unicode(va_arg(*a_list, wchar_t *), flags, elem));
	if (*str == 'p')
		return (s_into_pointeur(va_arg(*a_list, void *), flags, elem));
	if (*str == 'C')
		return (s_into_string(traite_wchar(va_arg(*a_list, wchar_t)),
		flags, elem));
		if (*str == 'o')
		return (s_into_ulong_oct(va_arg(*a_list, unsigned int),
		flags, elem, 1));
		if (*str == 'x')
		return (s_into_ulong_hex_min(va_arg(*a_list, unsigned int),
		flags, elem, 1));
		return (conversion_in_char2(flags, str, elem, a_list));
}

void	conversion_in_char2(char *flags, char *str,
	t_elem *elem, va_list *a_list)
{
	if (!ft_strncmp(str, "hu", 2))
		return (s_into_long_long((unsigned short)va_arg(*a_list, int),
		flags, elem, 2));
		if (!ft_strncmp(str, "ho", 2))
		return (s_into_ulong_oct((unsigned short)va_arg(*a_list, unsigned long),
		flags, elem, 2));
		if (!ft_strncmp(str, "hx", 2))
		return (s_into_ulong_hex_min((unsigned short)va_arg(*a_list,
		unsigned long), flags, elem, 2));
		if (!ft_strncmp(str, "hX", 2))
		return (s_into_ulong_hex_maj((unsigned short)va_arg(*a_list,
		unsigned long), flags, elem, 2));
		if (!ft_strncmp(str, "hhd", 3) || !ft_strncmp(str, "hhi", 3))
		return (s_into_long_long((signed char)va_arg(*a_list, int),
		flags, elem, 3));
		if (!ft_strncmp(str, "hhu", 3))
		return (s_into_long_long((unsigned char)va_arg(*a_list, unsigned int),
		flags, elem, 3));
		if (!ft_strncmp(str, "hho", 3))
		return (s_into_ulong_oct((unsigned char)va_arg(*a_list, unsigned int),
		flags, elem, 3));
		if (!ft_strncmp(str, "hhx", 3))
		return (s_into_ulong_hex_min((unsigned char)va_arg(*a_list,
		unsigned int), flags, elem, 3));
		return (conversion_in_char3(flags, str, elem, a_list));
}

void	conversion_in_char3(char *flags, char *str,
	t_elem *elem, va_list *a_list)
{
	if (!ft_strncmp(str, "lX", 2))
		return (s_into_ulong_hex_maj(va_arg(*a_list, unsigned long),
		flags, elem, 2));
		if (!ft_strncmp(str, "lld", 3) || !ft_strncmp(str, "lli", 3))
		return (s_into_long_long(va_arg(*a_list, long long), flags, elem, 3));
	if (!ft_strncmp(str, "llu", 3))
		return (s_into_ulong_long(va_arg(*a_list, unsigned long long),
		flags, elem));
		if (!ft_strncmp(str, "llo", 3))
		return (s_into_ulong_oct(va_arg(*a_list, unsigned long long),
		flags, elem, 3));
		if (!ft_strncmp(str, "llx", 3))
		return (s_into_ulong_hex_min(va_arg(*a_list, unsigned long long),
		flags, elem, 3));
		if (!ft_strncmp(str, "llX", 3))
		return (s_into_ulong_hex_maj(va_arg(*a_list, unsigned long long),
		flags, elem, 3));
		if (!ft_strncmp(str, "zd", 2) || !ft_strncmp(str, "zi", 2))
		return (s_into_long_long((intmax_t)va_arg(*a_list, long),
		flags, elem, 2));
		if (!ft_strncmp(str, "zu", 2))
		return (s_into_long_long((size_t)va_arg(*a_list, unsigned int),
		flags, elem, 2));
		return (conversion_in_char4(flags, str, elem, a_list));
}

void	conversion_in_char4(char *flags, char *str,
	t_elem *elem, va_list *a_list)
{
	if (*str == 'X')
		return (s_into_ulong_hex_maj(va_arg(*a_list, unsigned int),
	flags, elem, 1));
		if (!ft_strncmp(str, "hd", 2) || !ft_strncmp(str, "hi", 2))
		return (s_into_long_long((short)va_arg(*a_list, int), flags, elem, 2));
	if (!ft_strncmp(str, "lu", 2))
		return (s_into_long_long(va_arg(*a_list, unsigned long),
		flags, elem, 2));
		if (!ft_strncmp(str, "lo", 2))
		return (s_into_ulong_oct(va_arg(*a_list, unsigned long),
		flags, elem, 2));
		if (!ft_strncmp(str, "lx", 2))
		return (s_into_ulong_hex_min(va_arg(*a_list, unsigned long),
		flags, elem, 2));
		if (!ft_strncmp(str, "zx", 2))
		return (s_into_ulong_hex_min((size_t)va_arg(*a_list, unsigned int),
		flags, elem, 2));
		if (!ft_strncmp(str, "zX", 2))
		return (s_into_ulong_hex_maj((size_t)va_arg(*a_list, unsigned int),
		flags, elem, 2));
		if (!ft_strncmp(str, "zo", 2))
		return (s_into_ulong_oct((size_t)va_arg(*a_list, unsigned int),
		flags, elem, 2));
		return (conversion_in_char5(flags, str, elem, a_list));
}

void	conversion_in_char5(char *flags, char *str,
	t_elem *elem, va_list *a_list)
{
	if (!ft_strncmp(str, "hhX", 3))
		return (s_into_ulong_hex_maj((unsigned char)va_arg(*a_list,
		unsigned int), flags, elem, 3));
		if (!ft_strncmp(str, "ld", 2) || !ft_strncmp(str, "li", 2))
		return (s_into_long_long(va_arg(*a_list, long), flags, elem, 2));
	if (!ft_strncmp(str, "jd", 2) || !ft_strncmp(str, "ji", 2))
		return (s_into_long_long(va_arg(*a_list, long long), flags, elem, 2));
	if (!ft_strncmp(str, "ju", 2))
		return (s_into_long_long((uintmax_t)va_arg(*a_list, unsigned long long),
		flags, elem, 2));
		if (!ft_strncmp(str, "jo", 2))
		return (s_into_ulong_oct((uintmax_t)va_arg(*a_list, unsigned long long),
		flags, elem, 2));
		if (!ft_strncmp(str, "jx", 2))
		return (s_into_ulong_hex_min((uintmax_t)va_arg(*a_list, unsigned long long),
		flags, elem, 2));
		if (!ft_strncmp(str, "jX", 2))
		return (s_into_ulong_hex_maj((uintmax_t)va_arg(*a_list, unsigned long long),
		flags, elem, 2));
		while (*str == 'h' || *str == 'j' || *str == 'l' || *str == 'z' ||
		(*str <= '9' && *str >= '0'))
		str++;
	if (*str == '%')
		return (s_into_string("%", flags, elem));
	elem->size = -1;
}
