#include <iostream>
#include <vector>
using namespace::std;

int minDistance(string word1,string word2)
{
   const int m=word1.size();
   const int n=word2.size();
   if(m==0)
       return n;
   if(n==0)
       return m;
   int f[m+1][n+1];
   for(int i=0;i<=m;i++)
       f[i][0]=i;
   for(int j=0;j<=n;j++)
       f[0][j]=j;
   for(int i=1;i<=m;i++)
   {
       for(int j=1;j<=n;j++)
       {
           if(word1[i-1]==word2[j-1])
               f[i][j]=f[i-1][j-1];
           else
               f[i][j]=min(f[i-1][j-1]+1,min(f[i-1][j]+1,f[i][j-1]+1));
       }
   }
   return f[m][n];
}

int main()
{
    string a,b;
    cin>>a>>b;
    cout<<minDistance(a,b)<<endl;
    return 0; 
}
