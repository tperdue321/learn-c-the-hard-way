#include <stdio.h>

int main (int argc, char *argv[]) {
  // exploring with character arrays sillyness.
  int i = 0;
  char *chars[] = {"aaa", "bbb"};
  // char letters[3] = {};
  while (i < 2) {
    printf("%s\n", chars[i]);
    // letters = chars[i];
    int j = 0;
    while(chars[i][j]) {
      printf("%c\n", chars[i][j]);
      j++;
    }
    i++;
  } // end while


  // explore basic while loop counter in C
  i = 0;
  while (i < 25) {
    printf("%d", i);
    i++;
  } // end while
  return 0;
} // end main
