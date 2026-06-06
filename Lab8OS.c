//Example 1
#include<sys/types.h>  
#include<dirent.h>  
#include<stdio.h>  

int main(int c, char* arg[]) {  
DIR *d;  
struct dirent *r;  
int i=0;  

d=opendir(arg[1]);  // open given directory  

printf("\n\t NAME OF ITEM \n");  // print header line  

while((r=readdir(d)) != NULL) {  // read directory entries one by one  
printf("\t %s \n",r->d_name);    // print each file/folder name  
i=i+1;  // count each item  
}  

printf("\n TOTAL NUMBER OF ITEMS IN THAT DIRECTORY ARE %d \n",i);  

return 0;  
}
