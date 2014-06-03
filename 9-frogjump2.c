//青蛙一次可以跳1级或者2级台阶，那么N级台阶有几种跳法
#include <stdio.h>
long long frogjump(unsigned n)
{
    if(n<=1)
        return 1; 
    return frogjump(n-1)+frogjump(n-2);
}

int main()
{
    int n;
    scanf("%d",&n);
    printf("%lld\n",frogjump(n));
    return 0;
}
