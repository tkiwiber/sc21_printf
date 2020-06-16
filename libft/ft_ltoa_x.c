/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ltoa_x.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiwiber <alex_orlov@goodiez.app>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 18:15:06 by tkiwiber          #+#    #+#             */
/*   Updated: 2020/06/15 22:03:18 by tkiwiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	                digit_nbr(long long int n, int base)
{
	int	                    d_nbr;

	if (n < 0)
	{
		d_nbr = 2;
		n = -n;
	}
	else
		d_nbr = 1;
	while ((n /= base) > 0)
	{
		d_nbr++;
	}
	return (d_nbr);
}

static void	                *ft_reverse(char *str)
{
	int		                i;
	int	                	j;
	char                	c;

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

static int	                check_zero(char *str, long long int num)
{
	if (num == 0)
	{
		str[0] = '0';
		str[1] = '\0';
		return (1);
	}
	return (0);
}

char	                	*ft_ltoa_x(long long int n, int base, char up)
{
	int		        		i;
	long long int	        sign;
	char			        *str;
	long long int	        num;
    static char             digits[] = "0123456789abcdef0123456789ABCDEF";

	num = (long long int)n;
	str = (char*)malloc(sizeof(char) * (digit_nbr(num, base) + 1));
	if (!str)
		return (NULL);
	i = 0;
	if (check_zero(str, num))
		return (str);
	if ((sign = num) < 0)
		num = -num;
	while (num > 0)
	{
		str[i] = digits[num % base + base * up];
		num = num / base;
		i++;
	}
	if (sign < 0)
		str[i++] = '-';
	str[i++] = '\0';
	return (ft_reverse(str));
}
