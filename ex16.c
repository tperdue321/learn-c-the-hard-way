#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>


// describe a person
struct Person {
  char *name;
  int age;
  int height;
  int weight;
};

/*******************************************************************************
description: creates a struct of type Person
params: pass a string, and 3 ints for age, height and weight.
after:  dynamically allocates memory for a Person struct and returns the struct
        back to the calling function
*******************************************************************************/
struct Person *person_create(char *name, int age, int height, int weight);

/*******************************************************************************
description: destroys a struct of type Person
params: pass a Person struct to the function. 
after:  frees up the memory used up by a Person struct by destroying the Person
        struct passed to the function.
*******************************************************************************/
void person_destroy(struct Person *person);


void person_print(struct Person *person);

int main () {
  struct Person *joe = person_create("Joe", 8, 52, 80);
  struct Person *frank = person_create("Frank Blank", 20, 72, 180);

  printf("Joe is at memory location: %p\n", joe);
  printf("Joe takes up %lu bytes\n", sizeof(struct Person));
  person_print(joe);

  printf("Frank is at memory location%p:\n", frank);
  person_print(frank);

  // make everyone 20 years older and print again
  joe->age += 20;
  joe->height -= 2;
  joe->weight += 40;

  frank->age += 20;
  frank->weight += 20;
  person_print(frank);
  person_print(joe);

  person_destroy(joe);
  person_destroy(frank);
  // person_print(joe);
  // person_print(frank);
  return 0; 
}


struct Person *person_create(char *name, int age, int height, int weight) {
  struct Person *person = malloc(sizeof(struct Person));
  assert(person != NULL);
  
  person->name = strdup(name);
  person->age = age;
  person->height = height;
  person->weight = weight;

  return person;
}

void person_destroy(struct Person * person) {
  assert(person != NULL);

  free(person->name);
  free(person);
}

void person_print(struct Person *person) {
  assert(person != NULL);

  printf("Name: %s\n", person->name);
  printf("\tAge: %d\n", person->age);
  printf("\tHeight: %d\n", person->height);
  printf("\tWeight: %d\n", person->weight);
}