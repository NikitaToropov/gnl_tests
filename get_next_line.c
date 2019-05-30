/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/01 20:47:24 by cmissy            #+#    #+#             */
/*   Updated: 2019/05/09 03:01:14 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_gnl		*ft_find(t_gnl **start, int fd)
{
	t_gnl			*list;
	t_gnl			*tmp;

	list = *start;
	if (list && list->fdis == fd)
		return (list);
	while (list)
	{
		if (list->fdis == fd)
			return (list);
		tmp = list;
		list = list->next;
	}
	if (!(list = (t_gnl*)malloc(sizeof(*list))))
		return (NULL);
	list->fdis = fd;
	list->str = ft_strnew(0);
	list->next = NULL;
	if (!*start)
		*start = list;
	else
		tmp->next = list;
	return (list);
}

int					ft_pusher(char **line, t_gnl *list, char *tmp)
{
	if (tmp)
	{
		*line = ft_strsub(list->str, 0, (tmp++ - list->str));
		tmp = ft_strdup(tmp);
	}
	else
		*line = ft_strdup(list->str);
	if (!*line)
		return (-1);
	free(list->str);
	list->str = tmp;
	return (1);
}

int					get_next_line(const int fd, char **line)
{
	static t_gnl	*first;
	char			buff[BUFF_SIZE + 1];
	int				status;
	t_gnl			*list;
	char			*tmp;

	if (fd < 0 || !line || read(fd, buff, 0) < 0
			|| !(list = ft_find(&first, fd)))
		return (-1);
	if (!(list->str))
		return (0);
	tmp = ft_strchr(list->str, '\n');
	while (!tmp && (status = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[status] = '\0';
		tmp = ft_strjoin(list->str, buff);
		free(list->str);
		list->str = tmp;
		tmp = ft_strchr(list->str, '\n');
	}
	if (list->str && *(list->str))
		return (ft_pusher(line, list, tmp));
	return (0);
}
