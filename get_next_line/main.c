#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("Usage: %s <filename>\n", argv[0]);
		return (1);
	}
	int fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		perror("open");
		return (1);
	}
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
