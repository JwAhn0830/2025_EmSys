#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[]) {
    int fdin, fdout;
    ssize_t nread;
    char buffer[5];

    if (argc != 3) {
        printf("cp [source file] [dest file]\r\n");
        exit(-1);
    }

    fdin = open(argv[1], O_RDONLY);
    fdout = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);

    while(1) {
        nread = read(fdin, buffer, 5);

        if (nread == 0) {
            break;
        }
        else {
            write(fdout, buffer, nread);
        }
    }

    close(fdin);
    close(fdout);
}