#include <stdio.h>

int main(int argc, char *argv[]) {

  // create two arrays we care about
  int ages[] = { 23, 43, 12, 89, 2 };
  char *names[] = {
    "Alan", "Frank",
    "Mary", "John", "Lisa"
  };

  // safely get the size of ages
  int count = sizeof(ages) / sizeof(int);
  int i = 0;

  // print out names and ages using indexing
  for(; i < count; ++i)
    printf("%s has %d years alive.\n", names[i], ages[i]);

  printf("-----\n");

  // set pointers to point to beginning of arrays
  int *cur_age = ages;
  char **cur_name = names;

  // what is the size of a pointer?
  printf("size of an int pointer: %lu\n", sizeof(cur_age));
  printf("size of a pointer to character pointer %lu\n", sizeof(cur_name));
  printf("-----\n");

  // print out names and ages using pointers and incrementing index to
  // dereference new addresses
  for(i = 0; i < count; i++)
    printf("%s is %d years old.\n", *(cur_name + i), *(cur_age + i));

  printf("-----\n");

  // print out names and ages using pointers with array indexing 
  for(i = 0; i < count; i++)
    printf("%s is %d years old.\n", cur_name[i], cur_age[i]);

  printf("-----\n");

  // print out names and ages incrementing the pointers themselves 
  for(; (cur_age - ages) < count; cur_name++, cur_age++) {
    printf("address of cur_age: %d\n", cur_age);    
    printf("address of ages: %d\n", ages);    
    printf("(cur_age - ages): %d\n", (cur_age - ages));
    printf("%s is %d years old.\n", *cur_name, *cur_age);
  }



  return 0;
}