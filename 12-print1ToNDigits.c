#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int increase(char *number)
{
    int overflow = 0;
    int takeOver = 0;
    int length = strlen(number);
    int i=0 ,sum;
    for(i=length-1;i>=0;i--)
    {
       sum = number[i]-'0'+takeOver;
       if(i==length-1)
           sum++;
       if(sum>=10)
       {
           if(i==0)
               overflow = 1;
           else
           {
               sum-=10;
               takeOver=1;
               number[i]='0'+sum;
           }
       }
       else
       {
           number[i]='0'+sum;
           break;
       }
    }
    return overflow;
}
void printNumber(char *number)
{
    int isBegin0 = 1;
    int length = strlen(number);
    int i=0;
    for(i=0;i<length;i++)
    {
        if(isBegin0 && number[i]!='0')
            isBegin0 = 0;
        if(!isBegin0)
            printf("%c",number[i]);
    }
    printf("\t");
}

void print1ToNDigits(int n)
{
    if(n<=0)
        return;
    char *number = (char *)malloc((n+1)*sizeof(char));
    memset(number,'0',n);
    number[n] = '\0';
    while(!increase(number))
        printNumber(number);
    printf("\n");
    free(number);
}

int main()
{
    int n;
    scanf("%d",&n);
    print1ToNDigits(n);
    return 0;
}
