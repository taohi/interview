#include <stdio.h>
#define CARD_NUM    5

int compare(void *arg1,void *arg2)
{
    return *(int *)arg1 - *(int *)arg2;
}

int is_continuous(int *number,int length)
{
    if(number==NULL||length<1)    
        return 0;
    qsort(number,length,sizeof(int),compare);
    int num_zero = 0;
    int num_gap = 0;
    int i=0;
    for(i=0;i<length &&number[i]==0;i++)
        num_zero++;
    int small = num_zero;
    int big = small+1;
    while(big<length)
    {
        if(number[small]==number[big])
            return 0;
        num_gap+=number[big]-number[small]-1;
        small=big;
        ++big;
    }
    return (num_gap>num_zero)?0:1;
}

int main(int argc,char *argv[])
{
    int cards[CARD_NUM];
    int i=0;
    while(i<CARD_NUM)
    {
        scanf("%d",&cards[i]);
        i++;
    }
   if(is_continuous(cards,CARD_NUM))
       printf("Continuous.\n");
   else
       printf("Not continuous.\n");
    return 0;
}
