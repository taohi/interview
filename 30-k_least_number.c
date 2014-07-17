#include <stdio.h>

void heap_adjust(int *a,int i,int n)
{
    int child,temp;
    for(temp=a[i];2*i+1 < n;i=child)
    {
        child = 2*i +1;
        if(child!=n-1 && a[child+1]<a[child])
            ++child;
        if(temp <= a[child])
            break;
        a[i]=a[child];
    }
    a[i]=temp;
}

void swap(int *a,int i,int j)
{
    int temp;
    temp=a[i];
    a[i]=a[j];
    a[j]=temp;
}

void get_least_k(int *a,int n,int k)
{
    int i;
    //将全数组调整成小顶堆
    for(i=n/2 -1;i>=0;i--)
        heap_adjust(a,i,n);

    //取走目前最小的a[0],继续把剩下数组调整成小顶堆
    //重复K次，则取走了最小的K个数
    for(i=n-1;i>=n-k;i--)
    {
        swap(a,0,i);
        printf("%d\t",a[i]);
        heap_adjust(a,0,i);
    }
    printf("\n");
}

int main()
{
    int a[]={1,2,39,77,88,50,100,200,712,21,9,10,20,30,44,33,22,17,18,39};
    get_least_k(a,20,5);
    return 0;
}
