/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaehun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 17:35:54 by schaehun          #+#    #+#             */
/*   Updated: 2022/05/05 03:39:17 by schaehun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

char	*get_next_line(int fd);
char	*ft_get_strjoin(char *s1, char *s2);
void	ft_get_strcpy(char *dst, char *src);
int		ft_get_strlen(char *s);
char	*ft_get_strdup(char *s);
char	*ft_get_strchr(char *str, char c);
int		ft_get_search(char *s);

#endif
