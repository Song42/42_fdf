/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: schaehun <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/18 17:35:23 by schaehun          #+#    #+#             */
/*   Updated: 2022/05/05 03:40:51 by schaehun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_cut(char *s)
{
	int		i;
	int		len;
	char	*str;

	if (!s)
		return (NULL);
	len = 0;
	while (s[len] && s[len] != '\n')
		len++;
	if (s[0] == '\n')
		len = 0;
	str = (char *)malloc(len + 2);
	if (!str)
		return (NULL);
	i = 0;
	while (i < len + 1)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	free(s);
	return (str);
}

void	ft_get_swap(char *tmp, char *buf, char **line)
{
	tmp = ft_get_strjoin(*line, buf);
	free(*line);
	*line = tmp;
}

char	*get_next_line(int fd)
{
	int			len;
	static char	*line;
	char		*tmp;
	char		*out;
	char		buf[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	tmp = "";
	while (ft_get_search(line) == 0)
	{
		len = read(fd, buf, BUFFER_SIZE);
		buf[len] = '\0';
		if (len < 1)
			break ;
		if (line == NULL)
			line = ft_get_strdup(buf);
		else
			ft_get_swap(tmp, buf, &line);
	}
	out = ft_get_strdup(line);
	free(line);
	line = ft_get_strdup(ft_get_strchr(out, '\n'));
	return (ft_get_cut(out));
}
