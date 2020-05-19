/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiwiber <alex_orlov@goodiez.app>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 16:58:46 by tkiwiber          #+#    #+#             */
/*   Updated: 2020/05/17 21:23:28 by tkiwiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_digit(int n) 
{ 
    if (n == 0) 
        return 0; 
    return 1 + count_digit(n / 10); 
} 

int 		ft_print_d(va_list ap)
{
	int nbr;

	nbr = va_arg(ap, int);
	ft_putnbr_fd(nbr, 1);
	return (count_digit(nbr));
}
