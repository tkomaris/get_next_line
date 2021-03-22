/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomaris <tkomaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 13:42:23 by tkomaris          #+#    #+#             */
/*   Updated: 2021/03/22 21:48:58 by tkomaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_gnl_strdup(char *str1)
{
	int		a;
	int		b;
	char	*str2;

	if (!str1)
		return (0);
	a = 0;
	while (str1[a] && str1[a] != '\n')
		a++;
	str2 = malloc(sizeof(char) * (a + 1));
	if (!str2)
		return (0);
	b = 0;
	while (str1[b] && str1[b] != '\n')
	{
		str2[b] = str1[b];
		b++;
	}
	str2[b] = '\0';
	return (str2);
}

char	*ft_gnl_state(char *saved_state)
{
	char	*str;
	int		i;
	int		j;

	if (!saved_state)
		return (0);
	i = 0;
	while (saved_state[i] && saved_state[i] != '\n')
		i++;
	if (!saved_state[i])
	{
		free(saved_state);
		return (0);
	}
	str = malloc(sizeof(char) * ((ft_gnl_strlen(saved_state) - i) + 1));
	if (!str)
		return (0);
	i++;
	j = 0;
	while (saved_state[i])
		str[j++] = saved_state[i++];
	str[j] = '\0';
	free(saved_state);
	return (str);
}

int		get_next_line(int fd, char **line)
{
	int			index;
	char		*buff;
	static char	*save;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buff = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	index = 1;
	while (!ft_gnl_newline_check(save) && index != 0)
	{
		if ((index = read(fd, buff, BUFFER_SIZE)) == -1)
		{
			free(buff);
			return (-1);
		}
		buff[index] = '\0';
		save = ft_gnl_strjoin(save, buff);
	}
	free(buff);
	*line = ft_gnl_strdup(save);
	save = ft_gnl_state(save);
	if (index == 0)
		return (0);
	return (1);
}
