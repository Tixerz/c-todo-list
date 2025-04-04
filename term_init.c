#include <stdio.h>
#include <termios.h>
#include <unistd.h>
struct termios original_term;
void enable_raw_mode() {
  printf("\033[?25l\033[2J");
  tcgetattr(STDIN_FILENO, &original_term);
  struct termios raw;
  tcgetattr(STDIN_FILENO, &raw);
  raw.c_lflag &= ~(ECHO | ICANON);

  raw.c_lflag &= ~(ISIG);

  // disable ctrl-s and ctrl-q signals
  raw.c_iflag &= ~(IXON);

  // disabling the ctrl-v signal
  raw.c_lflag &= ~(IEXTEN);

  // fix ctrl - M signal raw.c_iflag &= ~(ICRNL);
  raw.c_cc[VMIN] = 0;
  raw.c_cc[VTIME] = 1;
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

void disable_raw_mode() {
  printf("\033[?25h\033[55;0H");
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &original_term);

}
