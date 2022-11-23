#include <stdio.h>
#include <stdlib.h>

int main() {
  char *str = NULL;
  str = malloc(sizeof(char) * 1);
  *str = 0;
  printf("%p\n", str);
  free(str);
  printf("%p\n", str);
  return 0;
}