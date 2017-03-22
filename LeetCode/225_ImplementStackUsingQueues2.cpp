/*
	不用辅助队列实现“队列模拟栈”. 只要在pop时记录是否到最后一个入队元素即可，仅用一个变量。
*/

class MyStack {
    queue<int> q;
    void validate()
    {
        if (q.empty())
            throw std::out_of_range("operation on empty stack!");
    }
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        validate();
        int res = q.back();
        int len = q.size();
        while (len > 1)
        {
            int head = q.front();
            q.pop();
            q.push(head);
            --len;
        }
        q.pop();
        return res;
    }
    
    /** Get the top element. */
    int top() {
        validate();
        return q.back();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
};