#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int min(int a,int b,int c)
{
    int min=(a<b)?a:b;
    min=(min<c)?min:c;
    return min;
}

//返回第index个丑数
int get_ugly_number(int index)
{
    if(index<0)
        return 0;
    int *ugly_num=(int *)malloc(sizeof(int)*index);
    memset(ugly_num,0,index*sizeof(int));
    ugly_num[0]=1;
    int next_ugly=1;
    int *p2=ugly_num;
    int *p3=ugly_num;
    int *p5=ugly_num;
    while(next_ugly<index)
    {
        int min_num = min(*p2*2,*p3*3,*p5*5);
        ugly_num[next_ugly]=min_num;
        while(*p2*2<=ugly_num[next_ugly])
            ++p2;
        while(*p3*3<=ugly_num[next_ugly])
            ++p3;
        while(*p5*5<=ugly_num[next_ugly])
            ++p5;
        ++next_ugly;
    }
   int wanted_ugly=ugly_num[next_ugly-1];
   free(ugly_num);
   return wanted_ugly;
}

int main()
{
    int index;
    scanf("%d",&index);
    printf("the %d ugly num:%d\n",index,get_ugly_number(index));
    return 0;
}
