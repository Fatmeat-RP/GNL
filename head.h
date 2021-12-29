/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   head.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarle-m <acarle-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 01:35:00 by acarle-m          #+#    #+#             */
/*   Updated: 2021/12/29 01:21:35 by acarle-m         ###   ########.fr       */
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

char	*ft_read(char *line, int fd);
char	*ft_strnjoin(char *dst, char *buf, t_s64 n);
t_s64	ft_eol(char *s);
t_s64	ft_strlen(char *s);
void	ft_shiftbuff(char *buf, t_s64 n);
char	*ft_strnjoinlast(char *dst, char *buf, t_s64 n);
char	*ft_strndup(char *buff, t_s64 n);

#endif
