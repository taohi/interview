#include <stdio.h>
enum status{
    kValid=0,
    kInvalid
};

int g_nstatus=kValid;
long long str_to_int_core(const char *digit ,int minus)
{
    long long num = 0;
    while(*digit!='\0')
    {
        if(*digit>='0' && *digit<='9')
        {
            int flag = minus?-1:1;
            num = num*10 + flag*(*digit - '0');
            if((!minus&& num>0x7FFFFFFF)||
                    (minus && num<(signed int )0x80000000))
            {
                num = 0;
                break;
            }
            digit++;
        }
        else
        {
            num=0;
            break;
        }
    }
    if(*digit=='\0')
        g_nstatus = kValid;
    return num;
}

int str_to_int(const char *str)
{
    long long num=0;
    g_nstatus=kInvalid;
    if(str!=NULL &&*str!='\0')
    {
        int minus = 0;
        if(*str=='+')
            str++;
        else if(*str=='-')
        {
            str++;
            minus=1;
        }
        if(*str!='\0')
            num = str_to_int_core(str,minus);
    }
    return (int)num;
}


int main()
{
    char str[20];
    scanf("%s",str);
    int result_num = str_to_int(str);
    if(g_nstatus == kValid)
        printf("result_num:%d\n",result_num); 
    else
        printf("invalid input.\n");
    return 0;
}
