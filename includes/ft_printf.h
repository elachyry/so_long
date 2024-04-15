/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melachyr <melachyr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 08:01:04 by melachyr          #+#    #+#             */
/*   Updated: 2024/01/18 11:46:08 by melachyr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_printf_hex(unsigned int number, const char fs);
int		ft_putstr(const char *str);
int		ft_putchar(const unsigned char c);
int		ft_printf_ptr(size_t ptr);
int		ft_putptr(size_t ptr);
int		ft_ptrlen(size_t ptr);
int		ft_printf_unsigned(unsigned int number);
char	*ft_utoa(unsigned int n);
int		ft_udiglen(unsigned int n);
int		ft_printf_int(int number);
char	*ft_itoa(int n);
// int		ft_diglen(int n);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *str);

#endif
