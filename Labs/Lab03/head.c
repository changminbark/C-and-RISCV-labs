/* 
 * Chang Min Bark
 * File name: head.c
 * Compile with: gcc -std=c99 head.c -o head
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINES 100
#define MAXBYTE 255

int read_file_lines(FILE *fp, char buffer[MAXLINES][MAXBYTE+1], 
        int lines_expected);

FILE *fp;
int num_lines = 10;
char buffer[MAXLINES][MAXBYTE + 1];

int main(int argc, char *argv[]) {
   if (argc == 1) {
        printf("Usage: ./head <filename> <lines>\n");
        return 0;
    }

   if (argc == 3) {
       num_lines = strtol(argv[2], NULL, 10);
    }

   if (argc > 3) {
       printf("Too many arguments!");
       exit(1);
   }

  fp = fopen(argv[1], "r");
  if (fp == NULL) {
      // printf("fopen failed");
      printf("fopen failed: No such file or directory");
      exit(1);
  }
  
  int lines_read = read_file_lines(fp, buffer, num_lines);
  
  fclose(fp);

  for (int i = 0; i < lines_read; i++) {
    printf("%s", buffer[i]);
  }

  return 0;
}

int read_file_lines(FILE *fp, char buffer[MAXLINES][MAXBYTE + 1], int lines_expected) {
    int line_count = 0;
    for (int i = 0; i < lines_expected; i++) {
        fgets(buffer[i], MAXBYTE + 1, fp);
        line_count++;
    }
    return line_count;
}
