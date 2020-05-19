/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiwiber <alex_orlov@goodiez.app>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 10:16:01 by gmorros           #+#    #+#             */
/*   Updated: 2020/05/19 17:16:29 by tkiwiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef FT_PRINTF_H
#	define FT_PRINTF_H

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "../libft/libft.h"

#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

typedef struct	s_type_field
{
	int			type;
	int			(*print)(va_list ap);
}				t_type_field;

typedef struct	s_mask
{
	char		type;
	char		*length;
	int			precision;
	int			width;
	char		*flag;
	int			parameter;
}				t_mask;

int				ft_printf(const char *string, ...);
int				ft_print_d(va_list ap);
int				ft_print_percent(va_list ap);
t_mask  		*ft_mask_get(char *plh);

#	endif
