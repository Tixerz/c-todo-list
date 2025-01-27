#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX_LEN 200

int count(char *buff) {
  int i = 0;
  while (buff[i] != '\0') {
    i++;
  }
  return i;
}

char **pull_data(char *path, char **main_buff) {
  FILE *file = fopen(path, "r");
  char temp_buff[MAX_LEN];
  int i = 0;
  int j = 0;
  main_buff = (char **)malloc(1 * sizeof(char *));
  int size;
  while (fgets(temp_buff, MAX_LEN, file)) {
    size = count(temp_buff);
    main_buff = realloc(main_buff, (i + 1) * sizeof(char *));
    main_buff[i] = (char *)malloc(size + 1);
    for (j = 0; j <= size - 1; j++) {
      main_buff[i][j] = temp_buff[j];
    }
    main_buff[i][j] = '\0';
    i++;
  }
  fclose(file);

  return main_buff;
}

void free_data(char **buff, int size) {
  for (int i = 0; i < size; i++) {
    free(buff[i]);
  }
  free(buff);
}

void blit(int row, int col, int size, char **main) {
  write(STDOUT_FILENO, "\x1b[H)", 4);

  for (int i = 0; i <= row; i++) {
    write(STDOUT_FILENO, "\x1b[1B", 4);
  }
  for (int i = 0; i <= col; i++) {
    write(STDOUT_FILENO, "\x1b[1C", 4);
  }

  for (int i = 0; i < size; i++) {
    printf("%s", main[i]);
    for (int j = 0; j <= col; j++) {
      write(STDOUT_FILENO, "\x1b[1C", 4);
    }
  }
  printf("\n");
}
