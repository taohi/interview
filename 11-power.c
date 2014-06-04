#include <stdio.h>
int flag_invalid_input = 0;

int equal(double num1,double num2)
{
    if((num1 - num2 < 0.0000001) && (num1 - num2 > -0.0000001))
        return 1;
    else
        return 0;
}

double power(double base,int exponent)
{
    double result = 1.0;
    unsigned int exponent_value ;
    int i;
    if(equal(base,0.0) && exponent<0)
    {
        flag_invalid_input = 1;
        return 0.0;
    }
    if(exponent<0)
        exponent_value = (unsigned int)(-exponent);
    else
        exponent_value = exponent;
    for(i=1;i<=exponent_value;i++)
        result *=base;
    if(exponent <0)
        result = 1.0/result;
    return result;
}

int main()
{
   double base;
   int    exponent;
   scanf("%lf%d",&base,&exponent);
   printf("%lf\n",power(base,exponent));
   return 0;
}
