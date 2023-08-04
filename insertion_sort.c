#include<stdio.h>
int main()
{
    int i,j,n,temp,a[100];
    printf("enter the size of array");
    scanf("%d ",&n);
    printf("enter %d element",n);
    for(i=0;i<=n;i++)
    {
    scanf("%d",&a[i]);
    }
    for (i = 1; i <=n; i++) {
        temp= a[i];
        j = i - 1;
 
        while (j >= 0 && a[j] > temp) {
            a[j + 1] = a[j];
            j = j - 1;
        }
        a[j + 1] = temp;
    }
    printf("sorted array is");
    for(i=0;i<=n;i++){
        printf("%d ",a[i]);
    }
        return 0;
}