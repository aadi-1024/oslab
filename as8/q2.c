#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    int fd[2], n;
    char buf[100];
    pid_t p;

    pipe(fd);
    p = fork();

    if (p > 0) {
        printf("Passing value to child\n");
        write(fd[1], "hello\n", 6);
        sleep(3);
    } else {
        printf("Child printing received value\n");
        n = read(fd[0], buf, 100);
        printf("%s\n", buf);
        write(1, buf, n);
    }
}