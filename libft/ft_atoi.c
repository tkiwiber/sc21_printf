/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiwiber <alex_orlov@goodiez.app>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/06 09:35:52 by tkiwiber          #+#    #+#             */
/*   Updated: 2020/05/12 16:42:11 by tkiwiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_skipspaces(const char *str)
{
	while (*str == '\t' || *str == '\n' || *str == '\v' || *str == '\f' \
	|| *str == '\r' || *str == ' ')
		str++;
	return (char *)(str);
}

static int		check_ull_overflow(unsigned long long res, \
unsigned long long prev, int sign)
{
	if (prev > res)
	{
		if (sign > 0)
		{
			return (-1);
		}
		else
			return (0);
	}
	else
	{
		return (1);
	}
}

int				ft_atoi(const char *str)
{
	unsigned long long	res;
	unsigned long long	prev;
	int					sign;
	char				*str_res;

	res = 0;
	sign = 1;
	prev = 0;
	str_res = ft_skipspaces(str);
	if (*str_res == '-' || *str_res == '+')
	{
		if (*str_res++ == '-')
			sign = -1;
	}
	while (*str_res >= '0' && *str_res <= '9')
	{
		res = res * 10 + (*str_res - '0');
		if (check_ull_overflow(res, prev, sign) != 1)
			return (check_ull_overflow(res, prev, sign));
		prev = res;
		str_res++;
	}
	return (res * sign);
}
