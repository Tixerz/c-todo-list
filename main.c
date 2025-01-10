#include <stdio.h>
#include <termios.h>
// functions from Event Listener
char ReadKey();

// terminal config funcs
void enable_raw_mode();
void disable_raw_mode();
// vars from term init
int main() {

  enable_raw_mode();

  char c;
  // main loop
  while (1) {
    // read key events
    c = ReadKey();
    if (c == 'f')
      break;
    printf("%c:%d\r\n", c, c);
  }
  disable_raw_mode();
  return 0;
}
