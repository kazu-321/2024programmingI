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
    int n,m,index,num;
    printf("n>>>");scanf("%d",&n);
    printf("m>>>");scanf("%d",&m);
    if(n==m){
        printf("n==mです。\n");
        return 0;
    }
    printf("桁数>>>");scanf("%d",&index);
    long long int num10=0;
    for(int i=0;i<index;i++){
        printf("%d桁目の値を入力>>>",i+1);
        scanf("%d",&num);
        num10+=power(n,i)*num;
    }

    index=0;
    while(power(m,index)<=num10) index++;
    // printf("10進数で %lld\n",num10);
    // printf("答えは%d桁\n",index);

    int ans[index];
    int i=0;
    while(num10!=0){
        // printf("%d %d %lld\n",i,index-i,num10%m);
        ans[index-i-1]=num10%m;
        num10=(int) (num10/m);
        i++;
    }
    for(int i=0;i<index;i++) printf("%d ",ans[i]);
    return 1;
}

int main(){
    main49();
}