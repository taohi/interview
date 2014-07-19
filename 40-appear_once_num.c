#include <stdio.h>

int is_bit1(int num,unsigned int index)
{
    num=num>>index;
    return (num &1);
}

unsigned int find_first_bit1(int num)
{
    int index=0;
    while((num&1)==0 && index <=8*sizeof(int))
    {
        num>>=1;
        index++;
    }
    return index;
}

void num_appear_once(int *data,int length ,int *num1,int *num2)
{
    if(data==NULL||length<2)
        return;
    int result_after_XOR=0;
    int i=0,j=0;
    for(;i<length;i++)
        result_after_XOR^=data[i];
    unsigned int index_of_1 = find_first_bit1(result_after_XOR);
    *num1=*num2=0;
    for(;j<length;j++)
    {
        if(is_bit1(data[j],index_of_1))
            *num1^=data[j];
        else
            *num2^=data[j];
    }
}

int main()
{
    int data[]={2,4,3,6,3,2,5,5};
    int num1,num2;
    num_appear_once(data,8,&num1,&num2);
    printf("%d,%d\n",num1,num2);
    return 0;
}
