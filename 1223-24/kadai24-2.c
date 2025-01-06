
#include <stdio.h>
#define NUM 20
int main(void)
{
  FILE *fp;
  char str1[NUM], str2[NUM];

  fp = fopen("file.txt", "r");
  if(fp == NULL){
    printf("Can not open the file.\n");
    return -1;
  }
  else{
    printf("The file is opened.\n");
  }
  fgets(str1, NUM-1, fp);
  fgets(str2, NUM-1, fp);

  printf("%s\n\n", str1);
  printf("%s", str2);

  fclose(fp);
  printf("The file is closed.\n");
  return 0;
}