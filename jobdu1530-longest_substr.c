/*
   1530 题目描述：
   最长不重复子串就是从一个字符串中找到一个连续子串，该子串中任何两个字符都不能相同，且该子串的长度是最大的。
   输入：
   输入包含多个测试用例，每组测试用例输入一行由小写英文字符a,b,c...x,y,z组成的字符串，字符串的长度不大于10000。
   输出：
   对于每组测试用例，输出最大长度的不重复子串长度。

   样例输入：
   absd
   abba
   abdffd
   样例输出：
   4
   2
   4

   来源：
   阿尔卡特2013年实习生招聘笔试题
*/

#include <stdio.h>
#include <string.h>

int find_longest(char *ptr)
{
    int cur_longest=0;
    int length=0;
    char *hash[150];
    int i=0;
    memset(hash,0,sizeof hash);
    while(*ptr!='\0')
    {
        if(hash[*ptr]==0)
        {
            hash[*ptr++]=ptr;
            length++;
        }
        else
        {
            if(length>cur_longest)
                cur_longest=length;
            ptr=hash[*ptr]+1;
            memset(hash,0,sizeof hash);
            length=0;
        }
    }
    if(length>cur_longest)
        cur_longest=length;
    return cur_longest;
}

int main()
{
    char buf[10001];
    while(scanf("%s",buf)!=EOF)
    {
        printf("%d\n",find_longest(buf));
    }
    return 0;
}
