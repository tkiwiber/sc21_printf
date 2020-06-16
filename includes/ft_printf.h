/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiwiber <alex_orlov@goodiez.app>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 10:16:01 by gmorros           #+#    #+#             */
/*   Updated: 2020/06/16 13:39:56 by tkiwiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef FT_PRINTF_H
#	define FT_PRINTF_H

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "../libft/libft.h"

/*
#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[38m"
#define RESET "\x1B[0m"
*/

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
}				t_mask;

typedef struct	s_type_field
{
	int			type;
	int			(*print)(va_list ap, t_mask *mask);
}				t_type_field;

int				ft_printf(const char *string, ...);
int				ft_print_d(va_list ap, t_mask *mask);
int 			ft_print_u(va_list ap, t_mask *mask);
int 			ft_print_x(va_list ap, t_mask *mask);
int 			ft_print_p(va_list ap, t_mask *mask);
int 			ft_print_c(va_list ap, t_mask *mask);
int 			ft_print_s(va_list ap, t_mask *mask);
int				ft_print_pct(va_list ap, t_mask *mask);
t_mask  		*ft_mask_get(va_list ap, const char *plh);
int 			ft_vsnprintf(char *str, size_t len, const char *fmt, va_list ap);

#	endif
