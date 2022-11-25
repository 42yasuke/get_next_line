/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:10:06 by jralph            #+#    #+#             */
/*   Updated: 2022/11/24 10:59:08 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

char	*ft_getlines(char *stash, size_t len)
{
	char	*res;
	size_t	i;

	i = 0;
	res = malloc (sizeof(char) * (len + 1));
	while (stash[i] && i < len)
	{
		res[i] = stash[i];
		i++;
	}
	res[i] = 0;
	return (res);
}
