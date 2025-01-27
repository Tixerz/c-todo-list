#include <stdio.h>
#include <termios.h>
// functions from screen lib

void full_display();
void select_focus();
void select_status();
// functions from Event Listener
int input(char *buff);

// terminal config funcs
void enable_raw_mode();
void disable_raw_mode();

// read key events for main menu

void menu_key(char *buff) {
  while(1) {
    if(input(buff) == 1) {
      full_display();
      select_focus();
    }else if(input(buff) == 0) {
      full_display();
      select_status();
    }else if(input(buff) == -1) break;
  }
}

int main() {

  enable_raw_mode();
  full_display();
  char c[4];
  menu_key(c);
  disable_raw_mode();
  return 0;
}
