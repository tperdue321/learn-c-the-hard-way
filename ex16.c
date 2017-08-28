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

/*******************************************************************************
description: prints all the values in a struct of type Person
params: pass a Person struct to the function. 
after:  values of the Person struct are printed to the stdout
*******************************************************************************/
void person_print(struct Person *person);

int main () {
  struct Person *joe = person_create("Joe", 8, 52, 80); // create a person
  // create a second person
  struct Person *frank = person_create("Frank Blank", 20, 72, 180); 

  // print out memory location of person one
  printf("Joe is at memory location: %p\n", joe);
  // print out the size of the person
  printf("Joe takes up %lu bytes\n", sizeof(struct Person));
  // print out values of person one
  person_print(joe);

  // print out memory location of person two 
  printf("Frank is at memory location%p:\n", frank);
  // print out values of person two 
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
  // create a ptr to a new person struct
  struct Person *person = malloc(sizeof(struct Person));
  // assert a valid ptr to a person is created 
  assert(person != NULL);
  
  // dup string to make sure person struct owns it
  // assign param values to the new person struct
  person->name = strdup(name);
  person->age = age;
  person->height = height;
  person->weight = weight;

  return person;
}

void person_destroy(struct Person * person) {
  // assert a valid ptr to a person is passed
  assert(person != NULL);

  // free up string memory
  free(person->name);
  // free up struct memory
  free(person);
}

void person_print(struct Person *person) {
  // assert a valid ptr to a person is passed
  assert(person != NULL);

  // print out all the values of the person struct
  printf("Name: %s\n", person->name);
  printf("\tAge: %d\n", person->age);
  printf("\tHeight: %d\n", person->height);
  printf("\tWeight: %d\n", person->weight);
}