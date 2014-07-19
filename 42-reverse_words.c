#include <stdio.h>

void reverse(char *pbegin,char *pend)
{
    char temp;
    if(pbegin==NULL||pend==NULL)
        return;
    while(pbegin<pend)
    {
        temp=*pbegin;
        *pbegin=*pend;
        *pend=temp;
        pbegin++;
        pend--;
    }

}

char *reverse_words(char *pdata)
{
    if(pdata==NULL)
        return NULL;
    char *pbegin=pdata;
    char *pend=pdata;
    while(*pend!='\0')
        pend++;
    pend--;
    //先翻转句子的每个字符
    reverse(pbegin,pend);
    pbegin=pend=pdata;
    //再翻转每个word的字符
    while(*pbegin!='\0')
    {
        if(*pbegin==' ')
        {
            pbegin++;
            pend++;
        }
        else if(*pend==' '||*pend=='\0')
        {
            reverse(pbegin,--pend);
            pbegin=++pend;
        }
        else
            pend++;
    }
    return pdata;
}

int main()
{
    char sentence[256];
    char *result=NULL;
//    fgets(sentence,256,stdin);
    scanf("%[^\n]",sentence);
    reverse_words(sentence);
    printf("%s\n",sentence);
    return 0;
}
