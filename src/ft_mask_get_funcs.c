/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mask_get_funcs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiwiber <alex_orlov@goodiez.app>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 12:22:04 by tkiwiber          #+#    #+#             */
/*   Updated: 2020/07/17 12:13:55 by tkiwiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				mask_get_parameter(const char **plh, t_mask *mask)
{
	const char		*tmp;
	static char		prm_set[] = "$";
	char			*prm_str;

	tmp = *plh;
	while (*tmp != '\0' && ft_strchr(prm_set, *tmp) == NULL)
		tmp++;
	if (*tmp == '\0')
	{
		mask->parameter = 0;
		return ;
	}
	if (!(prm_str = (char*)malloc(sizeof(char) * (ft_strlen(*plh) \
	- ft_strlen(tmp) + sizeof(char)))))
		return ;
	ft_strlcpy(prm_str, *plh, ft_strlen(*plh) - ft_strlen(tmp) + sizeof(char));
	mask->parameter = ft_atoi(prm_str);
	free(prm_str);
	*plh = tmp + sizeof(char);
}

void				mask_get_flag(const char **plh, t_mask *mask)
{
	const char		*tmp;
	static char		flg_set[] = "-+ 0'#";
	char			*flg_str;

	tmp = *plh;
	while (*tmp != '\0' && ft_strchr(flg_set, *tmp) != NULL)
		tmp++;
	if (*tmp == '\0')
	{
		mask->flag = NULL;
		return ;
	}
	if (!(flg_str = (char*)malloc(sizeof(char) * (ft_strlen(*plh) - \
	ft_strlen(tmp) + sizeof(char)))))
		return ;
	ft_strlcpy(flg_str, *plh, ft_strlen(*plh) - ft_strlen(tmp) + sizeof(char));
	if (!(mask->flag = (char*)malloc(sizeof(char) * (ft_strlen(flg_str)\
	+ sizeof(char)))))
		return ;
	ft_strlcpy(mask->flag, flg_str, ft_strlen(flg_str) + sizeof(char));
	free(flg_str);
	*plh = tmp;
}

void				mask_get_width(const char **plh, t_mask *mask, va_list ap)
{
	const char		*tmp;
	char			*wdt_str;
	char			*str_to_free;

	tmp = *plh;
	while (*tmp != '\0' && (ft_isdigit(*tmp) || ft_strchr("*", *tmp) != NULL))
		tmp++;
	if (*tmp == '\0')
		return ;
	if (!(wdt_str = (char*)malloc(sizeof(char) * (ft_strlen(*plh) - \
	ft_strlen(tmp) + sizeof(char)))))
		return ;
	ft_strlcpy(wdt_str, *plh, ft_strlen(*plh) - ft_strlen(tmp) + sizeof(char));
	(wdt_str[0] == '*') ? (mask->width = va_arg(ap, int)) : \
	(mask->width = ft_atoi(wdt_str));
	if (mask->width < 0)
	{
		mask->width *= -1;
		str_to_free = mask->flag;
		mask->flag = ft_strjoin(mask->flag, "-");
		free(str_to_free);
	}
	free(wdt_str);
	*plh = tmp;
}

void				mask_get_precision(const char **plh, \
t_mask *mask, va_list ap)
{
	const char		*tmp;
	static char		ch = '.';
	char			*prc_str;

	if (!ft_strchr(*plh, ch))
		return ;
	tmp = ft_strchr(*plh, ch) + sizeof(char);
	while (*tmp != '\0' && (ft_isdigit(*tmp) || ft_strchr("*", *tmp) != NULL))
		tmp++;
	if (!(prc_str = (char*)malloc(sizeof(char) * (ft_strlen(*plh) - \
	ft_strlen(tmp) + sizeof(char)))))
		return ;
	ft_strlcpy(prc_str, *plh + sizeof(char), ft_strlen(*plh) - ft_strlen(tmp));
	if (prc_str[0] == '*')
		mask->precision = va_arg(ap, int);
	else if (prc_str[0] == '\0')
		(mask->trunc = 1);
	else
		(mask->precision = ft_atoi(prc_str));
	(mask->precision == 0) ? (mask->trunc = 1) : (mask->precision += 0);
	free(prc_str);
	*plh = tmp;
}

void				mask_get_length(const char **plh, t_mask *mask)
{
	const char		*tmp;
	static char		*lgh_set = "hlLzjt";
	char			*lgh_str;

	tmp = *plh;
	while (*tmp != '\0' && ft_strchr(lgh_set, *tmp) != NULL)
		tmp++;
	if (*tmp == '\0')
	{
		mask->length = NULL;
		return ;
	}
	if (!(lgh_str = (char*)malloc(sizeof(char) * (ft_strlen(*plh) - \
	ft_strlen(tmp) + sizeof(char)))))
		return ;
	ft_strlcpy(lgh_str, *plh, ft_strlen(*plh) - ft_strlen(tmp) + sizeof(char));
	if (!(mask->length = (char*)malloc(sizeof(char) * (ft_strlen(lgh_str)\
	+ sizeof(char)))))
		return ;
	ft_strlcpy(mask->length, lgh_str, ft_strlen(lgh_str) + sizeof(char));
	free(lgh_str);
	*plh = tmp;
}
