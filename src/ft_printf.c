/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiwiber <alex_orlov@goodiez.app>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/16 21:23:57 by tkiwiber          #+#    #+#             */
/*   Updated: 2020/05/19 16:47:28 by tkiwiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_print_func.h"

int			call_print_func(va_list ap, const char *plh)
{
	int	i;

	i = 0;
	while (type_field[i].type != '\0')
	{
		if (type_field[i].type == plh[ft_strlen(plh) - 1])
			return (type_field[i].print(ap));
		i++;
	}
	return (0);
}



char		*get_placeholder_str(const char *fmt)
{
	const char		type_spf[] = "%diufFeEgGxXoscpaAn";
	const char		*tmp;
	char			*plh;
	size_t			count;

	if (!(plh = (char*)malloc(sizeof(char) * (10))))
		return (NULL);
	tmp = fmt;
	count = 0;
	while (*tmp)
	{
		count++;
		tmp++;
		if (ft_strchr(type_spf, *tmp))
			break ;
	}
	if (*tmp == '\0')
		return (NULL);
	ft_strlcpy(plh, fmt + 1, count + 1);

	return (plh);
}

int 		ft_printf(const char *fmt, ...)
{
	va_list 		ap;
	char			*plh;
	int				nbr;

	nbr = 0;
	va_start(ap, fmt);
	while (*fmt)
	{
		if (*fmt == '%')
		{
			plh = get_placeholder_str(fmt);
			nbr += call_print_func(ap, plh);
			fmt += ft_strlen(plh) + 1;
			free(plh);
		}
		else
		{
			ft_putchar_fd((char)(*fmt), 1);
			fmt++;
			nbr++;
		}
	}
	va_end(ap);
	
	return (nbr);
}
