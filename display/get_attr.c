#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>

void GetWindowSize(int *row, int *col) {
  struct winsize window;
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &window);
  *col = window.ws_col;
  *row = window.ws_row;
}

int count(char *buff) {
  int i = 0;
  while (buff[i] != '\0') {
    i++;
  }
  return i;
}
void SimpleDisplay(char *ptrBuffer, int *WinRow, int *WinCol) {

  // calculate the size of ptrBuffer
  int size = count(ptrBuffer);
  int numberOfXSpaces = (size / 2) - *WinCol;
  int numberOfYSpaces = *WinRow / 2;

  for (int i = 0; i <= numberOfYSpaces; i++) {
    write(STDOUT_FILENO, "\n", 1);
  }
  for (int i = 0; i <= numberOfXSpaces; i++) {
    write(STDOUT_FILENO, " ", 1);
  }
  printf("%s", ptrBuffer);
}
