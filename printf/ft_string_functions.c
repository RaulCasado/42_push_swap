/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_functions.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: racasado <racasado@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 19:33:35 by racasado          #+#    #+#             */
/*   Updated: 2024/11/22 11:59:16 by racasado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen_2(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_nbrlen(long long n, int base_len)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
		n = -n;
	while (n > 0)
	{
		n /= base_len;
		len++;
	}
	return (len);
}
