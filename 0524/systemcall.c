#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <unistd.h>
#include <stdio.h>

int mysystem(const char *cmdstring) 
{
	pid_t pid; int status;

	if (cmdstring == NULL) 
		return(1); 
	if ( (pid = fork()) < 0) {
		status = -1;
	} 
	else if (pid == 0) {
		execl("/bin/sh", "sh", "-c", cmdstring, (char *) 0);
		_exit(127);
	} 
	else {
		while (waitpid(pid, &status, 0) < 0)
			if (errno != EINTR) {
				status = -1;
			break;
		}
	}
	return(status);
}

int main()
{
	int status;
	if ((status = mysystem("date")) < 0)
		perror("mysystem() 오류");
	printf("종료코드 %d\n", WEXITSTATUS(status));
	
	if ((status = mysystem("hello")) < 0)
		perror("mysystem() 오류");
	printf("종료코드 %d\n", WEXITSTATUS(status));
	
	if ((status = mysystem("who; exit 44")) < 0)
		perror("mysystem() 오류");
	printf("종료코드 %d\n", WEXITSTATUS(status));
}
