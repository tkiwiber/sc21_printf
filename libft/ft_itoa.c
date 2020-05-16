/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiwiber <alex_orlov@goodiez.app>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 18:15:06 by tkiwiber          #+#    #+#             */
/*   Updated: 2020/05/08 20:06:50 by tkiwiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digit_nbr(long long int n)
{
	int	d_nbr;

	if (n < 0)
	{
		d_nbr = 2;
		n = -n;
	}
	else
		d_nbr = 1;
	while ((n /= 10) > 0)
	{
		d_nbr++;
	}
	return (d_nbr);
}

static void	*ft_reverse(char *str)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = ft_strlen(str) - 1;
	while (i < j)
	{
		c = str[i];
		str[i] = str[j];
		str[j] = c;
		i++;
		j--;
	}
	return (str);
}

static int	check_zero(char *str, long long int num)
{
	if (num == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return (1);
	}
	return (0);
}

char		*ft_itoa(int n)
{
	int				i;
	int				sign;
	char			*str;
	long long int	num;

	num = (long long int)n;
	str = (char*)malloc(sizeof(char) * (digit_nbr(num) + 1));
	if (!str)
		return (NULL);
	i = 0;
	if (check_zero(str, num))
		return (str);
	if ((sign = num) < 0)
		num = -num;
	while (num > 0)
	{
		str[i] = num % 10 + '0';
		num = num / 10;
		i++;
	}
	if (sign < 0)
		str[i++] = '-';
	str[i++] = '\0';
	return (ft_reverse(str));
}
