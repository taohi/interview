class Solution {
    public:
        int atoi(const char *str) {
            int result=0;
            int n=strlen(str);
            int i=0;
            int flag=1;
            if(n==0)
                return 0;
            while(str[i]==' ' && i<n)
                i++;
            if(str[i]=='-')
            {
                flag=-1;
                i++;
            }
            else if(str[i]=='+')
                i++;
            while(i<n)
            {
                if(str[i]>'9'||str[i]<'0')
                {
                    i++;
                    break;
                }
                else
                {
                    if(result>INT_MAX/10||(result==INT_MAX/10 && (str[i]-'0')>INT_MAX%10))
                        return flag==1?INT_MAX:INT_MIN;
                    result=result*10+str[i]-'0';
                    i++;
                }
            }
            return (result*flag);
        }
};
