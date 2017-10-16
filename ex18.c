#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>


// a typedef creates a fake type, in this
// case for a function pointer
typedef int (*compare_func)(int a, int b);

void die(const char *message);
int *bubble_sort(int* numbers, int count, compare_func compare);
int sorted_order(int a, int b);
int reverse_order(int a, int b);
int strange_order(int a, int b);
void test_sorting(int *numbers, int count, compare_func compare);

int main(int argc, char* argv[]) {
  if (argc < 2)
    die("Useage: ex18 1 2 3 4 5 etc");

  int count = argc - 1;
  char **inputs = argv + 1;
  int *numbers = malloc(count * sizeof(int));
  if(!numbers)
    die("Memory error.");

  for(int i = 0; i < count; i++)
    numbers[i] = atoi(inputs[i]);

  test_sorting(numbers, count, sorted_order);
  test_sorting(numbers, count, reverse_order);
  test_sorting(numbers, count, strange_order);
  free(numbers);
  return 0;
}

// a classic bubble sort function that uses the
// compare_func to do the sorting
int *bubble_sort(int* numbers, int count, compare_func compare) {
  int array_size = count * sizeof(int);
  int *target = malloc(array_size);
  int temp;

  if(!target)
    die("memory not allocated. exiting");

  memcpy(target, numbers, array_size);
  for(int i = 0; i < count; i++) {
    for(int j = 0; j < count - 1; j++) {
      if(compare(target[j], target[j+1])) {
        temp = target[j+1];
        target[j+1] = target[j];
        target[j] = temp;
      } // end if
    } // end for j < count - 1
  } // end for j < count

  return target;
} // end bubble_sort

void die(const char *message) {
  if(errno) {
    perror(message);
  } else {
    printf("ERROR: %s\n", message);
  }
  exit(1);
}

int sorted_order(int a, int b) {
  return a - b > 0;
}
int reverse_order(int a, int b) {
  return b - a > 0;
}
int strange_order(int a, int b) {
  if(a == 0 || b == 0)
    return 0;
  else
    return a % b > 0;
}
void test_sorting(int *numbers, int count, compare_func compare) {
  int *sorted = bubble_sort(numbers, count, compare);
  if(!sorted)
    die("failed to sort as requested");

  for(int i = 0; i < count; i++)
    printf("%d ", sorted[i]);
  printf("\n");
  // unsigned char *data = (unsigned char*)compare;
  // for(int i = 0; i < 40; i++)
  //   printf("%02x:", data[i]);
  free(sorted);
}
