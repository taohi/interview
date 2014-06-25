#include <iostream>
#include <stack>
using namespace::std;

bool isPopOrder(int *pPush ,int *pPop,int length)
{
    bool result = false;
    int *nextPush=pPush;
    int *nextPop=pPop;
    if(pPush!=NULL ||pPop!=NULL||length>0)
    {
        stack<int> stackData;
        while(nextPop-pPop<length)
        {
            while(stackData.empty()||stackData.top()!=*nextPop)
            {
                if(nextPush-pPush==length)
                    break;
                stackData.push(*nextPush);
                nextPush++;
            }
            if(stackData.top()!=*nextPop)
                break;
            stackData.pop();
            nextPop++;
        }
        if(stackData.empty() && nextPop-pPop==length)
            result = true;
    }
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
