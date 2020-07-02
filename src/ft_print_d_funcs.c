/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d_funcs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiwiber <alex_orlov@goodiez.app>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 17:26:13 by tkiwiber          #+#    #+#             */
/*   Updated: 2020/07/02 17:30:38 by tkiwiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_print_d_getnbr(va_list ap, t_mask *mask)
{
	if (!(ft_strncmp(mask->length, "ll", 2)))
		return (ft_ltoa((long long int)va_arg(ap, long long int)));
	else if (!(ft_strncmp(mask->length, "l", 1)))
		return (ft_ltoa((long int)va_arg(ap, long long int)));
	else if (!(ft_strncmp(mask->length, "hh", 2)))
		return (ft_itoa((signed char)va_arg(ap, long long int)));
	else if (!(ft_strncmp(mask->length, "h", 1)))
		return (ft_itoa((short int)va_arg(ap, long long int)));
	else
		return (ft_itoa((int)va_arg(ap, int)));
}

void			ft_print_d_add_wsp(char *str_out, t_mask *mask)
{
	int beg;

	if (mask->plh_wdth)
		ft_memset(str_out, (mask->plh_algn) ? 32 :\
		(mask->plh_w_ch), mask->width);
	if (mask->plh_wdth && mask->plh_w_ch == '0')
		beg = 0;
	else
	{
		if (mask->plh_algn)
			beg = 0;
		else
			beg = (mask->plh_wdth) ? (mask->plh_wdth + mask->trunc) : (0);
	}
	ft_memset(str_out + beg, mask->plh_s_ch, mask->plh_sign);
	beg = mask->plh_sign + (mask->plh_algn ? 0 : mask->plh_wdth);
	ft_memset(str_out + beg, '0', mask->plh_prcs);
}
