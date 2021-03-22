/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkomaris <tkomaris@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 13:42:30 by tkomaris          #+#    #+#             */
/*   Updated: 2021/03/22 21:48:40 by tkomaris         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

char	*ft_gnl_strdup(char *str1);
char	*ft_gnl_state(char *saved_state);
int		get_next_line(int fr, char **line);
int		ft_gnl_newline_check(char *str);
int		ft_gnl_strlen(const char *str);
char	*ft_gnl_strjoin(const char *s1, const char *s2);
void	*ft_gnl_memmove(void *dest, const void *src, size_t len);

#endif
