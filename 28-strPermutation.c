#include <stdio.h>
#define LENGTH  50

void permutation(char *pstr,char *pbegin)
{
    char *pch=NULL;
    char temp;
    if(pstr==NULL)
        return;
    if(*pbegin=='\0')
        printf("%s\n",pstr);
    else
    {
        for(pch=pbegin;*pch!='\0';++pch)
        {
            temp=*pch;
            *pch=*pbegin;
            *pbegin=temp;
            permutation(pstr,pbegin+1);
            temp=*pch;
            *pch=*pbegin;
            *pbegin=temp;
        }
    }
}

int main()
{
    char str[LENGTH]; 
    scanf("%s",str);
    permutation(str,str);
    return 0;
}

