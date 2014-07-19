#include <stdio.h>

int find_num_withsum(int *data,int length,int sum,int *num1,int *num2)
{
    int found=0;
    if(length<1||num1==NULL||num2==NULL)
        return found;
    int big=length-1;
    int small=0;
    while(big>small)
    {
        int cur_sum = data[small]+data[big];
        if(cur_sum == sum)
        {
            *num1 = data[small];
            *num2 = data[big];
            found = 1;
            break;
        }
        else if(cur_sum>sum)
            big--;
        else
            small++;
    }
    return found;
}

int main()
{
    int data[]={1,2,4,7,11,15};
    int number1,number2;
    if(find_num_withsum(data,6,15,&number1,&number2))
        printf("%d+%d\n",number1,number2);
    else
        printf("not found\n");
    return 0;
}
