#include <stdio.h>
char **pull_data(char *path, char **buff);
void blit(int row, int col, int size, char **buff);
void free_data(char **buff, int size);

void full_display() {
  char **menu =
      pull_data("./config/display_templates/main_menu_title.conf", menu);
  char **focus_button =
      pull_data("./config/display_templates/focus_button.conf", focus_button);
  char **status_button =
      pull_data("./config/display_templates/status_button.conf", status_button);
  blit(10, 10, 5, menu);
  blit(16, 20, 1, focus_button);
  blit(19, 20, 1, status_button);
  free_data(menu, 5);
  free_data(status_button, 1);
  free_data(focus_button, 1);
}

void select_focus() {
  printf("\033[0;36m");
  char **focus_button =
      pull_data("./config/display_templates/focus_button.conf", focus_button);
  focus_button[0][4] = '>';
  blit(16, 20, 1, focus_button);
  printf("\033[0;37m");
  free_data(focus_button, 1);
}

void select_status() {
  printf("\033[0;36m");
  char **status_button =
      pull_data("./config/display_templates/status_button.conf", status_button);

  status_button[0][4] = '>';
  blit(19, 20, 1, status_button);
  printf("\033[0;37m");
  free_data(status_button, 1);
}
