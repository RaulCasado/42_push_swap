/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racasado <racasado@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 16:26:48 by racasado          #+#    #+#             */
/*   Updated: 2024/11/22 11:58:50 by racasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_strlen_2(const char *s);
int		ft_percentage(void);
int		ft_putchar(va_list argcs);
int		ft_putstring(va_list argcs);
int		ft_putnbr_base(va_list argcs, char *base, int is_signed);
int		ft_putpointer(va_list argcs);
int		ft_printf(const char *format, ...);
char	*itoa_base(long long n, char *base, int is_signed);
char	*pointer_to_string(unsigned long long n, char *base);
int		ft_nbrlen(long long n, int base_len);

#endif