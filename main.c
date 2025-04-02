#include <stdio.h>
#include <termios.h>
#include "modules/runmod.h"
// functions from screen lib

void full_display();
void select_focus();
void select_status();
void select_test();
// functions from Event Listener
int input(char *buff);

// terminal config funcs
void enable_raw_mode();
void disable_raw_mode();

// read key events for main menu

void idx_hover_action(int idx) {
    if (idx == 0) {  // first element in menu
        full_display();
	select_focus();
    }
    else if (idx == 1) {
        full_display();
	select_status();
    }
    else if (idx == 2) {
        full_display();
	select_test();
    }

}

void menu_key(char *buff) {
  int nelems = 3;  // number of elements in menu
  int selected = 0;
  idx_hover_action(selected);
  while(1) {
    int k = input(buff);
    if(k == 1 && selected > 0) {
      selected--;
      idx_hover_action(selected);
    }else if(k == 0 && selected < nelems - 1) {
      selected++;
      idx_hover_action(selected);
    }else if(k == 3) {
      run_selected(selected);
      full_display();
      selected = 0;
      idx_hover_action(selected);
    }else if(k == -1) break;
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
