#include <string> 
#include <iostream>
using namespace::std;

string countAndSay(int n)
{
    string result[2];
    int cur=0;
    result[cur]="1";
    for(int count=1;count<n;count++)
    {
        int len=result[cur].size();
        for(int i=0;i<len;i++)
        {
            char c=result[cur][i];
            int sum=1;
            int j=i+1;
            while(c==result[cur][j])
            {
                sum++;
                j++;
                i++;
            }
            result[(cur+1)%2].append(1,'0'+sum);
            result[(cur+1)%2].append(1,c);
        }
        cout<<result[cur]<<endl;
        result[cur].clear();
        cur=(cur+1)%2;
    }
    cout<<result[cur]<<endl;
    return result[cur];
}

int main(int argc,char *argv[])
{
    int n;
    cin>>n;
    countAndSay(n);
    return 0;
}
