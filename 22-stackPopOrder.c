#include <iostream>
#include <stack>
using namespace::std;

bool isPopOrder(int *pPush ,int *pPop,int length)
{
    bool result = false;






    return result;
}



int main()
{
    int push[]={1,2,3,4,5};
    int pop[]={4,5,3,2,1};
    if(isPopOrder(push,pop,5))
        cout <<"Is Pop Order."<<endl;
    else
        cout <<"Not Pop Order."<<endl;
    return 0;
}
