#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*gnlsubstr(char *s, unsigned int start, size_t len);
char	*gnljoin(char *s1, char *s2);
int		ft_isnewline(char *s);
size_t	ft_strlen(const char *s);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	failed_malloc(void);

#endif
