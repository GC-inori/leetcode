class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int> q,w;//两个队列模拟栈，出栈时只要把队列中元素只剩一个即可 
    MyStack() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        while(q.size()>1) w.push(q.front()),q.pop();
        int res=q.front();
        q.pop();
        swap(q,w);
        return res;
    }
    
    /** Get the top element. */
    int top() 
    {
        while(q.size()>1) w.push(q.front()),q.pop();
        int res=q.front();
        q.pop();
        w.push(res);
        swap(q,w);
        return res;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
