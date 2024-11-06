#include <stdio.h>
int main(int argc, char **argv){
    if(argc==1){
        printf("引数が足りません\n");
        return 1;
    }
    if(argv[1][0]=='-'){
        printf("オプション[%c]\n",argv[1][1]);
    }
    if(argc>5){
        printf("引数が多すぎます\n");
        return 1;
    }
    for(int i=2;i<argc;i++){
        printf("%s\n",argv[i]);
    }
    return 0;
}