/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 20:47:56 by cmissy            #+#    #+#             */
/*   Updated: 2019/05/09 03:04:25 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE  10000

# include "libft/libft.h"
# include "fcntl.h"
# include "sys/types.h"
# include "sys/uio.h"
# include "unistd.h"
# include "stdlib.h"

typedef struct		s_gnl
{
	int				fdis;
	char			*str;
	struct s_gnl	*next;
}					t_gnl;

int					ft_pusher(char **line, t_gnl *list, char *tmp);
int					get_next_line(const int fd, char **line);

#endif
