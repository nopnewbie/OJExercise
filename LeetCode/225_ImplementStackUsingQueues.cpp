class MyStack {
    queue<int> q1, q2;
    
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        if (q2.empty())
            q1.push(x);
        else
            q2.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int res;
        if (q2.empty())
        {
            while(q1.size() > 1)
            {
                q2.push(q1.front());
                q1.pop();
            }
            res = q1.front();
            q1.pop();
        }
        else
        {
            while (q2.size() > 1)
            {
                q1.push(q2.front());
                q2.pop();
            }
            res = q2.front();
            q2.pop();
        }
        return res;
    }
    
    /** Get the top element. */
    int top() {
        if (q1.empty())
            return q2.back();
        else
            return q1.back();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.empty() && q2.empty();
    }
};