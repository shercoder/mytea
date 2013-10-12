#include <stdio.h>
#include <stdlib.h> /* exit() */
#include <string.h>
#include <unistd.h> /* getopt() */

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
 
  char option = getopt(argc, argv, "a");

//  printf("Filename ==> %s\n", argv[optind]);

  FILE *file = NULL;
  if (argv[optind] != NULL) {
    file = fopen(argv[optind], "w");
  }

  char line[BUFFER_SIZE];
  while (fgets (line, BUFFER_SIZE, stdin) != NULL ) {
    fputs (line, stdout);
    if (file != NULL) 
      fputs (line, file);
  }

  if (file != NULL) {
    fclose(file);
  }
  exit(EXIT_SUCCESS);
}
