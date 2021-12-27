#ifndef HEAD_H
# define HEAD_H

#define long long t_s64

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 8
# endif

t_s64	ft_strlen(char *s);
void	ft_strnjoin(char *dst, char *buf, t_s64 n);
t_s64	ft_strchr(char *s, char c);
t_s64	ft_strndup(char *buf, t_s64 n);

#endif
