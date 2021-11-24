/* ************************************************************************** */
/* ************************************************************************** */
/* **                                                                      ** */
/* **              ███    ███  █████  ██ ███    ██     ██████              ** */
/* **              ████  ████ ██   ██ ██ ████   ██    ██                   ** */
/* **              ██ ████ ██ ███████ ██ ██ ██  ██    ██                   ** */
/* **              ██  ██  ██ ██   ██ ██ ██  ██ ██    ██                   ** */
/* **              ██      ██ ██   ██ ██ ██   ████ ██  ██████              ** */
/* **                                                                      ** */
/* ************************************************************************** */
/* ************************************************************************** */
#include "get_next_line.h"

int main(void)
{
	int		fd1;
	int		fd2;
	int		fd3;
	char	*output;

	fd1 = open("./lorem.txt", O_RDONLY);
	fd2 = open("./kafka.txt", O_RDONLY);
	fd3 = open("./cicero.txt", O_RDONLY);
	if (fd1 < 0 || fd2 < 0 || fd3 < 0)
		return (print_error_message("Error while opening file ...\n"));
	for (int i = 0; i < 15; i++)
	{
		output = get_next_line(fd1);
		if (output)
			printf("%s", output);
		free(output);
		printf("Checkpoint 1\n");

		output = get_next_line(fd2);
		if (output)
			printf("%s", output);
		free(output);
		printf("Checkpoint 2\n");
		
		output = get_next_line(fd3);
		if (output)
			printf("%s", output);
		free(output);
		printf("Checkpoint 3\n");
	}
	return (0);
}
