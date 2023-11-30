#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
  pid_t p;
  if (fork() == 0) {
    printf("chuttad\n");
    exit(1);
  } else {
    p = wait(NULL);
  }
  printf("%d pid is", getpid());
  printf("%d pid of child", p);
}
