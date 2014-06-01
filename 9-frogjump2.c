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
