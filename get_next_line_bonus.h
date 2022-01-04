/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarle-m <acarle-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 01:35:00 by acarle-m          #+#    #+#             */
/*   Updated: 2022/01/04 01:46:17 by acarle-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include	<stdio.h>
# include	<unistd.h>
# include	<stdlib.h>
# include	<fcntl.h>

typedef long long	t_s64;
typedef struct s_struct
{
	char	buf[BUFFER_SIZE + 1];
	char	*ret;
	int		rd;
	t_s64	n;
}		t_struct;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8
# endif

char	*get_next_line(int fd);
char	*ft_cleanlione(char *line);
char	*ft_strndup(char *buff, t_s64 n);
t_s64	ft_strlen(char *s, int a);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2, int rd);

#endif
