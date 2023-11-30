#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
  pid_t p = fork();
  if (p == 0) {
    printf("in child proc\n");
  } else if (p < 0) {
    printf("fork fail\n");
  } else {
    printf("in parent pid is %d\n", p);
  }
  printf("pid is %d\n", p);
}
