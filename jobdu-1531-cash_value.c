#include <stdio.h>
#include <stdio.h>

int compare(void *arg1,void *arg2)
{
    return *(int *)arg1 - *(int *)arg2;
}

int main()
{
    int N=0;
    int value[100];
    int total=0;
    int i=0;
    while(scanf("%d",&N)!=EOF)
    {
        for(i=0;i<N;i++)
            scanf("%d",&value[i]);
        qsort(value,N,sizeof(int),compare);
        total=0;
        for(i=0;i<N;i++)
        {
            if(value[i]>total+1)
                break;
            else
                total+=value[i];
        }
        printf("%d\n",total+1);
    }
    return 0;
}
//动态规划思想：对于1~i的面值之和total，如果第i+1个数大于total+1则不会组成total+1. 
