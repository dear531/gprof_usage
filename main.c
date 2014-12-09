#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int sub(int a, int b)
{
	return a - b;
}

int add(int a, int b)
{
	return a + b;
}

int main(int argc, char *argv[])
{
	int i, a = 6, b = 3;
	int count;
	pid_t pid;
	if (0 > (pid = fork())) {
		fprintf(stdout, "fork error and exit\n");
		exit(EXIT_FAILURE);
	} else if (0 == pid) {
		for (count = 100 ; 0 <= count; count--) {
			for (i = 0; i < 5; i++)
				sub(a, b);
			for (i = 0; i < 5; i++)
				add(a, b);
			usleep(500);
		}
	} else {
		sleep(10);
	}
	return 0;
}
