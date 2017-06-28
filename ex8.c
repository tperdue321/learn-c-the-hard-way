#include <stdio.h>

int main(int argc, char *argv[]) {
  int i = 0;

  if (argc == 1) {
    printf("You only have one argument. What ya doing bud???\n");
  } else if (argc > 1 && argc < 4) {
    printf("Here are your arguments:\n");

    for(int i = 0; i < argc; i++)
      printf("%s ", argv[i]);

    printf("\n");
  } else {
    printf("You have too many arguments. What ya doing bud???\n");
  }
  return 0;
}
