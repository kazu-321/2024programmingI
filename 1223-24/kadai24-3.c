
#include <stdio.h>
int main(void){
   FILE *fp;
   fp = fopen("file.txt", "a");

   if(fp == NULL){
     printf("Can not open the file.\n");
     return -1;
   }
   else{
     printf("The file is opened.\n");
   }

   char input[256];
   scanf("%s",input);
   fputs(input,fp);
   fputs("\n",fp);
   printf("O.K.\n");

   fclose(fp);

   printf("The file is closed.\n");

   return 0;
}