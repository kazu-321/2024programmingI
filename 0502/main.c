#include <stdio.h>
int main42(){
    printf("\n\n課題4-2\n");
    char a,b,c;
    a='9';
    b='A';
    c='a';
    printf("%c %d %x \n",a,a,a);
    printf("%c %d %x \n",b,b,b);
    printf("%c %d %x \n",c,c,c);
    return 0;
}


int main46(){
    printf("\n\n課題4-6\n");
    int x,a,b;
    printf("x>>>");scanf("%d",&x);
    printf("a>>>");scanf("%d",&a);
    printf("b>>>");scanf("%d",&b);
    x+=1;
    printf("2) %d\n",x);
    a+=b;
    x*=a;
    printf("3) %d\n",x);
    x/=2;
    printf("4) %d\n",x);
    x--;
    printf("5) %d\n",x);
}


int main48(){
    printf("\n\n課題4-8\n");
    int x=1;
    x<<=1;   printf("%d\n",x);
    x<<=1;   printf("%d\n",x);
    x<<=1;   printf("%d\n",x);
    return 0;
}


int power(int base,int exp){
    int ans=1;
    for(int i=0;i<exp;i++) ans*=base;
    return ans;
}

int main49(){
    printf("\n\n課題4-9\n");
    printf("n進法からm進法に変換します。\n");
    printf("入力は各桁ごとに改行してください。\n");
    int n,m;
    printf("n>>>");scanf("%d",&n);
    printf("m>>>");scanf("%d",&m);
    if(n==m){
        printf("n==mです。\n");
        return 0;
    }
    int index=0;
    int num10=0;
    while(1){
        int num=0;
        printf("%d桁目の値を入力>>>",index+1);
        scanf("%d",&num);
        num10+=power(n,index)*num;
        printf("10進数に変換後:%d\n",num10);
        // printf("変換後の値:%d");
        index++;
    }
    return 1;
}

int main(){
    main49();
}