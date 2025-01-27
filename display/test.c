#include <stdio.h>

int stringcmp(char *moz, char *moz2) {
  int i = 0;
  while (moz[i] != '\0') {
    if (moz[i] != moz2[i]) {
      return -1;
    }
    i++;
  }
  return 0;
}

int main() {
  int row;
  int col;
  char *moz = "hello\0";
  char *moz2 = "hellu\0";
  int ret = stringcmp(moz, moz2);
  printf("ret%d", ret);
}
