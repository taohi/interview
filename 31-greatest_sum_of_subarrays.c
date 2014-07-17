#include <stdio.h>

int invalid_input=0;
int greatest_sub_array(int *a,int n)
{
    if(a==NULL||n<=0)
    {
        invalid_input=1;
        return 0;
    }
    int current_sum=0;
    int greatest_sum=0x80000000;
    int i=0;
    for(i=0;i<n;i++)
    {
        if(current_sum<=0)
            current_sum=a[i];
        else
            current_sum+=a[i];
        if(current_sum > greatest_sum)
            greatest_sum = current_sum;
    }
    return  greatest_sum;
}

int main()
{
    int a[]={1,-2,3,10,-4,7,2,-5};
    int greatest = greatest_sub_array(a,8);
    if(invalid_input==0)
        printf("greatest sum:%d\n",greatest);
    else
        printf("invalid input\n");
    return 0;
}
