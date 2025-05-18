#include"get_next_line.h"

int	ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (*s++)
		len++;
	return (len);
}
char	*create_new(char *stock, char *new, char *buf)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (stock)
	{
		while (stock[i] != '\0')
		{
			new[i] = stock[i];
			i++;
		}
	}
	while (buf[j] != '\0')
	{
		new[i + j] = buf[j];
		j++;
	}
	new[i + j] = '\0';
	free (stock);
	return (new);
}

char	*append(char *stock, char *buf)
{
	char	*new;
	int	len_stock;

	if (!buf)
		return (NULL);
	if (stock)
		len_stock = ft_strlen(stock);
	new = malloc(sizeof(char) * (ft_strlen(buf) + len_stock + 1));
	if (!new)
		return (NULL);
	new = create_new(stock, new, buf);
	return (new);
}

int	find_newline(char *str)
{
	if (!str)
		return (-1);
	int	i;

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
	unsigned int	i;

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
	return (dest);
}
