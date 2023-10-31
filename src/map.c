#include "../include/cub3d.h"
#include <fcntl.h>

// read map from file .cub

// Allowed chars are 
// N S E W and numbers 
// '0' empty space
// '1' wall

// open, close, read, write,
/* printf, malloc, free, perror, */
/* strerror, exit */

char *path = "./res/maps/lodev.cub";

int	read_file()
{

	char buffer[1024];
	ssize_t nread;
	int fd = open(path, O_RDONLY);
	
	if (fd == -1) {
		perror("Error opening file");
		exit(EXIT_FAILURE);
	}
	while ((nread = read(fd, buffer, sizeof(buffer))) > 0) {
		if (write(STDOUT_FILENO, buffer, nread) != nread) {
			perror("Error writing to stdout");
			exit(EXIT_FAILURE);
		}
	}
	if (nread == -1) {
		perror("Error reading file");
		exit(EXIT_FAILURE);
	}

	if (close(fd) == -1) {
		perror("Error closing file");
		exit(EXIT_FAILURE);
	}
	return 0;
}
