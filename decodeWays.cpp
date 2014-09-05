#include <iostream>
#include <vector>
using namespace::std;
int decodeWays(string &s)
{
    if(s.empty()||s[0]=='0')
        return 0;
    int i=0;
    vector<int> f(s.size(),0);
    //f[i]表示s到下标为i时解码的种数
    f[0]=1;
    if((s[0]=='1' && s[1]>'0')||(s[0]=='2' && s[1]<='6'&& s[1]>'0'))
        f[1]=2;
    else if(s[0]>='3' && s[1]=='0')
        return 0;
    else
        f[1]=1;
    for(i=2;i<s.size();i++)
    {
        if(s[i]==0)
        {
            if(s[i-1]=='0'||s[i-1]>='3')
                return 0;
            f[i]=f[i-2];
        }
        else if(s[i-1]=='1'||(s[i-1]=='2' && s[i]<='6'))
            f[i]=f[i-1]+f[i-2];
        else
            f[i]=f[i-1];
    }
    return f[s.size()-1];
}

int main()
{
    string s;
    cin>>s;
    cout<<decodeWays(s)<<endl;
    return 0;
}
