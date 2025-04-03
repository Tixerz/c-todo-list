#include <string.h>
#include <stdlib.h>
#include <stdio.h>

char **pull_data(char *path, char **buff);
void blit(int row, int col, int size, char **buff);
void free_data(char **buff, int size);

void full_display() {
  printf("\033[?2J");
  char **menu =
      pull_data("./config/display_templates/main_menu_title.conf", menu);
  char **focus_button =
      pull_data("./config/display_templates/focus_button.conf", focus_button);
  char **status_button =
      pull_data("./config/display_templates/status_button.conf", status_button);
  char **test_button =
      pull_data("./config/display_templates/test_button.conf", test_button);
  blit(10, 10, 5, menu);
  blit(16, 20, 1, focus_button);
  blit(19, 20, 1, status_button);
  blit(22, 20, 1, test_button);
  free_data(menu, 5);
  free_data(status_button, 1);
  free_data(focus_button, 1);
  free_data(test_button, 1);
}
void print_description(char* string) {
    char *copy = malloc(126);
    memcpy(copy, string, 123);
    if (strlen(string) > 123) {
	copy[123] = 0;
	strcat(copy, "...");
    }
    for (int i=0; copy[i] != 0; i++) {   // preventing from broking lines
        if (copy[i] < ' ') {             // ascii codes lower than whitespace are nonprintble
	    copy[i] = 0;
	    char* temp = copy + i;
	    for (int j=0; temp[j] < ' '; temp++) {}
	    strcat(copy, temp);
	}
    }
    char **ptr = &copy;
    printf("\033[15;66H\033[38;5;243mdescription-----------------------------------\n");
    printf("\033[38;5;15m");
    blit(14, 33, 1, ptr);
    free(copy);
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

void select_test() {
  printf("\033[0;36m");
  char **test_button =
      pull_data("./config/display_templates/test_button.conf", test_button);
  test_button[0][4] = '>';
  blit(22, 20, 1, test_button);
  print_description("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\ttest c code");
  printf("\033[0;37m");
  free_data(test_button, 1);

}




