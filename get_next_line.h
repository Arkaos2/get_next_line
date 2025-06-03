/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saibelab <saibelab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 16:04:38 by saibelab          #+#    #+#             */
/*   Updated: 2025/05/20 16:04:38 by saibelab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
char	*read_to_stock(int fd, char *stock);
char	*extract_line(char *stock);
char	*remove_line(char *stock);

int		ft_strlen(char *s);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
char	*append(char *stock, char *buf);
char	*create_new_stock(char *stock, char *new_stock, char *buf);
int		find_newline(char *str);

#endif
