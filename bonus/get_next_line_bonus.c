/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaehyuki <jaehyuki@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/16 16:39:44 by jaehyuki          #+#    #+#             */
/*   Updated: 2022/07/16 17:07:17 by jaehyuki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*free_buf(char **buf)
{
	if (*buf)
	{
		free(*buf);
		*buf = NULL;
	}
	return (NULL);
}

char	*set_next_buf(char *buf, char *line)
{
	char	*temp;
	int		i;

	if (!line)
		return (free_buf(&buf));
	if (ft_strchr_g(buf, '\n'))
	{
		i = 0;
		while (i <= (long long)ft_strlen_g(buf, '\n'))
			i++;
		temp = ft_strjoin_g(&(buf[i]), "", 0);
		if (!temp)
			return (NULL);
		if (buf)
			free_buf(&buf);
		buf = temp;
	}
	else
		return (free_buf(&buf));
	return (buf);
}

char	*get_line(char *buf)
{
	long long	i;
	char		*line;

	line = NULL;
	if (!buf[0])
		return (line);
	if (!(ft_strchr_g(buf, '\n')))
	{
		line = ft_strjoin_g(buf, "", 0);
		return (line);
	}
	line = (char *)ft_calloc_g(ft_strlen_g(buf, '\n') + 1, sizeof(char));
	if (!line)
		return (NULL);
	i = -1;
	while (++i < (long long)ft_strlen_g(buf, '\n'))
		line[i] = buf[i];
	return (line);
}

int	read_buf(char **buf, int fd)
{
	char	*str;
	int		bytes;

	str = (char *)ft_calloc_g(BUFFER_SIZE + 1, sizeof(char));
	if (!str)
		return (0);
	while (!ft_strchr_g(*buf, '\n'))
	{
		bytes = read(fd, str, BUFFER_SIZE);
		if (bytes <= 0)
			break ;
		str[bytes] = '\0';
		*buf = ft_strjoin_g(*buf, str, 1);
		if (!buf)
		{
			free(str);
			return (0);
		}
	}
	if (str)
		free(str);
	return (1);
}

char	*get_next_line(int fd)
{
	static char	*buf;
	char		*line;

	if (!buf)
	{
		buf = ft_calloc_g(1, sizeof(char));
		if (!buf)
			return (NULL);
	}
	if (!read_buf(&buf, fd))
	{
		free_buf(&buf);
		return (NULL);
	}
	line = get_line(buf);
	if (!line)
	{
		free_buf(&buf);
		return (NULL);
	}
	buf = set_next_buf(buf, line);
	return (line);
}
