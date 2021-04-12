#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#define BUFSIZE 512
int main(int argc, char *argv[])
{
	char buffer[BUFSIZE];
	int fd;
	ssize_t nread;
	long total = 0;
	if ((fd = open(argv[1], O_RDONLY)) == -1)
		perror(argv[1]);
	while((nread = read(fd, buffer, BUFSIZE)) > 0)
		total += nread;
	printf ("%s 파일 크기 : %ld 바이트 %d\n", argv[1], total, fd);
	close(fd);
	exit(0);
}
