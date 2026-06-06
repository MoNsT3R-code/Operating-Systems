// Make a calculater 

#include <stdio.h>
int main() {

  float number1;
  
      printf("Enter the number 1: ");
      scanf("%.2f", &number1); 
  
   float number2;
  
      printf("Enter the number 2: ");
      scanf("%.2d", &number2); 
      
    float sum = number1 + number2;
    printf("Sum: %.2df\n", sum);
    
    float divide = number1 % number2;
    printf("divide: %.2f\n", divide);

    float mul = number1 * number2;
    printf("multiply: %.2f\n", mul);

    float minus = number1 * number2;
    printf("minus: %.2f\n", minus);
    
    
    return 0;      

}

