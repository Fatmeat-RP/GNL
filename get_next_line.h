/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acarle-m <acarle-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 01:35:00 by acarle-m          #+#    #+#             */
/*   Updated: 2022/01/04 23:24:49 by acarle-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include	<stdio.h>
# include	<unistd.h>
# include	<stdlib.h>

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

#endif
