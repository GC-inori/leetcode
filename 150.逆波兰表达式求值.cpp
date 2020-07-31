遍历所有元素。如果当前元素是整数，则压入栈；如果是运算符，则将栈顶两个元素弹出做相应运算，再将结果入栈。
最终表达式扫描完后，栈里的数就是结果。
class Solution {
public:
    int evalRPN(vector<string>& tokens) 
    {
        stack<int> s;
        for(auto &c:tokens)
        {
            if(c[0]<='9'&&c[0]>='0'||c[0]=='-'&&c.size()>1)
                s.push(stoi(c));
            else
            {
                auto t=s.top();
                s.pop();
                if(c=="+") t+=s.top();
                else if(c=="*") t*=s.top();
                else if(c=="-") t=s.top()-t;
                else t=s.top()/t;
                s.pop();
                cout<<t<<endl;
                s.push(t);
            }
        }
        return s.top();
    }
};
