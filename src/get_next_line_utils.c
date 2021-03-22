/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomaris <tkomaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 13:42:13 by tkomaris          #+#    #+#             */
/*   Updated: 2021/03/22 21:48:47 by tkomaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_gnl_newline_check(char *str)
{
	int i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int		ft_gnl_strlen(const char *str)
{
	int i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_gnl_strjoin(char const *s1, char const *s2)
{
	size_t	len_s1;
	size_t	len_s2;
	size_t	len_total;
	char	*result;

	if (!s1 && !s2)
		return (0);
	len_s1 = ft_gnl_strlen((char *)s1);
	len_s2 = ft_gnl_strlen((char *)s2);
	len_total = len_s1 + len_s2 + 1;
	result = malloc(sizeof(char) * len_total);
	if (!result)
		return (0);
	ft_gnl_memmove(result, s1, len_s1);
	ft_gnl_memmove(result + len_s1, s2, len_s2);
	result[len_total - 1] = '\0';
	free((char *)s1);
	return (result);
}

void	*ft_gnl_memmove(void *dest, const void *src, size_t len)
{
	char *d;
	char *s;

	d = (char *)dest;
	s = (char *)src;
	if (s < d)
	{
		while (len--)
			*(d + len) = *(s + len);
		return (dest);
	}
	while (len--)
		*d++ = *s++;
	return (dest);
}
