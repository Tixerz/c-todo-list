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

int detectArrow(char *buff) {
  buff[1] = ReadKey();
  buff[2] = ReadKey();

  if(buff[1] == '[' && buff[2] == 'A') return 1;
  else if(buff[1] == '[' && buff[2] == 'B') return 0;
  return -1;
}
int input(char *buff) {

  buff[0] = ReadKey();

  if (buff[0] == 'f') return -1;
  else if(buff[0] == 27) return detectArrow(buff);
  return -2;
}
