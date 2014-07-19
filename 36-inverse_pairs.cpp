#include <stdio.h>

int inverse_pair_core(int *data,int *copy,int start,int end)
{
    if(start == end)
    {
        copy[start]=data[start];
        return 0;
    }
    int length = (end-start)/2;
    int left = inverse_pair_core(copy,data,start,start+length);
    int right = inverse_pair_core(copy,data,start+length+1,end);
    int i=start+length;
    int j=end;
    int index_copy = end;
    int count=0;
    while(i>=start &&j>=start+length+1)
    {
        if(data[i]>data[j])
        {
            copy[index_copy--]=data[i--];
            count+=j-start-length;
        }
        else
            copy[index_copy--]=data[j--];
    }
    for(;i>=start;--i)
        copy[index_copy--]=data[i];
    for(;j>=start+length+1;--j)
        copy[index_copy--]=data[j];
    return left+right+count;
}


int inverse_pairs(int *data,int length)
{
    if(data==NULL||length<0)
        return 0;
    int *copy = new int[length];
    for(int i=0;i<length;i++)
        copy[i]=data[i];
    int count = inverse_pair_core(data,copy,0,length-1);
    delete[] copy;
    return count;
}

int main()
{
    int data[]={7,5,6,4};
    printf("%d\n",inverse_pairs(data,4));
    return 0;
}
