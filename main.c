#include <stdio.h>
#include <termios.h>
// functions from Event Listener
char ReadKey();

// terminal config funcs
void enable_raw_mode();
void disable_raw_mode();

void detectArrow(char* buff) {
    buff[1] = ReadKey();
    buff[2] = ReadKey();

    if(buff[1] == '[' && buff[2] == 'A') printf("up");
    else if(buff[1] == '[' && buff[2] == 'B') printf("down");
}

//read key events
void input(char* buff) {
    while(1) {
        buff[0] = ReadKey();
        if(buff[0] == 'f')
            break;
        else if(buff[0] == 27)
            detectArrow(buff);
        printf("%c\n", buff[0]);
    }
}

int main() {

  enable_raw_mode();

  char c[4];
  input(c);
  disable_raw_mode();
  return 0;
}
