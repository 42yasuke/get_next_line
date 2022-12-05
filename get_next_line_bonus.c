/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:01:39 by jralph            #+#    #+#             */
/*   Updated: 2022/11/30 20:27:49 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static void	*ft_memmove(void *dest, const void *src)
{
	size_t	i;

	i = 0;
	while (((char *)src)[i])
	{
		((char *)dest)[i] = ((char *)src)[i];
		i++;
	}
	while (((char *)dest)[i])
	{
		((char *)dest)[i] = '\0';
		i++;
	}
	return (dest);
}

static void	ft_loop(char **stash, int fd)
{
	char		*tmp;
	int			len;
	char		*buf;

	len = BUFFER_SIZE;
	buf = malloc (sizeof(*buf) * (BUFFER_SIZE + 1));
	if (!buf)
		return ;
	while (!ft_strchr(*stash, '\n') && len == BUFFER_SIZE)
	{
		len = read(fd, buf, BUFFER_SIZE);
		if (len <= 0)
			break ;
		buf[len] = '\0';
		tmp = *stash;
		*stash = ft_strjoin(tmp, buf);
		if (!*stash)
		{
			*stash = NULL;
			return ;
		}
		free(tmp);
	}
	free(buf);
}

static char	*ft_last_line(char **stash)
{
	char	*lines;

	lines = malloc(sizeof(char) * (ft_strlen(*stash) + 1));
	if (!lines)
		return (NULL);
	ft_cpy(lines, *stash, 0);
	lines[ft_strlen(*stash)] = '\0';
	free(*stash);
	*stash = NULL;
	return (lines);
}

char	*get_next_line(int fd)
{
	static char		*stash[FD_MAX + 1];
	char			*lines;

	lines = NULL;
	stash[FD_MAX] = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FD_MAX)
		return (NULL);
	ft_loop(&stash[fd], fd);
	if (ft_strchr(stash[fd], '\n'))
	{
		lines = ft_getlines(stash[fd], ft_strchr(stash[fd], \
		'\n') - stash[fd] + 1);
		if (!lines)
		{
			free(stash[fd]);
			return (NULL);
		}
		stash[fd] = ft_memmove(stash[fd], ft_strchr(stash[fd], '\n') + 1);
		return (lines);
	}
	else if (stash[fd] && *stash[fd])
		return (ft_last_line(&stash[fd]));
	return (NULL);
}
