/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiwiber <alex_orlov@goodiez.app>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 10:16:01 by gmorros           #+#    #+#             */
/*   Updated: 2020/07/17 11:51:01 by tkiwiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef FT_PRINTF_H
#	define FT_PRINTF_H

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "../libft/libft.h"

typedef struct	s_mask
{
	char		type;
	char		*length;
	int			precision;
	int			width;
	char		*flag;
	int			parameter;
	int			plh_size;
	int			plh_sign;
	int			plh_wdth;
	int			plh_prcs;
	char		plh_s_ch;
	char		plh_w_ch;
	int			plh_old;
	int			plh_algn;
	int			trunc;
	int			prefix;
}				t_mask;

typedef struct	s_type_field
{
	int			type;
	int			(*print)(va_list ap, t_mask *mask);
}				t_type_field;

int				ft_printf(const char *string, ...);
char			*ft_print_d_getnbr(va_list ap, t_mask *mask);
void			ft_print_d_add_wsp(char *str_out, t_mask *mask);
int				ft_print_d(va_list ap, t_mask *mask);
int				ft_print_u(va_list ap, t_mask *mask);
void			ft_print_u_add_wsp(char *str_out, t_mask *mask);
int				ft_print_x(va_list ap, t_mask *mask);
int				ft_print_o(va_list ap, t_mask *mask);
int				ft_print_p(va_list ap, t_mask *mask);
int				ft_print_c(va_list ap, t_mask *mask);
int				ft_print_s(va_list ap, t_mask *mask);
int				ft_print_pct(va_list ap, t_mask *mask);
void			delete_mask(t_mask *mask);
t_mask			*ft_mask_get(va_list ap, const char *plh);
void			mask_get_parameter(const char **plh, t_mask *mask);
void			mask_get_flag(const char **plh, t_mask *mask);
void			mask_get_width(const char **plh, t_mask *mask, va_list ap);
void			mask_get_precision(const char **plh, t_mask *mask, va_list ap);
void			mask_get_length(const char **plh, t_mask *mask);
int				ft_vsnprintf(char *str, size_t len, const char *fmt,\
				va_list ap);

#	endif
