#include <stdio.h>
int numberof1(unsigned int n)
{
    int number = 0;
    while(n)
    {
        if(n%10==1)
            number++;
        n=n/10;
    }
    return number;
}

int numberof1_from1toN(unsigned int n)
{
    int number=0;
    int i;
    for(i=1;i<=n;i++)
        number+=numberof1(i);
    return number;
}

int main()
{
    unsigned  int n;
    scanf("%d",&n); 
    printf("%d\n",numberof1_from1toN(n));
    return 0;
}
