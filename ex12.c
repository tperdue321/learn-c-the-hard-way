#include <stdio.h>

int main(int argc, char *argv[]) {
  int areas[] = {10, 12, 13, 14, 20};
  char name[] = "Zed";
  char fullName[] = {
    'T', 'r', 'a', 'v', 'i', 's',
    ' ', 'J', '.', ' ',
    'P', 'e', 'r', 'd', 'u', 'e' , '\0'
  };


  printf("the size of an int: %ld\n", sizeof(int));
  printf("The size of int areas[]: %ld\n", sizeof(areas));
  printf("The number of ints in areas: %ld\n", sizeof(areas) / sizeof(int));
  printf("The first area is %d, the 2nd %d.\n", areas[0], areas[1]);
  printf("The size of a char: %ld\n", sizeof(char));
  printf("The size of char name[]: %ld\n", sizeof(name));
  printf("The number of chars: %ld\n", sizeof(name) / sizeof(char));
  printf("The size of char fullName[]: %ld\n", sizeof(fullName));
  printf("The number of chars%ld\n", sizeof(fullName) / sizeof(char));
  printf("name=\"%s\" and fullName=\"%s\"\n", name, fullName);

  return 0;
} // end main
