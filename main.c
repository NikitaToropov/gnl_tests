/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/06 13:38:13 by cmissy            #+#    #+#             */
/*   Updated: 2019/05/09 02:37:34 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int		main(void)
{
	char	*line;
//	int		fd1;
	int		fd2;
	int		ans;

//	fd1 = open("/Users/cmissy/Desktop/file.txt", O_RDONLY);
	fd2 = open ("/Users/cmissy/Desktop/gnl7_1.txt", O_RDONLY);
	while ((ans = get_next_line(fd2, &line) > 0))
	{
		printf("%i\n", ans);
        printf("%s\n", line);
        free(line);
	}
	printf("%i", ans);
/*	printf("read 1/1\n");
	printf("return    %i\n", get_next_line(fd1, &line));
	printf("line 1/1:                %s\n", line);
	printf("read 2/1\n");
	printf("return    %i\n", get_next_line(fd2, &line));
	printf("line 2/1:                %s\n", line);
	printf("read 1/2\n");
	printf("return    %i\n", get_next_line(fd1, &line));
	printf("line 1/2:                %s\n", line);
	printf("read 2/2\n");
	printf("return    %i\n", get_next_line(fd2, &line));
	printf("line 2/2:                %s\n", line);
	printf("read 1/3\n");
	printf("return    %i\n", get_next_line(fd1, &line));
	printf("line 1/3:                %s\n", line);
	printf("read 2/3\n");
	printf("return    %i\n", get_next_line(fd2, &line));
	printf("line 2/3:                %s\n", line);
	close(fd1);*/
	close(fd2);
	return (0);
}
