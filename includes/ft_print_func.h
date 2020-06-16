/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_func.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiwiber <alex_orlov@goodiez.app>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 17:54:04 by tkiwiber          #+#    #+#             */
/*   Updated: 2020/06/16 12:20:46 by tkiwiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef FT_PRINT_FUNC_H
#	define FT_PRINT_FUNC_H

#include "ft_printf.h"

t_type_field	type_field[] =
{
	{'d', &ft_print_d},
	{'i', &ft_print_d},
    {'u', &ft_print_u},
    {'x', &ft_print_x},
    {'X', &ft_print_x},
    {'p', &ft_print_p},
    {'c', &ft_print_c},
    {'s', &ft_print_s},
    {'%', &ft_print_pct},
    {'\0', 0}
};

#	endif