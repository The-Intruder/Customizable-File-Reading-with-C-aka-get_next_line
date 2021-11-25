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
	//int		fd2;
	//int		fd3;
	char	*output;

	fd1 = open("./txt_files/lorem.txt", O_RDONLY);
	//fd2 = open("./kafka.txt", O_RDONLY);
	//fd3 = open("./cicero.txt", O_RDONLY);
	if (fd1 < 0)
		return (printf("Error while opening file ...\n"));
	for (int i = 0; i < 100; i++)
	{
		output = get_next_line(fd1);
		if (output)
			printf("%s", output);
		free(output);
		//printf("Checkpoint 1\n");

		/*output = get_next_line(fd2);
		if (output)
			printf("%s", output);
		free(output);
		printf("Checkpoint 2\n");
		
		output = get_next_line(fd3);
		if (output)
			printf("%s", output);
		free(output);
		printf("Checkpoint 3\n");*/
	}
	return (0);
}
