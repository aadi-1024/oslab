#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd;
    char buf[80];
    static char msg[] = "hello";

    fd = open("file.txt", O_RDWR | O_CREAT);
    if (fd != -1) {
        write(fd, msg, sizeof(msg));
        lseek(fd, 0, 0);
        read(fd, buf, sizeof(msg));
        printf("%s\n", buf);
        close(fd);
    }
}