#include <iostream>
#include <string>
#include <algorithm>

using namespace::std;

int fib(int n)
{
    int fib_n=1;
    for(int i=2;i<=n;i++)
        fib_n*=i;
    return fib_n;
}



//Time Limit Exceeded.
string getPermutation(int n,int k)
{
    string result;
    if(k>fib(n)) return result;
    for(int i=0;i<n;i++)
    {
        char c='1'+i;
        result.push_back(c);
    }
    for(int i=1;i<k;i++)
        next_permutation(result.begin(),result.end());
    return result;
}

string getPermutation2(int n,int k)
{
    string s;
    if(k>fib(n)) return s;
    for(int i=0;i<n;i++)
    {
        char c='1'+i;
        s.push_back(c);
    }
    if(k==fib(n))
    {
        reverse(s.begin(),s.end());
        return s;
    }
    int i=0;
    for(i=0;i<n;i++)
        if(fib(i+1)>k)
            break;
    int cur=s.size()-1-i;
    while(k)
    {
        int res=k/fib(i);
        if(k%=fib(i))
        {
            char temp=s[cur+res];
            s.erase(cur+res,1);
            s.insert(s.begin()+cur,temp);
            cur++;
        }
        else
        {
            char temp=s[cur+res-1];
            s.erase(cur+res-1,1);
            s.insert(s.begin()+cur,temp);
            cur++;
            reverse(s.begin()+cur,s.end());
        }
        i--;
    }
    return s;
}
int main()
{
    int n,k;
    cin>>n>>k;
    //cout<<getPermutation(n,k)<<endl;
    cout<<getPermutation2(n,k)<<endl;
    return 0;
}
