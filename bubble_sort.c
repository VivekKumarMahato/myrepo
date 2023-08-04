#include<stdio.h>
int main(){
	int temp;
	int arr[]={3,13,7,26,44,23,98,57};
	printf("The Array  element before sorting : \n");
	for(int i=0;i<8;i++){
		printf("%d\n",arr[i]);
	}
	printf("\n");
	for(int i=0;i<8;i++){
		for(int j=0;j<i;j++){
			if(arr[j]>arr[j+1]){
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	printf("The Array  element after Bubble sorting : \n");
	for(int i=0;i<8;i++){
		printf("%d\n",arr[i]);
	}
	printf("\n");
return 0;	
}
