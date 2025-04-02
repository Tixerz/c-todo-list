#include <stdio.h>
#include <string.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include "box.h"
void blit(int row, int col, int size, char **main);
void free_data(char **buff, int size);
char **pull_data(char *path, char ** main_buff);
char ReadKey();
void box_entry() {
   struct winsize win;
   ioctl(STDOUT_FILENO, TIOCGWINSZ, &win);
   char **msgbox = pull_data("./modules/mod-boxtest/messagebox.conf", msgbox);
   blit(win.ws_row / 2, (win.ws_col / 2) - strlen(msgbox[0]), 4, msgbox);
   free_data(msgbox, 4); 
   ReadKey();

}
