/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_placeholder.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiwiber <alex_orlov@goodiez.app>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/19 09:58:17 by tkiwiber          #+#    #+#             */
/*   Updated: 2020/05/19 18:19:23 by tkiwiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		mask_get_parameter(char **plh, t_mask *mask)
{
	char		*tmp;
	char		*prm_set = "$";
	char		*prm_str;

	tmp = *plh;
	while (*tmp != '\0' && ft_strchr(prm_set, *tmp) == NULL)
		tmp++;
	if (*tmp == '\0')
	{
		mask->parameter = 0;
		return ;
	}
	if (!(prm_str = (char*)malloc(sizeof(char) * (ft_strlen(*plh) - ft_strlen(tmp) + sizeof(char)))))
		return ;
	ft_strlcpy(prm_str, *plh, ft_strlen(*plh) - ft_strlen(tmp) + sizeof(char));
	mask->parameter = ft_atoi(prm_str);
	free(prm_str);
	*plh = tmp + sizeof(char);
}

static void		mask_get_flag(char **plh, t_mask *mask)
{
	char		*tmp;
	char		*flg_set = "-+ 0'#";
	char		*flg_str;

	tmp = *plh;
	while (*tmp != '\0' && ft_strchr(flg_set, *tmp) != NULL)
		tmp++;
	if (*tmp == '\0')
	{
		mask->flag = NULL;
		return ;
	}
	if (!(flg_str = (char*)malloc(sizeof(char) * (ft_strlen(*plh) - ft_strlen(tmp) + sizeof(char)))))
		return ;
	ft_strlcpy(flg_str, *plh, ft_strlen(*plh) - ft_strlen(tmp) + sizeof(char));
	if (!(mask->flag = (char*)malloc(sizeof(char) * (ft_strlen(flg_str) + sizeof(char)))))
		return ;
	ft_strlcpy(mask->flag, flg_str, ft_strlen(flg_str) + sizeof(char));
	free(flg_str);
	*plh = tmp;
}

static void		mask_get_width(char **plh, t_mask *mask)
{
	char		*tmp;
	char		*prm_set = "*";
	char		*wdt_str;

	tmp = *plh;
	while (*tmp != '\0' && (ft_isdigit(*tmp) || ft_strchr(prm_set, *tmp) != NULL))
		tmp++;
	if (*tmp == '\0')
	{
		mask->width = 0;
		return ;
	}
	/*if (!(ft_memcmp(tmp, prm_set, sizeof(char))))
	{
		mask->width = va_arg(ap, int);
		return ;
	}*/
	if (!(wdt_str = (char*)malloc(sizeof(char) * (ft_strlen(*plh) - ft_strlen(tmp) + sizeof(char)))))
		return ;
	ft_strlcpy(wdt_str, *plh, ft_strlen(*plh) - ft_strlen(tmp) + sizeof(char));
	mask->width = ft_atoi(wdt_str);
	free(wdt_str);
	*plh = tmp;
}

static void		mask_get_precision(char **plh, t_mask *mask)
{
	char		*tmp;
	char		*prm_set = "*";
	char		ch = '.';
	char		*prc_str;

	if (!ft_strchr(*plh, ch))
	{
		mask->precision = 0;
		return ;
	}
	tmp = ft_strchr(*plh, ch) + sizeof(char);
	while (*tmp != '\0' && (ft_isdigit(*tmp) || ft_strchr(prm_set, *tmp) != NULL))
		tmp++;
	if (*tmp == '\0')
	{
		mask->precision = 0;
		return ;
	}
	/*if (!(ft_memcmp(tmp, prm_set, sizeof(char))))
	{
		mask->precision = va_arg(ap, int);
		return ;
	}*/
	if (!(prc_str = (char*)malloc(sizeof(char) * (ft_strlen(*plh) - ft_strlen(tmp) + sizeof(char)))))
		return ;
	ft_strlcpy(prc_str, *plh + sizeof(char), ft_strlen(*plh) - ft_strlen(tmp));
	mask->precision = ft_atoi(prc_str);
	free(prc_str);
	*plh = tmp;
}

static void		mask_get_length(char **plh, t_mask *mask)
{
	char		*tmp;
	char		*lgh_set = "hlLzjt";
	char		*lgh_str;

	tmp = *plh;
	while (*tmp != '\0' && ft_strchr(lgh_set, *tmp) != NULL)
		tmp++;
	if (*tmp == '\0')
	{
		mask->length = NULL;
		return ;
	}
	if (!(lgh_str = (char*)malloc(sizeof(char) * (ft_strlen(*plh) - ft_strlen(tmp) + sizeof(char)))))
		return ;
	ft_strlcpy(lgh_str, *plh, ft_strlen(*plh) - ft_strlen(tmp) + sizeof(char));
	if (!(mask->length = (char*)malloc(sizeof(char) * (ft_strlen(lgh_str) + sizeof(char)))))
		return ;
	ft_strlcpy(mask->length, lgh_str, ft_strlen(lgh_str) + sizeof(char));
	free(lgh_str);
	*plh = tmp;
}

static void		mask_get_type(char **plh, t_mask *mask)
{
	char		*tmp;
	char		*typ_set = "diufFeEgGxXoscpaAn";

	tmp = *plh;
	if (!(ft_strchr(typ_set, *tmp)))
	{
		mask->type = '\0';
		return ;
	}
	mask->type = *tmp;
	(*plh)++;
}

t_mask  		*ft_mask_get(char *plh)
{
	t_mask		*mask;

	if (!(mask = (t_mask*)malloc(sizeof(t_mask))))
		return NULL;

	mask_get_parameter(&plh, mask);
	mask_get_flag(&plh, mask);
	mask_get_width(&plh, mask);
	mask_get_precision(&plh, mask);
	mask_get_length(&plh, mask);
	mask_get_type(&plh, mask);
	//printf(RED "%s\n" RESET, plh);

	return (mask);
}