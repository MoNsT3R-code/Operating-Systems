#include <stdio.h>
#include <stdlib.h> // for atoi
#include <string.h> // for strlen, strcmp
int main(int argc, char *argv[]) {
  // If user asks for help
  if (argc == 2 && strcmp(argv[1], "--help") == 0) {
  printf("Usage: %s <name> <age>\n", argv[0]);
  printf(" <name> Your first name (text)\n");
  printf(" <age> Your age (number)\n");
  printf("\nExample:\n %s Alice 25\n", argv[0]);
  return 0;
  }
  // Directly assume: argv[1] = name, argv[2] = age
  char *name =  argv[1];
  char *ageStr =  argv[2];
  int age =  atoi(ageStr);
  printf("Hello, %s! You are %d years old.\n", name, age);
  // 1. Show length of name
  printf("Your name has %zu characters.\n", strlen(name));
  // 2. Tell if user is a minor or adult
  if (age < 18) {
  printf("You are a minor.\n");
  } else {

  printf("You are an adult.\n");
  }
  // 3. Show how many years left until 100
  printf("You will turn 100 in %d years!\n", 100 - age);
  return 0;
}

 





