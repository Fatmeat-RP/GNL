/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarle-m <acarle-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 01:35:00 by acarle-m          #+#    #+#             */
/*   Updated: 2021/12/29 03:35:36 by acarle-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEAD_H
# define HEAD_H

# include	<stdio.h>
# include	<unistd.h>
# include	<stdlib.h>
# include	<fcntl.h>

typedef long long	t_s64;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8
# endif

char	*get_next_line(int fd);
char	*ft_cleanlione(char *line);
char	*ft_strndup(char *buff, t_s64 n);
t_s64	ft_strlen(char *s);
t_s64	ft_eol(char *s);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);

#endif
