#include <stdio.h>
typedef unsigned int (*fun)(unsigned int);

unsigned int terminator(unsigned int n)
{
    return 0;
}

unsigned int sum(unsigned int n)
{
    static fun f[2]={terminator,sum};
    return n+f[!!n](n-1);
}

int main()
{
    int n;
    scanf("%d",&n);
    printf("%d\n",sum(n));
    return 0;
}
