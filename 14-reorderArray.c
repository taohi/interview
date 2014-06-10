#include <stdio.h>

void reorder(int *pdata,int length)
{
    int temp;
    if(!pdata||length==0)
        return;
    int *pfront=pdata;
    int *pend=pdata+length-1;
    while(pfront<pend)
    {
        while(pfront<pend && (*pfront&0x1) != 0)
            pfront++;
        while(pfront<pend && (*pend&0x1) == 0)
            pend--;
        if(pfront<pend)
        {
            temp=*pfront;
            *pfront=*pend;
            *pend=temp;
        }
    }
}

int main() 
{
    int data[]={0,1,2,3,4,5,6,7,8,9};
    int *pdata=data;
    int i=0;
    reorder(pdata,10);
    while(i<=9)
    {
        printf("%d\t",*(pdata+i));
        i++;
    }
    printf("\n");
    return 0;
}
