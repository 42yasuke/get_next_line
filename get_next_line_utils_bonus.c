/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 18:01:31 by jralph            #+#    #+#             */
/*   Updated: 2022/11/30 18:03:20 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_cpy(char *res, char const *s, size_t start)
{
	size_t	i;

	i = start;
	while (s && *s)
	{
		res[i] = *s;
		s++;
		i++;
	}
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (s)
	{
		while (s[i] != '\0')
			i++;
	}
	return (i);
}

char	*ft_getlines(char *stash, size_t len)
{
	char	*res;
	size_t	i;

	i = 0;
	res = malloc (sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	while (stash[i] && i < len)
	{
		res[i] = stash[i];
		i++;
	}
	res[i] = 0;
	return (res);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	len;

	len = 1;
	if (s1)
		len += ft_strlen(s1);
	if (s2)
		len += ft_strlen(s2);
	res = malloc (sizeof(*s1) * len);
	if (!res)
		return (NULL);
	ft_cpy(res, s1, 0);
	ft_cpy(res, s2, ft_strlen(s1));
	res[len - 1] = 0;
	return (res);
}

char	*ft_strchr(const char *s, int c)
{
	if (s)
	{
		while (*s && *s != (char)c)
			s++;
		if (*s == (char)c)
			return ((char *)s);
	}
	return (NULL);
}
