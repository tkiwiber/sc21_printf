/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_p.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiwiber <alex_orlov@goodiez.app>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 16:58:46 by tkiwiber          #+#    #+#             */
/*   Updated: 2020/06/17 15:33:47 by tkiwiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char			*ft_print_p_getnbr(va_list ap, char up)
{	
		return ft_ltoa_x((unsigned long int)va_arg(ap, unsigned long int), 16, up);
}

static void			ft_print_conversion(char *str_proto, t_mask *mask)
{
	mask->prefix = 2;
	mask->plh_w_ch = ' ';
	mask->plh_old = (int)ft_strlen(str_proto);
	(mask->precision < mask->plh_old) ? (mask->plh_prcs =  mask->plh_old) :\
	(mask->plh_prcs = mask->precision);
	if (mask->trunc && !ft_strncmp(str_proto, "0", 2))
		(mask->plh_prcs = 0) ;
	(mask->width > mask->plh_prcs + mask->prefix) ? (mask->plh_wdth = \
	mask->width) : (mask->plh_wdth = 0);
	(mask->plh_wdth) ? (mask->plh_size = mask->plh_wdth) :\
	(mask->plh_size = mask->plh_prcs + mask->prefix);
	(ft_strchr(mask->flag, '-')) ? (mask->plh_algn = 1) : (mask->plh_algn = 0);
}

static void			ft_print_add_width(char *str_out, t_mask *mask)
{
	if (mask->plh_wdth)
		ft_memset(str_out, (mask->plh_algn) ? 32 : (mask->plh_w_ch), mask->width);
}

static void			ft_print_add_precision(char *str_out, t_mask *mask)
{
	int				beg;

	if (mask->plh_algn) 
		beg = mask->prefix;
	else
		beg = mask->plh_size - mask->plh_prcs;
	ft_memset(str_out + beg, '0', mask->plh_prcs);
}

static void			ft_print_add_prefix(char *str_out, t_mask *mask)
{
	int				beg;

	if (mask->plh_algn) 
		beg = 0;
	else
		beg = mask->plh_size - mask->plh_prcs - mask->prefix;
	ft_memcpy(str_out + beg, "0x", mask->prefix);
}

static void			ft_print_add_word(char *str_out, char *str, t_mask *mask)
{
	int				beg;

	if (mask->plh_algn) 
		beg = mask->prefix + mask->plh_prcs - mask->plh_old;
	else
		beg = mask->plh_size - mask->plh_old;
	ft_memcpy(str_out + beg, str, mask->plh_old);
}

static char			*ft_print_p_get_strout(va_list ap, t_mask *mask)
{
	char			*str_out;
	char			*str_proto;
    char            up;

    up = 0;
	str_proto = ft_print_p_getnbr(ap, up);
	ft_print_conversion(str_proto, mask);
	if (!(str_out = (char*)malloc(sizeof(char) * (mask->plh_size + 1))))
		return (NULL);
    ft_print_add_width(str_out, mask);
	ft_print_add_precision(str_out, mask);
	ft_print_add_prefix(str_out, mask);
	if (!(mask->trunc && !ft_strncmp(str_proto, "0", 2)))
		ft_print_add_word(str_out, str_proto, mask);
	str_out[mask->plh_size] = '\0';
	free(str_proto);
	return (str_out);
}

int 				ft_print_p(va_list ap, t_mask *mask)
{
	char			*str_to_out;
	int				len;

	str_to_out = ft_print_p_get_strout(ap, mask);
	len = ft_strlen(str_to_out);
	ft_putstr_fd(str_to_out, 1);
	free(str_to_out);
	free(mask);
	return (len);
}
