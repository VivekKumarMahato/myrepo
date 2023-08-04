#include<stdio.h>
void swap(int *a,int *b){
   int temp=*a;
   *a = *b;
   *b = temp;
}
void heapify(int arr[],int n,int i){
    int smallest=i;
    int leftside=2*i+1;
    int rightside=2*i+2;

    if(leftside < n && arr[leftside] < arr[smallest])
       smallest=leftside;
    if(rightside<n && arr[rightside]<arr[smallest])
       smallest=rightside;

    if(smallest !=i){
    swap(&arr[i],&arr[smallest]);
     heapify(arr,n,smallest);
    }
}
void heapsort(int arr[],int n){
    for(int i=(n/2)-1;i>=0;i--)
     heapify(arr,n,i);
    for(int i=n-1;i>=0;i--){
     swap(&arr[0],&arr[i]);

     heapify(arr,i,0);
    }
}
   int main(){
    int arr[]={15,45,10,7,26,85,27};
    int n=sizeof(arr)/sizeof(arr[0]);
    printf("after heapsort the array is ");
     heapsort(arr,n);
     for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
     }
   }