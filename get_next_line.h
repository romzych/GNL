#ifndef GNL_H
# define GNL_H

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct		s_list
{
	int             temp_fd;
    char            *temp_read;
	struct s_list	*next;
}					t_list;

int     get_next_line(int fd, char **line);
int     ft_str_chr(char *buff);
int		gnl_read(int fd, char **str);
t_list  *ft_lstnew(int fd, char *temp);


#endif