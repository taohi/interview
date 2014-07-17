//时间复杂度O(logn) 
#include <stdio.h>
#include <math.h>

int power_of_10(unsigned int n)
{
    int i=0;
    int result=1;
    while(i<n)
    {
        result*=10;
        i++;
    }
    return result;
}

int number_of_1(int n)
{
    if(n<=0)
        return 0;
    char strN[50];
    sprintf(strN,"%d",n);
    int i=0,length=0;
    for(i=0;(*(strN+i)!='\0');i++)
        length++;
    int first = *strN - '0';
    if(length==1 && first==0)
        return 0;
    if(length==1 && first>1)
        return 1;
    //number_of_1表示n的最高位1出现的次数
    int num_first_digits=0;
    if(first>1)
        num_first_digits = power_of_10(length-1);
    else if(first==1)
        num_first_digits = atoi(strN+1)+1;
    int num_other_digits=first * (length-1)*power_of_10(length-2);
    int num_recursive=number_of_1(atoi(strN+1));
    return num_first_digits+num_other_digits+num_recursive;
}

int main()
{
    unsigned  int n;
    scanf("%d",&n); 
    printf("%d\n",number_of_1(n));
    return 0;
}
