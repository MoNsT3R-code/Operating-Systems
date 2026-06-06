//#include <stdio.h> 

//int main() { 

//    printf("Hello \n World!"); 
//    return 0;

//}

//#include <stdio.h>

//int main() {

//  int num1 = 5;
//  int num2 = 3;
//  int sum = num1 + num2;
//  printf("The sum is: %d\n", sum);
//  return 0;

//}

//#include <stdio.h>

//int main() {

//  float num1 = 5.5, num2 = 2.2;
//  float sum = num1 + num2;
//  printf("Sum: %.2f\n", sum);
//  return 0;
  
//}

//#include <stdio.h>

//int main() {

//  char letter = 'A';
//  char word[] = "Hello";
  
//  printf("character: %c\n", letter);
//  printf("string: %s\n", word);

//  return 0;
//}

//#include <stdio.h> 

//int main() {

//    int age; 
//    char name[50]; 
//    printf("Enter your age: ");
//    scanf("%d", &age); 
//    printf("Enter your name: ");
//    scanf("%s", name); 
//    printf("%s is %d years old.\n", name, age);
//    return 0;int sum = num1 + num2;
//  printf("The sum is: %d\n", sum);

//}

#include <stdio.h>

int main() {

    char name[50];
    int age, years;
    printf("Enter your first name: ");
    scanf("%s", name);
    printf("Enter your age: ");
    scanf("%d", &age);
    years = 50 - age;
    printf("%s, you will turn 50 in %d years.\n", name, years);
    return 0;

}









