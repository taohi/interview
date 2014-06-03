#include <stdio.h>
long long frogjump(unsigned n)
{
    int i=0;
    long long result=0;
    if(n<=1)
        return 1; 
    for(i=0;i<n;i++)
        result += frogjump(i);
    return result;
}

int main()
{
    int n;
    scanf("%d",&n);
    printf("%lld\n",frogjump(n));
    return 0;
}
