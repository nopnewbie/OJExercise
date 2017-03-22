class MinStack {
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        if (mStack.empty() || x < getMin())
            curMin.push(x);
        else
            curMin.push(curMin.top());
        mStack.push(x);
    }
    
    void pop() {
        if (mStack.empty())
            throw std::out_of_range("pop on empty stack!");
        mStack.pop();
        curMin.pop();
    }
    
    int top() {
        if (mStack.empty())
            throw std::out_of_range("get top on empty stack!");
        return mStack.top();
    }
    
    int getMin() {
        if (curMin.empty())
            throw std::out_of_range("getMin on empty stack!");
        return curMin.top();
    }
private:
    stack<int> mStack, curMin;
};