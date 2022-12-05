/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:10:16 by jralph            #+#    #+#             */
/*   Updated: 2022/11/29 17:42:19 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char	buf[BUFFER_SIZE + 1];

	len = BUFFER_SIZE;
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
	static char		*stash = NULL;
	char			*lines;

	lines = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ft_loop(&stash, fd);
	if (ft_strchr(stash, '\n'))
	{
		lines = ft_getlines(stash, ft_strchr(stash, '\n') - stash + 1);
		if (!lines)
		{
			free(stash);
			return (NULL);
		}
		stash = ft_memmove(stash, ft_strchr(stash, '\n') + 1);
		return (lines);
	}
	else if (stash && *stash)
		return (ft_last_line(&stash));
	return (NULL);
}
