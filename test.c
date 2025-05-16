/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saibelab <saibelab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/16 13:15:49 by saibelab          #+#    #+#             */
/*   Updated: 2025/05/16 15:35:11 by saibelab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 5
#endif
// void print_read(int fd)
// {
// 	char buf[6];
// 	ssize_t bytes;
// 	bytes = read(fd, buf, 5);
// 	while (bytes > 0)
// 	{
// 		buf[bytes] = '\0';
// 		printf("Buf = %s\n", buf);
// 		bytes = read(fd, buf, 5);
// 	}
// }

int ft_strlen(char *s)
{
	int len = 0;
	while(*s++)
		len++;
	return (len);
}
char *append(char *stock, char *buf)
{
	char *new;
	int i = 0;
	int j = 0;
	int len_stock = 0;

	if (!buf)
		return (NULL);
	if (stock)
		len_stock = ft_strlen(stock);
	new = malloc(sizeof(char) * (ft_strlen(buf) + len_stock + 1));
	if (!new)
		return (NULL);
	if (stock)
	{
		while(stock[i] != '\0')
		{
			new[i] = stock[i];
			i++;
		}
	}
	while(buf[j] != '\0')
	{
		new[i + j] = buf[j];
		j++;
	}
	new[i + j] = '\0';
	free(stock);
	return (new);
}

int find_newline(char *str)
{
	if (!str)
		return -1;

	int i;

	i = 0;
	while(str[i])
	{
		if (str[i] == '\n')
			return(i);
		i++;
	}
	return (-1);
}
char	*ft_strncpy(char *dest,  char *src, unsigned int n)
{
	unsigned int i;
	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return dest;
}

char *extract_line(char *stock)
{
	char *new;
	int i;

	new = NULL;
	i = 0;
	if (!stock)
		return NULL;
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
char *remove_line(char *stock)
{
	int i;
	int j;
	char *new_stock;

	i = 0;
	j = 0;
	while (stock[i] && stock[i] != '\n')
		i++;
	if (!stock[i])
	{
		free(stock);
		return NULL;
	}
	i++;
	while (stock[i + j])
		j++;
	new_stock = malloc(sizeof(char) * (j + 1));
	if(!new_stock)
		return (NULL);
	ft_strncpy(new_stock, stock + i, j);
	new_stock[j] = '\0';
	free (stock);
	return (new_stock);
}

char *get_next_line(int fd)
{
	static char *stock;
	char *buf;
	ssize_t bytes;
	char *line;

	buf = malloc(BUFFER_SIZE + 1);
	if (!buf)
		return NULL;
	if (!stock)
	{
		stock = malloc(1);
		if (!stock)
			return NULL;
		stock[0] = '\0';
	}
	while (find_newline(stock) == -1)
	{
		bytes = read(fd, buf, BUFFER_SIZE);
		if (bytes <= 0)
			break;
		buf[bytes] = '\0';
		stock = append(stock, buf);
		if (!stock)
		{
			free(buf);
			return (NULL);
		}
	}
	free(buf);
	if (!stock || !*stock)
		{
			free(stock);
			stock = NULL;
			return (NULL);
		}
	line = extract_line(stock);
	stock = remove_line(stock);
	return line;
}
int main(void)
{
	int fd = open("mon_fichier.txt", O_RDONLY);
	if (fd < 0)
	{
		perror("Erreur d'ouverture");
		return 1;
	}

	char *line;
	while ((line = get_next_line(fd)) != NULL)
	{
		printf("Ligne : %s", line);
		free(line);
	}
	close(fd);
	return 0;
}
