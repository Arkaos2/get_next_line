/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saibelab <saibelab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:05:14 by saibelab          #+#    #+#             */
/*   Updated: 2025/05/20 16:05:14 by saibelab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (1);
	int fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (1);
	char *line;
	int i = 1;
	while ((line = get_next_line(fd)))
	{
		printf("Ligne [%d] : %s", i++, line);
		free(line);
	}
	close(fd);
	return(0);
}
