#include <stdio.h>
int add(int num1,int num2)
{
    int sum,carry;
    do
    {
        sum = num1^num2;
        carry = (num1&num2)<<1;
        num1=sum;
        num2=carry;
    }while(num2!=0);
    return num1;
}

int main()
{
    int num1,num2;
    scanf("%d %d",&num1,&num2);
    printf("(%d)+(%d)= %d\n",num1,num2,add(num1,num2));
    return 0;
}
