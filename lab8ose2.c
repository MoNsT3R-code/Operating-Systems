

//Example 2

#include <stdio.h>
#include <stdlib.h>

int main()
{
   int num;
   FILE *fptr;

   // following line will create program.txt file
   fptr = fopen("program.txt","w"); //w is the write flag

   if(fptr == NULL)
   {
      printf("File Creation Error!");   
      exit(1);             
   }

   printf("Enter num: ");
   scanf("%d",&num);

   fprintf(fptr,"%d",num);
   fclose(fptr);

   return 0;
}
