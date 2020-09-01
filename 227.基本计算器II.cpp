模板
从左往右遍历 
1. 遇到数字直接压入数栈中
2.遇到左括号压入op栈中
3.遇到右括号将左右括号间的全部计算
4.遇到操作符 将op栈中所有优先级大于等于它的出栈运算 
class Solution {
public:
    stack<int> num;
    stack<char> op;
    unordered_map<char,int> um;
    int calculate(string s) 
    {
        um['+']=um['-']=0;
        um['*']=um['/']=1; 
        um['#']=-1;
        s.push_back('#');
        for(int i=0,n=s.size();i<n;i++)
        {
            if(s[i]==' ') continue;
            if(s[i]<='9'&&s[i]>='0')
            {
                int t=0;
                while(i<n&&s[i]<='9'&&s[i]>='0') t=t*10+(s[i++]-'0');
                num.push(t);
                i--;
            }
            else
            {
                while(op.size()&&um[op.top()]>=um[s[i]])
                {
                    auto t=op.top();
                    op.pop();
                    int b=num.top();
                    num.pop();
                    int a=num.top();
                    num.pop();
                    if(t=='+') num.push(a+b);
                    else if(t=='-') num.push(a-b);
                    else if(t=='*') num.push(a*b);
                    else num.push(a/b);
                }
                op.push(s[i]);
            }
        }
        return num.top();
    }
};
