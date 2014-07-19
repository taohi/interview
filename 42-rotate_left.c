#include <stdio.h>
#include <string.h>

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

void rotate_left(char *pdata,int length,int n)
{
    if(n<=0||n>length||pdata==NULL)
        return ;
    char *pbegin=pdata;
    char * pend=pdata+n-1;
    reverse(pbegin,pend);
    pbegin=pend+1;
    pend=pdata+length-1;
    reverse(pbegin,pend);
    reverse(pdata,pdata+length-1);
}

int main()
{
    char sentence[256];
    char *result=NULL;
//    fgets(sentence,256,stdin);
    scanf("%[^\n]",sentence);
    int length=strlen(sentence);
    int n;
    scanf("%d",&n);
    rotate_left(sentence,length,n);
    printf("%s\n",sentence);
    return 0;
}
