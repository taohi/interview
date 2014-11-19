class MinStack {
    private:
        stack<int> min;
        stack<int> data;
    public:
        void push(int x) 
        {
            data.push(x);
            if(min.empty()||x<=min.top())
            {
                min.push(x);
            }

        }
        void pop()
        {
            if(data.empty())
                return;
            if(data.top()==min.top())
            {
                data.pop();
                min.pop();
            }
            else
                data.pop();
        }

        int top()
        {
            return data.top();
        }

        int getMin()
        {
            return min.top();
        }
};
