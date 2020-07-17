/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_placeholder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiwiber <alex_orlov@goodiez.app>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 09:58:17 by tkiwiber          #+#    #+#             */
/*   Updated: 2020/07/17 11:53:25 by tkiwiber         ###   ########.fr       */
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
	ft_memset(mask, 0, sizeof(t_mask));
	mask->plh_w_ch = ' ';
	mask->type = 's';
	return (mask);
}

void				delete_mask(t_mask *mask)
{
	free(mask->flag);
	free(mask->length);
	free(mask);
}

t_mask				*ft_mask_get(va_list ap, const char *plh)
{
	t_mask			*mask;

	if (!(mask = create_mask()))
		return (NULL);
	mask_get_parameter(&plh, mask);
	mask_get_flag(&plh, mask);
	mask_get_width(&plh, mask, ap);
	mask_get_precision(&plh, mask, ap);
	mask_get_length(&plh, mask);
	mask_get_type(&plh, mask);
	return (mask);
}
