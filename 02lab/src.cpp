#include <stdio.h>
#include <stdlib.h>

int main() {
    int n=0,a=0,b=0,c=0;

    scanf("%d",&n);
    int* arr1 = new int[n];
    int* arr2 = new int[n];
    for (int i = 0; i < n; i++)
    {
        arr1[i]=rand()%100+1;
        arr2[i]=rand()%100+1;
    }
    for (int i = 0; i < n; i++)
    {
        printf("arr1[%d]|arr2[%d]\n",arr1[i],arr2[i]);
    }
    for (int i = 0; i < n; i++)
    {
        if (arr1[i]<arr2[i])
        {
            a++;
        }
        else if(arr1[i]==arr2[i])
        {
            b++;
        }
        else
        {
            c++;
        }
    }
    printf("a[%d] b[%d] c[%d]\n",a,b,c);
    
    return 0;
}