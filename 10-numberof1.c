#include <stdio.h>
int numberof1(int n)
{
    int count = 0;
    while(n)
    {
        ++count;
        n=(n-1) & n;
    }
    return count;
}
int main()
{
    int n;
    scanf("%d",&n);
    printf("%d\n",numberof1(n));
    return 0;
}
