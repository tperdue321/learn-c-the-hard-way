#include <stdio.h>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    // abort program if anything but 1 command line arg given
    printf("ERROR: You need one argument for this program.\n");
    return 1;
  } // end if

  // parsing first arg letter by letter while not null char
  for(int i = 0; argv[1][i]; i++) {
    char letter = argv[1][i];
    switch(letter) {
      case 'a':
      case 'A': // fallthrough
        printf("%d: 'A'\n", i);
        break;
      case 'e':
      case 'E': // fallthrough
        printf("%d: 'E'\n", i);
        break;
      case 'i':
      case 'I': // fallthrough
        printf("%d: 'I'\n", i);
        break;
      case 'o':
      case 'O': // fallthrough
        printf("%d: 'O'\n", i);
        break;
      case 'u':
      case 'U': // fallthrough
        printf("%d: 'U'\n", i);
        break;
      default:
        printf("%d %c is not a vowel\n", i, letter);

    } // end switch
  } // end for

  return 0; // return back to the console
} // end main
