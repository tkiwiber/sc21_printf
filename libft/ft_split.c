/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkiwiber <alex_orlov@goodiez.app>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/07 15:56:19 by tkiwiber          #+#    #+#             */
/*   Updated: 2020/05/14 20:27:35 by tkiwiber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char *str, int c)
{
	int		count;
	int		nw;

	nw = 0;
	count = 0;
	while (*str != '\0')
	{
		if (*str == (unsigned char)c)
			nw = 0;
		else if (nw != 1)
		{
			count += 1;
			nw = 1;
		}
		else if (nw == 0)
			nw = 1;
		str++;
	}
	return (count);
}

static int	ft_wordlen(char *str, size_t pos, int c)
{
	size_t	len;

	len = 0;
	if (pos >= ft_strlen(str))
		return (0);
	while (((pos) <= ft_strlen(str)) && (str[pos] != (unsigned char)c))
	{
		len++;
		pos++;
	}
	return (len);
}

static void	*ft_free_arr(char **str_array, int i)
{
	if (!*str_array)
		return (NULL);
	while (i >= 0)
	{
		free(str_array[i]);
		str_array[i--] = NULL;
	}
	free(str_array);
	str_array = NULL;
	return (NULL);
}

static char	**get_result(char const *str, char c, char **str_array)
{
	size_t	i;
	int		j;
	int		index;

	i = 0;
	index = 0;
	while (str[i] != '\0' && i <= ft_strlen(str))
	{
		if (str[i] == (unsigned char)c)
			i += 1;
		else
		{
			if (!(str_array[index] = (char*)malloc((ft_wordlen(\
			(char*)str, i, c)) * sizeof(char) + 1)))
				return (ft_free_arr(str_array, i));
			j = -1;
			while (++j < ft_wordlen((char*)str, i, c))
				str_array[index][j] = str[i + j];
			str_array[index][j] = '\0';
			i += j;
			index++;
		}
	}
	str_array[index] = NULL;
	return (str_array);
}

char		**ft_split(char const *str, char c)
{
	char	**str_array;

	if (str == NULL)
		return (NULL);
	str_array = (char**)malloc(sizeof(char*) * \
	(count_words((char *)str, c) + 1));
	if (str_array == NULL)
		return (NULL);
	return (get_result(str, c, str_array));
}
