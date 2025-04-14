#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>

int main(int argc, char *argv[]) {
	int filedes;
	char pathname[100] = "./";

	if (argc != 2 ) {
		printf("cd [source file]\r\n");
		filedes = open("./defaultFile.txt", O_CREAT | O_RDWR, 0644);
	}
	else {
		strcpy(pathname, argv[1]);
		filedes = open(pathname, O_CREAT | O_RDWR, 0644);
	}

	if (filedes == -1) {
		printf("file open error!\r\n");
		return -1;
	}

	close(filedes);
	return 0;
}
