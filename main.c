#include <stdio.h>
#include <termios.h>
// functions from screen lib

void full_display();
void select_focus();
void select_status();
// functions from Event Listener
char ReadKey();

// terminal config funcs
void enable_raw_mode();
void disable_raw_mode();

void detectArrow(char *buff) {
  buff[1] = ReadKey();
  buff[2] = ReadKey();

  if (buff[1] == '[' && buff[2] == 'A') {
    full_display();
    select_focus();

  } else if (buff[1] == '[' && buff[2] == 'B') {
    full_display();
    select_status();
  }
}

// read key events
void input(char *buff) {
  while (1) {
    buff[0] = ReadKey();
    if (buff[0] == 'f')
      break;
    else if (buff[0] == 27)
      detectArrow(buff);
    printf("%c\r\n", buff[0]);
  }
}

int main() {

  enable_raw_mode();
  full_display();
  char c[4];
  input(c);
  disable_raw_mode();
  return 0;
}
