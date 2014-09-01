#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXLEN  1000
int longest_common_substr(char *str1,char *str2)
{
   int len1=strlen(str1); 
   int len2=strlen(str2); 
   int **c=NULL;
   int i=0,j=0,k=0,max=-1;
   int x,y;
   char s[MAXLEN];
   c=(int**)malloc(sizeof(int*)*(len1+1));
   for(i=0;i<=len1;i++)
       c[i]=(int *)malloc(sizeof(int)*(len2+1));
   for(i=0;i<=len1;i++)
       c[i][0]=0;
   for(j=0;j<len2;j++)
       c[0][j]=0;
   for(i=1;i<=len1;i++)
   {
       for(j=1;j<=len2;j++)
        {
            if(str1[i-1]==str2[j-1])
                c[i][j]=c[i-1][j-1]+1;
            else
                c[i][j]=0;
            if(c[i][j]>max)
            {
                max=c[i][j];
                x=i;
                y=j;
            }
        }
   }
   //输出公共子串
   k=max;
   i=x-1;
   j=y-1;
   s[k--]='\0';
   while(i>=0&&j>=0)
   {
       if(str1[i]==str2[j])
       {
           s[k--]=str1[i];
           i--;
           j--;
       }

       else
           break;
   }
   fputs(s,stdout);
   for(i=0;i<=len1;i++)
       free(c[i]);
   free(c);
   return max;
}

int main()
{
    char str1[MAXLEN];
    char str2[MAXLEN];
    scanf("%s%s",str1,str2);
    int common_len=longest_common_substr(str1,str2);
    printf("\ncommon_length:%d\n",common_len);
    return 0;
}
