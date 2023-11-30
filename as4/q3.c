#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
  char* args[] = {"./exe", NULL};
  execv("./abc", NULL);
  printf("were so back\n");
}
