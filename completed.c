//#include <stdio.h>
//int main() {
//  double fever;
//    printf("\nPlease enter your temperature: "); 
//    scanf("%lf",&fever);
      
//      if(fever>98.6) { 
      
//        printf("You have a high fever\n");
//        printf("Take some medicine\n\n"); 
      
//        }
//    else if(fever==98.6) 
//      printf("Your temperature is normal\n\n"); 
//    else
//      printf("Your temperature is low\n\n");
//}

  //printf("Even numbers from 0 to 10 are: ");
  //for (int i=0; i<=10; i+=2) { 
  //    printf("%d", i); 
  //  if(i!=10) printf(", "); 
  //}
//}

  //int list[5]={18,9,45,36,90}; 
  //char name[8]={"Abdullah"}; 
  //  printf("\n\n3rd element of list is %d\n", list[2]);
  //  printf("6th element of array name is %c\n", name[5]);
  //  printf("The complete string \"name\" is %s\n", name);
  //}

//  int j=2, FibCount=10, f[10];
//  f[0]=0; f[1]=1; 
//  printf("\nFirst 10 Fibonacci Numbers are: ");
//  printf("%d, %d", f[0], f[1]);
//  while(j<FibCount){ 
//    f[j] = f[j-1] + f[j-2];
//    printf(", %d", f[j]);
//    j++;
//  }
//  printf("\n\n"); 
//  return 0;
//}

// Task 2

//#include <stdio.h> // include stdio
//int main() {

//  float omega[25]; // array of size 25
//  int n; // loop variable

//  omega[0] = 0.8 ; // first value
//  omega[1] = 1.2 ; // second value

//  for (n = 2; n < 25 ; n++) // fill array
  
//    omega[n] = 0.6 * omega[n-1] + 0.4 * omega[n-2] + 1.0/(n+1); // recurrence
  
//  for (n = 0; n < 25 ; n++) // print all
  
//    printf("%.3f%s", omega[n], n < 25 ? ", " : ""); // comma separated
  
//  printf("\n"); // new line
  
//  for (n = 0; n < 25 ; n++) // filter
  
//    if (omega[n] > 2.0) printf("%.3f ", omega[n]); // print >2.0
  
//  printf("\n"); // new line
//  return 0; // end

//}


