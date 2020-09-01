class Solution {
public:
    stack<int> num;
    stack<char> op;
    void eval()
    {
        int b=num.top();
        num.pop();
        int a=num.top();
        num.pop();
        char c= op.top();
        op.pop();
        if(c=='+')
            num.push(a+b);
        else num.push(a-b);
    }
    int calculate(string s)
    {
        for(int i=0,n=s.size();i<n;i++)
        {
            if(s[i]==' ') continue;
            else if(s[i]<='9'&&s[i]>='0')
            {
                int j=i,t=0;
                while(j<n&&s[j]<='9'&&s[j]>='0') t=t*10+(s[j++]-'0');
                num.push(t);
                i=j-1;
            }
            else if(s[i]=='(') op.push('(');
            else if(s[i]==')')
            {
                while(op.top()!='(') eval();
                op.pop();
            }
            else
            {
                if(op.size()&&op.top()!='(') eval();
                op.push(s[i]);  
            }
        }
        if(op.size()) eval();
        return num.top();
    }
};
