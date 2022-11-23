/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:10:16 by jralph            #+#    #+#             */
/*   Updated: 2022/11/23 13:23:39 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static char	*ft_strchr(const char *s, int c)
{
	while (*s && *s != (char)c)
		s++;
	if (*s == (char)c)
		return ((char *)s);
	return (0);
}

static void	*ft_memmove(void *dest, const void *src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		((char *)dest)[i] = ((char *)src)[i];
		i++;
	}
	while (dest[i])
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

static char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	len;

	len = 1;
	if (*s1)
		len += ft_strlen(s1);
	if (*s2)
		len += ft_strlen(s2);
	res = malloc (sizeof(*s1) * len);
	if (!res)
		return (NULL);
	ft_cpy(res, s1, 0);
	ft_cpy(res, s2, ft_strlen(s1));
	res[len - 1] = 0;
	return (res);
}

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	char		*lines;
	static char	*stash = NULL;
	char		*tmp;
	size_t		len;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	len = 1;
	while (len > 0)
	{
		len = read(fd, buf, BUFFER_SIZE);
		buf[len] = '\0';
		tmp = stash;
		stash = ft_strjoin(stash, buf);
		free(tmp);
		if (ft_strchr(stash, '\n'))
			break ;
	}
	if (ft_strchr(stash, '\n'))
	{
		lines = ft_getlines(stash, ft_strchr(stash, '\n') - stash);
		stash = ft_memmove(stash, ft_strchr(stash, '\n'));
	}
	else if (len < BUFFER_SIZE)
	{
		lines = malloc(sizeof(char) * (ft_strlen(stash) + 1));
		ft_cpy(lines, stash, 0);
		lines[ft_strlen(stash)] = '\0';
		free(stash);
	}
	return (lines);
}