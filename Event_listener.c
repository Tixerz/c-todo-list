#include <ctype.h>
#include <stdio.h>
#include <unistd.h>
char ReadKey() {
  int ret;
  char c;
  while ((ret = read(STDIN_FILENO, &c, 1)) != 1) {
  }
  return c;
}
