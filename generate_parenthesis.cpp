#include <iostream>
#include <string>
#include <vector>
using namespace::std;

void generate_parenthesis(int n,int left,int right,string &str,vector<string> &result)
{
    
    if(n==left && n==right)
        result.push_back(str);
    if(left<n)
    {
        str.push_back('(');
        generate_parenthesis(n,left+1,right,str,result);
        str.erase(str.end()-1);
    }
    if(right<n && right<left)
    {
        str.push_back(')');
        generate_parenthesis(n,left,right+1,str,result);
        str.erase(str.end()-1);
    }
}

int main()
{
    vector<string> result;
    string str;
    int n;
    cin>>n;
    generate_parenthesis(n,0,0,str,result);
    for(int i=0;i<result.size();i++)
        cout<<result[i]<<endl;
    return 0;
}


