class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> s,s1;//s保存栈中元素  s1保存最小元素 
    MinStack() 
    {    
    }
    
    void push(int x) 
    {
        s.push(x);
        if(s1.size()&&s1.top()<x)
            s1.push(s1.top());
        else s1.push(x);  
    }
    
    void pop() 
    {
        s.pop();
        s1.pop();    
    }
    
    int top() 
    {
        return s.top();    
    }
    
    int getMin() 
    {
        return s1.top();    
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
