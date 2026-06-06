

//Example 3

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>

int main()
{
   int num;
   FILE *fptr;
   struct stat info;

   if ((fptr = fopen("program.txt","r")) == NULL){
       printf("Error! opening file");

       // Program exits if the file pointer returns NULL.
       exit(1);
   }

    stat("test.txt", &info);                   // get file info
    printf("Size: %ld bytes\n", info.st_size); // file size
    printf("Owner: %d\n", info.st_uid);        // owner ID
    printf("Mode: %o\n", info.st_mode);        // permissions
    printf("Modified: %ld\n", info.st_mtime);  // last modified time

    if (access("test.txt", R_OK) == 0)         // check read access
        printf("Readable\n");
    else
        printf("Not readable\n");
    if (access("test.txt", W_OK) == 0)         // check write access
        printf("Writable\n");
    else
        printf("Not writable\n");

   fscanf(fptr,"%d", &num); //What is going on here?

   printf("Value of n as Read from the file=%d", num);
   fclose(fptr); 
  
   return 0;
}
