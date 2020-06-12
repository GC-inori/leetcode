使用栈数据结构：
遇到左括号，需要压栈。
遇到右括号，判断栈顶是否和当前右括号匹配；若不匹配则返回false，否则匹配弹出栈顶。
最后判断栈是否为空；若为空则合法，否则不合法。
class Solution 
{
public:
    bool isValid(string s) 
    {
        if(s.empty()) return 1;
        const int N=s.size();
        int Stack[N],t=-1;
        for(auto c:s)
        {
            if(c=='(') Stack[++t]=0;
            else if(c=='[') Stack[++t]=1;
            else if(c=='{') Stack[++t]=2;
            else
            {
                if(t<0) return 0;
                if(c==')'&&Stack[t]!=0) return 0;
                if(c==']'&&Stack[t]!=1) return 0;
                if(c=='}'&&Stack[t]!=2) return 0;
                t--;
            }
        }
        return t<0?1:0;    
    }
};
