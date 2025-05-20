/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saibelab <saibelab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 15:25:04 by saibelab          #+#    #+#             */
/*   Updated: 2025/05/20 15:25:04 by saibelab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

char	*extract_line(char *stock)
{
	char	*new;
	int		i;

	new = NULL;
	i = 0;
	if (!stock)
		return (NULL);
	while (stock[i] && stock[i] != '\n')
		i++;
	if (stock[i] == '\n')
		i++;
	new = malloc(sizeof(char) * (i + 1));
	if (!new)
		return (NULL);
	ft_strncpy(new, stock, i);
	new[i] = '\0';
	return (new);
}

char	*remove_line(char *stock)
{
	int		i;
	int		j;
	char	*new_stock;

	i = 0;
	j = 0;
	while (stock[i] && stock[i] != '\n')
		i++;
	if (!stock[i])
	{
		free(stock);
		return (NULL);
	}
	i++;
	while (stock[i + j])
		j++;
	new_stock = malloc(sizeof(char) * (j + 1));
	if (!new_stock)
		return (NULL);
	ft_strncpy(new_stock, stock + i, j);
	new_stock[j] = '\0';
	free (stock);
	return (new_stock);
}

char	*read_to_stock(int fd, char *stock)
{
	char	*buf;
	ssize_t	bytes;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	while (find_newline(stock) == -1)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes <= 0)
			break ;
		buf[bytes] = '\0';
		stock = append(stock, buf);
		if (!stock)
		{
			free (buf);
			return (NULL);
		}
	}
	free (buf);
	return (stock);
}

char	*get_next_line(int fd)
{
	static char	*stock;
	char		*line;

	if (!stock)
	{
		stock = malloc(1);
		if (!stock)
			return (NULL);
		stock[0] = '\0';
	}
	stock = read_to_stock(fd, stock);
	if (!stock || !*stock)
	{
		free(stock);
		stock = NULL;
		return (NULL);
	}
	line = extract_line(stock);
	stock = remove_line(stock);
	return (line);
}
