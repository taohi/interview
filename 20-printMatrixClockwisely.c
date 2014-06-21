#include <stdio.h>
void printCircle(int num[][4],int col,int row,int start)
{
    int i=0;
    int endx=row-start-1;
    int endy=col-start-1;
    //从左往右打印一行
    for(i=start;i<=endx;i++)
        printf("%d\t",num[start][i]);
    //从上往下打印一列
    if(start<endy)
        for(i=start+1;i<=endy;i++)
            printf("%d\t",num[i][endx]);
    //从右往左打印一行
    if(start<endx && start<endy)
        for(i=endx-1;i>=start;i--)
            printf("%d\t",num[endy][i]);
    //从下往上打印一列
    if(start<endy-1 && start <endx)
        for(i=endy-1;i>=start+1;i--)
            printf("%d\t",num[i][start]);
}

void printClockwisely(int num[][4],int col,int row)
{
    int start=0;
    if(num==NULL || col<=0 || row<=0)
        return;
    while(col >start*2 && row >start*2) 
    {
        printCircle(num,col,row,start);
        start ++;
    }
    printf("\n");
}

int main()
{
    int num[][4]={
        {1,2,3,4},
        {5,6,7,8},
        {9,10,11,12},
        {13,14,15,16}
    };
    printClockwisely(num,4,4);
    return 0;
}
