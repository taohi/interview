#include <stdio.h>
#define LEN 50
void replaceBlank(char *str,int length)
{
    int len1=0,len2=0,space_num=0;
    int i=0;
    while(str[len1]!='\0')
    {
        if(str[len1]==' ')
            space_num++;
        len1++;
    }
    len2=len1+space_num*2; 
    if(len2>length)
        return;
    while(len1>0)
    {
        if(str[len1] ==' ')
        {
            str[len2--]='0';
            str[len2--]='2';
            str[len2--]='%';
        }
        else
            str[len2--]=str[len1];
        len1--;
    }
    printf("%s\n",str);
}

int main()
{
    char str[LEN];
    scanf("%[^\n]",str);
    replaceBlank(str,LEN);
}
