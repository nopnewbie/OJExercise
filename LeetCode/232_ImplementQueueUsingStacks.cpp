class MyQueue {
    stack<int> in, out;
    void validate()
    {
        if (this->empty())
            throw std::out_of_range("operation on empty queue!");
    }
    
    void toOut()
    {
        if (out.empty())
            while (!in.empty())
            {
                out.push(in.top());
                in.pop();
            }
    }
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        in.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        validate();
        int ret = peek();
        out.pop();
        return ret;
    }
    
    /** Get the front element. */
    int peek() {
        validate();
        toOut();
        return out.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return in.empty() && out.empty();
    }
};