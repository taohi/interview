#include <iostream>
#include <stack>
using namespace::std;

class minStack
{
    private:
        stack <int> datastack;
        stack <int> minstack;
    public:
        int top();
        void pop();
        void push(int);
        void getMin();
};

int minStack::top()
{
    return datastack.top();
}

void minStack::pop()
{
    cout<<"pop():\t\t";
    if(datastack.empty()||minstack.empty())
        cout << "stack empty."<<endl;
    else
    {
        if(datastack.top() == minstack.top())
            minstack.pop();
        datastack.pop();
        minStack::getMin();
    }
}

void minStack::push(int n)
{
    cout<<"push("<<n<<"):\t";
    datastack.push(n);
    if(minstack.empty())
        minstack.push(n);
    else if(minstack.top()>=n)
        minstack.push(n);
    minStack::getMin();
}

void minStack::getMin()
{
    if (minstack.empty())
        cout<<"stack empty."<<endl;
    else
        cout <<"min in stack:" << minstack.top()<<endl;
}

int main()
{
    minStack testStack;
    testStack.push(3);
    testStack.push(5);
    testStack.push(2);
    testStack.pop();
    testStack.pop();
    testStack.push(1);
    testStack.pop();
    testStack.pop();
    testStack.pop();
    return 0;
}
