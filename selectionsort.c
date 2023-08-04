#include <stdio.h>
int main()
{
    int n = 10;
    int arr[] = {3,2,6,5,4,7,8,9,5,1};
    int min;
    for(int i = 0; i < n - 1; i++) {
        min = i;
        for(int j = i + 1; j < n; j++) {
            if(arr[min] > arr[j]) {
                min = j;
            }
        }
        if(min!= i)
        {
            int temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
    printf("Sorted Array: ");
    for(int i = 0; i < n; i++)  {
        printf(" %d", arr[i]);
    }
    return 0;
}
