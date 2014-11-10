#include <iostream>
#include <string>
using namespace std;
bool isPalindrome(string s)
{
    if(s.empty())
        return true;
    string::size_type idx1=0;
    string::size_type idx2=s.size()-1;
    while(idx1<idx2)
    {
        if(!isalnum(s[idx1]))
        {
            idx1++;
            continue;
        }
        if(!isalnum(s[idx2]))
        {
            idx2--;
            continue;
        }
        if(tolower(s[idx1])!=tolower(s[idx2]))
            return false;
        idx1++;
        idx2--;
    }
    return true;
}

//for testing case.
int main()
{
    string s="A man,a plan a canal:Panama";
    if(isPalindrome(s))
        cout<<"true"<<endl;
    return 0;
}
