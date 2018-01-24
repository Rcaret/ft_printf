/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcaret <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 18:11:40 by rcaret            #+#    #+#             */
/*   Updated: 2018/01/22 18:27:51 by rcaret           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "stdio.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct	s_elem
{
	char		*str;
	size_t		saut;
	int			size;
}				t_elem;

int				ft_printf(const char *restrict format, ...);

void			check_conversion(const char *str,
	va_list *a_list, t_elem *elem);
void			conversion_in_char5(char *flags, char *str,
	t_elem *elem, va_list *a_list);
void			conversion_in_char4(char *flags, char *str,
	t_elem *elem, va_list *a_list);
void			conversion_in_char3(char *flags, char *str,
	t_elem *elem, va_list *a_list);
void			conversion_in_char2(char *flags, char *str,
	t_elem *elem, va_list *a_list);
void			conversion_in_char1(char *flags, char *str,
	t_elem *elem, va_list *a_list);

void			s_into_string(char *elem, char *flags, t_elem *l_elem);
void			s_into_int(int elem, char *flags, t_elem *l_elem, char c);
void			s_into_char(char elem, char *flags, t_elem *l_elem);
void			s_into_uint(unsigned int elem, char *flags, t_elem *l_elem);
void			s_into_unicode(wchar_t *elem, char *flags, t_elem *l_elem);
void			s_into_ulong_oct(unsigned long long elem,
	char *flags, t_elem *l_elem, size_t saut);
void			s_into_ulong_hex_min(unsigned long long elem,
	char *flags, t_elem *l_elem, size_t saut);
void			s_into_ulong_hex_maj(unsigned long long elem,
	char *flags, t_elem *l_elem, size_t saut);
void			s_into_long_long(long long elem, char *flags,
	t_elem *l_elem, size_t saut);
void			s_into_ulong_long(unsigned long long elem,
	char *flags, t_elem *l_elem);
void			s_into_pointeur(void *elem, char *flags, t_elem *l_elem);

char			*flag_espace(char *str);
char			*flag_nb_unicode(char *str, char *flags, int taille);
char			*flag_moins(char *str, char *flags, int j);
char			*flag_plus(char *str);
char			*flag_nb(char *str, char *flags, int j);
char			*flag_dieze(char *str, char *ajout, char *flags);
char			*flag_nb2(char *str, char *flags);

char			*traite_wchar(wchar_t data);

char			*allocitoa_dec(long long n, size_t *j);
char			*allocitoa_udec(unsigned long long n, size_t *j);
char			*allocitoa_hex(unsigned long long n, size_t *j);
char			*allocitoa_oct(unsigned long long n, size_t *j);
char			*allocitoa_hex_pointeur(unsigned long long n, size_t *j);
char			*ft_strjoin_char(char *s1, char c);
char			*ft_itoa_long(long n);
char			*ft_itoa_uint(unsigned int n);
char			*ft_itoa_ulong(unsigned long n);
char			*ft_itoa_long_long(long long n);
char			*ft_itoa_ulong_long(unsigned long long n);
char			*ft_itoa_octale(unsigned long long n);
char			*ft_itoa_hexa_min(unsigned long long n);
char			*ft_itoa_hexa_maj(unsigned long long n);
char			*ft_itoa_pointeur(unsigned long long n);
char			*ft_strchr_nb(char *s1);
char			*ft_strcpy2(char *dest, char *src, int i);
char			*ft_strcpy3(char *dest, char *src, int i);

char			*ft_strdup(const char *s1);
char			*ft_strchr(const char *s, int c);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
size_t			ft_strlen(const char *str);
int				ft_atoi(const char *str);
char			*ft_itoa(int n);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strcat(char *dest, const char *src);
char			*ft_strcpy(char *dest, const char *src);

#endif
