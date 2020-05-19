/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_func.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiwiber <alex_orlov@goodiez.app>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 17:54:04 by tkiwiber          #+#    #+#             */
/*   Updated: 2020/05/19 11:37:54 by tkiwiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#	ifndef FT_PRINT_FUNC_H
#	define FT_PRINT_FUNC_H

#include "ft_printf.h"

t_type_field	type_field[] =
{
	{'d', &ft_print_d},
	{'i', &ft_print_d},
    {'%', &ft_print_percent},
    {'\0', 0}
};

#	endif