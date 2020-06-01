/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_d.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiwiber <alex_orlov@goodiez.app>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/17 16:58:46 by tkiwiber          #+#    #+#             */
/*   Updated: 2020/06/01 21:49:14 by tkiwiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
**	Сonsistently applies logic from precision, width and flag to create output string.
**	General steps:
**
**					%+6.4d for 777 is "  +0777"
**
**					 	  +	  0   7   7   7	  \0
**			    	|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|___|
**              	 01  02  03  04  05  06  07  08  09  10  11  12  13  14  15  16  
**
**
**	1)	count length for otput string (size): count digits in number + sign + space (or '0') + 1
**		(end of string)
**		-	length: ft_strlen form ft_print_d_getnbr()
**		-	sign: if number < 0, or flag = '+', or flag = ' ' then add 1 char to length
**		-	what is wider: strlen > precision => ignore presision, else length = precison (diff fills 
**		  	with '0')
**		-	size = strlen + sign if no width/percision or they are less wider
**			size = percision + sign if percision > strlen and percision > width
**			size = width (with no sign) otherwize
**						  width < precision => ignore width, else length = width and diff fills with
**		  	with ' ' if flag = ' ' or '0' if flag = '0'
**		-	blank_nbr = size
**		-	sing_nbr = 1 if flag is '0', ' ', '+' or number < 0, otherwise 0
**		-	zero_nbr = width - percision - sign
**	2)	memory allocation for output string (+ 1 char for '\0')
**	3)	set align = left if flag = '-' otherwise align = right
**  4)	form output string:
**		-	fills size with blank (if width > percision && percision > strlen)
**		-	begin = 0 if align = left or begin = size - percision - sign - 1
**		-	put sign at begin, begin + sign_br
**		-	put '0' at begin (zero_nbr times), begin + zero_nbr
**		-	put proto_str without sign, begin + strlen - 1
**		-	put '\0' 
**			return (str_output)	
**			
*/	

static char			*ft_print_d_getnbr(va_list ap, t_mask *mask)
{	
	if (!(ft_strncmp(mask->length, "ll", 2)))
		return ft_ltoa((long long int)va_arg(ap, long long  int));
	else if (!(ft_strncmp(mask->length, "l", 1)))
		return ft_ltoa((long int)va_arg(ap, long long  int));
	else if (!(ft_strncmp(mask->length, "hh", 2)))
		return ft_itoa((signed char)va_arg(ap, long long  int));
	else if (!(ft_strncmp(mask->length, "h", 1)))
		return ft_itoa((short int)va_arg(ap, long long  int));
	else
		return ft_itoa((int)va_arg(ap, int));
}

static void			ft_print_conversion(char *str_proto, t_mask *mask)
{
	mask->plh_old = (int)ft_strlen(str_proto);
	(ft_strchr(mask->flag, ' ')) ? (mask->plh_s_ch = ' ') : \
	(mask->plh_s_ch += 0);
	(ft_strchr(mask->flag, '+')) ? (mask->plh_s_ch = '+') : \
	(mask->plh_s_ch += 0);
	(str_proto[0] == '-') ? (mask->plh_s_ch = '-') : (mask->plh_s_ch += 0);
	(mask->plh_s_ch == '\0') ? (mask->plh_sign = 0) : (mask->plh_sign = 1);
	mask->plh_old -= mask->plh_sign;
	(mask->precision > mask->plh_old) ?	(mask->plh_prcs = mask->precision - \
	mask->plh_old) : (mask->plh_prcs = 0);
	if (mask->plh_prcs)
		(mask->width > mask->precision + mask->plh_sign) ? (mask->plh_wdth =\
		mask->width - mask->precision - mask->plh_sign) : (mask->plh_wdth = 0);
	else
		(mask->width > mask->plh_old + mask->plh_sign) ? (mask->plh_wdth =\
		mask->width - mask->plh_old - mask->plh_sign) : (mask->plh_wdth = 0);
	
	mask->plh_size = mask->plh_old + mask->plh_prcs + mask->plh_wdth + \
	mask->plh_sign;
	(ft_strchr(mask->flag, '-')) ? (mask->plh_algn = 1) : (mask->plh_algn = 0);
	(ft_strchr(mask->flag, '0') && !(mask->plh_algn) && !(mask->precision)) ?\
	(mask->plh_w_ch = '0') : (mask->plh_w_ch += ' ');
}
static void			ft_print_add_width(char *str_out, t_mask *mask)
{
/*	int				beg;

	if (mask->plh_wdth && mask->plh_w_ch == '0')
		beg = mask->plh_sign;
	else
		beg = (mask->plh_algn ? mask->plh_size - mask->plh_wdth : 0);
	ft_memset(str_out + beg, (mask->plh_algn) ? ' ' : (mask->plh_w_ch),	mask->plh_wdth);
*/
	if (mask->plh_wdth)
		ft_memset(str_out, (mask->plh_algn) ? ' ' : (mask->plh_w_ch),	mask->width);
}

static void			ft_print_add_sign(char *str_out, t_mask *mask)
{
	int				beg;

	if (mask->plh_wdth && mask->plh_w_ch == '0')
		beg = 0;
	else
		beg = (mask->plh_algn ? 0 : mask->plh_wdth);
	ft_memset(str_out + beg, mask->plh_s_ch, mask->plh_sign);
}

static void			ft_print_add_precision(char *str_out, t_mask *mask)
{
	int				beg;
	
	beg = mask->plh_sign + (mask->plh_algn ? 0 : mask->plh_wdth);
	ft_memset(str_out + beg, '0', mask->plh_prcs);
}

static void			ft_print_add_word(char *str_out, char *str, t_mask *mask)
{
	int				beg;

	beg = mask->plh_size - mask->plh_old - (mask->plh_algn ? mask->plh_wdth : 0);
	ft_memcpy(str_out + beg, str, mask->plh_old);
}

static char			*ft_print_d_get_strout(va_list ap, t_mask *mask)
{
	char			*str_out;
	char			*str_proto;
	char			*str_proto_s;
	
	str_proto = ft_print_d_getnbr(ap, mask);
	ft_print_conversion(str_proto, mask);
	if (!(str_out = (char*)malloc(sizeof(char) * (mask->plh_size + 1))))
		return (NULL);
	if (!(str_proto_s = (char*)malloc(sizeof(char) * (mask->plh_old + 1))))
		return (NULL);
	str_proto_s = ft_strtrim(str_proto, "-");
	ft_print_add_width(str_out, mask);
	ft_print_add_sign(str_out, mask);
	ft_print_add_precision(str_out, mask);
	//printf("[%s]",str_proto);
	if (!(((mask->precision == -1) && ft_strncmp(str_proto, "0", ft_strlen(str_proto)) == 0)))
		ft_print_add_word(str_out, str_proto_s, mask);
	str_out[mask->plh_size] = '\0';
	free(str_proto);
	free(str_proto_s);
	return (str_out);
}

int 				ft_print_d(va_list ap, t_mask *mask)
{
	char			*str_out;
	int				len;

	str_out = ft_print_d_get_strout(ap, mask);
	len = ft_strlen(str_out);
	ft_putstr_fd(str_out, 1);
	free(str_out);
	free(mask);
	return (len);
}
