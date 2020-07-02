/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_placeholder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiwiber <alex_orlov@goodiez.app>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 09:58:17 by tkiwiber          #+#    #+#             */
/*   Updated: 2020/07/02 12:25:27 by tkiwiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			mask_get_type(const char **plh, t_mask *mask)
{
	const char		*tmp;
	static char		*typ_set = "diufFeEgGxXoscpaAn";

	tmp = *plh;
	if (!(ft_strchr(typ_set, *tmp)))
	{
		mask->type = '\0';
		return ;
	}
	mask->type = *tmp;
	(*plh)++;
}

t_mask				*create_mask(void)
{
	t_mask			*mask;

	if (!(mask = (t_mask*)malloc(sizeof(t_mask))))
		return (NULL);
	mask->parameter = 0;
	mask->flag = NULL;
	mask->length = NULL;
	mask->precision = 0;
	mask->plh_algn = 0;
	mask->plh_old = 0;
	mask->plh_prcs = 0;
	mask->plh_s_ch = 0;
	mask->plh_sign = 0;
	mask->plh_size = 0;
	mask->plh_w_ch = ' ';
	mask->plh_wdth = 0;
	mask->type = 's';
	mask->width = 0;
	mask->trunc = 0;
	mask->prefix = 0;
	return (mask);
}

t_mask				*ft_mask_get(va_list ap, const char *plh)
{
	t_mask			*mask;

	mask = create_mask();
	mask_get_parameter(&plh, mask);
	mask_get_flag(&plh, mask);
	mask_get_width(&plh, mask, ap);
	mask_get_precision(&plh, mask, ap);
	mask_get_length(&plh, mask);
	mask_get_type(&plh, mask);
	return (mask);
}
