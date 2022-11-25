#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

#include "get_next_line.h"

int main() {
	int	fd = open("test.txt",  O_RDONLY);
	int	i = 0;
	char *line;
	
	while (i < 2)
	{
		line = get_next_line(fd);
		printf("%s\n", line);
		if(line)
			free(line);
		i++;
	}
	return (0);
}
