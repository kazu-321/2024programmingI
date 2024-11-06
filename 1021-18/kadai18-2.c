#include <stdio.h>
#include <string.h>
typedef struct PLC {					/*構造体型の宣言*/
	char name[100];
	int i;
	double d;
} PL;

int main(){
    PL plc[3];
    for(int i=0;i<3;i++){
        printf("input plc[%d].name >>>",i);scanf("%s",plc[i].name);
        printf("input plc[%d].i >>>",i);scanf("%d",&plc[i].i);
        printf("input plc[%d].d >>>",i);scanf("%lf",&plc[i].d);
        printf("\n");
    }
    for(int i=0;i<3;i++){
        printf("%d %s %d %lf",i,plc[i].name,plc[i].i,plc[i].d);
        printf("\n");
    }
    return 0;
}
