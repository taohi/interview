#include <iostream>
#include <vector>
#include <algorithm>
using namespace::std;

void printNum(vector<int> num)
{
    for(int i=0;i<num.size();i++)
        cout<<num[i]<<" ";
    cout<<endl;
}

void nextPermutation(vector<int> &num)
{
    if(num.size()==0||num.size()==1)
        return;
    vector<int>::iterator iter1=num.end()-1;
    vector<int>::iterator iter2=num.end()-2;
    while(*iter2>=*iter1 && iter2>=num.begin())
    {
            iter2--;
            iter1--;
    }
    if(*iter2>=*iter1)
    {
        reverse(num.begin(),num.end());
        return;
    }
    vector<int>::iterator iter3=num.end()-1;
    while(*iter2>=*iter3)
    {
        if(iter3==num.begin())
            iter3=num.end()-1;
        else
            iter3--;
    }
    swap(*iter2,*iter3);
    reverse(iter1,num.end());
} 
int main()
{
    vector<int> num;
    int temp;
    while(cin>>temp)
        num.push_back(temp);
    nextPermutation(num);
    printNum(num);
    return 0;
}
