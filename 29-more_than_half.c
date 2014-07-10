#include <stdio.h>
//输入是否有效的全局标志
int input_valid = 1;

//检查某整数number是否出现次数超过一半
int is_than_half(int *num,int length,int number)
{
    int times=0,i=0;
    int than_half=0;
    for(i=0;i<length;i++)
    {
        if(num[i]==number)
            times++;
    }
    if(times*2>length)
        than_half=1;
    else
        input_valid=0;
}

//找出可能超过一半的那个数，然后调用is_than_half
//对该数确认
int more_than_half(int *num,int length)
{
    int result = num[0];
    int i,times=1;
    if(num==NULL||length<=0)
    {
        input_valid=0;
        return 0;
    }

    for(i=0;i<length;i++)
    {
        if(times==0)
        {
            result=num[i];
            times++;
        }
        else if(num[i]==result)
            times++;
        else
            times--;
    }
    return result;
}

int main()
{
    int n[]={1,2,2,2,5,6,7,3,2,2,2,3,2};
    int result=more_than_half(n,13);
    if(input_valid)
        printf("the num is:%d\n",result);
    return 0;
}
