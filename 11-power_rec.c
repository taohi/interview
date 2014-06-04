#include <stdio.h>
int flag_invalid_input = 0;

int equal(double num1,double num2)
{
    if((num1 - num2 < 0.0000001) && (num1 - num2 > -0.0000001))
        return 1;
    else
        return 0;
}

double power_rec(double base,unsigned int exponent_value)
{
    double result;
    if(exponent_value == 0)
        return 1;
    if(exponent_value == 1)
        return base;
    result = power_rec(base,exponent_value>>1);
    result *=result;
    if(exponent_value &0x1 ==1)
        result *=base;
    return result; 
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
    result =power_rec(base,exponent_value);
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
