#include <stdio.h>
#include <stdlib.h>

#define MAX_LEN 256

int count(char *buff) {
  int i = 0;
  while (buff[i] != '\0') {
    i++;
  }
  return i;
}

void pull_data(char *path, char **main_buff) {
  FILE *file = fopen(path, "r");
  char temp_buff[MAX_LEN];
  int i = 0;
  int size;
  while (fgets(temp_buff, MAX_LEN, file)) {
    size = count(temp_buff);

    main_buff[i] = (char *)malloc(size);
    for (int j = 0; j <= size; j++) {
      main_buff[i][j] = temp_buff[j];
    }
    i++;
  }
  fclose(file);
}

void free_data(char **buff, int size) {
  for (int i = 0; i < size; i++) {
    free(buff[i]);
  }
  free(buff);
}
