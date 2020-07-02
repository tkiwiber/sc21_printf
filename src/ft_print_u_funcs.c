/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_u_funcs.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiwiber <alex_orlov@goodiez.app>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 19:05:20 by tkiwiber          #+#    #+#             */
/*   Updated: 2020/07/02 19:06:34 by tkiwiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_print_u_add_wsp(char *str_out, t_mask *mask)
{
	int				beg;

	if (mask->plh_wdth)
		ft_memset(str_out, (mask->plh_algn) ? 32 : (mask->plh_w_ch),\
		mask->width);
	if (mask->plh_wdth && mask->plh_w_ch == '0')
		beg = 0;
	else
		beg = (mask->plh_algn ? 0 : mask->plh_wdth);
	ft_memset(str_out + beg, mask->plh_s_ch, mask->plh_sign);
	beg = mask->plh_sign + (mask->plh_algn ? 0 : mask->plh_wdth);
	ft_memset(str_out + beg, '0', mask->plh_prcs);
}
