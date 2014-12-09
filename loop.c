#include <stdio.h>
#include <string.h>

int sub(void)
{
	int i, j;
	char buf1[10] = {0}, buf2[10] = {0};
	memset(buf1, 0xff, sizeof(buf1));
	for (i = 0, j = 0; -1 != i; i++) {
		if (0 == ++j % 100000000)
			fprintf(stdout, "j :%d\n", j);
		memcpy(buf2, buf1, sizeof(buf1));
	}
	fprintf(stdout, "j :%d\n", j);
	return 0;
}

int main(void)
{
	sub();
	return 0;
}
