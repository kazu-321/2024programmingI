#include <stdio.h>
int main(int argc, char **argv){
	int i;
	printf("入力数＝%d\n",argc);
	printf("コマンド名＝%s\n",argv[0]);
	for(i=1; i<argc; ++i){
		printf("%d個目の引数の%d文字目=%c\n",i,1,argv[i][1]);
	}
	return 0;
}