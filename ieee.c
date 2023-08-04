#include<stdio.h>
void printbinary(int n,int i){
    int k;
    for(k=i-1;k>=0;k--){
        if((n>>i)&1)
        printf("1");
        else
        printf("0");
    }
}
 typedef union {
    float f;
    struct {
        unsigned int mantisa :23;
        unsigned int exponent :8;
        unsigned int sign :1;
    }raw;
}myfloat;
void printIEEE(myfloat var)
{
printf("%d",var.raw.sign);
printf("||");
printbinary(var.raw.exponent,8);
printf("||");
printbinary(var.raw.mantisa,23);
printf("\n");
 }
int main(){
   float n;
   myfloat var;
    printf("enter the number : ");
    scanf("%d",&n);
    var.f=n;
    printf("the number is ",var.f);
    printIEEE(var);
    return 0;
}
