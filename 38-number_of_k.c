#include <stdio.h>

int get_firstK(int *data,int length,int k,int start,int end)
{
    if(start>end)
        return -1;
    int mid_index=(start+end)/2;
    int mid_data=data[mid_index];
    if(mid_data==k)
    {
        if((mid_index>0 && data[mid_index-1]!=k)||mid_index==0)
            return mid_index;
        else
            end=mid_index-1;
    }
    else if(mid_data>k)
        end=mid_index-1;
    else
        start = mid_index+1;
    return get_firstK(data,length,k,start,end);
}
int get_lastK(int *data,int length,int k,int start,int end)
{
    if(start>end)
        return -1;
    int mid_index=(start+end)/2;
    int mid_data=data[mid_index];
    if(mid_data==k)
    {
        if((mid_index<length-1 && data[mid_index+1]!=k)||mid_index==length-1)
            return mid_index;
        else
            start=mid_index+1;
    }
    else if(mid_data<k)
        start=mid_index+1;
    else
        end = mid_index-1;
    return get_lastK(data,length,k,start,end);
}

int get_number_of_k(int *data,int length,int k)
{
    int number=0;
    if(data!=NULL &&length>0)
    {
        int first = get_firstK(data,length,k,0,length-1);
        int last = get_lastK(data,length,k,0,length-1);
        if(first>-1 &&last>-1)
            number = last-first+1;
    }
    return number;
}
int main()
{
    int data[]={1,2,3,3,3,3,4,5};
    printf("count:%d\n",get_number_of_k(data,8,3));
    return 0;
}
