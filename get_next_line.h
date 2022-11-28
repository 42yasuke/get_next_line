/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jralph <jralph@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:10:20 by jralph            #+#    #+#             */
/*   Updated: 2022/11/28 21:05:14 by jralph           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

char	*get_next_line(int fd);
void	ft_cpy(char *res, char const *s, size_t start);
char	*ft_getlines(char *stash, size_t len);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

#endif