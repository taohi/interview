#include <stdio.h>
//使用二分查找的方式，使得时间复杂度为O(logn)
int minInOrder(int *num,int index1,int index2)
{
    int result=num[index1];
    int i=0;
    while(i<=index2)
    {
        if(result>num[i])
            result=num[i];
        i++;
    }
    return result;
}

int min(int *num,int length)
{
    if(num==NULL||length<=0)
        return -1;
    int index1=0,index2=length-1;
    int indexMid=index1;
    while(num[index1]>=num[index2])
    {
        if(index2-index1 == 1)
        {
            indexMid = index2;
            break;
        }
        indexMid=(index1+index2)/2;
        if(num[indexMid]==num[index1] && num[index1]==num[index2])
            return minInOrder(num,index1,index2);
        if(num[indexMid]>num[index1])
            index1=indexMid;
        else if(num[indexMid]<num[index2])
            index2=indexMid;
    }
    return num[indexMid];
}

int main()
{
    //int num[]={3,4,5,1,2};
    int num[]={1,1,1,0,1};
    printf("min number:%d\n",min(num,5));
    return 0;
}
