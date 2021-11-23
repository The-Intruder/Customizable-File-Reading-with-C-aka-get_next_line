//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//#include <fcntl.h>
//#include <unistd.h>
#include "get_next_line.h"

static int	print_error_message(char *s)
{
	write(2, s, strlen(s));
	return(0);
}

int main()
{
	int		fd;
	char	*buf;
	//int		read_bytes;

	buf = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	fd = open("file.txt", O_RDONLY);
	if (fd < 0)
		return (print_error_message("Error while opening file ...\n"));
	/*
	for (int i = 0; i < 5; i++)
	{
		read_bytes = read(fd, buf, BUFFER_SIZE);
		if (read_bytes < 0)
			return (print_error_message("Error while reading file ...\n"));
		else if (read_bytes == 0)
			return (print_error_message("`read()' function reached EOF ...\n"));
		printf("%s", buf);
	}
	*/
	printf("%s", get_next_line(fd));
	return (0);
}
