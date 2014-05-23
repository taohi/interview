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
    //这个scanf的参数，表示获取输入，直到出现回车符。
    //所以这样能输入带空格的字符串。
    scanf("%[^\n]",str);
    replaceBlank(str,LEN);
}
